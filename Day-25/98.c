#include <stdio.h>
#include <string.h>
#define MAX_CHAR 256
void findCommonCharacters(const char *str1, const char *str2) 
{
    int freq1[MAX_CHAR] = {0};
    int freq2[MAX_CHAR] = {0};
    int found = 0;
    for (int i = 0; str1[i] != '\0'; i++) 
    {
        freq1[(unsigned char)str1[i]]++;
    }
    for (int i = 0; str2[i] != '\0'; i++) 
    {
        freq2[(unsigned char)str2[i]]++;
    }
    printf("Common characters: ");
    for (int i = 0; i < MAX_CHAR; i++) 
    {
        if (freq1[i] > 0 && freq2[i] > 0) 
        {
            int min_freq = (freq1[i] < freq2[i]) ? freq1[i] : freq2[i];
            for (int j = 0; j < min_freq; j++) 
            {
                printf("%c ", i);
            }
            found = 1;
        }
    }
    if (!found) 
    {
        printf("None");
    }
    printf("\n");
}
int main() {
    char str1[] = "entered string";
    char str2[] = "another entered string";
    printf("String 1: %s\n", str1);
    printf("String 2: %s\n", str2);
    findCommonCharacters(str1, str2);
    return 0;
}
