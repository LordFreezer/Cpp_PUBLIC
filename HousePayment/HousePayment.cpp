#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double calculate(double principal, double YearlyInterestRate, double NumYears)
{
        double payment;
        payment = (principal * (YearlyInterestRate/1200))/
                  (1-(pow((1/(1+(YearlyInterestRate/1200))),(12*NumYears))));
        return payment;
}
int main()
   {
    cout << setprecision(2) << fixed;
    int month = 1;
    double p, yir, years, payment;
    cout << "enter in the principal, yearly interest rate, and number of years"
         << endl << "format '70000 9.5 30' " << endl;
    cin >> p >> yir >> years;
    payment = calculate(p, yir, years);
    double totalPaid = payment, monthlyInterest = ((yir/1200)*p) ,
           Principal = (payment - monthlyInterest) ,
           remaining = p - Principal, totalPrincipal = Principal;
    for(int i = 0; i < 75; i++)cout << "-";
    cout << endl;
    cout
<< "| Principal     " << p << " Interest Rate " << yir
<< " Years " << years <<  "   Payment " << payment << "  |" << endl
<< "|                                                                         |"
<< endl
<< "|                                                                         |"
<< endl
<< "| Month     Pay     Total     Monthly   Principal    Total      Remaining |"
<< endl
<< "|                   Paid     Interest      Paid    Principal     Balance  |"
<< endl
<< "|                                                     Paid                |"
<< endl
<< "|                                                                         |"
<< endl;
    for(int i = 0; i < years*12; i++)
    {
        if(i == (years*12)-10)
        {
           cout << "|";
           for(int i = 0; i < 10; i++)cout << " -     ";
           cout << "   |"<< ""<< endl;
        }
    if(i < 8 || i > (years*12) - 9)
    {
        cout << "| " <<setw(3) << month << " "
             << setw(10) << payment << " "
             << setw(10) << totalPaid << " "
             << setw(10) << monthlyInterest << " "
             << setw(10) << Principal << " "
             << setw(10) << totalPrincipal << " "
             << setw(12) << remaining << " |" << endl;
    }
    month++;
    monthlyInterest = ((yir/1200)*remaining);
    Principal = (payment - monthlyInterest);
    remaining -= Principal;
    totalPaid += payment;
    totalPrincipal += Principal;
    }
     for(int i = 0; i < 75; i++)cout << "-";
  }