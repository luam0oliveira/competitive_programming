// https://br.spoj.com/problems/ENCOTEL/
// ad-rock

#include <bits/stdc++.h>

using namespace std;

int codes[8] = {'2','3','4','5','6','7','8','9'};

int letterToNumber(char letter){
    int l = letter;
    int init = 'A';
    if (l < init || l > init + 25)
        return l;
    else if (init + 3 > l)
        return codes[0];
    else if (init + 6 > l)
        return codes[1];
    else if (init + 9 > l)
        return codes[2];
    else if (init + 12 > l)
        return codes[3];
    else if (init + 15 > l)
        return codes[4];
    else if (init + 19 > l)
        return codes[5];
    else if (init + 22 > l)
        return codes[6];
    else if (init + 26 > l)
        return codes[7];
    return '-';
}



int main() {
	string start, end;
    while (cin >> start){
        end="";
        for (int i = 0;i<start.size();i++){
            end += (char) letterToNumber(start[i]);
        }
        cout << end << endl;
    }
}
