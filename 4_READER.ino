class Reader {
  public:

    /// @brief reads input and saves readings in commandBuffer variable
    /// @detailed checks if character is available in UART port
    ///           then saves character in commandBuffer[commandBufferIndex] and increases commandBufferIndex
    ///           sets commandBufferIndex to 0 if encounters end line character ASCII(10)
    ///           changes endline character into NULL ASCII(0)
    static void readInput();

    /// @brief simulates how readInput works but reads character from testing variable
    /// @detailed checks if character is available in testBuffer
    ///           then saves character in commandBuffer[commandBufferIndex] and increases commandBufferIndex
    ///           sets commandBufferIndex to 0 if encounters end line character ASCII(10)
    ///           changes endline character into NULL ASCII(0)
    static void readTestInput();
    
  private:
    static const int commandLength;
    ///contains all available commands
    static const command_t commands[];
    ///used to store commands arriving from UART
    static char commandBuffer[];
    ///keeps track of position of last saved character
    static int commandBufferIndex;

    /// @brief private constructor, 
    ///        all class fields are static so constructor is no needed
    Reader(){}

    /// @brief interprets commands 
    /// @return prints "OK!" if command is correct 
    ///         prints "ERROR!" if command is incorrect
    /// @detailed loops trough list of commands and checks if 
    ///           any command if included in first indexes of input commandBuffer
    static void commandInterpreter();
    
    /// @brief reads two values separated by space from arguments array and saves them in args[2] 
    /// @detailed starts parsing from 0, ends when encounters NULL - ASCII(0)
    ///           Correct arguments format: COMMAND VAL1 VAL2
    ///           if format incorrect one of the arguments == -1
    static void readArgumentsFromCommands(const char *arguments, int args[2]);

    /// @brief prints "Got HELLO!\n
    /// @return true
    static bool helloParser(const char *arguments);

    /// @brief parser for LED command
    /// @return true if parsing was a success
    ///         false if parsing wasn't a success
    /// @detailed reads value from arguments array
    ///           if values are in correct intervals 
    ///           returns true and sets pattern to led specified by variable
    ///           else returns false
    static bool ledParser(const char *arguments);

    /// @brief parser for PATTERN command
    /// @return true if parsing was a success
    ///         false if parsing wasn't a success
    /// @detailed reads value from arguments array
    ///           if values are in correct intervals 
    ///           returns true and sets pattern to led specified by variable
    ///           else returns false
    static bool patternParser(const char *arguments);

    /// @brief parser for TEST command
    /// @return true if parsing was a success
    ///         false if parsing wasn't a success
    /// @detailed reads value from arguments array
    ///           if values are in correct intervals 
    ///           returns true and starts testing 
    ///           else returns false
    static bool testingParser(const char *arguments);
};
const command_t Reader::commands[4] = {
  {"HELLO", Reader::helloParser},
  {"LED ", Reader::ledParser},
  {"PATTERN ", Reader::patternParser},
  {"TEST ", Reader::testingParser}
};
const int Reader::commandLength=50;
char Reader::commandBuffer[commandLength];
int Reader::commandBufferIndex=0;
    

static void Reader::readInput()
{
  
  if(Serial.available()>0){
    int data = Serial.read();
    if(Reader::commandBufferIndex<Reader::commandLength-1)
      Reader::commandBuffer[Reader::commandBufferIndex] = data==10 ? 0 : data;
    else
      Reader::commandBuffer[Reader::commandLength-1] = 0;

    if(data == 10){
      
      Reader::commandBufferIndex=0;
      Reader::commandInterpreter();  
    }
    else  
      Reader::commandBufferIndex++; 
  }
  
}

static void Reader::readTestInput()
{
  
  if(Tester::buff != 0){
    int data = Tester::buff;
    Tester::buff = 0;
    
    if(commandBufferIndex<commandLength-1)
      commandBuffer[commandBufferIndex] = data==10 ? 0 : data;
    else
      commandBuffer[commandLength-1] = 0;

    if(data == 10){
      
      commandBufferIndex=0;
      commandInterpreter();  
    }
    else  
      commandBufferIndex++; 
  }
}

static void Reader::commandInterpreter()
{
  int comLen = sizeof(Reader::commands)/sizeof(command_t);
  bool correctCommand = false;
  for(int i=0; i<comLen; i++){
    if(Str::compareCommandAndString(Reader::commands[i].keyword,Reader::commandBuffer))
      correctCommand = Reader::commands[i].commandParser(Reader::commandBuffer);
  }
  if(!correctCommand)
    Serial.println("ERROR!");
  else 
    Serial.println("OK!");
}

static bool Reader::helloParser(const char *arguments) {
 Serial.print("Got HELLO!\n");
 return true;
}

static void Reader::readArgumentsFromCommands(const char *arguments, int args[2]) {
  args[0] = -1; 
  args[1] = -1; 

  int BEGIN = 0;
  int END = 0;
  int spacesFound = 0;
  
  for(int i=0; arguments[i] != 0; i++){
    
    END=i;
    if(arguments[i] == 32){
      spacesFound++;
      switch(spacesFound){
      case 1:
        BEGIN = i+1;
      break;
      case 2:
        if(Str::isANumber(arguments,BEGIN,END))
          args[0] = Str::charToInt(arguments,BEGIN,END);
        BEGIN = i+1;
      break;
      }
    }
  }
  if(Str::isANumber(arguments,BEGIN,END+1))
    args[1] = Str::charToInt(arguments,BEGIN,END+1);
}

static bool Reader::ledParser(const char *arguments) {
  int args[2];
  bool success = false;
   
  Reader::readArgumentsFromCommands(arguments,args);
 
  if(args[0]>=0&&args[0]<Led::ledNumber && args[1]>=0&&args[1]<2){
    success = true;
    Led::startPattern(args[0],args[1]);
  }
 
  return success;
}

static bool Reader::patternParser(const char *arguments) {
  int args[2];
  bool success = false;
   
  Reader::readArgumentsFromCommands(arguments,args);
 
  if(args[0]>=0&&args[0]<Led::ledNumber && args[1]>=0&&args[1]<sizeof(Led::patterns)/sizeof(LedPattern)){
    success = true;
    Led::startPattern(args[0],args[1]);
  }
 
  return success;
}



static bool Reader::testingParser(const char *arguments) {
  int args[2];
  bool success = false;
   
  Reader::readArgumentsFromCommands(arguments,args);

  if(args[1]>=0 && args[1]<Tester::getTestCasesSize()){
    Tester::startTest(args[1]);
    success = true;
  }
  
   return success;
}
