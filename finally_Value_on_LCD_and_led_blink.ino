#define trigPin1 6
#define echoPin1 7

long duration, distance, UltraSensor;
#include <LiquidCrystal.h> //Import the LCD library
//Include^
//Init
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 

//Global Var
#define contra 9 //Define the pin that controls the contrast of the screen
#define bri 10 //Define the pin the controls the brightness of the screen
//Both pins are PWM so you can analogWrite to them and have them output a variable value


void setup() {//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // put your setup code here, to run once:

pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(13,OUTPUT);
  
  lcd.begin(16, 2); //Tell the LCD that it is a 16x2 LCD
  pinMode(contra, OUTPUT); //set pin 9 to OUTPUT
  pinMode(bri, OUTPUT); //Set pin 10 to OUTPUT
  //pinMode-ing OUTPUT makes the specified pin output power
  digitalWrite(contra, LOW); /*outputs no power to the contrast pin.
                            this lets you see the words*/
  analogWrite(bri, 255); //Outputs full power to the screen brightness LED
}//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void loop() {//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // put your main code here, to run repeatedly:


  SonarSensor(trigPin1, echoPin1);
UltraSensor = distance/10;

//Serial.println(UltraSensor);


  
  lcd.print(" distance "); //Output " Hello, World!!" on the first line of the LCD
  lcd.setCursor(0, 1); /*Set the (invisible) cursor on the first place second row of the LCD.
                        Cursor values are 0-indexed, 0 would the be the first place.
                        The cursor coordinates are X,Y coordinates.*/
  lcd.print(UltraSensor);
  if(UltraSensor>=10)
  digitalWrite(13,1);
  else
  digitalWrite(13,0);

}//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void SonarSensor(int trigPin,int echoPin)
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);  //pulseIn() is built-in Arduino function used to check for how long the echoPin remains HIGH
distance = (duration/2) / 2.91;  //pulse() is first send & then receives so actually it covers double distance therefore divided by 2
delay(500);
} 

