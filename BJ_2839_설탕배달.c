#include <stdio.h>
int main(void)
{
	int n;
	int min = 5000;
	scanf("%d", &n);
	for (int i = 0; i <= (n / 5); i++)
	{
		for (int j = 0; j <= (n - (i * 5))/3; j++)
		{
			if (n - (5 * i) - (3 * j) == 0){
				int dump = i + j;
				if (dump < min) {
					min = dump;
				}
			};
		}
	}
	if (min == 5000)
		printf("%d", -1);
	else
		printf("%d", min);
}
