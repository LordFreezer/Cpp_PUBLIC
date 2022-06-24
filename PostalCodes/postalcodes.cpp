#include <iostream>
using namespace std;
int main()
{
    string st;
    int status;
    for(int i = 0; i < 6; i++)
    {
        getline(cin, st);
	cout << st << endl;
	status = 1;
	int pos = 2, count;
	for(int k = 0; k < 12; k++)
	{
	    count = 0;
	    for(int j = 0; j < 5; j++)
	    {
	        if(st[pos + j] == '1'){count += 1;}
	    }
	    if(count != 2){status = 0;}
	    pos += 6;
	}
	cout << ((status == 1)?"Valid":"Invalid") << endl;
    }
}
