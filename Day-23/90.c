#include <stdio.h>
#include <string.h>
char findFirstRepeating(char *str) 
{
    int count[256] = {0}; 
    for (int i = 0; str[i] != '\0'; i++) 
    {
        unsigned char ch = str[i];
        count[ch]++;
    }
    for (int i = 0; str[i] != '\0'; i++) 
    {
        unsigned char ch = str[i];
        if (count[ch] > 1) 
        {
            return str[i]; 
        }
    }
    return '\0'; 
}
int main() 
{
    char str[] = "Entered String";
    char result = findFirstRepeating(str);
    if (result != '\0') 
    {
        printf("The first repeating character is: %c\n", result);
    } 
    else 
    {
        printf("No repeating characters found.\n");
    }
    
    return 0;
}
