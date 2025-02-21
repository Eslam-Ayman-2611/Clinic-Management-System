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
    int i;
    for (i =0;i<MAX_PATIENTS;i++)
        {
            if (patients[i].patientID==patientID)
                return (i) ;
        }
return -1 ;
}

// Edit Existing Patient Record
void editPatientRecord()
{
     while(1)
    {
        int ID , Index;
        int choice;
        int exit_flag = 0;

        printf("Welcom to Edit mode....\n");
        printf("please enter the ID..\n");
        scanf("%i",ID);

        Index=searchPatient(ID);

         if(Index>-1)
         {
             printf("Patient details....\n");
             printf("ID: %i \n",patients[Index].patientID);
             printf("Name: %s\n",patients[Index].name);
             printf("age: %i\n",patients[Index].age);
             printf("Gender: %s \n",patients[Index].gender);
            ////////////////////////////////////////////////////
             printf("what do you want to Edit...\n");
             printf("1. Name \n");
             printf("2. Age \n");
             printf("3. Gender \n");
             printf("4. Rservation \n");
             printf("5. All \n");
             printf("6. Exit \n");
             printf("your choice is : \n");
             scanf("%i",&choice);
            /////////////////////////////////////////////////

            switch(choice)
            {
            case 1:
                printf("New Name is:\n");
                scanf("%[^\n]",patients[Index].name);

                printf("update Patient details....\n");
                printf("ID: %i \n",patients[Index].patientID);
                printf("Name: %s\n",patients[Index].name);
                printf("age: %i\n",patients[Index].age);
                printf("Gender: %s \n",patients[Index].gender);
                printf("Reservation has not changed...\n");
                break;
                ///////////////////////////////////////////
            case 2:
                 printf("New Age is:\n");
                scanf("%i",patients[Index].age);

                printf("update Patient details....\n");
                printf("ID: %i \n",patients[Index].patientID);
                printf("Name: %s\n",patients[Index].name);
                printf("age: %i\n",patients[Index].age);
                printf("Gender: %s \n",patients[Index].gender);
                printf("Reservation has not changed...\n");
                break;
                //////////////////////////////////////////////
            case 3:
                printf("New Gender is:\n");
                scanf("%[^\n]",patients[Index].gender);

                printf("update Patient details....\n");
                printf("ID: %i \n",patients[Index].patientID);
                printf("Name: %s\n",patients[Index].name);
                printf("age: %i\n",patients[Index].age);
                printf("Gender: %s \n",patients[Index].gender);
                printf("Reservation has not changed...\n");
                break;
                /////////////////////////////////////////////
            case 4:
                cancelReservation();  //لسه في شغل هنا
                //reserve   eslam&omar

                ////////////////////////////////////////////
            case 5:
                printf("New Name is:\n");
                scanf("%[^\n]",patients[Index].name);

                printf("New Age is:\n");
                scanf("%i",patients[Index].age);

                printf("New Gender is:\n");
                scanf("%[^\n]",patients[Index].gender);

                cancelReservation();  //لسه في شغل هنا
                //reserve   eslam&omar

                printf("update Patient details....\n");
                printf("ID: %i \n",patients[Index].patientID);
                printf("Name: %s\n",patients[Index].name);
                printf("age: %i\n",patients[Index].age);
                printf("Gender: %s \n",patients[Index].gender);
                break;
                ////////////////////////////////////////////
            case 6:
                printf("Exiting Edit Mode...\n");
                exit_flag = 1;
                break;

               ////////////////////////////////////////////

            default:
                printf("invalid choice , Try again \n");
                continue;
            }


         }
            else{

                printf("sorry , The ID is not exist ");

            }


          if (exit_flag) {             // if True (1)
                           break;
                          }


         }
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

    int patientID;
    printf("PLEASE ENTER YOUR ID: \n");
    scanf("%d",&patientID);
    
        int ID = searchPatientID(patientID);
        if (ID  == 0)
        {
            printf(" There is no any patient with this ID\n");
        }
        else
        {
            printf("The Basic Information Of The Patient`s IS : \n");
            printf(" THE ID IS : %d\n", patients[ID ].patientID);
            printf("THE NAME IS: %s\n", patients[ID ].name);
            printf("THE Age IS: %d\n", patients[ID ].age);
            printf("THE gender IS: %s\n", patients[ID ].gender);
            printf("THE consult_flag IS: %s\n", (patients[ID ].consult_flag ));
    }
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
