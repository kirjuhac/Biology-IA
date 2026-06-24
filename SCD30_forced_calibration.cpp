#include <Wire.h>
#include <Adafruit_SCD30.h>

Adafruit_SCD30 scd30;

void setup() {
  Serial.begin(115200);

  if (!scd30.begin()) {                                // check if the sensor is recognized
    Serial.println("Sensor not found");
    while (1);
  }

  scd30.selfCalibrationEnabled(false);                // disable self calibration

  Serial.println("Waiting 2 minutes...");
  delay(120000);                                      // wait 2 minutes

  if (scd30.forceRecalibrationWithReference(420)) {   // force calibrate with outdoor air reference to 420ppm
    Serial.println("FRC successful");
  } else {
    Serial.println("FRC failed");
  }
}

void loop() {
}
