// https://br.spoj.com/problems/KOOPMANS/
// Matematica

#include <bits/stdc++.h>
#define MODULO 1300031

using namespace std;

typedef long long ll;

int i,f,n;

int mod(ll a, ll b){
    return ((a % b) + b)%b;
}

ll mdc(ll a,ll b){
    while (b != 0){
        int r = mod(a, b);
        a = b;
        b = r;
    }
    return a;
}

ll mmc(ll a, ll b){
    return a*b/(mdc(abs(a),abs(b)));
}

vector<ll> genMult(vector<int> numeros){
    vector<ll> res;
    for(int num: numeros){
        int size = res.size();
        for(int k = 0;k < size;k++){
            ll v = -mmc(num,res[k]); 
            if (f/abs(v) < ceil(i/fabs(v))) continue;

            res.push_back(v);
        }
        res.push_back(num);
    }

    return res;
}

ll SPA(int i, int f, ll num){
    ll pT = ceil(i/fabs(num));
    ll uT = f/fabs(num);
    return num * (pT+uT)*(uT - pT+1)/2;
}

int main(){
    int cases;cin>>cases;

    while(cases--){ cin>>i>>f>>n;
        vector<int>numeros;
        for (int k=0;k<n;k++){
            int a;cin>>a;
            if (f/a < ceil(i*1.0/a*1.0)) continue;
            numeros.push_back(a);
        }

        vector<ll> MMCs = genMult(numeros);

        ll sum = 0;
        for(int k =0;k<MMCs.size();k++){
            sum = mod(sum + SPA(i,f,MMCs[k]), MODULO);
        }
        cout<<sum<<endl;
    }
}
