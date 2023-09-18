#define PIN_LED 7
unsigned int toggle;
unsigned int times;

void setup() {
  pinMode(PIN_LED,OUTPUT);
  Serial.begin(115200);
  //시작될 때 까지 잠시 대기.
  while(!Serial)
  {}
  toggle = 0;
  times = 0;
  digitalWrite(PIN_LED,toggle);
  delay(1000);
}

void loop(){     
  while (true)
  {
    toggle = changetoggle_State(toggle);
    digitalWrite(PIN_LED,toggle);
    delay(100);
    times += 1;
    
    toggle = changetoggle_State(toggle);
    digitalWrite(PIN_LED,toggle);
    delay(100);
    times += 1;

    if (times >= 10)
    {
      toggle = changetoggle_State(toggle);
      digitalWrite(PIN_LED,toggle);
      times = 0;
      delay(1000000);
      break;
    }
  }
}

int changetoggle_State(int toggle)
{
  if (toggle == 1)
    return 0;
  else
    return 1;
}
