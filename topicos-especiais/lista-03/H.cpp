#include <iostream>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

pair<int,char> alfabeto[100];
set<string> solutions;
string enc;
int l;


bool solve(string palavra, int left, int right, bool zero)
{
    if (solutions.size() >= 100)
        return true;

    if (left == right && !zero)
    {
        solutions.insert(palavra);
        return true;
    }
    
    if (enc[left] == '0')
        solve(palavra, left + 1, right, true);
    else
    {
        for (int i = 0; i < l; i++)
        {
            if (left != right-1 && ((enc[left] - '0') * 10 + enc[left + 1] - '0') == alfabeto[i].first)
            {   
                solve(palavra + alfabeto[i].second, left + 2, right, false);
            }
    
            if ((enc[left] - '0') == alfabeto[i].first)
            {
                solve(palavra + alfabeto[i].second, left + 1, right, false);
            }
        }
    }
    
    return false;
}



int main()
{
    int ind, cont=1;
    char let;
    while (true)
    {
        cin >> l;
        if (l == 0) break;
        solutions.clear();
        for (int i = 0; i < l; i++)
        {
            cin >> let >> ind;

            alfabeto[i] = {ind,let};
        }
        sort(alfabeto, alfabeto + l, [](const pair<int,char>& lhs, const pair<int,char>& rhs)
        	{
        		return lhs.second < rhs.second;
        	});
        cin >> enc;
        solve("", 0, enc.size(), false);
        cout<<"Case #"<<cont<<endl;
        for (auto it = solutions.begin(); it != solutions.end(); it++)
        {
            cout << *it << endl;
        }
        cont++;
        cout <<endl;
    }

    return 0;
}