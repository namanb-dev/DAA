// Implement Merge sort for the given array int arr[] = {12, 11, 13, 5, 6, 7}. After implementing
// Merge Sort, apply the same implementation to sort another array: int arr2[] = {38, 27, 43,
// 3, 9, 82, 10}.

#include <iostream>
#include<vector>
using namespace std;

void Merge(int a[], int p, int q, int r)
{
    int n1 = p - q - 1;
    int n2 = r - q;

    int L[n1+1];
    int R[n2+1];

    // copy left subarray
    for(int i=0; i<n1; i++)
    L[i] = a[p+i];

    // copy right subarray
    for(int j=0; j<n2; j++)
    R[j] = a[q+1+j];

    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    int i=0, j=0;

    // merge back into a[p....r]
    for(int k=p; k<=r; k++)
    {
        if(L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
    }
}


void MergeSort(int a[], int p, int r)
{
    if(p<r)
    {
        int q=(p+r)/2;
        MergeSort(a, q, r);
        MergeSort(a, q+1, r);
        Merge(a, p, q, r);
        
    }
}

int main() {
    
    int size; 
    cout<<"Enter size: ";
    cin>>size;

    int array[size];
    cout<<"Enter the elements: ";
    for(int i=0; i<size; i++)
    {
        cin>>array[i];
    }

    MergeSort(array, 0, size-1);

    cout << "Sorted array:\n";
    for (int i=0; i<size; i++)
        cout << array[i] << " ";
 
    return 0;
}
