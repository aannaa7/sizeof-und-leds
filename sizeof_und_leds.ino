// LED-Pins auf dem Mikrocontroller
int ledPins [4] = {3, 4, 5, 6};

// Taster-Pins für +1 und -1
int add = 9;
int subtract = 8;

// aktueller Zählwert
int value = 0;

// Größe verschiedener Datentypen in Bytes
int intgr = sizeof(int);
int chrctr = sizeof(char);
int bl = sizeof(bool);
int dbl = sizeof(double);

// letzter Tasterzustand für +1 / -1
int lastAdd = LOW;
int lastSubtract = LOW;

void setup() {
  pinMode (add, INPUT);
  pinMode (subtract, INPUT);
  for (int k = 0; k < 4; k++){
    pinMode (ledPins [k], OUTPUT);
  }
  
  Serial.begin (9600);
  
  Serial.print("integer: ");
  Serial.println(intgr);

  Serial.print("character: ");
  Serial.println(chrctr);

  Serial.print("bool: ");
  Serial.println(bl);

  Serial.print("double: ");
  Serial.println(dbl);
}

void loop() {
  // aktueller Tasterzustand
  int addState = digitalRead(add);
  int subtractState = digitalRead(subtract);

  // Flanke: nur zählen, wenn von LOW nach HIGH gewechselt wird
  if (addState == HIGH && lastAdd == LOW){
    value++;
  }
  if (subtractState == HIGH && lastSubtract == LOW){
    value--;
  }

  Serial.println (value);



 // LEDs leuchten, wenn value der Größe des jeweiligen Typs entspricht
  if (value == intgr){
    digitalWrite (ledPins[0], HIGH);
  }
  else{
    digitalWrite (ledPins[0], LOW);
  }
  
  if (value == chrctr){
    digitalWrite (ledPins[1], HIGH);
  }
  else{
    digitalWrite (ledPins[1], LOW);
  }
  
  if (value == bl){
    digitalWrite (ledPins[2], HIGH);
  }
  else{
    digitalWrite (ledPins[2], LOW);
  }

  if (value == dbl){
    digitalWrite (ledPins[3], HIGH);
  }
  else{
    digitalWrite (ledPins[3], LOW);
  }

  // aktuellen Zustand merken
  lastAdd=addState;
  lastSubtract=subtractState;
}
