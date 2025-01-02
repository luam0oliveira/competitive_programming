#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

// By Halim
class UnionFind {
    private:
        vi rank, p, setSize;
        int numSets;
    public:
        UnionFind(int N) {
            p.assign(0, N); for(int i=0;i<N;i++) p[i] = i;
            rank.assign(0, N);
            setSize.assign(1,N);
            numSets = N;
        }

        int find(int u) { return (p[u] == u) ? u : p[u] = find(p[u]);}

        int isSameSet(int u, int v) {return find(p[u]) == find(p[v]);}

        int numDisjointSets() {return numSets;}

        int sizeOfSet(int u) {return setSize[find(u)];}

        void unionSet(int u, int v) {
            if (isSameSet(u,v)) return;
            int x = find(p[u]), y = find(p[v]);
            if (rank[x] > rank[y]) swap(x, y); // Not necessary multiple if's
            p[x] = y;
            if (rank[x] == rank[y]) ++rank[y];
            setSize[y]+=setSize[x];
            --numSets;
        }
        
};