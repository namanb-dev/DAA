// Consider an array arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91} and use Binary Search to find
// the target 23.

#include<iostream>
using namespace std;

int BinarySearch(const vector<int>& array, int key)
{
    int mid , low, high;

    low = 0;
    high = array.size() - 1;

    while(low <= high)
    {
        mid = low + (high-low)/2;

        if (array[mid] == key)
        return mid;

        else if (key > array[mid])
        low = mid + 1;

        else 
        high = mid - 1;
    }
    return -1;
}

int main()
{
    int size ;
    cout<<"Enter size: ";
    cin>>size;

    vector<int> array(size);
    cout<<"Enter the elements of the array: ";
    for(int i=0; i<size; i++)
    {
        cin>>array[i];
    }

    int key;
    cout<<"Enter Key: ";
    cin>>key;

    int result = BinarySearch(array, key);

    if(array[result] == key)
    cout<<"the index at which the key is present is: "<<result<<endl;
    else
    cout<<"key is not present in the array";
}
