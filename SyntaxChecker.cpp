#include "SyntaxChecker.h"
#include <iostream>

SyntaxChecker::SyntaxChecker(){}

SyntaxChecker::SyntaxChecker(string fileName){
  fileReader = new FileProcessor(fileName);
}

SyntaxChecker::~SyntaxChecker(){}

bool SyntaxChecker::checkForMatch(){
  string lineText;
  int numLines = fileReader->getNumOfLines();
  char check;

  for(int i = 0; i < numLines + 1; i++){
    lineText = fileReader->readLine(i);
    for(int j = 0; j < lineText.size(); j++){
      if(lineText[j] == '(' || lineText[j] == '[' || lineText[j] == '{'){
        delimStack.push(lineText[j]);
        continue;
      }
      else{
        switch(lineText[j]){
          case ')':
            check = delimStack.peek();
            delimStack.pop();
            if(check == '{'){
              cout << "Line " << i << ": expected } and found )" << endl;
              return false;
            }
            else if(check == '['){
              cout << "Line " << i << ": expected [ and found )" << endl;
              return false;
            }
            break;

          case '}':
            check = delimStack.peek();
            delimStack.pop();
            if(check == '('){
              cout << "Line " << i << ": expected ) and found }" << endl;
              return false;
            }
            else if(check == '['){
              cout << "Line " << i << ": expected [ and found }" << endl;
              return false;
            }
            break;

          case ']':
            check = delimStack.peek();
            delimStack.pop();
            if(check == '{'){
              cout << "Line " << i << ": expected } and found ]" << endl;
              return false;
            }
            else if(check == '('){
              cout << "Line " << i << ": expected ) and found ]" << endl;
              return false;
            }
            break;
        }
      }
    }
  }
  if(!delimStack.isEmpty()){
    switch(delimStack.peek()){
      case '(':
        cout << "Reached end of file: missing )" << endl;
        break;
      case '{':
        cout << "Reached end of file: missing }" << endl;
        break;
      case '[':
        cout << "Reached end of file: missing ]" << endl;
        break;
    }
    return false;
  }
  else
    return true;
}
