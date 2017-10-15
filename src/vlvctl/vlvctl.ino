

int _ledPin = 13;


void setup() {
  // put your setup code here, to run once:
  pinMode(_ledPin, OUTPUT);

}


void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(_ledPin, HIGH);
  delay(100);
  digitalWrite(_ledPin, LOW);
  delay(100);  
}