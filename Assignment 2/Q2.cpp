// Given the arrival and departure times of all trains reaching a railway station on the same day, write a program to
// determine the minimum number of platforms required so that no train has to wait for a platform. For each train, the
// arrival time is always different from its departure time, but the arrival time of one train may be equal to the departure
// time of another train. At any given instant, a single platform cannot be used simultaneously for the departure of one
// train and the arrival of another train; therefore, in such cases, separate platforms must be allocated. [Minimum
// Platforms | Practice Problems]
// Input:
// Train = [T1, T2, T3, T4, T5]
// AT = [09:00, 09:10, 09:20, 11:00, 11:20]
// DT = [09:40, 12:00, 09:50, 11:30, 11:40]
// Output:
// Minimum number of platforms required = 3


// first i converted the time in minutes from hours to make it simple for comparison 
// that is hourse * 60 = minutes

// so the data is as 
// AT = [540, 550, 560, 660, 680]
// DT = [580, 590, 610, 690, 700]

#include <iostream>
#include<algorithm>
using namespace std;

int minplatforms(int AT[], int DT[], int n)
{
   
    sort(AT, AT+n);
    sort(DT, DT+n);

    int i=0, j=0;
    int platform = 0;
    int max_platform = 0;

    while(i<n)
    {
        if(AT[i] <= DT[j])
        {
            platform++;
            max_platform = max(max_platform, platform);
            i++;
        }
        else
        {
            platform--;
            j++;
        }
    }

    return max_platform;
}

int main() {
    int trains = 5;
    int AT[] = {540, 550, 560, 660, 680};
    int DT[] = {580, 720, 590, 690, 700};

    int ans = minplatforms(AT, DT, trains);
    cout<<"min platform needed: "<<ans<<endl;
    return 0;
}
