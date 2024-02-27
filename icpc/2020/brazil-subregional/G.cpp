#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false); 
	cin.tie(0);
	
    int c, v, max, anterior;

   	cin >> c;

   	anterior = 100;
   	max = 100;

   	for(int i = 1; i < c + 1; i++)
   	{
   		cin >> v;

   		if (anterior + v > max)
   			max = anterior + v;
   		
   		anterior += v;
   	}

   	cout << max;

    return 0;
}
