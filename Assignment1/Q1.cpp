// Consider an array arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91} and use Binary Search to find
// the target 23.

#include <iostream>
#include <vector>
using namespace std;

int BinarySearch(const vector<int>& array, int low, int high, int key)
{
    // element not found
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    // If key found
    if (array[mid] == key)
        return mid;

    // If key is smaller, left half
    if (key < array[mid])
        return BinarySearch(array, low, mid - 1, key);

    // Else right half
    return BinarySearch(array, mid + 1, high, key);
}

int main()
{
    int size;
    cout << "Enter size: ";
    cin >> size;

    vector<int> array(size);
    cout << "Enter the elements of the array (sorted): ";
    for (int i = 0; i < size; i++)
        cin >> array[i];

    int key;
    cout << "Enter Key: ";
    cin >> key;

    int result = BinarySearch(array, 0, size - 1, key);

    if (result != -1)
        cout << "The key is present at index: " << result << endl;
    else
        cout << "Key is not present in the array";
}
