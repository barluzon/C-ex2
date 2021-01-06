#include <stdio.h>
#include "myBank.h"
#define ROW 50
#define COLUMN 2
#define CLOSED_ACCCOUNT 0.0
#define ACTIVE_ACCOUNT 1.0
#define ACCOUNT_BALANCE_COLUMN 0
#define ACCOUNT_STATUS_COLUMN 1
#define FIRST_ACCOUNT_ID 901

double bankArray [ROW][COLUMN] = {{0.0}};

//returns the first available account index. returns -1 if there are no available accounts
int getAvailableAccountIndex() {
    int availableID = -1;
    for(int i=0 ; i<ROW ; i++){
        if(bankArray[i][ACCOUNT_STATUS_COLUMN] == CLOSED_ACCCOUNT){
            availableID = i;
            break;
        }
    }
    return availableID;
}

void openAccount() {
    printf("Please enter amount for deposit: ");
    double initialAmount;
    if (scanf("%lf", &initialAmount) == 0) {
        printf("Failed to read the amount\n");
        return;
    }
    if (initialAmount < 0) {
        printf("Invalid Amount\n");
        return;
    }
    int accountIndex = getAvailableAccountIndex();
    if(accountIndex != -1) {
        bankArray[accountIndex][ACCOUNT_STATUS_COLUMN] = ACTIVE_ACCOUNT;
        bankArray[accountIndex][ACCOUNT_BALANCE_COLUMN] = initialAmount;
        printf("New account number is: %d\n", FIRST_ACCOUNT_ID + accountIndex);
    } else {
        printf("The bank is full.\n");
    }
}

void accountBalance() {
    printf("Please enter account number: ");
    int accountID;
    if((scanf("%d",&accountID))==0){
        printf("Failed to read the account number\n");
        return;
    }
    if( accountID<901 ||  accountID>950) {
        printf("Invalid account number\n");
        return;
    }
    int accIndex = accountID-FIRST_ACCOUNT_ID;
    if(bankArray[accIndex][ACCOUNT_STATUS_COLUMN] == ACTIVE_ACCOUNT){
     double accBalance = bankArray[accIndex][ACCOUNT_BALANCE_COLUMN];
     printf("The balance of account number %d is: %.2lf\n", FIRST_ACCOUNT_ID+ accIndex, accBalance);
    }
    if (bankArray[accIndex][ACCOUNT_STATUS_COLUMN] == CLOSED_ACCCOUNT){
        printf("This account is closed\n");
    }
}

void deposit () {
    printf("Please enter account number: ");
    int accountID;
    if((scanf("%d",&accountID))==0){
        printf("Failed to read the account number\n");
        return;
    }
    if( accountID<901 ||  accountID>950) {
        printf("Invalid account number\n");
        return;
    }
    int accIndex = accountID - FIRST_ACCOUNT_ID;
    if (bankArray[accIndex][ACCOUNT_STATUS_COLUMN] == CLOSED_ACCCOUNT){
        printf("This account is closed\n");
        return;
    }
    printf("Please enter the amount to deposit: ");
    double amount;
    if (scanf("%lf", &amount) == 0) {
        printf("Failed to read the amount\n");
        return;
    }
    if (amount < 0) {
        printf("Cannot deposit a negative amount\n");
        return;
    }
    
    if (bankArray[accIndex][ACCOUNT_STATUS_COLUMN] == ACTIVE_ACCOUNT) {
        bankArray[accIndex][ACCOUNT_BALANCE_COLUMN] += amount;
        printf("The new balance is: %.2lf\n", bankArray[accIndex][ACCOUNT_BALANCE_COLUMN]);
    }
}

//add else case (if ret<amount) or bank status = not set
void withdrawal () {
    printf("Please enter account number: ");
    int accountID;
    if((scanf("%d",&accountID))==0){
        printf("Failed to read the account number\n");
        return;
    }
    if( accountID<901 ||  accountID>950) {
        printf("Invalid account number\n");
        return;
    }
    int accIndex = accountID - FIRST_ACCOUNT_ID;
    if (bankArray[accIndex][ACCOUNT_STATUS_COLUMN] == CLOSED_ACCCOUNT){
        printf("This account is closed\n");
        return;
    }
    printf("Please enter the amount to withdraw: ");
    double amount;
    scanf("%lf", &amount);
    if (amount < 0) {
        printf("Cannot withdraw a negative amount\n");
        return;
    }
    
    if (bankArray[accIndex][ACCOUNT_STATUS_COLUMN] == ACTIVE_ACCOUNT) {
        if (bankArray[accIndex][ACCOUNT_BALANCE_COLUMN] >= amount ) {
            bankArray[accIndex][ACCOUNT_BALANCE_COLUMN]-=amount;
            printf("The new balance is: %.2lf\n", bankArray[accIndex][ACCOUNT_BALANCE_COLUMN]);
        } else {
            printf("Cannot withdraw more than the balance\n");
        }
    }
}

void closeAccount () {
    printf("Please enter account number: ");
    int accountID;
    if((scanf("%d",&accountID))==0){
        printf("Failed to read the account number\n");
        return;
    }
    if( accountID<901 ||  accountID>950) {
        printf("Invalid account number\n");
        return;
    }
    int accIndex = accountID - FIRST_ACCOUNT_ID;
    if (bankArray[accIndex][ACCOUNT_STATUS_COLUMN] == CLOSED_ACCCOUNT) {
        printf("This account is already closed\n");
    }
    if (bankArray[accIndex][ACCOUNT_STATUS_COLUMN] == ACTIVE_ACCOUNT) {
        bankArray[accIndex][ACCOUNT_BALANCE_COLUMN] = 0.0;
        bankArray[accIndex][ACCOUNT_STATUS_COLUMN] = CLOSED_ACCCOUNT;
        printf("Closed account number %d\n",accountID);
    }
}

void interestRate () {
    printf("Please enter interest rate: ");
    int rate;
    if((scanf("%d",&rate))==0){
        printf("Failed to read the interest rate\n");
        return;
    }
    if(rate < 0){
        printf("Invalid interest rate\n");
        return;
    }
    for(int i=0 ; i<ROW ; i++) { //loop through all bank accounts 
        if(bankArray[i][ACCOUNT_STATUS_COLUMN] == ACTIVE_ACCOUNT){ //if the account is active
            bankArray[i][ACCOUNT_BALANCE_COLUMN] *= 1+(rate/100.00); //add the interest rate to the account
        }
    }
}

void printAccounts (){
    for (int i = 0; i < ROW; i++) {
        if(bankArray[i][ACCOUNT_STATUS_COLUMN] == ACTIVE_ACCOUNT){
            printf("The balance of account number %d is: %.2lf\n",i+FIRST_ACCOUNT_ID,bankArray[i][ACCOUNT_BALANCE_COLUMN]);
        }
    }
}

void closeAllAccounts(){
    for(int i=0;i<ROW;i++){
        if(bankArray[i][ACCOUNT_STATUS_COLUMN] != ACTIVE_ACCOUNT) {
            bankArray[i][ACCOUNT_BALANCE_COLUMN] = 0.0;
            bankArray[i][ACCOUNT_STATUS_COLUMN] = CLOSED_ACCCOUNT;
        }
    }
}