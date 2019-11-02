void setup() {
  Serial.begin(9600); //Baud rate: 9600
}
void loop() {
  int sensorValue = analogRead(A0);// read the input on analog pin 0:
  float voltage = sensorValue * (5.0 / 1024.0); // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  Serial.println(voltage); // print out the value you read:
  delay(500);
}

//SENSOR DE TURBIDEZ

//int16_t turby;
//
//void setup() {
//  Serial.begin(9600);
//  delay(1000);
//
//}
//
//void loop() {
//  int sensorValue = analogRead(A0);
//  float adc2;
//  adc2 = map(sensorValue, 10500, 15000, 300, 0);
//  adc2 = constrain(adc2, 0, 300);
//  turby = adc2;
//  Serial.println(turby);
//  delay(1000);
//}
