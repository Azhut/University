
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;



int main()
{
    int n;
    cin>>n;
    int* Group=new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> Group[i];
    }

   for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-1; j++) {
            if (Group[j] > Group[j + 1]) {
                int b = Group[j];
                Group[j] = Group[j + 1];
                Group[j + 1] = b;
            }
        }
    }


    int MinOfGroups=n/2+1;
    int MinOfVoters=0;
    for (int i = 0; i < MinOfGroups; ++i) {
        MinOfVoters+=Group[i]/2+1;
    }
    cout << MinOfVoters << endl;
    return 0;
}