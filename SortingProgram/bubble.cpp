#include <iostream>
using namespace std;

int bubbleSort(int arr[], int n);
void printArray(int arr[], int n);
#if __INCLUDE_LEVEL__ < 1
int main()
{
    int arr[] = {12, 34, 54, 2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Array before sorting: \n";
    printArray(arr, n);

    bubbleSort(arr, n);

    cout << "\nArray after sorting: \n";
    printArray(arr, n);

}
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
}
#endif
int bubbleSort(int arr[], int n)
{
   int cost;
   int i, j;
   int swapped;
   for(i = 0; i < n - 1; i++)
   {
     swapped = 0;
     for(j = 0; j < n-i-1; j++)
     {
       cost++;
       if(arr[j] > arr[j + 1])
       {
         swap(arr[j], arr[j + 1]);
         cost += 6;
         swapped = 1; // assigns to true
       }
     }
    if(swapped == 0) // assigns to false
      break;
  }
  return cost;
}
