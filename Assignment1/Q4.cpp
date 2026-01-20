// You are given a 1D array that may contain both positive and negative integers, and find
// the sum of a contiguous subarray of numbers which has the largest sum. For example, if
// the given array is {-2, -5, 6, -2, -3, 1, 5, -6}, then the maximum subarray sum is 7.
#include <iostream>
using namespace std;

int main() {
    int n = 7;
    int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};

    int current_sum = 0, maxsum = INT_MIN;

    for(int i=0; i<n; i++)
    {
        current_sum += arr[i];

        maxsum = max(current_sum, maxsum);

        if( current_sum < 0)
        {
            current_sum = 0;
        }
    }

    cout << maxsum;
    return 0;
}
