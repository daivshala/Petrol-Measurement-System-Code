
#include<LiquidCrystal.h>
LiquidCrystal lcd(A5,A4,A3,A2,13,4);     //RS=A5, EN=A4, D4=A3,D5=A2,D6=13, D7=4  

int trigPin1 = A0;      //Trig
int echoPin1 = A1;      //Echo
float st = 1.56;        //size of tank
float  ft, et;             //ft = filled tank, st = size of tank  //et= empty tankt 
float addPetrol=0,temp;
long duration1, cm1;
void setup() {
 
  Serial.begin (9600);
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("Petrol Level ");
  lcd.setCursor(0,1);      //set curssor to next line
  lcd.print("Indicator...");
  delay(5000);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  lcd.clear();
}
 
void loop()
{

  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
 
  // Read the signal from the sensor
  pinMode(echoPin1, INPUT);
  duration1 = pulseIn(echoPin1, HIGH);
  if(st==0)
  {
    
  
  cm1 = (duration1/2) / 29.1;
//  inches1 = (duration1/2) / 74;
  et = 0.12 * cm1;               //find field tank
  //ft = 1.56 - et;   //find empty tank
  addPetrol=ft-et;
}  
  //to print field tank
  lcd.setCursor(0,0);
  lcd.print("Field Tank  ");
  lcd.setCursor(0,1);
  lcd.print("in litter ");
  lcd.print(addPetrol);
  delay(5000);
  lcd.clear();                    //clear the display
  
  //to print empty tank
  lcd.setCursor(0,0);        //select 1st row
  lcd.print("Empty Tank ");
  lcd.setCursor(0,1);
  //lcd.print("in litter "); // move cursor to next line
  lcd.print(et);
  delay(5000);
}
 

