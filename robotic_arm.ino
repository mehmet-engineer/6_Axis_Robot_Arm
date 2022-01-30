#include <Servo.h>

#define buzzer 2
#define buton_1 12
#define buton_2 13

Servo motor1;
Servo motor2;
Servo motor3;
Servo motor4;
Servo motor5;

int value1;
int value2;
int value3;
int value4;
int value5;
int sayac=0;

void setup() {

  motor1.attach(11);
  motor2.attach(10);
  motor3.attach(9);
  motor4.attach(6);
  motor5.attach(5);
  
  pinMode(buzzer,OUTPUT);
  pinMode(buton_1,INPUT);
  pinMode(buton_2,INPUT);

  Serial.begin(9600);
  Acilis_sesi();
  Baslangic_konumlari();
  
}

void loop() {
  
  value1 = motor1.read();
  value2 = motor2.read();
  value3 = motor3.read();
  value4 = motor4.read();
  value5 = motor5.read();
  Serial.print(value1);
  Serial.print("-");
  Serial.print(value2);
  Serial.print("-");
  Serial.print(value3);
  Serial.print("-");
  Serial.print(value4);
  Serial.print("-");
  Serial.print(value5);
  Serial.println(" ");
  delay(400);
  
}

void Acilis_sesi(){
  digitalWrite(buzzer,HIGH);
  delay(300);
  digitalWrite(buzzer,LOW);
  delay(100);
  digitalWrite(buzzer,HIGH);
  delay(200);
  digitalWrite(buzzer,LOW);
  delay(200);
}

void Baslangic_konumlari(){
  motor1.write(90);
  motor2.write(40);
  motor3.write(60);
  motor4.write(0);
  
  motor5.write(150);
  delay(300);
  motor5.write(180);
  delay(500);
  motor5.write(150); 
  
  digitalWrite(buzzer,HIGH);
  delay(500);
  digitalWrite(buzzer,LOW); 
}
