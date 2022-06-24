/*
CHad Marshall
programming 2 dr mcdaniel
due 10/8/2019
postfix evaluation 
This program takes a postfix expression and 
evaluates it 

*/
#include<iostream>
#include<string>
#include<fstream>
#include "stackfix2Stack.cpp"
#include<math.h>
using namespace std;

string infixToPostfix(string str);
int order(char ch);
int Evaluation(string temp);
int isDigitOrOpp(char ch);
int evaluate(int opn1, char token, int opn2);
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
  int r;
  string str, temp, empty = "";
  fstream file("fixDatafil.cpp");
  
  while(getline(file, str))
  {
     if(empty != str)
       {
         cout << str << endl;
         temp = infixToPostfix(str);
         cout << temp << endl;
         r = Evaluation(temp);
         cout << r << endl << endl;
      }
  }
}
int Evaluation(string temp)
{
  stack<int> stk2;
  int size = temp.length(), opn1, opn2, result;
  for(int i = 0; i < size-1; i++)
  {
    switch (isDigitOrOpp(temp[i]))
    {
      case 0:
        opn1 = temp[i] - '0';
        stk2.push(opn1);
        break;
      case 1:
        stk2.pop(opn2);
        stk2.pop(opn1);
        result = evaluate(opn1, temp[i], opn2);
        stk2.push(result);
        break; 
    }
  }
  stk2.pop(result);
  return result;
  
}
int isDigitOrOpp(char ch)
{
  int value;
  if(ch >= '0' && ch <= '9') // checks for numbers
    value = 0;
  else 
    value = 1;
  return value;
}
int evaluate(int opn1, char token, int opn2)
  {
    int result;
    switch (token)
      {
        case '+' : result = opn1 + opn2;
          break;
        case '-' : result = opn1 - opn2;
          break;
        case '*' : result = opn1 * opn2;
          break;
        case '/' : result = opn1 / opn2;
          break;
        case '^' : result = pow(opn1, opn2);
          break; 
      }
    return result;
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
