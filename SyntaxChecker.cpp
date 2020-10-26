#include "SyntaxChecker.h"
#include <iostream>

//default constructor
SyntaxChecker::SyntaxChecker(){}

//overloaded constructor
SyntaxChecker::SyntaxChecker(string fileName){
  fileReader = new FileProcessor(fileName);
}

//destructor
SyntaxChecker::~SyntaxChecker(){
  delimStack.~Stack();
}

//checks if the delimiters match and returns true or false if there are no matches or if there is a wrong match
bool SyntaxChecker::checkForMatch(){
  string lineText;
  int numLines = fileReader->getNumOfLines();
  char check;

  //iterating through each line in the file
  for(int i = 0; i < numLines + 1; i++){
    lineText = fileReader->readLine(i);
    //iterating through each character per line
    for(int j = 0; j < lineText.size(); j++){
      //if the character is an opening delimeter, add it to stack
      if(lineText[j] == '(' || lineText[j] == '[' || lineText[j] == '{'){
        delimStack.push(lineText[j]);
        continue;
      }
      else{
        //checking if the character is a closing delimeter and then matching it to top of stack
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
  //if there is an opening delimiter in the stack at the end, there is a missing closing
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

//checks if file can be opened
bool SyntaxChecker::checkFile(){
  return fileReader->checkFile();
}
