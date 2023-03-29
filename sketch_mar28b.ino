#define BLYNK_TEMPLATE_ID "TMPL7B5AtGnu"
#define BLYNK_TEMPLATE_NAME "Electrolert"
#define BLYNK_AUTH_TOKEN "pyuL6jJS23y963kyBNi8mZPkT15yPzan"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <time.h>


const int irPin = A0;
bool eventTrigger = false;
int interval = 1000;
int check = 0;

char ssid[] = "Ayy";
char pass[] = "hellcat9";

BlynkTimer timer;

void myTimerEvent(){
   
   int irValue = analogRead(irPin);
   Serial.println(irValue);

   Blynk.virtualWrite(V0, irValue);

   if (irValue > 220 && eventTrigger == false){
     if (check <= 3){
        check++;
        int i;
      for(i = 10; i >= 0; i--)
      {
        delay(1000);
      }
     }
    
    eventTrigger = true;
    Blynk.logEvent("irValue", "The fluid is below set level");
     
  }
  else if (irValue < 200){
    eventTrigger = false;
  }
}

void setup(){

  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(100L, myTimerEvent);

}

void loop(){

  Blynk.run();
  timer.run();
}
