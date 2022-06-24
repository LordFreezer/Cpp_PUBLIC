/*
Chad Marshall
Programming 1
Testpayroll.cpp
due: 3/?/2019
This program reads data based on individual's salary
 and hours worked to provide a payroll.
*/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
double GrossPay(double rate, double hours);
char INSF(char inscode);
double FEDTAX(double fedtax);
int main()
  {
   cout << setprecision(2) << fixed;
    char cname[20];
    double rate, hours, INS, gross, ss, pye, state, fedtax, net;
    char inscode; // part 1
    cout << "NAME";
         for(int i = 0; i < 19; i++) cout << " "; // creates 19 spaces
         cout << " RATE  HOURS     INS     SOC    STATE    FED    NET    Gross"
         << endl;
         for(int i = 0; i < 47; i++) cout << " "; // creates 47 spaces
         cout << " SEC     TAX     TAX         *testing*"
         << endl
         << endl;
    while (cin.get(cname,21)) // part 2
      {
        string name = cname;
        cin >> rate >> hours >> ws >> inscode >> ws; // part a
        gross = GrossPay(rate, hours);
        state = 0.03 * gross; // part e
        ss = 0.07 * gross; // part d
        INS = INSF(inscode);
        pye = gross * 52; // part f
        fedtax = FEDTAX(pye);
        net = gross - INS - ss - state - fedtax;  // part h
        cout <<name
        << setw(8) << rate
        << setw(8) <<  hours
        << setw(8) << INS
        << setw(8) << ss
        << setw(8) << state
        << setw(8) << fedtax
        << setw(8) << net
        << setw(8) << gross //test for values
        << endl;
      }
    return 0;
   }
double GrossPay(double rate, double hours) // part b
   {
      double  overtime, gross;
      if(hours > 40) overtime = (hours - 40);
      gross = rate * (hours+overtime);
      return gross;
   }
char INSF(char inscode)
   {
      double INS;
      if(inscode == 'N')INS = 0.00; // part c
      else if (inscode == 'S')INS = 9.50;
      else if (inscode == 'F')INS = 24.75;
      return INS;
   }
 double FEDTAX(double pye) // part g
   {
      double fedtaxRate, fedtax;
      if(pye >= 20000)
        {
        fedtaxRate = 0.28;
        fedtax = ((20000 - 8000)*.15+(pye - 20000)* fedtaxRate)/52;
        }
      else if(pye >= 8000 && pye < 20000)
        {
        fedtaxRate = 0.15;
        fedtax = ((pye - 8000)* fedtaxRate)/52;
        }
      else if(pye < 8000)
        {
        fedtaxRate = 0.00;
        fedtax = pye * fedtaxRate;
        }
      return fedtax;
   }


