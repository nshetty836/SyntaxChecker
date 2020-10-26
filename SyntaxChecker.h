#include "Stack.h"
#include "FileProcessor.h"

class SyntaxChecker{
  public:
    SyntaxChecker(); // default constructor
    SyntaxChecker(string fileName); // overloaded constructor taking in file name
    ~SyntaxChecker(); // destructor
    bool checkForMatch();
    bool checkFile();

    Stack<char> delimStack;
    FileProcessor *fileReader;
    string fileText;
};
