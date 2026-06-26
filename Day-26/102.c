#include <stdio.h>
int main() 
{
    int age;
    printf("Enter your age: ");
    scanf("%d", &age);
    if (age >= 18) 
    {
        printf("You are eligible to vote!\n");
    } 
    else 
    {
        printf("You are not eligible to vote. You must be 18 or older.\n");
    }
    return 0;
}
