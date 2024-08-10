//#include <ir_Lego_PF_BitStreamEncoder.h>
#include <IRremote.h>
int IRpin =2;
int Relay1 = 10;
int Relay2 = 11;
int Relay3 = 12;
int Relay4 = 13; 
IRrecv irrecv (IRpin);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(Relay1, OUTPUT);
  pinMode(Relay2, OUTPUT);
  pinMode(Relay3, OUTPUT);
  pinMode(Relay4, OUTPUT);

digitalWrite(Relay1,HIGH);
digitalWrite(Relay2,HIGH);
digitalWrite(Relay3,HIGH);
digitalWrite(Relay4,HIGH);
}

void loop() {
  if (irrecv.decode(&results))
  {
    Eksekusi();
    Serial.println(results.value);
    irrecv.resume();
    
  }
}

void Eksekusi() {
  switch(results.value){
    case 16753245:
    
    digitalWrite(Relay4,!digitalRead(Relay4));
    break;
    case 1653245:
    digitalWrite(Relay2,!digitalRead(Relay4));
    break;
    case 1675345:
    digitalWrite(Relay3,!digitalRead(Relay3));
    break;
    case 167545:
    digitalWrite(Relay4,!digitalRead(Relay4));
    break;
    case 16750695:
    digitalWrite(Relay4,!digitalRead(Relay4));
    digitalWrite(Relay3,!digitalRead(Relay3));
    digitalWrite(Relay2,!digitalRead(Relay2));
    digitalWrite(Relay1,!digitalRead(Relay1));
    break;
    default:
    break;
    
  }
  delay(200);
}
