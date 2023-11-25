#include <bits/stdc++.h>

using namespace std;

int main()
{
  int steps, parts = 0, num;
  if (scanf("%d", &steps) != 1)
    return 0;

  for (int i = 0; i < steps; i++)
  {
    if (scanf("%d", &num) != 1)
      return 0;
    parts += num - 1;
  }
  printf("%d\n", parts);
  return 0;
}
