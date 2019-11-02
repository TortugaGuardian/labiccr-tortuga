#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup(void)
{

  Serial.begin(9600);
  Serial.println("TORTUGA");

  // Start up the library
  sensors.begin();
}


void loop(void){ 
  Serial.print("lECTURA TEMPERATURAS");
  sensors.requestTemperatures(); 
  Serial.println("LISTO");
  Serial.print("LA TEMPERATURA ES: ");
  Serial.println(sensors.getTempCByIndex(0));  
}
