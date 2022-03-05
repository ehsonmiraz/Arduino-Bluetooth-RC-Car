//Arduino Bluetooth Controlled Car//




char command; 
const int r1=13,r2=12,l1=11,l2=10;
void setup() 
{       
Serial.begin(9600);//Set the baud rate to your Bluetooth module.
pinMode(r1,OUTPUT);   //right motors forward
pinMode(r2,OUTPUT);   //right motors reverse
pinMode(l1,OUTPUT);   //left motors forward
pinMode(l2,OUTPUT);   //left motors reverse

}

void loop(){
  if(Serial.available() > 0){ 
    command = Serial.read(); 
    Stop(); //initialize with motors stoped
    //Change pin mode only if new command is different from previous.   
    //Serial.println(command);
    switch(command){
    case 'F':  
      forward();
      break;
    case 'B':  
       back();
      break;
    case 'L':  
      left();
      break;
    case 'R':
      right();
      break;
    }
  } 
}

void forward()
{ 
  digitalWrite(r1,HIGH); 
  digitalWrite(l1,HIGH);
  
}

void back()
{   digitalWrite(r2,HIGH);
    digitalWrite(l2,HIGH);
}

void left()
{  Serial.println(command);
   digitalWrite(r1,HIGH);  
   digitalWrite(l2,HIGH);
}

void right()
{ Serial.println(command);
  digitalWrite(l1,HIGH);
  digitalWrite(r2,HIGH);
} 

void Stop()
{
  digitalWrite(r1,LOW);
  digitalWrite(r2,LOW);
  digitalWrite(l1,LOW);
  digitalWrite(l2,LOW);
}
