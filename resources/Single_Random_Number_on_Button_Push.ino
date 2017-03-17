//This program will give a single random number on every 
//push of a button

int pushButton = 2;
int buttonState = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(pushButton, INPUT);
  pinMode(13, OUTPUT);
}

void loop()
{
  randomLoop();
}

int randomLoop()
{
  int buttonState = digitalRead(pushButton);

  if (buttonState == HIGH)
  {
    int val = random(1000);
    Serial.println(val);
    digitalWrite(13, HIGH);
    delay(300); //it's easy to debounce here this way, because I don't need to keep something showing like a number
  }
  else
  {
    return 0;
  }
}

