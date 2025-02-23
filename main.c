#include <stdio.h>
#include <string.h>
#include "main.h"

//=Team======================================================  Display Main Menu ===========================================================
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
//=Omar======================================================  Admin Login ============================================================
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
//=Team======================================================  Admin Menu ============================================================
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
            case 1: reserveSlot(); break;
            case 2: editPatientRecord(); break;
            case 3: cancelReservation(); break;
            case 4: UserMood(); Home_Menu(); break;
            case 5: printf("Logging out...\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while(choice != 4);

}
//=Mohamed======================================================  edit Patient Record ============================================================
int searchPatient(int patientID)
{
    int i;
    for (i =0;i<MAX_PATIENTS;i++)
        {
            if (patients[i].patientID==patientID&&patients[i].patientID!=0)
                return (i) ;
        }
return -1 ;
}
void editPatientRecord()
{
   int Back_choice;
   int exit_flag = 0;
     while(exit_flag==0)
    {
        int ID,Index;
        //////////////////////////////
        printf("Welcom to Edit mode....\n");
        printf("please enter the ID..\n");
        scanf("%i",&ID);
        Index=searchPatient(ID);
        //////////////////////////////
         if(Index>-1)
         {
             printf("Patient details....\n");
             printpatientdata(Index);
            ////////////////////////////////////////////////////
             printf("what do you want to Edit...\n");
             printf("1. Name \n");
             printf("2. Age \n");
             printf("3. Gender \n");
             printf("4. Rservation \n");
             printf("5. All \n");
             printf("6. Exit \n");
             printf("your choice is : \n");
             int choice;
             scanf("%i",&choice);
            /////////////////////////////////////////////////
            switch(choice)
            {
            case 1:
                printf("New Name is:\n");
                fflush(stdin);
                gets(patients[Index].name);
                printf("update Patient details....\n");
                printpatientdata(Index);
                exit_flag = 1;
                break;
             //********************************************* //
            case 2:
                 printf("New Age is:\n");
                scanf("%i",&patients[Index].age);

                printf("update Patient details....\n");
                printpatientdata(Index);
                exit_flag = 1;
                break;
            //********************************************* //
            case 3:
                printf("New Gender is:\n");
               fflush(stdin);
               gets(patients[Index].gender);


                printf("update Patient details....\n");
                printpatientdata(Index);
                exit_flag = 1;
                break;
            //********************************************* //
            case 4:
                  printf("Editing main Reservation:\n");
                  editReserve(ID,Index);
                  exit_flag=1;
                  break;
            //******************************************* //
            case 5:
                printf("New Name is:\n");
                fflush(stdin);
                gets(patients[Index].name);
           //////////////////////////////////////////
                printf("New Age is:\n");
                scanf("%i",&patients[Index].age);
           ////////////////////////////////////////
                printf("New Gender is:\n");
                 fflush(stdin);
                gets(patients[Index].gender);
                /////////////////////////////////////
                printf("Editing main Reservation:\n");
                editReserve(ID , Index );
          /////////////////////////////////////////////////////////
                exit_flag = 1;
                break;
          //********************************************* //
            case 6:
                printf("Exiting Edit Mode...\n");
                adminMenu();
                exit_flag = 1;
                break;
        //********************************************* //

            default:
                printf("invalid choice , Try again \n");
                continue;
            }


         }

            else
        {

                printf(" sorry , The ID is not exist \n");
                break;

        }


    }
//Mohamed
}

//=Eslam======================================================  Reserve a Slot ============================================================
//
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
//=Amir======================================================  Cancel a Reservation ============================================================
void deletepatientdata(int PatientLocation)
{
    patients[PatientLocation].age = 0;
    patients[PatientLocation].patientID= 0;
    strcpy(patients[PatientLocation].gender, "");
    strcpy(patients[PatientLocation].name, "");
    patientCount--;
}

void cancelReservation()
{

    int ID;
    int PatientLocation;
    int flag = 0 ;
    printf(" Enter Your ID .\n");
    scanf("%d", &ID);
    PatientLocation = searchPatient(ID);

    if (PatientLocation !=-1)
    {
      printf("User existed .\n");
      if(patients[PatientLocation].consult_flag==0)
      {
        for (int d = 0; d < DAYS_IN_WEEK; d++)
        {
          for (int s = 0; s < SLOTS_PER_DAY; s++)
          {

            if (busySlots[d][s]==ID)
            {
                 busySlots [d] [s] = 0;//
                 availableSlots[d][s] = 1;
                 slotCount--;
                 deletepatientdata (PatientLocation);
                 printf(" We canceled your slot and deleted your data .\n");
            }
          }
        }
      }
      else
      {
        while(flag==0)
        {
            for (int d = 0; d < DAYS_IN_WEEK; d++)
            {
              for (int s = 0; s < SLOTS_PER_DAY; s++)
              {

                  if (busySlots[d][s]==ID)
                {
                    if(flag==0)
                    {
                        flag=1;
                    }
                    else
                    {
                        busySlots [d] [s] = 0;//
                        availableSlots[d][s] = 1;
                        slotCount--;
                        patients[PatientLocation].consult_flag=0;
                        printf(" We canceled your consultation .\n");
                    }
                }
              }
            }
         patients[PatientLocation].consult_flag=0;
        }
      }

      }

    else
    {
      printf("User not found");
    }

  }

