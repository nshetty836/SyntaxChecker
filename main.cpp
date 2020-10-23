#include "Stack.h"

using namespace std;

int main(int argc, char **argv)
{
  Stack<char> s1(2);

  s1.push('R');
  s1.push('i');
  s1.push('c');
  // s1.push('e');

  // cout << s1.peek() << endl;
  // cout << s1.pop() << endl;
  // cout << s1.peek() << endl;
  cout << s1.getSize() << endl;
  s1.printStack();

}
