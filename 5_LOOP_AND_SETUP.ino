void setup() {
  Serial.begin(9600);

  Led::setupLeds();
}

void loop() {

  Reader::readTestInput();
  Tester::testSoftware();
  
  Reader::readInput();
  Led::executePatterns();
  
}
