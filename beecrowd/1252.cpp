#include <bits/stdc++.h>

using namespace std;

int m;

bool forma(int a, int b)
{
  int moduloA = a % m, moduloB = b % m;
  if (moduloA != moduloB)
  {
    return moduloA < moduloB;
  }
  else if (a % 2 == 0 && b % 2 == 0)
  {
    return a < b;
  }
  else if ((a % 2 == 1 || a % 2 == -1) && (b % 2 == 1 || b % 2 == -1))
  {
    return a > b;
  }
  return a % 2 == 1 || a % 2 == -1;
}

int main()
{
  int n;

  while (true)
  {
    if (scanf("%d %d", &n, &m) != 2)
      return 0;

    printf("%d %d\n", n, m);

    if (n == 0 && m == 0)
    {
      return 0;
    }

    int numeros[n];

    for (int i = 0; i < n; i++)
    {
      int num;
      if (scanf("%d", &num) != 1)
        return 0;

      numeros[i] = num;
    }

    sort(numeros, numeros + n, forma);

    for (int i = 0; i < n; i++)
    {
      printf("%d\n", numeros[i]);
    }
  }

  return 0;
}
