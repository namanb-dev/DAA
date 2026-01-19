// Implement Quick Sort for arr[n] = { 4, 2, 6, 9, 2 }
#include <iostream>
using namespace std;

int partition(int arr[], int p, int q) // p is the lower value, and q is the higher value
{
    int pivot = arr[q];
    int i = p - 1;

    for (int j=p; j < q; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[q]);
    return i + 1;
}

void quicksort(int arr[], int p, int q)
{
     if (p < q) {
        int pivot = partition(arr, p, q);
        quicksort(arr, p, pivot - 1);
        quicksort(arr, pivot + 1, q);
     }
}

int main() {
     int arr[] = {4,2,6,9,2};
    int size = 5;

    quicksort(arr, 0, size - 1);

    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    return 0;
}
