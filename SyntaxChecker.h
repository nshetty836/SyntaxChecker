#include "Stack.h"
#include "FileProcessor.h"

class SyntaxChecker{
  public:
    SyntaxChecker();
    SyntaxChecker(string fileName);
    ~SyntaxChecker();
    bool checkForMatch();

    Stack<char> delimStack;
    FileProcessor *fileReader;
    string fileText;
};
