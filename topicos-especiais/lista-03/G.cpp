#include <iostream>
#include <vector>
#include <set>

using namespace std;

void Print_Vector(vector<int> Vec) 
{ 
    for (int i = 0; i < Vec.size(); i++) { 
        cout << Vec[i] << " "; 
    } 
    cout << endl; 
    return; 
} 

int main()
{
    int n, t, nums[12];
    set<vector<int>> ans;
    while(true)
    {
        
        ans.clear();
        cin >> n >> t;
        if (t == 0)
            break;
            
        for (int i = 0; i < t; i++)
        {
            cin >> nums[i];
        }
        
        int bmask = 1 << t;
        
        for (int i = 0; i < bmask; i++)
        {
            int sum = 0;
            vector<int> sum_nb;
            for (int j = 0; j < t; j++)
            {
                if (i & (1 << j))
                {
                    sum_nb.push_back(nums[j]);
                    sum += nums[j];
                }
            }
            
            if (sum == n)
            {
            	ans.insert(sum_nb);
            }
                
        }
        
        cout << "Sums of "<<n<<":"<<endl;
        if (ans.size())
        {
            for (auto it = ans.rbegin(); it != ans.rend(); it++)
            {
                auto vetor = *it;
                for (int i = 0; i < vetor.size()-1; i ++)
                {
                    cout <<vetor[i]<<"+";
                }
                cout<<vetor[vetor.size()-1]<<endl;
            }
        }
        else
        {
            cout << "NONE" << endl;
        }
    }

    return 0;
}