//==Eslam====================================================== User mood  ============================================================
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
//==Rawda====================================================== View Patient Record ============================================================
void viewPatientRecord()
{

    int patientID;
    printf("PLEASE ENTER YOUR ID: \n");
    scanf("%d",&patientID);

        int ID = searchPatient(patientID);
        if (ID  == -1)
        {
            printf(" There is no any patient with this ID\n");
        }
        else
        {
            printf("The Basic Information Of The Patient`s IS : \n");
            printpatientdata(ID);

        }
}
//==Rawda====================================================== view Reservations ============================================================
void viewReservations()
{
    int day;
    printf("Enter the day number : \n1 for Sat. \n2 for Sun. \n3 for Mon. \n4  for Tues.\n5 for Wed. \n6  for Thu. \n7 for Fri.): ");
    scanf("%d", &day);
    day--;

    if (day < 0 || day > 6)
        printf("Invalid day!\n");
    else
        {
             printf("\nReservations for Day %d:\n", day + 1);
             printf("Today's Reservations with patints ID and Time Slot:\n");

            int flag = 0;  //<There is no Reservation if flag =0 >  < flag=1 Reservation >


        for (int slot = 0; slot < SLOTS_PER_DAY; slot++)
        {
            if (busySlots[day][slot] != 0) //<There is Reservation in Day>
                {
                    flag = 1;
                    switch (slot)
                    {
                         case 0:  printf("Time: from 2:00 to 2:30  \t"); break;
                         case 1:  printf("Time: from 2:30 to 3:00  \t"); break;
                         case 2:  printf("Time: from 3:00 to 3:30  \t"); break;
                         case 3:  printf("Time: from 4:00 to 4:30  \t"); break;
                         case 4:  printf("Time: from 4:30 to 5:00  \t"); break;
                    }
                   printf(" Patient ID: %d \n", busySlots[day][slot]);
                 }
        }
      if(!flag )
      {
         printf("No reservations for today.\n");
      }
    }
}
//==Amir===========================================================check patient researve ====================================================

int checkpatientresearve(int patientID)
{

  int PatientLocation;
  PatientLocation = searchPatient(patientID);

  if (PatientLocation != -1)
  {
    printf("User existed .\n");
    for (int d = 0; d < DAYS_IN_WEEK; d++)
    {
      for (int s = 0; s < SLOTS_PER_DAY; s++)
      {
        if (busySlots[d][s] == patientID)
        {
          return 1;
        }
      }
    }
  }

  else
  {
    printf("User not found");
    return 0;
  }
}
//======================================================new patient============================================================
void NewPatient()
{
    if(patientCount<35&&slotCount<35&&FirstEmptyIndex()!=-1)
    {
        int index=FirstEmptyIndex();

         printf("Entering new patient data:\n");

         printf("Enter name:\n");
         fflush(stdin);
         gets(patients[index].name);

         printf("Enter age:\n");
         scanf("%i",&patients[index].age);

         printf("Enter gender:\n");
         fflush(stdin);
         gets(patients[index].gender);

         int id;
         int flag = 0 ;
         do
         {
            printf("* Note that: \n1-ID must contain 4 numbers not started whith 0 \n 2-ID must be unique \n");
            printf(" Enter ID:\n");
            scanf("%i",&id);
            if(checkIDavailable(id)==1)
            {


                printf("Did user pay %i $?:\n if No, press 0\n if Yes, press any thing else\n",price);
                int cost_flag=0;
                scanf("%i",&cost_flag);
              if(cost_flag!=0)
              {
               printf("User paid %i $!!\n",price);
               patients[index].patientID=id;
               reserveingSlot(id);
               printf("Patient data successfully added!!\n");
               patientCount++;
               flag++;
              }
              else
              {
                  flag=1;
                  printf("No data added for this user!\n");
              }

            }
            else
            {
                printf(" Invalid ID \n");
                printf(" try another one \n");
            }
         } while (flag==0);

    }
    else
    {
        printf("Maximum weekly capacitance reached!!\n");
    }
}
int FirstEmptyIndex()
{
    int i;
    for (i = 0; i < MAX_PATIENTS; i++)
    {
        if (strcmp(patients[i].name, "") == 0 &&
            patients[i].age == 0 &&
            strcmp(patients[i].gender, "") == 0 &&
            patients[i].patientID == 0)
        {
            return i; // Return the first empty index found
        }
    }
    return -1; // Return -1 if no empty slot is found
}
//==Eslam============================================================Existing Patient ====================================================
void ExistingPatient()
{
  int ID ;
  int PatientLocation ;

  printf(" Enter Your ID .\n");
  scanf("%d",&ID);
  PatientLocation=searchPatient(ID);//  PatientLocation=searchPatient(ID)-1;
  if(PatientLocation==-1)
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
        reserveingSlot(ID);
        patients[PatientLocation].consult_flag=1;
        printf("Consultation is for free!\n");
    }
  }
}
//============================================================== reserveing Slot ====================================================

