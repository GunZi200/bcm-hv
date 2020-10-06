#include <Arduino.h>
#include "vicor.h"

Vicor vicor;

void setup() {

  Serial.begin(115200);
  //Initialize the chip

  while (!Serial) {
  };
  
  while (vicor.begin() != 0) {
    Serial.println("Failed to Initialize the chip, please confirm the wire connection");
    delay(1000);
  }

  //vicor.disable_faults();
  //vicor.read_CML();
  //Serial.flush();
  //abort();
  
  
}

void loop() {

  //vicor.clear_faults();
  //vicor.operation();

  Serial.print("Input voltage (V):");
  Serial.println(vicor.get_READ_VIN());

  Serial.print("Output voltage (V):");
  Serial.println(vicor.get_READ_VOUT());

  Serial.print("K factor (V/V):");
  Serial.println(vicor.get_READ_K_FACTOR());

  Serial.print("Time on delay (s):");
  Serial.println(vicor.get_TON_DELAY());

  Serial.print("Output resistance (Ohms):");
  Serial.println(vicor.get_READ_BCM_ROUT());
  
  Serial.print("Internal temperature (°C):");
  Serial.println(vicor.get_READ_TEMPERATURE_1());

  Serial.print("Output current (A):");
  Serial.println(vicor.get_READ_IOUT());

  Serial.print("Input current (A):");
  Serial.println(vicor.get_READ_IIN());

  Serial.print("Output power (W):");
  Serial.println(vicor.get_READ_POUT());

  Serial.print("\n");

  Serial.print("Min rated HI-side voltage: ");
  Serial.println(vicor.get_MFR_VIN_MIN(), HEX);

  Serial.print("Max rated HI-side voltage: ");
  Serial.println(vicor.get_MFR_VIN_MAX(), HEX);

  Serial.print("Min rated LO-side voltage: ");
  Serial.println(vicor.get_MFR_VOUT_MIN());

  Serial.print("Max rated LO-side voltage: ");
  Serial.println(vicor.get_MFR_VOUT_MAX());

  Serial.print("Max rated HI-side current: ");
  Serial.println(vicor.get_MFR_IOUT_MAX());

  Serial.print("Max rated LO-side power: ");
  Serial.println(vicor.get_MFR_POUT_MAX());
  
  vicor.get_PMBUS_REVISION();
  vicor.print_mfr_id();
  vicor.print_mfr_revision();
  vicor.print_mfr_model();
  vicor.print_mfr_location();
  vicor.print_mfr_date();
  vicor.print_mfr_serial();

  
  vicor.read_CML();
  vicor.read_status_mfr();
  vicor.read_capability();
  vicor.read_status_iout();
  vicor.read_status_input();
  vicor.read_status_temperature();
  vicor.print_status_word();
  vicor.read_CML();

  Serial.print("\n");

  delay(1000);

}
