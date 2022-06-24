/*
Chad Marshall
8/01/2019
Dr.Mcdaniel
Programming 2
This program utilizes three sorting methods to sort data
*/

#include <iostream>
#include <ctime>
#include "shell.cpp"
#include "bubble.cpp"
#include "quick.cpp"
using namespace std;
void setTemp(int arr[], int temp[], int n);

int main()
{
    srand(time(NULL));
    int n = 20;
    int arr[n], tempArr[n];
    int cost;
    for(int i = 0; i < n; i++)
    {
       arr[i] = rand() % 50;
       tempArr[i] = arr[i];
    }

    cout << "Array before sorting: \n";
    printArray(arr, n);
    cout << "\n";


    bubbleSort(arr, n);
    cost = bubbleSort(arr, n);
    cout << "\nArray after bubble sorting: \n";
    printArray(arr, n);
    cout << "cost of bubble sort: " << cost << "\n";
    setTemp(arr, tempArr, n);


    shellSort(arr, n);
    cost = shellSort(arr, n);
    cout << "\nArray after shell sorting: \n";
    printArray(arr, n);
    cout << "cost of shell sort: " << cost << "\n";
    setTemp(arr, tempArr, n);


    quickSort(arr, 0, n - 1);
    cost = quickSort(arr, 0, n - 1);
    cout << "\nArray after quick sorting: \n";
    printArray(arr, n);
    cout << "cost of quick sort: " << cost << "\n";
    setTemp(arr, tempArr, n);

}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
void setTemp(int arr[], int temp[], int n)
{
    for(int i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }
}
