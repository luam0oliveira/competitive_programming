#include <bits/stdc++.h>
#define INF 1e14
#define int long long
using namespace std;

// solved but I dont understand the code, its a copy-paste

int mat_inicial[510][510], mat_hung[300][300];
signed main() {
    int n;cin>>n;
    int m = (n+1)/2;
    
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cin>>mat_inicial[i][j];
        }
    }  
    n = m;
    int ii = 1;
    for(int i=1;i<=n;i++, ii+=2) {
        int jj = 1;
        for(int j=1;j<=m;j++, jj+=2) {
            mat_hung[i][j] = mat_inicial[ii][jj-1] + mat_inicial[ii][jj+1];
        }
    }


    vector<int> u (n+1), v (m+1), p (m+1), way (m+1);
    for (int i=1; i<=n; ++i) {
        p[0] = i;
        int j0 = 0;
        vector<int> minv (m+1, INF);
        vector<bool> used (m+1, false);
        do {
            used[j0] = true;
            int i0 = p[j0],  delta = INF,  j1;
            for (int j=1; j<=m; ++j)
                if (!used[j]) {
                    int cur = mat_hung[i0][j]-u[i0]-v[j];
                    if (cur < minv[j])
                        minv[j] = cur,  way[j] = j0;
                    if (minv[j] < delta)
                        delta = minv[j],  j1 = j;
                }
            for (int j=0; j<=m; ++j)
                if (used[j])
                    u[p[j]] += delta,  v[j] -= delta;
                else
                    minv[j] -= delta;
            j0 = j1;
        } while (p[j0] != 0);
        do {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0);
    }

    cout << -v[0] << endl;
}
