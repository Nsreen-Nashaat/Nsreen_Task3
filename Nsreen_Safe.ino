#define signal1_A  2
#define signal1_B  3
#define signal2_A  4
#define signal2_B  5
#define signal3_A  6
#define signal3_B  7
int G_led = 8;
long long counter1 =0;
long long counter2 =0;
long long counter3 =0;
int angle1 , angle2 , angle3 ;

void setup() 
{
  pinMode(G_led,OUTPUT);
  pinMode(signal1_A,INPUT_PULLUP);
  pinMode(signal1_B,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(signal1_A),ISR_A,CHANGE);
  attachInterrupt(digitalPinToInterrupt(signal1_B),ISR_B,CHANGE);
  pinMode(signal2_A,INPUT_PULLUP);
  pinMode(signal2_B,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(signal2_A),ISR2_A,CHANGE);
  attachInterrupt(digitalPinToInterrupt(signal2_B),ISR2_B,CHANGE);
  pinMode(signal3_A,INPUT_PULLUP);
  pinMode(signal3_B,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(signal3_A),ISR3_A,CHANGE);
  attachInterrupt(digitalPinToInterrupt(signal3_B),ISR3_B,CHANGE);
  Serial.begin(50000);
  Serial.begin(9600);
}

void loop() 
{
  angle1 = (counter1*9);
  angle2 = (counter2*9);
  angle3 = (counter3*9);
  if (angle1==37 && angle2==10 && angle3==54)
  {
    digitalWrite(G_led,HIGH);
  }
}

void ISR_A()
{
  if (digitalRead(signal1_A)!= digitalRead(signal1_B))
   counter1++;
  else
   counter1--; 
}

void ISR_B()
{
  if (digitalRead(signal1_A)<= digitalRead (signal1_B))
   counter1++;
  else
   counter1--; 
}
void ISR2_A()
{
  if (digitalRead(signal2_A)!= digitalRead(signal2_B))
   counter2++;
  else
   counter2--; 
}

void ISR2_B()
{
  if (digitalRead(signal2_A)<= digitalRead (signal2_B))
   counter2++;
  else
   counter2--; 
}
void ISR3_A()
{
  if (digitalRead(signal3_A)!= digitalRead(signal3_B))
   counter3++;
  else
   counter3--; 
}

void ISR3_B()
{
  if (digitalRead(signal3_A)<= digitalRead (signal3_B))
   counter3++;
  else
   counter3--; 
}
