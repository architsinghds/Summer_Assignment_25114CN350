#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100
#define ASCII_SIZE 256
char getMaxOccurringChar(char* str) 
{
    int count[ASCII_SIZE] = {0};
    int len = strlen(str);
    for (int i = 0; i < len; i++) 
    {
        count[(unsigned char)str[i]]++;
    }
    int max = -1; 
    char result = '\0';
    for (int i = 0; i < len; i++) 
    {
        if (max < count[(unsigned char)str[i]]) 
        {
            max = count[(unsigned char)str[i]];
            result = str[i];
        }
    }
    return result;
}
int main() {
    char str[MAX_SIZE];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    if (strlen(str) == 0) 
    {
        printf("The string is empty.\n");
        return 0;
    }
    char max_char = getMaxOccurringChar(str);
    printf("The maximum occurring character is '%c'\n", max_char);
    return 0;
}
