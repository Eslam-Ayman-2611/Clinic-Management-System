#include "Header.h"

//=Team======================================================  Display Main Menu ===========================================================

void Wellcome()
{
    printf("*************************************************\n");
    printf("*          DOCTOR INFORMATION BOARD             *\n");
    printf("*************************************************\n");
    usleep(300000);
    printf("* Doctor    : Name of Doctor                    *\n");
    printf("* Specialty : Internal Medicine                 *\n");
    printf("*************************************************\n");
    usleep(300000);
    printf("*              WORKING HOURS                    *\n");
    printf("*************************************************\n");
    usleep(300000);
    
    printf("*  1:00 -  1:30  |                              *\n");
    printf("*  1:30 -  2:00  |                              *\n");
    printf("*  2:00 -  2:30  |                              *\n");
    printf("*  2:30 -  3:00  |                              *\n");
    printf("*  3:00 -  3:30  |                              *\n");
    printf("*  4:00 -  4:30  |                              *\n");
    printf("*  4:30 -  5:00  |                              *\n");
    usleep(300000);

    printf("*************************************************\n");
    printf("*              EMERGENCY HOURS                  *\n");
    printf("*************************************************\n");
    usleep(300000);

    printf("*  6:00 -  6:300 |        Emergency             *\n");
    printf("*  6:30 -  7:00  |        Emergency             *\n");
    usleep(300000);

    printf("*************************************************\n");
    printf("* Degree    : Doctorate in Internal Medicine    *\n");
    printf("*************************************************\n");
    usleep(300000);

}

//=Team======================================================  Display Main Menu ===========================================================

