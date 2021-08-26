const int trig = 11;/* Trigger pin off ultrasonic sensor is connected to 8th pin in arduino*/
const int echo = 12;/*Echo is connected to 12th pin*/
const int led = 13;/* Led is connected to 10th pin*/
long duration;
int distance;
void setup() 
{
  pinMode(trig,OUTPUT); /* pinMode is to determine the role of the pin, Here tirgger is OUTPUT for arduino*/
  pinMode(echo,INPUT);
  pinMode(led,OUTPUT);
  pinMode(4,OUTPUT);/* These 4,5,6,7 are connected to motor driver so its OUTPUT*/
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  
  Serial.begin(9600);/* Baud rate*/
}
void loop() 
      {
        digitalWrite(trig,LOW);/* Trigger is turned off initiially*/
        delayMicroseconds(2);/* delayed for 2 microseconds*/
        digitalWrite(trig,HIGH);/* Trigger is turned on, now ultrasonic sensor will start emitting sound waves*/
        delayMicroseconds(10);
        digitalWrite(trig,LOW);/* Turned off again*/
        
        duration=pulseIn(echo,HIGH);/* Echo is turned on to capture the rebounded sound waves*/
        
        distance=duration*0.0342/2;/* Distance formula, 0.0342 is speed of sound*/
        Serial.print("Distance:");
        Serial.println(distance);
   if(distance>15 && distance<30)/* If the distance of obstacle is in between 40 and 15 cm*/ 
        {
          digitalWrite(led,HIGH);/* Led is turned on*/
          delay(100);
          digitalWrite(led,LOW);
          delay(100);
          digitalWrite(4,HIGH);/* Motor driver code for forward */
         digitalWrite(5,LOW);    /* High low high low */
         digitalWrite(6,HIGH);
         digitalWrite(7,LOW);
          
        }
        else if(distance<15)/* if obstacle is less than 15 cm */
        {
         digitalWrite(led,HIGH);
         digitalWrite(4,HIGH);/* Motor driver code for stop */ 
         digitalWrite(5,HIGH);
         digitalWrite(6,HIGH);
         digitalWrite(7,HIGH);
         delay(1000);
         digitalWrite(led,HIGH);/* Led is turned on*/
          delay(100);
          digitalWrite(led,LOW);
          delay(100);
         digitalWrite(4,LOW);/* Motor driver code for reverse */ 
         digitalWrite(5,HIGH);
         digitalWrite(6,LOW);
         digitalWrite(7,HIGH);
         delay(1000);
         digitalWrite(led,LOW);
   
         digitalWrite(4,HIGH);/* Motor driver code for left */ 
         digitalWrite(5,HIGH);
         digitalWrite(6,HIGH);
         digitalWrite(7,LOW);
         delay(1000);
         digitalWrite(4,HIGH); 
         digitalWrite(5,LOW);
         digitalWrite(6,HIGH);
         digitalWrite(7,LOW);
         
        }
       else
       {
        
          digitalWrite(led,LOW);
          
          digitalWrite(4,HIGH); 
         digitalWrite(5,LOW);
         digitalWrite(6,HIGH);
         digitalWrite(7,LOW);
       }
      }