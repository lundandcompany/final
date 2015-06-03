
#include <SoftwareSerial.h>
#include "mpr121.h"
#include <Wire.h>

SoftwareSerial quadra(18, 5);


const int m1 = 9;// push
const int m2 = 8; // full in

const int ball = 12;
const int nosesw = 11;
const int tommy = 10;
const int sw1 = 3;
const int sw2 = 4;
const int top = 13;

int x = 0;
int y = 0;
int z = 0;
int b = 0;

int t0 = 0;
int t1 = 0;
int t2 = 0;





void setup() {
    pinMode(m1, OUTPUT);
    pinMode(m2, OUTPUT);
    
    pinMode(sw1, INPUT);
    pinMode(sw2, INPUT);
    
    pinMode(ball, INPUT_PULLUP);
    pinMode(nosesw, INPUT_PULLUP);
    pinMode(tommy, INPUT_PULLUP); 
    pinMode(top, INPUT_PULLUP);
    
    digitalWrite(m1, LOW);
    digitalWrite(m2, LOW);
    
    Serial.begin(115200);
    quadra.begin(19200);
    quadra.write(byte(252));
    quadra.write(byte(59));
    
    

  Serial.begin(9600);
  Wire.begin();
}




void loop() {
  

   
   if (!digitalRead(tommy)){
   y++;
   if (y == 3) {ticc(); y = 0;}
   if (y == 2) {ticb();}
   if (y == 1) {tica();}
   }
   
if (!digitalRead(nosesw)){
   x++;
   if (x == 3) {nosec(); x = 0;}
   if (x == 2) {walking();}
   if (x == 1) {nosea();}
}


if (!digitalRead(sw1)){
   z++;
   if (z == 3) {rollmore(); z = 0;}
   if (z == 2) {roll();}
   if (z == 1) {headstand();}
}


if (digitalRead (ball) == 0 ) {if (b == 0) {b = 1; holded(); } Serial.println("forward"); }

}

  
  
  




void walking(){
  
  soundPlay(6);
  walk(9, 230);
  pause (300);
  
  soundPlay(14);
  walk(12, 230);
  pause (300);
  
}


void holded(){
  
  backset();
  fwd(290);
  tice();
  
}
void tica(){
  soundPlay(5);
  tic(7, 100);
  
}

void tice(){
  soundPlay(3);
  tic(7, 100);
  
}

void ticb(){
    soundPlay(6);
  tic(7, 150);
  
}

void ticc(){
    soundPlay(14);
  tic(4, 120);
  pause (250);
  tic(5, 120);
  backset();
  
}


void nosea(){
  pause (300);
  soundPlay(3);
   nose (60, 50, 4);
   pause (100);
    return;


}

void noseb(){

  soundPlay(4);
   nose (40, 80, 2); 
   pause (80);
   nose (50, 40, 5);
   nose (40, 80, 2);
   soundPlay(2);
   walk(5, 180); 
   soundStop();
   return;
}

void nosec(){

  soundPlay(7);
   nose (80, 50, 2);
   pause (100);
   nose (60, 40, 4); 
   pause (80);
   nose (40, 30, 5);
   
  soundPlay(1);
   walk( 5, 170);
  return;

}


void roll(){

  soundPlay(10);
  backset();
  fwd(750);
  pause (500);
  goback();
  while(digitalRead(ball)){
  }
  stoped();
  fwd(500);
  backset();
  pause (1000);
  
}


void headstand(){
  soundPlay(9);
  pause (1300);
  soundPlay(10);
  backset();
  fwd(750);
  pause (500);
  back(300);
  backpause(50);
  soundPlay(12);
  pause (3000);
 
  goback();
  while(digitalRead(ball)){
  }
  stoped();
  fwd(450);
  backset();
  pause (1000);
  
}





void rollmore(){
  roll();
  pause (100);
  roll();
  
}






void walk(int t, int s){
  int i;
  for (i = 0; i < t; i++){
  backset();
  fwd (s);
  }
  stoped();
  backset();
  
}

void tic(int t, int s){
  int i;
 // fwd(500);
  for (i = 0; i < t; i++){
  back(s- 30);
  fwd (s);
  }
  stoped();
//  backset();
  
}




void testSound(){
  int i;
for(byte i = 1; i < 19; (i++)){
    Serial.println(i);
    soundPlay(i);
    pause (2500);
    
  }
}








void nose(int n, int p, int t){
  
  int i;
  for (i = 0; i < t; i++) {
    goback();
    while(!digitalRead(sw2)){
    }
    pause (n);
    fwd(n);
    stoped();
    pause (p);
  }
  return;
  
}

void waitswa(){
  while(!digitalRead(sw2)) ;
  
}

void soundPlay(int sound){
  quadra.write(byte(sound));
  pause (300);
  return;
}


void pause (int p){
 delay (p);
}

void backset(){
  goback();
  Serial.println("here");
  while(! digitalRead(sw2)){
  }
  stoped();
  return;
  
}



void back (int b){
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    delay (b);
    digitalWrite(m1, LOW); 
}

void backpause (int b){
  int i;
  for (i = 0; i < b; i++){
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    delay (3);
    digitalWrite(m1, LOW); 
    digitalWrite(m2, HIGH);
    delay (1);
  }
  
    digitalWrite(m1, LOW);
    digitalWrite(m2, LOW);
  return;
}

void fwd (int f){
    digitalWrite(m1, LOW);
    digitalWrite(m2, HIGH);
    delay (f);
    digitalWrite(m2, LOW); 
    return;
}


void goback(){
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    return;
}

void gofwd(){
    digitalWrite(m1, LOW);
    digitalWrite(m2, HIGH);
    return;
}

void stoped (){
    digitalWrite(m1, LOW);
    digitalWrite(m2, LOW);
    return;
}

void soundStop(){
  soundPlay(246);
  
}

