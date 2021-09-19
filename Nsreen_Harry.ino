int Sensor_1 = 3 ;
int Sensor_2 = 4;
int Sensor_3 = 5;
int State_1 , State_2 ,State_3 ;

void setup() 
{
  Serial.begin(9600);
  pinMode(Sensor_1, INPUT);
  pinMode(Sensor_2, INPUT);
  pinMode(Sensor_3, INPUT);

}

void loop() 
{
  State_1 = digitalRead (Sensor_1);
  State_2 = digitalRead (Sensor_2);
  State_3 = digitalRead (Sensor_3);

  if (State_1 == LOW && State_2 == HIGH && State_3 == LOW)
  {
    Serial.print("Move Forward");
  }
  else if (State_1 == LOW && State_2 == LOW && State_3 == LOW)
  {
    Serial.print("Move Backward");
  }
  else if (State_1 == LOW && State_2 == LOW && State_3 == HIGH)
  {
    Serial.print("Rotate 90 degree to the right");
  }
  else if (State_1 == HIGH && State_2 == LOW && State_3 == LOW)
  {
    Serial.print("Rotate 90 degree to the left");
  }
  

}
