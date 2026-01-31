// You are given N activities, each having a start time and a finish time. A single person (or machine) can perform only
// one activity at a time. Two activities are said to be compatible if the start time of one activity is greater than or equal
// to the finish time of the other activity. Write a program using greedy strategy to select the maximum number of non-
// overlapping activities that can be performed by the person.
// E.g.:
// Input:
// N = 6
// start = [1, 3, 0, 5, 8, 5]
// finish = [2, 4, 6, 7, 9, 9]
// Output:
// Maximum number of activities = 4
// Selected activities: (1, 2), (3, 4), (5, 7), (8, 9)

#include <iostream>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b)
{
    return a.second < b.second;
}

int maxmeetings(int start[], int end[], int n)
{
    vector <pair <int, int> > v;

    for(int i=0; i<n; i++)
    {
        pair<int, int> p = make_pair(start[i], end[i]);
        v.push_back(p);
    }

    sort(v.begin(), v.end(), cmp);

    int count = 1;
    int ansEnd = v[0].second;

    for(int i=1; i<n; i++)
    {
        if(v[i].first > ansEnd)
        {
            count++;
            ansEnd = v[i].second;
        }
    }
    return count;
}
int main() {
    
    int N = 6;
    int start[] = {1, 3, 0, 5, 8, 5};
    int finish[] = {2, 4, 6, 7, 9, 9};

    int ans = maxmeetings(start, finish, N);

    cout << ans <<endl;
    return 0;
}
