#include <stdio.h>
#include <math.h>

int main() 
{
    int a, b, s, n, l, u, c, temp;
    
    printf("Enter lower limit: ");
    if (scanf("%d", &l) != 1) return 1;
    
    printf("Enter upper limit: ");
    if (scanf("%d", &u) != 1) return 1;
    
    printf("The armstrong numbers are: ");
    
    for (n = l; n <= u; n++) 
    {
        if (n == 0) 
        {
            printf("0 ");
            continue;
        }
        b = 0; 
        c = 0; 
        temp = n; 
        while (temp > 0) 
        {
            c++;
            temp = temp / 10;
        }
        s = n;
        temp = n; 
        while (temp > 0) 
        {
            a = temp % 10;
            b = b + round(pow(a, c)); 
            temp = temp / 10;
        }
        if (b == s) 
        {
            printf("%d ", s);
        }
    }
    printf("\n");
    return 0;
}
