#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        unsigned int a,b; cin>>a>>b;
        unsigned ll power = 1;
        unsigned int count = 1;
        if (b == 1) {
            cout<<a<<endl;
            continue;
        }
        while(power < a) {
            power*=b;
        }

        while(a > 0) {
            if (power <= a) {
                count+= a/power;
                a=a%power;
            }
            power/=b;
        }

        cout<<count-1<<endl;
    }
    return 0;
}