#include <stdio.h>
#include <stdlib.h>
int verifyPIN();
void checkBalance(float balance);
float depositMoney(float balance);
float withdrawMoney(float balance);

int main() 
{
    int pinVerified = 0;
    int choice;
    float balance = 5000.0; 
    int dynamicLoop = 1;

    printf("==========================================\n");
    printf("       WELCOME TO THE ATM SIMULATOR       \n");
    printf("==========================================\n");

    pinVerified = verifyPIN();
    if (!pinVerified) 
    {
        printf("\nToo many incorrect attempts. Your card is blocked.\n");
        printf("Please contact your bank branch. Exiting...\n");
        return 0;
    }

    while (dynamicLoop) {
        printf("\n---------- MAIN MENU ----------\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                checkBalance(balance);
                break;
            case 2:
                balance = depositMoney(balance);
                break;
            case 3:
                balance = withdrawMoney(balance);
                break;
            case 4:
                printf("\nThank you for using our ATM. Goodbye!\n");
                dynamicLoop = 0;
                break;
            default:
                printf("\nInvalid choice! Please select a valid option.\n");
        }
    }
    return 0;
}

int verifyPIN() {
    const int CORRECT_PIN = 1234; 
    int enteredPin;
    int attempts = 0;

    while (attempts < 3) 
    {
        printf("Enter your 4-digit secret PIN: ");
        scanf("%d", &enteredPin);

        if (enteredPin == CORRECT_PIN) {
            return 1; 
        } 
        else 
        {
            attempts++;
            printf("Incorrect PIN. Attempts remaining: %d\n\n", 3 - attempts);
        }
    }
    return 0; 
}

void checkBalance(float balance) 
{
    printf("\n>>> Your current balance is: $%.2f\n", balance);
}

float depositMoney(float balance) 
{
    float depositAmount;
    printf("\nEnter the amount to deposit: $");
    scanf("%f", &depositAmount);

    if (depositAmount <= 0) 
    {
        printf("Invalid amount! Deposit must be greater than zero.\n");
    } 
    else 
    {
        balance += depositAmount;
        printf("Successfully deposited: $%.2f\n", depositAmount);
        printf("Updated balance: $%.2f\n", balance);
    }
    return balance;
}
float withdrawMoney(float balance) 
{
    float withdrawAmount;

    printf("\nEnter the amount to withdraw: $");
    scanf("%f", &withdrawAmount);

    if (withdrawAmount <= 0) 
    {
        printf("Invalid amount! Withdrawal must be greater than zero.\n");
    } 
    else if (withdrawAmount > balance) 
    {
        printf("Transaction Denied: Insufficient balance!\n");
        printf("Available balance: $%.2f\n", balance);
    } 
    else 
    {
        balance -= withdrawAmount;
        printf("Successfully withdrew: $%.2f\n", withdrawAmount);
        printf("Remaining balance: $%.2f\n", balance);
    }
    return balance;
}
