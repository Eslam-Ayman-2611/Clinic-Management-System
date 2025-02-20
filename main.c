#include <stdio.h>
#include <string.h>
#include "main.h"


// Display Main Menu
void Home_Menu()
{

    int option;
    do
    {
        printf("\tClinic Management System\n");
        printf("1. Admin Mode\n");
        printf("2. User mood\n");
        printf("3. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                adminLogin();
                return ;
                break;
            case 2:
                UserMood();
                break;
            case 3:
                printf("you are out of system!!!");
                break;
            default:
                printf("invalid!! please try again!!");
        }

    }while(option!=3);

}

// Admin Login
void adminLogin()
{
    int password;
    int attempts=0;

    while(attempts<3)
    {
    printf("Enter password:\n");
    scanf("%i",&password);
        if(password==1234)
        {
            printf("Admin mode accessed!!");
            adminMenu();
            return;
        }
        else
        {
            attempts++;
            printf("incorrect!!try again\n");
        }
        if(attempts==3)
    {
        printf("Maximum trials reached!!\n");
        return ;
    }
    }


}

// Admin Menu
void adminMenu()
{

    int choice;
    do
    {
        printf("\nAdmin Menu\n");
        printf("1. Reserve Slot\n");
        printf("2. Edit Patient Record\n");
        printf("3. Cancel Reservation\n");
        printf("4. usermood\n");
        printf("5. Logout\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: reserveSlot();choice=4; break;
            case 2: editPatientRecord();choice=4; break;
            case 3: cancelReservation();choice=4; break;
            case 4: UserMood(); choice=4; break;
            case 5: printf("Logging out...\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while(choice != 4);

}
// Check if Patient Exists
int searchPatient(int patientID)
{
return 0 ;
}

// Edit Existing Patient Record
void editPatientRecord()
{
//Mohamed
}


// Reserve a Slot
void reserveSlot()
{
    if(patientCount<35)
    {
        if(slotCount<35)
        {
            int choice;
    do
    {
        printf("\n You want : \n");
        printf("1. Register as New patient\n");
        printf("2. Register as pre-existing patient\n");
        printf("3. Back\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: NewPatient();choice=3; break;
            case 2: ExistingPatient(); choice=3; break;
            case 3: printf("back step\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while(choice != 3);
        }
    }

}

// Cancel a Reservation
void cancelReservation()
{
//amir
}


void UserMood()
{

    int choice;
    do
    {
        printf("\n User  Menu\n");
        printf("1. view Patient Record \n");
        printf("2. view Reservations \n");
        printf("3. Logout\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: viewPatientRecord(); break;
            case 2: viewReservations(); break;
            case 3: printf("Logging out...\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while(choice != 3);

}

// View Patient Record
void viewPatientRecord()
{
//Rawda
}
// View todays's Reservations
void viewReservations()
{
//Rawda
}
int checkpatientresearve(int patientID)
{
    //amir
    return 0 ;
}
void NewPatient()
{
//Omar
}
//Eslam
void ExistingPatient()
{
  int ID ;
  int PatientLocation ;

  printf(" Enter Your ID .\n");
  scanf("%d",&ID);
  PatientLocation=searchPatient( ID);
  if(PatientLocation==0)
  {
    printf(" We don't have this ID ");
  }
  else
  {
    if(patients[PatientLocation].consult_flag==1)
    {
    printf(" You already recorded slot and consultation ");
    }
    else 
    {
        reserveingSlot();
    }
  }
}
void reserveingSlot()
{
    //Eslam&omar
}
