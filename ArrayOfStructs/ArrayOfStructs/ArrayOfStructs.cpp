/*Chad Marshall
Programming 1
due 2/?/2019
ArrayOfStruct.cpp
This program creates a struct of how ever many records the user wants.
The user enters in data for each field amd the program sorts the data
by each field.
*/
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<iomanip>
using namespace std;
void bsortDesc(struct Thing list[80], int s);
void bsortDesc2(struct Thing list[80], int s);
struct Thing
{
    int a;
    int b;
    int c;
};

void dump(Thing arr[], int MAX)
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        printf("%i\t%10i\t%i\t%i\n",
            i + 1, arr[i].a, arr[i].b, arr[i].c);
    }
}


int main()
{
    int j, k, max;
    cout << "enter in how many records" << endl;
    cin >> max;
    struct Thing arr[max];

    int i;

    for (i = 0; i < max; i++)
    {

        cout << "enter an integer" << endl;
        cin >> arr[i].a;

        cout << "enter a second integer" << endl;
        cin >> arr[i].b;

        cout << "enter a third integer" << endl;
        cin >> arr[i].c;
    }

    cout << "array unsorted" << endl;

    dump(arr, max);

    for (int h = 0; h < 60; h++)cout << "-"; // creates seperation line
    cout << endl;
    cout << "array sorted by field a" << endl;
    bsortDesc(arr, max);
    dump(arr, max);
    for (int f = 0; f < 60; f++)cout << "-";// creates dashed lines
    cout << endl;
    cout << "array sorted by field b" << endl;
    bsortDesc2(arr, max);
    dump(arr, max);
    return 0;
}

void bsortDesc(struct Thing list[80], int s)// sorts the a field
{
    int i, j;
    struct Thing temp;

    for (i = 0; i < s - 1; i++)
    {
        for (j = 0; j < (s - 1 - i); j++)
        {
            if (list[j].a > list[j + 1].a)
            {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}
void bsortDesc2(struct Thing list[80], int s)//sorts b field
{
    int i, j;
    struct Thing temp;

    for (i = 0; i < s - 1; i++)
    {
        for (j = 0; j < (s - 1 - i); j++)
        {
            if (list[j].b > list[j + 1].b)
            {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }

}
