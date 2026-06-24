#include <Wire.h>
#include <Adafruit_SCD30.h>

Adafruit_SCD30 scd30;

void setup() {
  Serial.begin(115200);

  while (!Serial) {
    delay(10);
  }

  Serial.println("Starting SCD30...");

  if (!scd30.begin()) {
    Serial.println("SCD30 not found!");
    while (1) {
      delay(100);
    }
  }

  Serial.println("SCD30 detected.");
}

void loop() {
  if (scd30.dataReady()) {

    if (scd30.read()) {
      Serial.print("CO2: ");
      Serial.print(scd30.CO2);
      Serial.print(" ppm");

      Serial.print("Temp: ");
      Serial.print(scd30.temperature);
      Serial.print(" °C");

      Serial.print("Humidity: ");
      Serial.print(scd30.relative_humidity);
      Serial.println(" %");
    } else {
      Serial.println("Failed to read sensor.");
    }
  } else {
    Serial.println("No data available.");
  }

  delay(5000);  // Wait 5 seconds
}
