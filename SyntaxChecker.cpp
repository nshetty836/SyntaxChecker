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
            if(check == '\0'){
              cout << "\nLine " << i << ": No opening bracket found for )\n" << endl;
              return false;
            }
            delimStack.pop();
            if(check == '{'){
              cout << "\nLine " << i << ": expected } and found )\n" << endl;
              return false;
            }
            else if(check == '['){
              cout << "\nLine " << i << ": expected [ and found )\n" << endl;
              return false;
            }
            break;

          case '}':
            check = delimStack.peek();
            if(check == '\0'){
              cout << "\nLine " << i << ": No opening bracket found for }\n" << endl;
              return false;
            }
            delimStack.pop();
            if(check == '('){
              cout << "\nLine " << i << ": expected ) and found }\n" << endl;
              return false;
            }
            else if(check == '['){
              cout << "\nLine " << i << ": expected [ and found }\n" << endl;
              return false;
            }
            break;

          case ']':
            check = delimStack.peek();
            if(check == '\0'){
              cout << "\nLine " << i << ": No opening bracket found for ]\n" << endl;
              return false;
            }
            delimStack.pop();
            if(check == '{'){
              cout << "\nLine " << i << ": expected } and found ]\n" << endl;
              return false;
            }
            else if(check == '('){
              cout << "\nLine " << i << ": expected ) and found ]\n" << endl;
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
        cout << "\nReached end of file: missing )\n" << endl;
        break;
      case '{':
        cout << "\nReached end of file: missing }\n" << endl;
        break;
      case '[':
        cout << "\nReached end of file: missing ]\n" << endl;
        break;
    }
    return false;
  }
  else
    return true;
}

bool SyntaxChecker::checkFile(){
  return fileReader->checkFile();
}
