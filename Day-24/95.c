#include <stdio.h>
#include <string.h>
int main() 
{
    char str[200], longest[100], word[100];
    int i = 0, j = 0, maxLen = 0;
    printf("Enter a sentence: ");
    gets(str);
    while(1) 
    {
        if(str[i] != ' ' && str[i] != '\0') 
        {
            word[j++] = str[i];
        }
        else 
        {
            word[j] = '\0';
            if(j > maxLen) 
            {
                maxLen = j;
                strcpy(longest, word);
            }
            j = 0;
            if(str[i] == '\0')
                break;
        }
        i++;
    }
    printf("Longest Word = %s", longest);

    return 0;
}
