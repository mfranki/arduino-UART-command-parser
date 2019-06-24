/************* TYPEDEFs / STRUCTs****************/
typedef bool (*commandParser_t)(const char *arguments);

typedef struct {
 const char *keyword;
 commandParser_t commandParser;
} command_t;

struct LedStep {
 int state;
 uint32_t cycleTime;
};
typedef LedStep* LedPattern;

struct TestCaseStep {
  char character;
  int duration;
};
typedef TestCaseStep* TestCase;
