#include <iostream>

using namespace std;

//10000
//1933803664

int main() {
    long long n;
    long long Sum =0;
    cin >> n;
    for (int i = 0; i <= n; ++i) {
        for (int j = i; j <= n ; ++j) {
            Sum+=j;
            Sum+=i;
        }
    }

    cout << Sum << endl;
    return 0;
}
