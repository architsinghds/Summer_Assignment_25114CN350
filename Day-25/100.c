#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int compare_lengths(const void *a, const void *b) 
{
    const char *str_a = *(const char **)a;
    const char *str_b = *(const char **)b;
    size_t len_a = strlen(str_a);
    size_t len_b = strlen(str_b);
    if (len_a < len_b) return -1;
    if (len_a > len_b) return 1;
    return strcmp(str_a, str_b);
}
int main() 
{
    const char *words[] = 
    {
        "elephant", 
        "cat", 
        "hippopotamus", 
        "dog", 
        "giraffe", 
        "ant"
    };
    int num_words = sizeof(words) / sizeof(words[0]);
    printf("Words before sorting:\n");
    for (int i = 0; i < num_words; i++) 
    {
        printf("%s\n", words[i]);
    }
    qsort(words, num_words, sizeof(char *), compare_lengths);
    printf("\nWords after sorting by length:\n");
    for (int i = 0; i < num_words; i++) 
    {
        printf("%s\n", words[i]);
    }
    return 0;
}
