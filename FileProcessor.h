#include <iostream> //pre-processor directive
#include <fstream>

using namespace std;
class FileProcessor{

public:
  FileProcessor();//default constructor
  FileProcessor(string fileName);
  ~FileProcessor();//destructor
  bool checkFile();
  string readFile();
  string readLine(int num);
  int getLineNum();
  int getNumOfLines();
  
  ifstream fileIn;

  int numOfLines;
  int lineNum;
  string fileText;
  string fileName;

};
