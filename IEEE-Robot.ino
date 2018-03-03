#include <SoftwareSerial.h>

// Motor A 

int inA1 = 3;
int inA2 = 5; 

// Motor B 

int inB1 = 6 ;
int inB2 = 9 ;


const byte rxPin = 7;
const byte txPin = 8;

char x ;

int speed = 0;

SoftwareSerial bluetooth (rxPin, txPin);

uint16_t encoderl,encoderr;
void setup() {
  Serial.begin(9600);

  bluetooth.begin(9600);
 pinMode(13,OUTPUT);
 pinMode(12,OUTPUT);
  while (!Serial || !bluetooth){
    // waiting for connection 
  }

  Serial.println("IEEE Robot Ready");
  bluetooth.println("IEEE Robot Ready");
  

  pinMode(inA1 , OUTPUT);
  pinMode(inA2 , OUTPUT);
  pinMode(inB1 , OUTPUT); 
  pinMode(inB2 , OUTPUT);
  bool donel=false,doner=false;
  do{
    encoderl=analogRead(0);
    encoderr=analogRead(1);
    if(encoderr<512)
      doner=true;
if(encoderl<512)
donel=true;
    if(!donel)
        {analogWrite(inA1 , 0);
        analogWrite(inA2, 200);
        }
        else
        {
        analogWrite(inA1 , 0);
        analogWrite(inA2, 0);
        }
        if(!doner){
        analogWrite(inB1 , 0);    
        analogWrite(inB2, 200) ;
        } 
        else
        {
          analogWrite(inB1 , 0);    
        analogWrite(inB2, 0) ;
        }
  }while(!donel || !doner);
}

void loop() {
  if (bluetooth.available()>0){
      x = bluetooth.read();
       Serial.println(x);
      switch (x){
      case 'F' :  {
        Serial.write("Go Fowrord");
        analogWrite(inA1 , 0);
        analogWrite(inA2, speed);
        analogWrite(inB1 , 0);    
        analogWrite(inB2, speed) ; 
        break;   
      }
       case 'B' :  {
        Serial.write("Go Fowrord");
        analogWrite(inA1 , speed);
        analogWrite(inA2, 0);
        analogWrite(inB1 , speed);    
        analogWrite(inB2, 0) ; 
        break;   
      }
      case 'R' :  { 
        Serial.write("Go Rigth");
        analogWrite(inA1 , 0);
        analogWrite(inA2, 0);
        analogWrite(inB1 , speed);    
        analogWrite(inB2, 0) ; 
        break;   
      }
      case 'L' :  { 
        Serial.write("Go Left");
        analogWrite(inA1 , speed);
        analogWrite(inA2, 0);
        analogWrite(inB1 , 0);    
        analogWrite(inB2, 0) ; 
        break;   
      }
    
      case '0' : {
        speed = 5 ; 
        Serial.write("Speed : 5");
        break; } 
     
      case '1' : {
        Serial.write("Speed : 30");
        speed = 30 ;
        break ; 
      }
      case '2' : {
        Serial.write("Speed : 55");
        speed = 55;
        break  ;
      }
      case '3' : {
        Serial.write("Speed : 80");
        speed = 80;
        break;
      }
      case '4' : {
        Serial.write("Speed : 105");
        speed = 105;
        break; 
      }
      case '5' : {
        Serial.write("Speed : 130");
        speed = 130;
        break;
      }
      case '6' : {
        Serial.write("Speed : 155");
        speed = 155 ; 
        break; 
      }
      case '7' : {
        Serial.write("Speed : 18.");
        speed = 180;
     
        break ; 
      }
      case '8' : {
        Serial.write("Speed : 205");
        speed = 205;
        break; 
      }
      case '9' : {
        Serial.write("Speed : 230");
        speed = 230;
        break ; 
      }

      
      default : {
        Serial.write("Stop");
        analogWrite(inA1 , 0);
        analogWrite(inA2, 0);
        analogWrite(inB1 , 0);
        analogWrite(inB2, 0) ;
        
        } 
      
  }

}

encoderl=analogRead(0);
encoderr=analogRead(1);
if(encoderr<512)
digitalWrite(13,HIGH);
else 
digitalWrite(13,LOW);
if(encoderl<512)
digitalWrite(12,HIGH);
else 
digitalWrite(12,LOW);



}
