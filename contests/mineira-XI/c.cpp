#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    
    vector<int> c(a);
    for (int i = 0; i < a; i++) {
        cin >> c[i];
    }
    
    map<int, vector<int>> d;
    vector<int> visited(a, 0);

    for (int i = 0; i < a; i++) {
        if (c[i] - b >= 0) {
            if (d.find(c[i] - b) == d.end()) {
                d[c[i] - b] = vector<int>();
            }
            d[c[i] - b].push_back(i + 1);
        }
        
        if (d.find(c[i] + b) == d.end()) {
            d[c[i] + b] = vector<int>();
        }
        d[c[i] + b].push_back(-(i + 1));
    }

    int count = 0;
    for (auto& entry : d) {
        sort(entry.second.begin(), entry.second.end());
        for (int j = 0; j < entry.second.size(); j++) {
            if (visited[abs(entry.second[j]) - 1]) continue;
            if (entry.second[j] > 0) {
                visited[entry.second[j] - 1] = 1;
                count++;
                break;
            } else {
                count++;
                break;
            }
        }
    }

    cout << count << endl;
    return 0;
}
