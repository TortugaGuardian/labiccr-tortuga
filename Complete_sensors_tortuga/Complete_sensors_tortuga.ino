#include <Wire.h>  // Only needed for Arduino 1.6.5 and earlier
#include "SSD1306.h" // alias for `#include "SSD1306Wire.h"`
#include <SPI.h>
#include <LoRa.h>
#include<Arduino.h>

//OLED pins to ESP32 GPIOs via this connecthin:
//OLED_SDA â€” GPIO4
//OLED_SCL â€” GPIO15
//OLED_RST â€” GPIO16

SSD1306 display(0x3c, 4, 15);

// WIFI_LoRa_32 ports

// GPIO5 â€” SX1278â€™s SCK
// GPIO19 â€” SX1278â€™s MISO
// GPIO27 â€” SX1278â€™s MOSI
// GPIO18 â€” SX1278â€™s CS
// GPIO14 â€” SX1278â€™s RESET
// GPIO26 â€” SX1278â€™s IRQ(Interrupt Request)

#define SS 18
#define RST 14
#define DI0 26
// #define BAND 429E6 //915E6
#define BAND 915E6

#define spreadingFactor 12  //
 #define SignalBandwidth 125E3 //62.5E3
//#define SignalBandwidth 31.25E3
#define preambleLength 8
#define codingRateDenominator 8

//  LoRa.setTxPower(17); //2-17
//  LoRa.setSpreadingFactor(12); //6-12
//  LoRa.setCodingRate4(8); //5-8
//  LoRa.setSignalBandwidth(7.8E3); 
  //7.8E3, 10.4E3, 15.6E3, 20.8E3, 31.25E3, 41.7E3, 62.5E3, 125E3, and 250E3.
  

int sensor1 = 67; //T
int sensor2 = 87; //PH
int sensor3 = 30; //TURBIDEZ
int sensor4 = 50; //uP

//const uint8_t dsPinT = D3;
int16_t turby, ds18b20, pht, oxit;
String resultSerialT;
  String deviceId = "1", temp = "24.3", ph = "6.43", uP1 = "350", uP2 = "2250", uP3 = "4000" , turbidez = "130", postData;

String JSON;

void setup() {
  Serial.begin(115200);
  while (!Serial); //If just the the basic function, must connect to a computer

// Initialising the UI will init the display too.
  display.init();
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.drawString(5,5,"LoRa Sender");
  display.display();
  
  SPI.begin(5,19,27,18);
  LoRa.setPins(SS,RST,DI0);
 // Serial.println("LoRa Sender");
  if (!LoRa.begin(BAND)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
  
 // Serial.print("LoRa Spreading Factor: ");
 // Serial.println(spreadingFactor);
  LoRa.setSpreadingFactor(spreadingFactor);
  
 // Serial.print("LoRa Signal Bandwidth: ");
 // Serial.println(SignalBandwidth);
  LoRa.setSignalBandwidth(SignalBandwidth);

  LoRa.setCodingRate4(codingRateDenominator);

  LoRa.setPreambleLength(preambleLength);
  
 // Serial.println("LoRa Initial OK!");
  display.drawString(5,20,"LoRa Initializing OK!");
  display.display();
  delay(2000);
}

void loop() {
 
// postData = "{deviceId:" + deviceId + "," + "temp:" + String(ds18b20) + "," + "PH:" + ph + "," + "TURBIDEZ:" + String(turby) + "," + "uP:" +  uP + "}"; //DINAMICO SENSORES
postData = "deviceId:" + deviceId + "," + "temp:" + temp + "," + "PH:" + ph + "," + "TURBIDEZ:" + turbidez + "," + "uP1:" +  uP1 + ","  + "uP2:" +  uP2  + ","  + "uP3:" +  uP3;
 
J();

}

void S1() {
  Serial.print("Sending packet: ");
  Serial.println(sensor1);
  LoRa.beginPacket();
  LoRa.print("T: ");
  LoRa.print(sensor1);
  LoRa.endPacket(); 
  delay(3000);  
}

void S2() {
  Serial.print("Sending packet: ");
  Serial.println(sensor2);
  LoRa.beginPacket();
  LoRa.print("PH: ");
  LoRa.print(sensor2);
  LoRa.endPacket(); 
  delay(3000);
}

void S3() {
  Serial.print("Sending packet: ");
  Serial.println(sensor3);
  LoRa.beginPacket();
  LoRa.print("TURBIDEZ: ");
  LoRa.print(sensor3);
  LoRa.endPacket(); 
  delay(3000);
}

void S4() {
  Serial.print("Sending packet: ");
  Serial.println(sensor4);
  LoRa.beginPacket();
  LoRa.print("uP: ");
  LoRa.print(sensor4);
  LoRa.endPacket(); 
  delay(3000);
}

void J() {
//  Serial.print("[{\"T\":");
//  delay(10);
//  Serial.print(sensor1);
//  delay(50);
//  Serial.print("}, ");
//  delay(50);
//
//  Serial.print("{\"PH\":");
//  delay(10);
//  Serial.print(sensor2);
//  delay(50);
//  Serial.print("}]");
//  delay(50);

  
  Serial.println(postData);
  LoRa.beginPacket();
  LoRa.print(postData);
  LoRa.endPacket(); 
  delay(3000);
}
