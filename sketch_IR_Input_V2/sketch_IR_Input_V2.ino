bool sensorState = 0;
bool preSensorState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(PD2, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  delay(10);
  Serial.println("Start");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (switchCheck() == 1)
  {
    Serial.println("<D>");
    digitalWrite(LED_BUILTIN, HIGH); 
    delay(200);
    digitalWrite(LED_BUILTIN, LOW); 
  }
  delay(10);
}

bool switchCheck()
{
  sensorState = digitalRead(PD2);
  if ((sensorState == 0) && (preSensorState == 1))
  {
    delay(25);
    sensorState = digitalRead(PD2);
    if (sensorState == 0)
    {
      preSensorState = sensorState;
      return 1;
    }
  }
  else if ((sensorState == 1) && (preSensorState == 0))
  {
    delay(25);
    sensorState = digitalRead(PD2);
    if (sensorState == 1)
    {
      preSensorState = sensorState;
    }
  }
  return 0;
}
