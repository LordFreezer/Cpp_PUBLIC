#include<iostream>

using namespace std;

template <typename T>
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
  void dump()
  {
    for(int i = 0; i <= top; i++)
    {
      cout << i << "      " << stk[i] << endl;
    }
  }
};

#if __INCLUDE_LEVEL__ < 1

int main()
{
  stack<char> stk;
  
  stk.push('3');
  stk.push('4');
  stk.push('9');
  stk.push('1');

  cout << "testing if stack is empty: " 
       << (stk.empty() == 1 ? true : false) << endl;

  cout << "index token" << endl;
  stk.dump();
  char ch;
  int i = 0;
  cout << "after popping some values:" << endli;
  while(!stk.empty())
  {
    stk.pop(ch);
    cout << ch << endl;
    cout << endl;
    stk.dump();
  }  
  cout << "testing if stack is empty: " 
       << (stk.empty() == 1 ? true : false) << endl;
}
#endif
