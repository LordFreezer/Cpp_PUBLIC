/* Chad Marshall
   Programming I
   Due: January 25, 2019
   My Failure At Creating A Program
   This probably will input a month, day and a year, then
   output the day of the Week.
*/
#include <iostream>
using namespace std;
int main()
{
 int month, day, year, dotw, t, TE;
 do{
    cout<< "Enter in the month, day, and year in (6 18 2014)\n";
    cin>> month>> day>> year;
    if(day > 31 || day < 0)
    {
        cout << "The day is either too large or too small\n";
    }
    else if(month > 12 || month < 0)
    {
        cout << "The month is either too large or too small\n";
    }
 }while(day > 31 || day < 0 || month > 12 || month < 0);
 ((month == 1 || month == 10)?TE = 1:
 ((month == 2 || month == 3 || month == 11)?TE = 4:
 ((month == 4 || month == 7)?TE = 0:
 ((month == 5)?TE = 2:((month == 6)?TE = 5:
 ((month == 8)?TE = 3:
 ((month == 9 || month == 12)?TE = 6:month = 999)))))));
 t = TE + day + year + 6;
 t = t + year / 4 - year / 100 + year / 400;
 if ((year % 400 == 0) && (month <= 2)) {t -= 1;}
  else if (year % 100 == 0) {} /* not a leap year */
    else if ((year % 4 == 0) && (month <= 2)){t -= 1;}
 dotw = t%7;      
 switch(dotw)
 {
    case 0: cout << "Saturday" << endl; break;
    case 1: cout << "Sunday" << endl; break;
    case 2: cout << "Monday" << endl; break;
    case 3: cout << "Tuesday" << endl; break;
    case 4: cout << "Wednesday" << endl; break;
    case 5: cout << "Thursday" << endl; break;
    case 6: cout << "Friday" << endl; break;
    default: std::cout << "You don goofed...\n";
 }
}
