#include <stdio.h>
 
int main ()
{
	int num = 0, i = 0, n = 0, count = 0, bitCount = 0;
	printf ("Enter the number: ");
	scanf ("%d", &num);
	n = num;
	while (n)
	{
		count ++;
		n = n >> 1;
	}
	for (i = 0; i < count; i++)
	{
		if (((num >> i) & 1) == 0)
		{
			bitCount ++;
		}
	}
	printf ("\nNumber of bit's set to zero's are: %d\n", bitCount);
	return 0;
}
