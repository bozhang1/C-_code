#include <stdio.h>
int main()
{
	int sum = 0;
	for (int i = 0; i < 5;i++)
	{
		sum = sum + i;
		i++;
	}
	printf("%d", sum);
}