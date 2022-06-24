#include <iostream>
using namespace std;

int quickSort(int arr[], int l, int h);
int partitionQuick(int arr[], int l, int h);
void printArray(int arr[], int n);

#if __INCLUDE_LEVEL__ < 1
int main()
{
    int arr[] = {12, 34, 54, 2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Array before sorting: \n";
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

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

int quickSort(int arr[], int l, int h)
{
    int cost, i, x = 0;
    int stack[h - l + 1];
    int top = -1;
    stack[++top] = l;
    stack[++top] = h;
    while (top >= 0)
    {
        h = stack[top--];
        l = stack[top--];
        x = arr[h];
        i = (l - 1);
        for (int j = l; j <= h - 1; j++)
        {
            if (arr[j] <= x)
            {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[h]);
        int p = i+1;
        if (cost++, p - 1 > l)
        {
            stack[++top] = l;
            stack[++top] = p - 1;
        }
        if (cost++, p + 1 < h)
        {
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }
    return cost;
}
