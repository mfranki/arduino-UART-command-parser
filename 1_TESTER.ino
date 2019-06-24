class Tester {
  public:  
    /// char buffer that keeps character for Reader::readTestInput(); method
    static char buff;

    /// @brief starts test
    /// @detailed bsets up flags that indicate that 
    ///           test has started and which test to do
    static void Tester::startTest(int testIndex);

    /// @brief function used in main loop enables test execution
    /// @detailed checks state of test flags and sends 
    ///           characters one by one to Tester::buff with delays given in specified test
    ///           when encounters test character = -1 ends test
    ///           when encounters test character = -2 restarts test 
    static void testSoftware();  

    /// @brief returns amount of programmed tests in testCases array
    static int getTestCasesSize();
    
  private:
    static int testedCase;
    static int testedCaseStep;
    static uint32_t timer;
    ///TESTS 
    /// @brief "HELLO\n" test
    static const TestCaseStep test0[];
    /// @brief "LED 0 1\n
    ///         LED 1 1\n
    ///         LED 2 1\n
    ///         LED 3 1\n
    ///         LED 4 1\n
    ///         LED 0 0\n
    ///         LED 1 0\n
    ///         LED 2 0\n
    ///         LED 3 0\n
    ///         LED 4 0\n" test
    static const TestCaseStep test1[];

    /// @brief "PATTERN 0 1\n
    ///         PATTERN 1 2\n
    ///         PATTERN 2 3\n
    ///         PATTERN 3 4\n
    ///         PATTERN 4 5\n
    ///         PATTERN 0 0\n
    ///         PATTERN 1 0\n
    ///         PATTERN 2 0\n
    ///         PATTERN 3 0\n
    ///         PATTERN 4 0\n" test
    static const TestCaseStep test2[];

    /// @brief array of test cases
    static const TestCase testCases[];
    
    Tester(){}
};
int Tester::testedCase = -1;
int Tester::testedCaseStep = -1; 
char Tester::buff = 0;
uint32_t Tester::timer = 0; 

const TestCaseStep Tester::test0[] = {
  {'H',100},
  {'E',100},
  {'L',100},
  {'L',100},
  {'O',100},
  {10,100},
  {-1,0}  //END OF TEST
};

const TestCaseStep Tester::test1[] = {
  {'L',10},
  {'E',10},
  {'D',10},
  {' ',10},
  {'0',10},
  {' ',10},
  {'1',10},
  {10,200},
  {'L',10},
  {'E',10},
  {'D',10},
  {' ',10},
  {'1',10},
  {' ',10},
  {'1',10},
  {10,200},
  {'L',10},
  {'E',10},
  {'D',10},
  {' ',10},
  {'2',10},
  {' ',10},
  {'1',10},
  {10,200},
  {'L',10},
  {'E',10},
  {'D',10},
  {' ',10},
  {'3',10},
  {' ',10},
  {'1',10},
  {10,200},
  {'L',10},
  {'E',10},
  {'D',10},
  {' ',10},
  {'4',10},
  {' ',10},
  {'1',10},
  {10,200},
  {'L',10},
  {'E',10},
  {'D',10},
  {' ',10},
  {'0',10},
  {' ',10},
  {'0',10},
  {10,200},
  {'L',10},
  {'E',10},
  {'D',10},
  {' ',10},
  {'1',10},
  {' ',10},
  {'0',10},
  {10,200},
  {'L',10},
  {'E',10},
  {'D',10},
  {' ',10},
  {'2',10},
  {' ',10},
  {'0',10},
  {10,200},
  {'L',10},
  {'E',10},
  {'D',10},
  {' ',10},
  {'3',10},
  {' ',10},
  {'0',10},
  {10,200},
  {'L',10},
  {'E',10},
  {'D',10},
  {' ',10},
  {'4',10},
  {' ',10},
  {'0',10},
  {10,200},
  {-2,0}  //END OF TEST
};

const TestCaseStep Tester::test2[] = {
  {'P',10},
  {'A',10},
  {'T',10},
  {'T',10},
  {'E',10},
  {'R',10},
  {'N',10},
  {' ',10},
  {'0',10},
  {' ',10},
  {'1',10},
  {10,500},
  {'P',10},
  {'A',10},
  {'T',10},
  {'T',10},
  {'E',10},
  {'R',10},
  {'N',10},
  {' ',10},
  {'1',10},
  {' ',10},
  {'2',10},
  {10,500},
  {'P',10},
  {'A',10},
  {'T',10},
  {'T',10},
  {'E',10},
  {'R',10},
  {'N',10},
  {' ',10},
  {'2',10},
  {' ',10},
  {'3',10},
  {10,500},
  {'P',10},
  {'A',10},
  {'T',10},
  {'T',10},
  {'E',10},
  {'R',10},
  {'N',10},
  {' ',10},
  {'3',10},
  {' ',10},
  {'4',10},
  {10,500},
  {'P',10},
  {'A',10},
  {'T',10},
  {'T',10},
  {'E',10},
  {'R',10},
  {'N',10},
  {' ',10},
  {'4',10},
  {' ',10},
  {'5',10},
  {10,5000},
  {'P',10},
  {'A',10},
  {'T',10},
  {'T',10},
  {'E',10},
  {'R',10},
  {'N',10},
  {' ',10},
  {'0',10},
  {' ',10},
  {'0',10},
  {10,500},
  {'P',10},
  {'A',10},
  {'T',10},
  {'T',10},
  {'E',10},
  {'R',10},
  {'N',10},
  {' ',10},
  {'1',10},
  {' ',10},
  {'0',10},
  {10,500},
  {'P',10},
  {'A',10},
  {'T',10},
  {'T',10},
  {'E',10},
  {'R',10},
  {'N',10},
  {' ',10},
  {'2',10},
  {' ',10},
  {'0',10},
  {10,500},
  {'P',10},
  {'A',10},
  {'T',10},
  {'T',10},
  {'E',10},
  {'R',10},
  {'N',10},
  {' ',10},
  {'3',10},
  {' ',10},
  {'0',10},
  {10,500},
  {'P',10},
  {'A',10},
  {'T',10},
  {'T',10},
  {'E',10},
  {'R',10},
  {'N',10},
  {' ',10},
  {'4',10},
  {' ',10},
  {'0',10},
  {10,500},
  {-2,0}  //END OF TEST
};

const TestCase Tester::testCases[] = {Tester::test0,
                                      Tester::test1,
                                      Tester::test2};

static int Tester::getTestCasesSize()
{
  return sizeof(Tester::testCases)/sizeof(TestCase);
}

static void Tester::startTest(int testIndex)
{
  Tester::testedCase = testIndex;
  Tester::testedCaseStep = -1;
  Tester::timer = 0;
  Serial.print("STARTED TEST: "); Serial.println(testIndex);
}

static void Tester::testSoftware()
{
  if(Tester::testedCase<0 || Tester::testedCase>=sizeof(Tester::testCases)/sizeof(TestCase))
    return;

  if(millis()-Tester::timer > testCases[Tester::testedCase][Tester::testedCaseStep].duration){
    Tester::timer = millis();
    Tester::testedCaseStep++;

    int character = testCases[Tester::testedCase][Tester::testedCaseStep].character;
    if(character == -2){
      Tester::testedCaseStep = -1;
    }else if(character == -1){
      Tester::testedCase = -1;
      Tester::buff = 0;
    } else 
      Tester::buff = (char)character;
  }
}
