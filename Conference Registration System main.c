#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct Participant {
    char name[100];
    int id;
    char organization[100];
    float fees;
    bool status; 
};
 int x;

void inputParticipantsData(struct Participant participants[], int *count) {
    if (*count >= 50) {
        printf("The maximum number of participants has been reached. We cannot accept more.\n");
        return;
    }
    int y;
    
    printf("Enter the name of the participant:\n");
    getchar(); 
    fgets(participants[*count].name, 100, stdin);
    participants[*count].name[strcspn(participants[*count].name, "\n")] = '\0'; 

    printf("Enter the ID:\n");
    scanf("%d", &participants[*count].id);
    getchar();

    printf("Enter the organization:\n");
    fgets(participants[*count].organization, 100, stdin);
    participants[*count].organization[strcspn(participants[*count].organization, "\n")] = '\0';

    printf("Enter the registration fees:\n");
    scanf("%f", &participants[*count].fees);

    printf("Enter the payment status (1 for paid or 0 for unpaid):\n");
    scanf("%d", &y);
    participants[*count].status = (y==1);

    (*count)++;
    printf("Participant added successfully!\n");
}

void updatePaymentStatus(struct Participant *participants) {
    if (participants->status==true) {
        printf("The payment status has already been updated to paid.\n");
    } else {
        participants->status= true;
        printf("Payment status successfully updated to paid for %d!\n", participants->id);
    }
}

void displayParticipants(struct Participant participants[], int count) {
    if (count == 0) {
        printf("There are no participants registered yet.\n");
        return;
    }

    char y[50]; 

    printf("Participants details:\n");
    printf("Name | ID | Organization | Registration Fees | Payment Status \n");

    for (x = 0; x < count; x++) {
        if (participants[x].status == true) {
            strcpy(y, "Paid");
        } else {
            strcpy(y, "Unpaid");
        }
        
        printf("%s | %d | %s | %.3f | %s \n", participants[x].name, participants[x].id, participants[x].organization, participants[x].fees, y);
    }
}


void adjustFee(struct Participant *participant, float change, int steps, int oper) {
    if (steps <= 0) {
        printf("Fee adjustment completed for participant %s. Final fee: %.2f\n", participant->name, participant->fees);
        return;
    }

    if (oper) {
        participant->fees+= change;
    } else {
        participant->fees-= change;
    }
    
    adjustFee(participant, change, steps - 1, oper); 
}


int main() {
    struct Participant participants[50];
    int count = 0; 
    int choice;

    do {
        printf("\nWelcome to the Conference Registration! Kindly choose from the menu below:\n");
        printf("1. Input Participant Data\n");
        printf("2. Update Payment Status\n");
        printf("3. Display Participants\n");
        printf("4. Adjust Registration Fee\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputParticipantsData(participants, &count);
                break;
            case 2: {
                int id;
                int found = 0;
                printf("Enter Participant ID to update payment status: ");
                scanf("%d", &id);
                for (x= 0; x<count; x++) {
                    if (participants[x].id == id) {
                        updatePaymentStatus(&participants[x]);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Participant with ID %d not found.\n", id);
                }
                break;
            }
            case 3:
                displayParticipants(participants, count);
                break;
            case 4: {
                int id;
                int found = 0;
                printf("Enter Participant ID for whom you need to adjust the fees: ");
                scanf("%d", &id);
                for (x=0; x<count; x++) {
                    if (participants[x].id == id) {
                        float change;
                        int steps, oper;
                        printf("Enter the amount you want to adjust: ");
                        scanf("%f", &change);
                        printf("How many times must the amount be adjusted? ");
                        scanf("%d", &steps);
                        printf("Enter 1 to add or 0 to subtract: ");
                        scanf("%d", &oper);
                        adjustFee(&participants[x], change, steps, oper);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Participant with ID %d not found.\n", id);
                }
                break;
            }
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

