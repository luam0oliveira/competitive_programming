/**
 *     author: demot.r
 *     created: 2024-11-16 12:48:16
 *     source: 
 *     description: a better form
**/

#include<bits/stdc++.h>
#define ll long long
using namespace std;


// SOL 1
// int main() {
//     int n;cin>>n;
//     for(ll i=1;i<=n;i++) {
//         ll ans = i*i*(i*i - 1);
//         if (i == 3) {
//             ans -= 16;
//         }else if (i == 4) {
//             ans -= 48;
//         }else if (i > 4) {
//             ans -= 8;
//             ans -= 24;
//             ans -= 16 * (i - 4);
//             ans -= 16;
//             ans -= 24 * (i - 4);
//             ans -= 8 * (i - 4) * (i - 4); 
//         }
//         cout<<ans/2<<endl;
//     }
//     return 0;
// }



// SOL 2 (https://japlslounge.com/posts/cses/two_knights/1.htm)
int main() {
    int n;cin>>n;
    cout << 0 <<endl;
    for(ll i=2;i<=n;i++) {
        // all possible positions 
        ll ans = (i*i) * (i*i - 1);
        // all correct possible positions
        ans -= 8 * (i-1) * (i-2);
        cout << ans/2<<endl;
    }
    return 0;
}