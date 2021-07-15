#include <stdio.h>

int factorial(int n)
{
  int res = 1;
  for(int i = 2; i <= n; i++)
    res *= i;
  return res;
}

int main()
{
  int n, r;
  scanf("%d %d", &n, &r);
  int answer = factorial(n) / (factorial(n - r) * factorial(r));
  printf("%d", answer);
} 
