// // You are given a 1D array that may contain both positive and negative integers, and find
// // the sum of a contiguous subarray of numbers which has the largest sum. For example, if
// // the given array is {-2, -5, 6, -2, -3, 1, 5, -6}, then the maximum subarray sum is 7.
// #include <iostream>
// using namespace std;

// int main() {
//     int n = 7;
//     int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};

//     int current_sum = 0, maxsum = INT_MIN;

//     for(int i=0; i<n; i++)
//     {
//         current_sum += arr[i];

//         maxsum = max(current_sum, maxsum);

//         if( current_sum < 0)
//         {
//             current_sum = 0;
//         }
//     }

//     cout << maxsum;
//     return 0;
// }

// the above is the dynamic approach

// below is the divide and conquer approach
#include <iostream>
using namespace std;

int max_cross_sum(int A[], int p, int mid, int r)
{
    int left_sum = INT_MIN;
    int sum = 0;

    for(int i=mid; i>=p; i--)
    {
        sum = sum + A[i];
        if(sum > left_sum)
        {
            left_sum = sum;
        }
    }

    int right_sum = INT_MIN;
    sum = 0;

    for(int i=mid+1; i<=r; i++)
    {
        sum = sum + A[i];
        if(sum > right_sum)
        {
            right_sum = sum;
        }
    }

    return(left_sum + right_sum);
}

int max_sum_array(int A[], int p, int r) // here p -> first element of the array, and r -> last element of the array
{
    if(p == r)
    {
        return A[p];
    }

    int mid = (p+r)/2;

    int left_sum = max_sum_array(A, p, mid);
    int right_sum = max_sum_array(A, mid+1, r);
    int cross_sum = max_cross_sum(A, p, mid, r);
    
    return max(left_sum, max(cross_sum, right_sum));
}


int main() {
    int n = 8;
    int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};

    int maximum_sum = max_sum_array(arr, 0, n - 1);
    cout << maximum_sum <<endl;

    return 0;
}
