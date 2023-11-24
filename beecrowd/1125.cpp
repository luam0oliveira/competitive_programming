#include <bits/stdc++.h>

using namespace std;

int main()
{
  int g, p, s;

  while (true)
  {
    if (scanf("%d %d", &g, &p) != 2)
      return 0;

    int chegada[g][p];

    for (int i = 0; i < g; i++)
    {
      for (int j = 0; j < p; j++)
      {
        int posicao;

        if (scanf("%d", &posicao) != 1)
          return 0;
        chegada[i][posicao - 1] = j;
      }
    }
    if (scanf("%d", &s) != 1)
      return 0;

    for (int i = 0; i < s; i++)
    {
      int quant;
      if (scanf("%d", &quant) != 1)
        return 0;
      int scores[p] = {0};
      for (int j = 0; j < quant; j++)
      {
        int pont;
        if (scanf("%d", &pont) != 1)
          return 0;
        for (int k = 0; k < g; k++)
        {
          scores[chegada[k][j]] += pont;
        }
      }
      int maior = *max_element(scores, scores + p);
      vector<int> maiores;
      for (int j = 0; j < p; j++)
      {
        if (scores[j] == maior)
        {
          maiores.push_back(j + 1);
        }
      }

            bool first = true;
      for (int j = 0; j < maiores.size(); j++)
      {
        if (first)
        {
          first = false;
          cout << maiores[j];
        }
        else
        {
          cout << " " << maiores[j];
        }
      }
      cout << endl;
    }
  }
  return 0;
}