void reserveingSlot(int ID )
{
    int day =0 , slot = 0 , counter =0 , flag =0  ;
    if(slotCount>=35)
     {
        printf(" NO slots available in this week ");
     }
    else
    {
        do
        {
                printf(" choose day : \n");
                printf(" 1-Saturday  \n");
                printf(" 2-Sunday : \n");
                printf(" 3-Monday : \n");
                printf(" 4-Tuesday : \n");
                printf(" 5-Wednesday : \n");
                printf(" 6-Thursday : \n");
                printf(" 7-Friday : \n");
                scanf("%d",&day);
                if (day < 1 || day > 7)
                {
                    printf("Invalid day! Please choose between 1 and 7.\n");
                    continue;
                }
                ////////////////////////////////////////////////////////////
                counter=0;
                printf(" Empty slots : \n");
                if(availableSlots[day-1][0]==1)
                                {printf(" 1- 2:00 to 2:30   \n");counter++;}
                if(availableSlots[day-1][1]==1)
                                {printf(" 2- 2:30 to 3:00   \n");counter++;}
                if(availableSlots[day-1][2]==1)
                                {printf(" 3- 3:00 to 3:30   \n");counter++;}
                if(availableSlots[day-1][3]==1)
                                {printf(" 4- 4:00 to 4:30   \n");counter++;}
                if(availableSlots[day-1][4]==1)
                                {printf(" 5- 4:30 to 5:00   \n"); counter++;}
                /////////////////////////////////////////////////////////////
                if (counter==0)
                    printf(" NO empty slots in this day \n please chooe another day");
                else
                {
                    printf(" choose one of these %i slots ",counter);
                    scanf("%d",&slot);
                    if(slot>5||slot<1||availableSlots[day-1][slot - 1] == 0)
                    {
                        printf("invalid slot\n");
                    }
                    else
                    {
                        availableSlots[day-1][slot-1]=0;
                        busySlots[day-1][slot-1]=ID;
                        slotCount++;
                        flag=1;
                        if(patients[searchPatient(ID)].consult_flag==1)
                        {
                          int bookFlag=0;
                        for(int day0 = 0 ; day0< DAYS_IN_WEEK;day0++)
                            {
                                for(int slot0=0 ; slot0 < SLOTS_PER_DAY ;slot0++ )
                                {
                                    if (bookFlag==1) continue;
                                    if(busySlots[day0][slot0]==busySlots[day-1][slot-1])
                                    {
                                        if((day-1>day0)||(day-1==day0&&slot-1>slot0)||!((day-1==day0&&slot-1==slot0)))
                                            printf(" your consultation booked ");
                                            flag=1;
                                    }
                                    else
                                    {
                                        busySlots[day-1][slot-1]=0;
                                        availableSlots[day-1][slot-1]=1;
                                        slotCount--;
                                        flag=0;
                                        printf(" you can't book consultation before your slot ");
                                        printf(" choose another slot ");
                                        bookFlag=1;
                                    }
                                }
                                }
                        }
                    }
                }

        } while(flag==0);
    }
}
//==Eslam============================================================ check ID available ====================================================

int checkIDavailable(int ID)
{
if(ID>=1000&&ID<=9999)
{
    for(int i =0 ; i<patientCount;i++)
    {
        if(patients[i].patientID==ID)
            {
                return 0 ;
            }
    }
return 1 ;
}
return 0 ;
}
//============================================================== print patient data ====================================================
void printpatientdata(int ID)
{
        printf("The Name is: %s\n", patients[ID].name);
        printf("The Gender is: %s\n", patients[ID].gender);
        printf("The Age is: %d\n", patients[ID].age);
        printf("The ID is : %d\n", patients[ID].patientID);
        if(patients[ID ].consult_flag==1)
            printf("Consultation Reserved \n");
        else
            printf("No consultation Reserved \n");
}
//============================================================== edit Reserve =============================================================
void editReserve(int ID, int Index)
 {
      for (int i = 0; i < DAYS_IN_WEEK; i++)
          {
                 for (int j = 0; j < SLOTS_PER_DAY; j++)
            {

          if (busySlots[i][j]==ID)
         {
             reserveingSlot(ID);
             availableSlots[i][j]=1;
             busySlots[i][j]=0;
             slotCount--;
             ////////////////////////
             printf("Patient details....\n");
             printpatientdata(Index);
             printf("Reservation has  changed....\n");
             break;
         }

           }

          }

 }
