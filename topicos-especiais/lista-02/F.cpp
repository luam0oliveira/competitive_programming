#include <iostream>
#include <bitset>
#include <map>

const int SPACES = 1000000;

using namespace std;

int main()
{
    
    while (true)
    {
        int n,m,start,end,rep;
        bool valid = true;
        bitset<1000010> cro;
        valid = true;
        cin >> n >> m;
        if (n == m and n == 0)
            return 0;
        
        for (int i = 0; i < n; i++)
        {
            cin >> start >> end;
            

            for (int j = start; j < end && j <= SPACES; j++)
            {
                if (cro.test(j))
                {
                    valid = false;
                    break;
                }
                cro.set(j);
            }
        }
        

        for (int i = 0; i < m; i++)
        {
            cin >> start >> end >> rep;
            while (start < SPACES)
            {   
                for (int j = start; j < end && j <= SPACES; j++)
                {
                    if (cro.test(j))
                    {
                        valid = false;
                        break;   
                    }
                    cro.set(j);
                }
        
                start += rep;
                end += rep;
            }
        }

        if (valid)
            cout << "NO CONFLICT" << endl;
        else
            cout << "CONFLICT" << endl;
    }

    return 0;
}
