#include "Stack.h"
#include "FileProcessor.h"

class SyntaxChecker{
  public:
    SyntaxChecker();
    SyntaxChecker(string fileName);
    ~SyntaxChecker();
    bool checkForMatch();
    bool checkFile();

    Stack<char> delimStack;
    FileProcessor *fileReader;
    string fileText;
};
