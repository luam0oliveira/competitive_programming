#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> st, esp;
    
    int n, m, k, cont, valid;
    bool b;
    
    while (true)
    {
        cin >> n;
        
        if (n == 0) return 0;
        while (true)
        {
            st = stack<int>();
            esp = stack<int>();
            for(int i = n; i >= 1; i--)
                st.push(i);
            
            b = false;
            int comp[n];
            for(int i = 0; i < n; i++)
            {
                cin >> k;
                comp[i] = k;
                if (k == 0)
                {
                    b = true;
                    break;
                }
            }
            if (b)
                break;
            
            cont = 0;
            valid = true;
            while (true)
            {
                
                if (st.size() == 0 && esp.size() == 0)
                    break;
                
                if (esp.size() != 0 && st.size() == 0 && esp.top() != comp[cont])
                {
                    valid = false;
                    break;
                }
                else
                if (st.size() != 0 && comp[cont] == st.top())
                {
                    cont++;
                    st.pop();
                }
                else
                if (esp.size() != 0 && comp[cont] == esp.top())
                {
                    cont++;
                    esp.pop();
                }
                else
                {
                    esp.push(st.top());
                    st.pop();
                }
            }
            if (valid)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
        cout << "\n";
    }
    
    return 0;
}
