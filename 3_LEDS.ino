class Led {
  public:
    int pattern;
    uint32_t timer;
    int currentStep;
    
    
    ///amount of leds can be max 11 due to hardware
    static const int ledNumber;
    
    ///contains all leds
    static Led leds[];  

    /// @brief sets up flags telling Led::executePatterns(); 
    ///        to execute given pattern for given led
    static void startPattern(int ledInd, int patternInd);
    
    /// @brief declares pins as outputs                                 
    static void setupLeds();

    /// @biref executes patterns set on leds
    /// @return void
    /// @detailed loops through all leds and checks 
    ///           if time passed from setting up a timer step is greater than cycleTime
    ///           then increments currentStep and sets up a timer
    ///           sets currentStep to 0 when encounters end of pattern sign -> state = -1
    static void executePatterns();

    ///LED Patterns
    static const LedStep ledOn[];
    static const LedStep ledOff[];
    static const LedStep blinkEvery500ms[];
    static const LedStep blinkTwiceEverySec[];
    static const LedStep blinkeEvery2Sec[];
    static const LedStep blinkOnceAndTwiceEvSec[];
    ///contains all led patterns
    static const LedPattern patterns[];   
    
  private:

    /// @brief private constructor, 
    ///        only class is allowed to create new members
    Leds(){}
}; 

const int Led::ledNumber = 5;
Led Led::leds[ledNumber];     

const LedStep Led::ledOn[] = {
  { 1, 1000 },
  { -1, 0 }      /// end of pattern sign
};
const LedStep Led::ledOff[] = {
  { 0, 1000 },
  { -1, 0 }      /// end of pattern sign
};
const LedStep Led::blinkEvery500ms[] = {
  { 1, 100 },
  { 0, 400 },
  { -1, 0 }      /// end of pattern sign
};
const LedStep Led::blinkTwiceEverySec[] = {
  { 1, 100 },
  { 0, 100 },
  { 1, 100 },
  { 0, 700 },
  { -1, 0}       /// end of pattern sign
};
const LedStep Led::blinkeEvery2Sec[] = {
  { 1, 1000 },
  { 0, 1000 },
  { -1, 0}       /// end of pattern sign
};

const LedStep Led::blinkOnceAndTwiceEvSec[] = {
  { 1, 100 },
  { 0, 900 },
  { 1, 100 },
  { 0, 100 },
  { 1, 100 },
  { 0, 700 },
  { -1, 0}       /// end of pattern sign
};
const LedPattern Led::patterns[] = {Led::ledOff,
                               Led::ledOn,
                               Led::blinkEvery500ms,
                               Led::blinkTwiceEverySec,
                               Led::blinkeEvery2Sec,
                               Led::blinkOnceAndTwiceEvSec};

static void Led::setupLeds()
{
  for(int i=2; i<2+Led::ledNumber; i++)
    pinMode(i, OUTPUT);
}

static void Led::startPattern(int ledInd, int patternInd)
{
  Led::leds[ledInd].pattern = patternInd;
  Led::leds[ledInd].currentStep = 0;
  Led::leds[ledInd].timer = millis();
  digitalWrite(ledInd+2,Led::patterns[Led::leds[ledInd].pattern][Led::leds[ledInd].currentStep].state);
}

static void Led::executePatterns()
{
  for(int i=0; i<Led::ledNumber; i++){
    if(millis()-Led::leds[i].timer > Led::patterns[Led::leds[i].pattern][Led::leds[i].currentStep].cycleTime){
      Led::leds[i].currentStep++;
      Led::leds[i].timer = millis();
      
      if(Led::patterns[Led::leds[i].pattern][Led::leds[i].currentStep].state == -1)
        Led::leds[i].currentStep = 0;
//      Serial.println(Led::leds[i].pattern);
      digitalWrite(i+2,Led::patterns[Led::leds[i].pattern][Led::leds[i].currentStep].state);
    } 
  }
}