void Home_Menu()
{

    short option;
    do
    {
        printf("\tClinic Management System\n");
    usleep(300000);
        printf("1. Admin Mode\n");
    usleep(300000);
        printf("2. User mood\n");
    usleep(300000);
        printf("3. Exit\n");
    usleep(300000);
        printf("Enter your option: ");
        fflush(stdin);
        scanf("%hi", &option);
        switch(option)
        {
            case 1:
                Clear_Screen();
                Admin_Login();
                return ;
                break;
            case 2:
                Clear_Screen();
                User_Mood();
                break;
            case 3:
                Clear_Screen();
                printf("you are out of system!!!");
                option=3;
                break;
            default:
                printf("invalid!! please try again!!");
        }
        
    }while(option!=3);
    
}
//=Omar======================================================  Admin Login ============================================================
void Admin_Login() {
    int password ;
    int attempts = 0;
    
    while (attempts < 6) {
        printf(" Enter password : ");
        fflush(stdout);
        scanf("%d",&password);
        if (password== 4444) {
            printf("Admin mode accessed!\n");
            Admin_Menu();
        } 
        else
        {
            printf("Incorrect! Try again.\n");
            attempts++;
            
            if (attempts == 3) {
                printf("\nYou entered an incorrect password 3 times!\n");
                printf("Please wait 15 seconds before trying again...\n");
                
                for (int i = 1; i <= 15; i++) {
                    printf(" %d seconds...\n", i);
                    fflush(stdout);
                    usleep(300000);
                }
                printf("You can try again now.\n");
            }
        }
    }
    
    printf("Too many failed attempts. Access denied!\n");
}
//=Team======================================================  Admin Menu ============================================================
void Admin_Menu()
{
    Clear_Screen();
    int choice;
    do
    {
        printf("\nAdmin Menu\n");
        usleep(300000);
        printf("1. Reserve Slot\n");
        usleep(300000);
        printf("2. Edit Patient Record\n");
        usleep(300000);
        printf("3. Cancel Reservation\n");
        usleep(300000);
        printf("4. Show treasury funds \n");
        usleep(300000);
        printf("5. usermood\n");
        usleep(300000);
        printf("6. Logout\n");
        usleep(300000);
        printf("Enter your choice: ");
        fflush(stdin);
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: Clear_Screen(); Reserve_Slot(); break;
            case 2: Clear_Screen(); Edit_Patient_Record(); break;
            case 3: Clear_Screen(); Cancel_Reservation(); break;
            case 4: Clear_Screen(); Money_safe_view(); break;
            case 5: Clear_Screen(); User_Mood(); Home_Menu(); break;
            case 6: Clear_Screen(); printf("Logging out...\n");choice=6; break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while(choice != 6);
    
}
//=Eslam======================================================  Reserve a Slot ============================================================
void Reserve_Slot()
{
    if(patientCount<35)
    {
        if(slotCount<35)
        {
            char choice;
    do
    {
        printf("\n You want : \n");

        printf("1. Register as New patient\n");
        printf("2. Register as pre-existing patient\n");
        printf("3. Register as Emergency patient\n");
        printf("4. Back\n");

        printf("Enter your choice: ");
        fflush(stdin);
        scanf("%c", &choice);

        switch(choice)
        {
            case '1': New_Patient();choice='4'; break;
            case '2': Existing_Patient(); choice='4'; break;
            case '3': Emergency_Patient(); choice='4'; break;
            case '4': printf("back step\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while(choice != '4');
        }
    }

}
//======================================================new patient============================================================
void New_Patient()
{
    if(patientCount<35&&slotCount<35&&First_Empty_Index()!=-1)
    {
         int index=First_Empty_Index();
         int id;
         int flag = 0 ;

         do
         {
            printf("\nEntering new patient data:\n");
            printf("*\a Note that:  not started whith 0\n");
            printf("\n1-ID must contain 4 numbers");
            printf("\n2-ID must be unique");
            printf(" Enter ID:\n");
            scanf("%i",&id);
            clear_input_buffer();
            if(Check_ID_Available(id)==1)
            {
              printf("Did user pay %i $? \n",price);
              printf("\nif Yes : Enter 1 ");
              printf("\nif No : press any thing else ");

              char Cost_flag='0';
              fflush(stdin);
              scanf("%c",&Cost_flag);
              
              if(Cost_flag=='1')
              {
               printf("\nUser paid %i $!!\n",price);
               patients[index].patientID=id;
               /////////////////////////
                Input_Valid_Name(index);
                /////////////////////////
                printf("Enter age:\n");
                Input_Valid_Age(index);
                /////////////////////////
                Input_Valid_Gander(index);
                /////////////////////////
                Clear_Screen();
                Choose_Slot(id);

               char edit_confirm;
               printf("\n\nDo yo want to edit any patient data?\n");
               printf("if yes>>press 1\n");
               printf("if no>>press any number\n");
               fflush(stdin);
               scanf("%c",&edit_confirm);

               if(edit_confirm=='1')
               {
                Clear_Screen();
                Edit_Patient_Record();
               }
               Clear_Screen();
               printf("Patient data successfully added!!\n");
               patientCount++;

               flag=1;
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
int First_Empty_Index()
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
//=Mohamed======================================================  edit Patient Record ============================================================
int Search_Patient(int patientID)
{
    int i;
    for (i =0;i<MAX_PATIENTS;i++)
    {
            if (patients[i].patientID==patientID&&patients[i].patientID!=0)
                return (i) ;
        }
return -1 ;
}
void Edit_Patient_Record()
{
   int Back_choice;
   int exit_flag = 0;
     while(exit_flag==0)
    {
        int ID,Index;
        //////////////////////////////
        printf("Welcom to Edit mode....\n");
        printf("please enter the ID..\n");
        fflush(stdin);
        scanf("%i",&ID);
        clear_input_buffer();
        Index=Search_Patient(ID);
        //////////////////////////////
         if(Index>-1)
         {
             printf("Patient details....\n");
void Print_Patient_Data(int ID);//Rawda========================= works well
             Print_Patient_Data(Index);
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
             fflush(stdin);
             scanf("%i",&choice);
            switch(choice)
            {
            case 1:
                printf("New Name is:\n");
                Input_Valid_Name(Index);
                printf("update Patient details....\n");
                Print_Patient_Data(Index);
                exit_flag = 1;
                break;
            //******************************************* //
            case 2:
                printf("New Age is:\n");
                Input_Valid_Age(Index);

                printf("update Patient details....\n");
                Print_Patient_Data(Index);
                exit_flag = 1;
                break;
            //******************************************* //
            case 3:
                printf("New Gender is:\n");
                Input_Valid_Gander(Index);

                printf("update Patient details....\n");
                Print_Patient_Data(Index);
                exit_flag = 1;
                break;
            //********************************************* //
            case 4:
                  printf("Editing main Reservation:\n");
                  Edit_Reserve(ID,Index);
                  exit_flag=1;
                  break;
            //******************************************* //
            case 5:
                printf("New Name is:\n");
                Input_Valid_Name(Index);
           //////////////////////////////////////////
                printf("New Age is:\n");
                Input_Valid_Age(Index);
           ////////////////////////////////////////
                printf("New Gender is:\n");
                Input_Valid_Gander(Index);
                /////////////////////////////////////
                printf("Editing main Reservation:\n");
                Edit_Reserve(ID , Index );
          /////////////////////////////////////////////////////////
                exit_flag = 1;
                break;
          //********************************************* //
            case 6:
                printf("Exiting Edit Mode...\n");
                Clear_Screen();
                Admin_Menu();
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

//=Amir======================================================  Cancel a Reservation ============================================================
void Delete_Patient_Data(int PatientLocation)
{
    patients[PatientLocation].age = 0;
    patients[PatientLocation].patientID= 0;
    strcpy(patients[PatientLocation].gender, "");
    strcpy(patients[PatientLocation].name, "");
    patientCount--;
}

void Cancel_Reservation()
{

    int ID;
    int PatientLocation;
    int flag = 0 ;
    printf(" Enter Your ID .\n");
    fflush(stdin);
    scanf("%d", &ID);
    clear_input_buffer();
    PatientLocation = Search_Patient(ID);

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
                 Delete_Patient_Data (PatientLocation);
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
                        printf(" But your slot and data still recorded .\n");
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

//==Eslam============================================================Existing Patient ====================================================
void Existing_Patient()
{
  int ID ;
  int PatientLocation ;

  printf(" Enter Your ID .\n");
  fflush(stdin);
  scanf("%d",&ID);
  PatientLocation=Search_Patient(ID);//  PatientLocation=searchPatient(ID)-1;
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
    {   Clear_Screen();
        Choose_Slot(ID);
        patients[PatientLocation].consult_flag=1;
        printf("Consultation is for free!\n");
    }
  }
}
//============================================================== reserveing Slot ====================================================

void Choose_Slot(int ID )
{
    int day =0 , slot = 0 , counter =0 , flag =0  ;
    if(slotCount>=35)
     {
        printf(" NO slots available in this week ");
     }
    else
    {
        Print_All_Slots_Week();
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
                fflush(stdin);
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
                    fflush(stdin);
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
                        if(patients[Search_Patient(ID)].consult_flag==1)
                        {
                          int bookFlag=0;
                        for(int day0 = 0 ; day0< DAYS_IN_WEEK;day0++)
                            {
                                for(int slot0=0 ; slot0 < SLOTS_PER_DAY ;slot0++ )
                                {
                                    if (bookFlag==1) continue;
                                    if(busySlots[day0][slot0]==busySlots[day-1][slot-1])
                                    {
                                        if(day-1>day0)
                                        // if((day-1>day0)||(day-1==day0&&slot-1>slot0)||!((day-1==day0&&slot-1==slot0)))
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

int Check_ID_Available(int ID)
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
//============================================================== edit Reserve =============================================================
void Edit_Reserve(int ID, int Index)
 {
      for (int i = 0; i < DAYS_IN_WEEK; i++)
          {
                 for (int j = 0; j < SLOTS_PER_DAY; j++)
            {

          if (busySlots[i][j]==ID)
         {  
            Clear_Screen();
            Choose_Slot(ID);
             availableSlots[i][j]=1;
             busySlots[i][j]=0;
             slotCount--;
             ////////////////////////
             printf("Patient details....\n");
             Print_Patient_Data(Index);
             printf("Reservation has  changed....\n");
             break;
         }
           }

          }

 }
//============================================================== choose emergency =============================================================
void Choose_Emergency_Slot(int ID )
{
    int day =0 , slot = 0 , counter =0 , flag =0  ;
    if(EmergencyCount>=MAX_EMERGENCY)
     {
        printf(" NO slots available in this week ");
     }
    else
    {
        Print_All_Emergency_Slots_Week();
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
                fflush(stdin);
                scanf("%d",&day);
                if (day < 1 || day > 7)
                {
                    printf("Invalid day! Please choose between 1 and 7.\n");
                    continue;
                }
                ////////////////////////////////////////////////////////////
                counter=0;
                printf(" Empty slots : \n");
                if(EmergincySlots[day-1][0]==0)
                                {printf(" 1- 6:00 to 6:30   \n");counter++;}
                if(EmergincySlots[day-1][1]==0)
                                {printf(" 2- 6:30 to 7:00   \n");counter++;}
                /////////////////////////////////////////////////////////////
                if (counter==0)
                    printf(" NO empty slots in this day \n please chooe another day");
                else
                {
                    printf(" choose one of these %i slots ",counter);
                    fflush(stdin);
                    scanf("%d",&slot);
                    if(slot>2||slot<1||EmergincySlots[day-1][slot-1] != 0)
                    {
                        printf("invalid slot\n");
                    }
                    else
                    {
                        EmergincySlots[day-1][slot-1]=ID;
                        EmergencyCount++;
                        flag=1;
                    }
                }
        }while(flag==0);
    }
} 



void Emergency_Patient()
{
    if(EmergencyCount<MAX_EMERGENCY)
    {
        int index=First_Empty_Index();

         printf("Entering new patient data:\n");

         printf("Enter name:\n");
         getchar();
         fgets(patients[index].name,50,stdin);

         printf("Enter age:\n");
         fflush(stdin);
         scanf("%i",&patients[index].age);

         printf("Enter gender:\n");
         getchar();
         fgets(patients[index].gender,10,stdin);

         int id;
         int flag = 0 ;
         do
         {
            printf("* Note that: \n1-ID must contain 4 numbers not started whith 0 \n 2-ID must be unique \n");
            printf(" Enter ID:\n");
            fflush(stdin);
            scanf("%i",&id);
            if(Check_ID_Available(id)==1)
            {

                printf("Did user pay %i $?:\nif Yes, Enter 1 \n if No, press any thing else \n",price);
                int cost_flag=0;
              fflush(stdin);
              scanf("%i",&cost_flag);
              if(cost_flag==1)
              {
               printf("User paid %i $!!\n",price);
               patients[index].patientID=id;
               Choose_Slot(id);
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

//============================================================== choose emergency =============================================================
void Money_safe_view()
{
    printf("Total money in safe is:%d\n",patientCount*price);
}
//============================================================== choose emergency =============================================================

void Input_Valid_Age(int index)
{
    int valid_input;
    do
    {
        valid_input = scanf("%d", &patients[index].age);

        if (valid_input != 1 || patients[index].age <= 0||patients[index].age>120) 
        {
            printf("Invalid input. Please enter a valid age (positive number smaller than 120 ).\n");
            clear_input_buffer();
        }
    } while (valid_input != 1 || patients[index].age <= 0||patients[index].age>120); 
}
//============================================================== choose emergency =============================================================
void clear_input_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
//============================================================== Valid_String =============================================================
 
int Valid_String(const char* str)
{
    int lnth = strlen(str);
    for (int i = 0; i < lnth; i++)
    {
        if (!isalpha(str[i]) && str[i] != ' ')
        {
            return 0;
        }
    }
    return 1;
}
//============================================================== Valid_String =============================================================
void Clear_Screen() 
{
    system("clear");
}

//============================================================== input_valid_Name =============================================================
void Input_Valid_Name(int index)
{
    while (1)
    {
        fflush(stdin);
        printf("Enter name:\n");
        fgets(patients[index].name, 50, stdin);
        patients[index].name[strcspn(patients[index].name, "\n")] = 0;

        if (strlen(patients[index].name) == 0)
        {
            printf("Error: Name cannot be empty.\n");
            continue;
        }

        if (Valid_String(patients[index].name))
        {
            break;
        }
        printf("Error: Name must contain only letters and spaces.\n");
    }
}
//============================================================== input_valid_Name =============================================================
void Input_Valid_Gander(int index)
{
    while (1) {
        printf("Enter gender (male/female):\n");
        fflush(stdin);
        fgets(patients[index].gender, sizeof(patients[index].gender), stdin);
        patients[index].gender[strcspn(patients[index].gender, "\n")] = 0; // Remove newline

        if (strcmp(patients[index].gender, "Female") == 0 ||strcmp(patients[index].gender, "Male") == 0 ||strcmp(patients[index].gender, "male") == 0 || strcmp(patients[index].gender, "female") == 0) {
            break;
        }

        printf("Error: Gender must be exactly 'Male','male' or 'Female','female'.\n");
    }
}

//============================================================== input_valid_Name =============================================================
