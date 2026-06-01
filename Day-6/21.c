#include <stdio.h>

int main() 
{
    int decimalNum, tempNum, binaryNum[32], index = 0;

    printf("Enter a decimal number: ");
    scanf("%d", &decimalNum);

    if (decimalNum == 0) 
    {
        printf("Binary equivalent: 0\n");
        return 0;
    }

    tempNum = decimalNum; 

    while (tempNum > 0) 
    {
        binaryNum[index] = tempNum % 2; 
        tempNum = tempNum / 2;          
        index++;                        
    }

    printf("Binary equivalent of %d: ", decimalNum);
    for (int j = index - 1; j >= 0; j--) 
    {
        printf("%d", binaryNum[j]);
    }
    printf("\n");

    return 0;
}
