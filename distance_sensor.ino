#include <NewPing.h>
#define Trigger_Pin 12
#define Echo_Pin 13
#define Max_Distance 250
#define Buzzer_Pin 11

int distance = 0;

NewPing sonar(Trigger_Pin, Echo_Pin, Max_Distance);

void setup(){
  
  Serial.begin(9600);
  pinMode(Buzzer_Pin,OUTPUT);
  
  } 

  void loop(){
    
    delay(75);
    Serial.print("Uzaklık: ");
    Serial.print(sonar.ping_cm());
    Serial.println("cm");
    distance = sonar.ping_cm();    
    
     beep(distance);
    
    }


    void beep(int distance){
    if(distance > 60){
      digitalWrite(Buzzer_Pin,HIGH);
        delay(distance * 50);
    }
    
    else{
      if(distance <= 20){
        digitalWrite(Buzzer_Pin,HIGH);
        delay(distance * 10);
      }
      
      
    }

    
}
