#include <bits/stdc++.h>

using namespace std;

int binary_search(vector<int> arr, int l,  int value)
{
    int mid,left = l, right = arr.size();
    mid = (left + right) / 2;
    
    while (left <= right)
    {
        if (mid != l && arr[mid] == value)
        {
            return mid;
            
        }
        
        if (arr[mid] > value)
            right = mid-1;
        else
            left = mid +1;
        mid = (left + right)/2;
    }
    return -1;
}

int main()
{
    int num_books;
    while (cin >> num_books)
    {
        int sum, a;
        vector<int> books;
        
        for (int i=0;i < num_books;i++)
        {
            cin >> a;
            books.push_back(a);
        }
        
        
        sort(books.begin(), books.end());
        
        cin >> sum;
        
        int menor = 0, maior = 0, diff = 1000002;
        for (int i = 0; i < num_books;i++)
        {
            int pos = binary_search(books, i, sum - books[i]);
            if (pos != -1 && pos != i && books[pos] - books[i] < diff)
            {
                menor = books[i];
                maior = books[pos];
            }
        }
        
        cout<<"Peter should buy books whose prices are "<<menor<<" and "<<maior<<"."<<endl<<endl;
    }

    return 0;
}
