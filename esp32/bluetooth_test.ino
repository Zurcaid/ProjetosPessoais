// This example code is in the Public Domain (or CC0 licensed, at your option.)
// By Evandro Copercini - 2018
//
// This example creates a bridge between Serial and Classical Bluetooth (SPP)
// and also demonstrate that SerialBT have the same functionalities of a normal Serial
// Note: Pairing is authenticated automatically by this device

#include "BluetoothSerial.h"

String device_name = "ESP32-BT-Slave";

// Check if Bluetooth is available
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

// Check Serial Port Profile
#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Port Profile for Bluetooth is not available or not enabled. It is only available for the ESP32 chip.
#endif

BluetoothSerial SerialBT;

const char turnON ='a';
const char turnOFF ='b';

void setup() {
  Serial.begin(115200);
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  SerialBT.begin("ESP32");  //Bluetooth device name
  //SerialBT.deleteAllBondedDevices(); // Uncomment this to delete paired devices; Must be called after begin
  Serial.printf("The device with name \"%s\" is started.\nNow you can pair it with Bluetooth!\n", device_name.c_str());
}

void loop() {
  char message;
  if (SerialBT.available()) {
    message=SerialBT.read();
    Serial.write(message);
    if(message == '1'){
      digitalWrite(2, HIGH);
      Serial.println("Ligado");
      SerialBT.println("Ligado");
    }
    else if(message == '2'){
      digitalWrite(2, LOW);
      Serial.println("Desligado");
      SerialBT.println("Desligado");
    }
    else if(message == '3'){
      digitalWrite(4, HIGH);
      Serial.println("Ligado");
      SerialBT.println("Ligado");
    }
    else if(message == '4'){
      digitalWrite(4, LOW);
      Serial.println("Desligado");
      SerialBT.println("Desligado");
    }
  }
  delay(20);
}
