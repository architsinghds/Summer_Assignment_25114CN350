#include <stdio.h>
int main()
{
     char S[100] = "Hello and Welcome to the world";
     int n;
     do
     {
          printf("\n\n1.Convert String to Upper Case");
          printf("\n2.Convert String to Lower Case");
          printf("\n3.Convert String to Toggle Case");
          printf("\n0.Exit");
          printf("\n\nEnter Your Choice :--> ");
          scanf("%d", &n);
          printf("\nOriginal String :--> %s", S);
          if(n == 1)
          {
               printf("\nUpper Case :--> ");
                 int i = 0;
               while(S[i] != '\0')     
               {
                    if(S[i] >= 'a' && S[i] <= 'z')
                         printf("%c", S[i] - 32);
                    else
                              printf("%c", S[i]);
                    i++;
               }
          }
          else if(n == 2)
          {
               printf("\nLower Case :--> ");
               int i = 0;
               while(S[i] != '\0')    
               {
                    if(S[i] >= 'A' && S[i] <= 'Z')
                            printf("%c", S[i] + 32);
                    else
                         printf("%c", S[i]);
                    i++;
               }
          }
          else if(n == 3)
          {
               printf("\nToggle Case :--> ");
               int i = 0;
               while(S[i] != '\0')
               {
                    if(S[i] >= 'a' && S[i] <= 'z')
                         printf("%c", S[i] - 32);
                    else if (S[i] >= 'A' && S[i] <= 'Z')
                         printf("%c", S[i] + 32);
                    else
                         printf("%c", S[i]);
                    i++;
               }
          }
          else
          {
               if(n==4)
               {
                    break;
               }
               printf("\nPlease Enter a valid option\n");
          }
     }
     while(n!=0);
     {
          printf("Thank you very much..");
     }
     return 0;
}
