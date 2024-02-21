#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef pair<int,int> dados;

bool ordprocessos(dados a, dados b) { return a.first > b.first;};


struct myComp {
    bool operator()(
        dados &a,
        dados &b)
    {
        return a.second > b.second;
    }
};


void solve()
{
	int n,t, c;

	while(cin >> n)
	{
		vector<dados> processos;
		while (n--)
		{
			dados temp;
			cin >> temp.first >> temp.second;
			processos.push_back(temp);
		}
		sort(processos.begin(), processos.end(), ordprocessos);
		ll tempo = 1, ans = 0;
		priority_queue<dados, vector<dados>, myComp> aexecutar;
		while(!processos.empty() || !aexecutar.empty())
		{

			while(!processos.empty())
			{
				if(processos.back().first <= tempo)
				{
					aexecutar.push(processos.back());
					processos.pop_back();

				}
				else
				{
					break;
				}
			}

			if (aexecutar.empty())
			{
				if (processos.empty())
					break;
				tempo = processos.back().first;
				while(!processos.empty())
				{
					if (processos.back().first > tempo)
						break;
					aexecutar.push(processos.back());
					processos.pop_back();
				}
			}

			dados par = aexecutar.top();

			if (tempo > par.first)
			{
				ans += tempo - par.first;
			}

			tempo += par.second;
			aexecutar.pop();
		}
		cout << ans << endl;
	}

}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve(); 
	return 0;
}
