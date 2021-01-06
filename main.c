#include <stdio.h>
#include "myBank.h"

int main() {
    enum Action {
        OPEN_ACCOUNT = 'O',
        BALANCE_INQUIRY = 'B',
        DEPOSIT = 'D',
        WITHDRAWAL = 'W',
        CLOSE_ACCOUNT = 'C',
        INTEREST = 'I',
        PRINT = 'P',
        EXIT = 'E',
        NONE = 0
    };
    char action = NONE;
    printf("\nPlease choose a transaction type:\n O-Open Account\n B-Balance Inquiry\n D-Deposit\n W-Withdrawal\n C-Close Account\n I-Interest\n P-Print\n E-Exit\n");
    while(action != EXIT) {
        scanf(" %c", &action);
        switch (action) {
            case OPEN_ACCOUNT: {
                openAccount();
                break;
            }

            case BALANCE_INQUIRY: {
                accountBalance();
                break;
            }

            case DEPOSIT: {
                deposit();
                break;
            }

            case WITHDRAWAL: {
                withdrawal();
                break;
            }

            case CLOSE_ACCOUNT: {
                closeAccount();
                break;
            }

            case INTEREST: {
                interestRate();
                break;
            }
            case PRINT: {
                printAccounts();
                break;
            }
            case NONE: {
                break;
            }
            case EXIT: {
                closeAllAccounts();
                break;
            }
            default: {
                printf("Invalid transaction type\n");
                break;
            }
        }
        if (action != EXIT) {
            printf("\nPlease choose a transaction type:\n O-Open Account\n B-Balance Inquiry\n D-Deposit\n W-Withdrawal\n C-Close Account\n I-Interest\n P-Print\n E-Exit\n");
        }
    }
}