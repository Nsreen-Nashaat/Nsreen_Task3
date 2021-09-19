#include <Timer.h>;
Timer myTimer ;
int R_led = 4; // choose the pin for the LED
int G_led = 5;
int W_led = 6;
int inPin = 2;   // choose the input pin (for a pushbutton)
int ButtonState = 0;  

void setup() 
{
  Serial.begin(500000);
  
  pinMode(R_led, OUTPUT);  // declare LED as output
  pinMode(G_led, OUTPUT);
  pinMode(W_led, OUTPUT);
  pinMode(inPin, INPUT);
  
}

void loop() 
{
  ButtonState = digitalRead(inPin);  // read input value
  if (ButtonState == LOW) 
  {         // check if the input is LOW (button pressed)
    myTimer.after( 1000 ,fn1); //turn on for 15 min
    myTimer.every( 120000 ,fn2 ,5000); 
    myTimer.after( 300000 ,fn3 );
    myTimer.after( 480000 ,fn3 );
  }
}
void fn1()
{
   digitalWrite(R_led, HIGH); // turn LED ON
   delay (900000);
}

void fn2()
{
  digitalWrite(G_led, HIGH);
}

void fn3()
{
  digitalWrite(W_led, HIGH);
}
