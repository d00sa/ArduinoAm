#define PIN_LED 13
unsigned int count, toggle;

void setup() {
  pinMode(PIN_LED,OUTPUT);
  Serial.begin(115200);
  while(!Serial)
  {}
  count = toggle = 0;
  digitalWrite(PIN_LED,toggle);
}

void loop() {
  Serial.println(++count);
  toggle = changetoggle_State(toggle);
  digitalWrite(PIN_LED,toggle);
  delay(1000);
}

int changetoggle_State(int toggle)
{
  if (toggle == 1)
    return 0;
  else
    return 1;
}
