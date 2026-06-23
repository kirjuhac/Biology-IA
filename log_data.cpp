#include <SPI.h>
#include <SD.h>

File logFile;

void setup() {
  Serial.begin(115200);

  if (!SD.begin(14)) { //init SD card
    Serial.println("SD init failed");
    return;
  }

  Serial.println("SD ready!");

  logFile = SD.open("log.txt", FILE_WRITE); //create file, open file

  if (!logFile) {
    Serial.println("File open failed");
    return;
  }
}

void loop() {

  logFile.println("hello world"); // log data
  logFile.flush(); // save data

  Serial.println("logged: hello world"); //confirm idk why this is there

  delay(10000);
}
