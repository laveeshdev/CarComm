#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(9, 10); 
const byte address[6] = "00001";
int ENA=3;
int in1=2;
int in2=4;

int ENB=6;
int in3=5;
int in4 =7;

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  //for(int i=255;i>=0;i--)
  {
  analogWrite(ENA,255);
  analogWrite(ENB,255);

  delay (40);
  }
  Serial.begin(9600);
  radio.begin();
radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
radio.startListening();  

}
void loop() {
  if (radio.available())              //Looking for the data.
{   
int data = "";//Saving the incoming data
radio.read(&data, sizeof(data));    //Reading the data
Serial.println(data);


if(data==0){
  for(int i=255;i>=0;i--)
  {
  analogWrite(ENA,i);
  analogWrite(ENB,i);

  delay (5);
  }
}
}
}
