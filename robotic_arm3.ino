#include <Servo.h>

#define buzzer 2
#define buton_1 13
#define buton_2 12

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

int adim=1;

void setup() {

  motor1.attach(11);
  motor2.attach(10);
  motor3.attach(9);
  motor4.attach(6);
  motor5.attach(5);
  
  pinMode(buzzer,OUTPUT);
  pinMode(buton_1,INPUT_PULLUP);
  pinMode(buton_2,INPUT_PULLUP);

  Serial.begin(9600);
  
  motor5.write(150);
  delay(300);
  
  Acilis_sesi();
  Baslangic_konumlari();

  while(digitalRead(buton_1)==HIGH);
  while(digitalRead(buton_1)==LOW);
  buzzer_bip();
  
}

void loop() {
  
    goto_fromStart_toPosition1();
    buzzer_bip();
    delay(1000);
    
    while(1){
      goto_fromPosition1_toPosition2();
      buzzer_bip();
      delay(1000);

      goto_fromPosition2_toPosition1();
      buzzer_bip();
      delay(1000);
    }
    
    
}

void goto_fromStart_toPosition1(){
  
  motor5.write(150);

  while(1){
    //motor1.write(43);
    //motor2.write(16);
    //motor3.write(13);
    //motor4.write(96);

    if(motor1.read()!=43){
      motor1.write(motor1.read()-adim);
    }
    if(motor2.read()!=16){
      motor2.write(motor2.read()-adim);
    }
    if(motor3.read()!=13){
      motor3.write(motor3.read()-adim);
    }
    if(motor4.read()!=96){
      motor4.write(motor4.read()+(2*adim));
    }
    if(motor1.read()==43 && motor2.read()==16 && motor3.read()==13 && motor4.read()==96){
      break;
    }

    delay(40);
  }

  delay(400);
  motor2.write(6);
  delay(400);
  motor5.write(180);

  // son konumlar -> motor1=43, motor2=6, motor3=13, motor4=96, motor5=180
  
}

void goto_fromPosition1_toPosition2(){

  motor2.write(35);
  delay(30);

  while(1){
    //motor1.write(88);
    //motor2.write(35);
    //motor3.write(28);
    //motor4.write(80);

    if(motor1.read()!=88){
      motor1.write(motor1.read()+adim);
    }
    if(motor2.read()!=35){
      motor2.write(motor2.read()+adim);
    }
    if(motor3.read()!=28){
      motor3.write(motor3.read()+adim);
    }
    if(motor4.read()!=80){
      motor4.write(motor4.read()-(2*adim));
    }
    if(motor1.read()==88 && motor2.read()==35 && motor3.read()==28 && motor4.read()==80){
      break;
    }

    delay(20);
  }
  
  
  motor5.write(150);
  delay(50);
  
  // son konumlar -> motor1=88, motor2=35, motor3=28, motor4=80, motor5=150
}

void goto_fromPosition2_toPosition1(){

  while(1){
    //motor1.write(43);
    //motor2.write(16);
    //motor3.write(13);
    //motor4.write(96);

    if(motor1.read()!=43){
      motor1.write(motor1.read()-(5*adim));
    }
    if(motor2.read()!=16){
      motor2.write(motor2.read()-adim);
    }
    if(motor3.read()!=13){
      motor3.write(motor3.read()-adim);
    }
    if(motor4.read()!=96){
      motor4.write(motor4.read()+(2*adim));
    }
    if(motor1.read()==43 && motor2.read()==16 && motor3.read()==13 && motor4.read()==96){
      break;
    }

    delay(40);
  }

  delay(400);
  motor2.write(6);
  delay(400);
  motor5.write(180);

  // son konumlar -> motor1=43, motor2=6, motor3=13, motor4=96, motor5=180
  
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
  //motor1.write(90);
  //motor2.write(40);
  //motor3.write(60);
  //motor4.write(0);

  motor5.write(150);
  delay(300);
  motor5.write(180);
  delay(500);
  motor5.write(150); 

  digitalWrite(buzzer,HIGH);
  delay(300);
  digitalWrite(buzzer,LOW); 
  delay(400);

  motor2.write(40);

  digitalWrite(buzzer,HIGH);
  delay(300);
  digitalWrite(buzzer,LOW); 
  delay(400);

  motor3.write(60);

  digitalWrite(buzzer,HIGH);
  delay(300);
  digitalWrite(buzzer,LOW); 
  delay(400);

  motor4.write(0);

  digitalWrite(buzzer,HIGH);
  delay(300);
  digitalWrite(buzzer,LOW); 
  delay(400);
  
  motor5.write(150);
  delay(300);
  motor5.write(180);
  delay(500);
  motor5.write(150);
  delay(300);
  motor5.write(180);
  delay(500);
  motor5.write(150);
  
  digitalWrite(buzzer,HIGH);
  delay(800);
  digitalWrite(buzzer,LOW); 
}

void buzzer_bip(){
  digitalWrite(buzzer,HIGH);
  delay(300);
  digitalWrite(buzzer,LOW);
  delay(100);
}

void motorlari_oku(){
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
