#include <stdio.h>
int main() 
{
    char input[100], output[100];
    int i, j = 0;
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    for(i = 0; input[i] != '\0'; ++i) 
    {
        if(input[i] != ' ') 
        {
            output[j++] = input[i];
        }
    }
    output[j] = '\0'; 
    printf("String after removing spaces: %s\n", output);

    return 0;
}
