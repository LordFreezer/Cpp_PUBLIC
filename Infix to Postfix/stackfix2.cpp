/*
Chad Marshall
due : 10/1/2019
stackfix2.cpp (my fourth or fifth attempt)
Programming 2 Dr. Mcdaniel
This program takes input in the form of infix 
and uses stacks to convert it to convert to postfix
*/
#include<iostream>
#include<string>
#include<fstream>
#include "stackfix2Stack.cpp"
using namespace std;

string infixToPostfix(string str);
int order(char ch);
/*template <typename T>
class stack
{
  public:
  T stk[50];
  int top = -1;
  void push(T ch)
  {
    stk[++top] = ch;
  }

  void pop(T &ch)
  {
   ch = stk[top--];
  }
  int empty()
  {
    return top == -1;
  }
};*/

int main()
{
  string str, temp;
  fstream file("fixDatafil.cpp");
  while(getline(file, str))
  {
    cout << str << endl;
    temp = infixToPostfix(str);
    cout << temp << endl;
  }
}
string infixToPostfix(string str)
{
  stack<char> stk;
  int size = str.length();
  char ch; // my temp variable
  string temp;// my variable that im passing back to the main
  for(int i = 0; i <= size; i++)
  { 
    if(str[i] != ' ') // skip over blanks
    {
      if((str[i] >= 'a' && str[i] <= 'z') || (str[i]>= 'A' && str[i] <= 'Z'))
        temp += str[i];
      else if(str[i] >= '0' && str[i] <= '9') // checks for numbers
        temp += str[i];
      else
      {   
        if(str[i] == '(')//chesks for open paren
          stk.push(str[i]);
        else
        {
          if(str[i] == ')') // checks for close paren
          {
            while(stk.stk[stk.top] != '(')// inside paren
            {
              ch = stk.stk[stk.top]; // test str[stk.top];
              stk.pop(ch);
              temp += ch;
            }
            stk.pop(ch);
          }
          else
          {
            if(stk.empty())
              stk.push(str[i]);
            else             // && order(str[i]) <= order(stk.stk[stk.top]))
            {                                   // checks oder of opperations
              while(!stk.empty() && order(str[i]) <= order(stk.stk[stk.top]))
              {
                stk.pop(ch);
                temp += ch;
              }
              stk.push(str[i]);
            } 
          }
        }
      }
    }
  }
  while(!stk.empty())
  {
    stk.pop(ch);
    temp += ch;
  }
  return temp;
}
int order(char ch)
{
  switch(ch)
  {
    case '^': return 3;
    case '*':
    case '/': return 2;
    case '+':
    case '-': return 1;
    case '(': return 0;
  }
}
