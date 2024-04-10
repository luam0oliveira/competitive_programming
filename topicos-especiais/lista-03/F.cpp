#include <iostream>

using namespace std;

typedef struct pedra
{
    int a, b;
} Pedra;

Pedra pecas[14], pos[16];
int selecionadas[14], num_pecas, espaco, num_sel;

void swap(int position)
{
    int aux = pecas[position].a;
    pecas[position].a = pecas[position].b;
    pecas[position].b = aux;
}

void reset()
{
	for (int i = 0; i < 14; i++)
	{
		selecionadas[i] = 0;
		pecas[i] = {0,0};
		pos[i] = {0,0}; 
	}

	pos[14] = {0,0};
	pos[15] = {0,0};
}


bool possivel(int position)
{
    if (selecionadas[position])
        return false;
    
    
    if (pecas[position].a == pos[num_sel-1].b)
        return true;
        
    swap(position);
    
    return pecas[position].a == pos[num_sel-1].b;
}

bool verifica()
{
    return num_sel == espaco+1 && pos[espaco+1].a == pos[espaco].b;
}

bool solve()
{
    if (verifica())
        return true;
    else 
    if (num_sel == espaco+1)
        return false;
    
    for (int i = 0; i < num_pecas; i++)
    {
        if (possivel(i))
        {
            selecionadas[i] = 1;
            pos[num_sel] = pecas[i];
            num_sel++;
            
            if (solve())
                return true;
            
            selecionadas[i] = 0;
            num_sel--;
        }
    }
    return false;
}

int main()
{
    while (true)
    {
        cin >> espaco;
        if (!espaco) break;
        reset();
        cin >> num_pecas;
        
        int a, b;
        num_sel = 1;
        
        cin >> a >> b;
        
        pos[0] = {a,b};
        
        cin >> a >> b;
        pos[espaco+1] = {a,b};
        
        for (int i = 0; i < num_pecas; i++)
        {
            cin >> a >> b;
            pecas[i] = {a,b};
        }
        if(solve())
            cout << "YES" <<endl;
        else
            cout <<"NO"<<endl;
    }

    return 0;
}
