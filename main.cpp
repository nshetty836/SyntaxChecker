#include "SyntaxChecker.h"

using namespace std;

int main(int argc, char **argv)
{
  //checking if there at least 2 arguments in command line to get file name
  if(argc >= 2)
  {
    string fileName = argv[1];
    SyntaxChecker *s1;
    int choice;
    //while loop while the user wants to check more files
    while(true){
      s1 = new SyntaxChecker(fileName);
      //checking whether the file can be opened
      if(s1->checkFile() == true){
        bool check = s1->checkForMatch();
        //if all delimiters match, ask user if they want to check another or exit
        if(check == true){
          cout << "\nDelimiter syntax in file '" << fileName << "' is correct." << endl;
          cout <<  "\n1) Check another file\n2) Exit\nEnter 1 or 2: " << endl;
          cin >> choice;
          if(choice == 1){
            cout << "Enter the file name: " << endl;
            cin >> fileName;
            continue;
          }
          else{
            cout << "Thank you, good bye.\n" << endl;
            break;
          }
        }
        else
          break;
      }
      else{
        cout << "\nError: file could not be opened. \nPlease enter file name: " << endl;
        cin >> fileName;
      }
    }
  }
  //if there is no command line argument
  else
    cout << "\nError: Please give a source code file name in the command line.\n" << endl;





}
