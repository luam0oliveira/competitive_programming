#include <bits/stdc++.h>
using namespace std;

int gl = 0, pl = 0, gr = 0, pr = 0;
bool left_serve = true;


void show_score()
{
	if (gl == 2)
	{
		printf("%d (winner) - %d\n", gl, gr);
	}
	else if (gr == 2)
	{
		printf("%d - %d (winner)\n", gl, gr);
	}
	else if (left_serve)
		printf("%d (%d*) - %d (%d)\n", gl,pl,gr,pr);
	else
		printf("%d (%d) - %d (%d*)\n", gl,pl,gr,pr);
}

void verify_pont()
{
	if ((pl - pr >= 2 && pl >=5) || pl >= 10)
	{
		pl = 0;
		pr = 0;
		gl += 1;
		left_serve = true;
	}
	else if ((pr - pl >= 2 && pr >=5) || pr >= 10)
	{
		pl = 0;
		pr = 0;
		gr += 1;
		left_serve = false;
	}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string comandos;

    cin >> comandos;

    for(int i = 0; i < comandos.size(); i++)
    {	
    	if (comandos[i] == 'Q')
    	{
    		show_score();
    	}
    	else
    	{
    		if (left_serve)
    		{
    			if (comandos[i] == 'S')
    				pl += 1;
    			else
    			{
    				pr += 1;
    				left_serve = !left_serve;
    			}
    		}
    		else
    		{
    			if (comandos[i] == 'S')
    				pr += 1;
    			else
    			{
    				pl += 1;
    				left_serve = !left_serve;
    			}
    		}

    	}
    	verify_pont();
    }

    return 0;
}