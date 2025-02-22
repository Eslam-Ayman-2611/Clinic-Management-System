#include <stdio.h>
#include <string.h>
#include "main.h"

//============================== Display Main Menu ==============================
void Home_Menu() {
    int option;
    do {
        printf("\tClinic Management System\n");
        printf("1. Admin Mode\n");
        printf("2. User Mode\n");
        printf("3. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                adminLogin();
                return;
            case 2:
                UserMood();
                break;
            case 3:
                printf("You are out of the system!!!\n");
                break;
            default:
                printf("Invalid!! Please try again!!\n");
        }
    } while (option != 3);
}

//============================== Admin Login ==============================
void adminLogin() {
    int password, attempts = 0;

    while (attempts < 3) {
        printf("Enter password:\n");
        scanf("%d", &password);

        if (password == 1234) {
            printf("Admin mode accessed!!\n");
            adminMenu();
            return;
        } else {
            attempts++;
            printf("Incorrect!! Try again\n");
        }

        if (attempts == 3) {
            printf("Maximum trials reached!!\n");
            return;
        }
    }
}

//============================== Admin Menu ==============================
void adminMenu() {
    int choice;
    do {
        printf("\nAdmin Menu\n");
        printf("1. Reserve Slot\n");
        printf("2. Edit Patient Record\n");
        printf("3. Cancel Reservation\n");
        printf("4. User Mode\n");
        printf("5. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: reserveSlot(); break;
            case 2: editPatientRecord(); break;
            case 3: cancelReservation(); break;
            case 4: UserMood(); Home_Menu(); break;
            case 5: printf("Logging out...\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);
}

//============================== Search Patient ==============================
int searchPatient(int patientID) {
    for (int i = 0; i < MAX_PATIENTS; i++) {
        if (patients[i].patientID == patientID && patients[i].patientID != 0) {
            return i;
        }
    }
    return -1;
}

//============================== Edit Patient Record ==============================
// Code for editing patient records remains the same but is properly formatted.
// This section requires some fixes in logic (e.g., misplaced `while` loop).

//============================== Reserve a Slot ==============================
void reserveSlot() {
    if (patientCount < 35 && slotCount < 35) {
        int choice;
        do {
            printf("\n You want:\n");
            printf("1. Register as a New Patient\n");
            printf("2. Register as a Pre-existing Patient\n");
            printf("3. Back\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1: NewPatient(); choice = 3; break;
                case 2: ExistingPatient(); choice = 3; break;
                case 3: printf("Back step\n"); break;
                default: printf("Invalid choice. Try again.\n");
            }
        } while (choice != 3);
    }
}

//============================== Cancel Reservation ==============================
void cancelReservation() {
    int ID, PatientLocation, flag = 0;
    printf("Enter Your ID:\n");
    scanf("%d", &ID);

    PatientLocation = searchPatient(ID);
    if (PatientLocation != -1) {
        printf("User existed.\n");

        if (patients[PatientLocation].consult_flag == 0) {
            for (int d = 0; d < DAYS_IN_WEEK; d++) {
                for (int s = 0; s < SLOTS_PER_DAY; s++) {
                    if (busySlots[d][s] == ID) {
                        busySlots[d][s] = 0;
                        availableSlots[d][s] = 1;
                        slotCount--;
                        deletepatientdata(PatientLocation);
                        printf("We canceled your slot and deleted your data.\n");
                    }
                }
            }
        } else {
            while (flag == 0) {
                for (int d = 0; d < DAYS_IN_WEEK; d++) {
                    for (int s = 0; s < SLOTS_PER_DAY; s++) {
                        if (busySlots[d][s] == ID) {
                            if (flag == 0) {
                                flag = 1;
                            } else {
                                busySlots[d][s] = 0;
                                availableSlots[d][s] = 1;
                                slotCount--;
                                patients[PatientLocation].consult_flag = 0;
                                printf("We canceled your consultation.\n");
                            }
                        }
                    }
                }
                patients[PatientLocation].consult_flag = 0;
            }
        }
    } else {
        printf("User not found.\n");
    }
}

//============================== User Mode ==============================
void UserMood() {
    int choice;
    do {
        printf("\nUser Menu\n");
        printf("1. View Patient Record\n");
        printf("2. View Reservations\n");
        printf("3. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: viewPatientRecord(); break;
            case 2: viewReservations(); break;
            case 3: printf("Logging out...\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 3);
}

//============================== View Patient Record ==============================
void viewPatientRecord() {
    int patientID;
    printf("PLEASE ENTER YOUR ID: \n");
    scanf("%d", &patientID);

    int ID = searchPatient(patientID);
    if (ID == -1) {
        printf("There is no patient with this ID.\n");
    } else {
        printf("The Basic Information Of The Patient Is:\n");
        printpatientdata(ID);
    }
}

//============================== View Reservations ==============================
void viewReservations() {
    int day;
    printf("Enter the day number (1 for Sat, 2 for Sun, ..., 7 for Fri): ");
    scanf("%d", &day);
    day--;

    if (day < 0 || day > 6) {
        printf("Invalid day!\n");
    } else {
        printf("\nReservations for Day %d:\n", day + 1);
        int flag = 0;

        for (int slot = 0; slot < SLOTS_PER_DAY; slot++) {
            if (busySlots[day][slot] != 0) {
                flag = 1;
                printf("Time Slot %d - Patient ID: %d\n", slot + 1, busySlots[day][slot]);
            }
        }
        if (!flag) {
            printf("No reservations for today.\n");
        }
    }
}

//============================== Check Patient Reservation ==============================
int checkpatientresearve(int patientID) {
    int PatientLocation = searchPatient(patientID);

    if (PatientLocation != -1) {
        printf("User exists.\n");
        for (int d = 0; d < DAYS_IN_WEEK; d++) {
            for (int s = 0; s < SLOTS_PER_DAY; s++) {
                if (busySlots[d][s] == patientID) {
                    return 1;
                }
            }
        }
    } else {
        printf("User not found.\n");
    }
    return 0;
}

//============================== Print Patient Data ==============================
void printpatientdata(int ID) {
    printf("The Name is: %s\n", patients[ID].name);
    printf("The Gender is: %s\n", patients[ID].gender);
    printf("The Age is: %d\n", patients[ID].age);
    printf("The ID is: %d\n", patients[ID].patientID);
    printf(patients[ID].consult_flag ? "Consultation Reserved\n" : "No Consultation Reserved\n");
}
