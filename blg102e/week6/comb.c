#include <stdio.h>

int main()
{
  int n, r;

  scanf("%d %d", &n, &r);
  int up = 1;
  int down = 1;

  if(n - r < r)
    r = n - r;

  while(r > 0)
  {
    up *= n;
    down *= r;
    n--;
    r--;
  }
  printf("%d", up / down);
}
