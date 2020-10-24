#include "SyntaxChecker.h"

using namespace std;

int main(int argc, char **argv)
{
  // if(argc >= 2)
  // {
  //   string fileName = argv[1];
  // }
  // else
  //   cout << "\nERROR: Please give a data file name in the command line.\n" << endl;


  SyntaxChecker *s1 = new SyntaxChecker("sampleinput.txt");
  s1->checkForMatch();



  // Stack<char> s1(2);
  //
  // s1.push('R');
  // s1.push('i');
  // s1.push('c');
  // // s1.push('e');
  //
  // // cout << s1.peek() << endl;
  // // cout << s1.pop() << endl;
  // // cout << s1.peek() << endl;
  // cout << s1.getSize() << endl;
  // s1.printStack();

}
