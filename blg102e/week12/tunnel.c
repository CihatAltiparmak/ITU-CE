#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
	int a , b, c;
	scanf("%d %d %d", &a, &b, &c);
	int is_available = (a <= 40) + (b <= 40) + (c <= 40);
	if (is_available > 1) {
	    printf("%.2lf\n", 1.0 * a * b * c );
	}
    }
}
