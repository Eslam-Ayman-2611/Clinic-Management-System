#include"Admin.c"
//==Eslam====================================================== User mood  ============================================================
void User_Mood()
{

    int choice;
    do
    {
        printf("\n User  Menu\n");
        printf("1. view Patient Record \n");
        printf("2. view Reservations in day  \n");
        printf("3. view all Reservations in week \n");
        printf("4. view all Emergency slots in week \n");
        printf("5. Logout\n");

        printf("Enter your choice: ");
        fflush(stdin);
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: View_Patient_Data(); break;
            case 2: view_Day_Reservations(); break;
            case 3: Print_All_Slots_Week(); break;
            case 4: Print_All_Emergency_Slots_Week(); break;
            case 5: printf("Logging out...\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while(choice != 4);

}
//==Rawda====================================================== View_Patient_Data ============================================================
void View_Patient_Data()
{

    int patientID;
    printf("PLEASE ENTER YOUR ID: \n");
    fflush(stdin);
    scanf("%d",&patientID);

        int ID = Search_Patient(patientID);
        if (ID  == -1)
        {
            printf(" There is no any patient with this ID\n");
        }
        else
        {
            printf("The Basic Information Of The Patient`s IS : \n");
            Print_Patient_Data(ID);

        }
}
//==Rawda====================================================== View Patient Record ============================================================
void view_Day_Reservations()
{
    int day;
    printf("Enter the day number : \n1 for Sat. \n2 for Sun. \n3 for Mon. \n4  for Tues.\n5 for Wed. \n6  for Thu. \n7 for Fri.): ");
    fflush(stdin);
    scanf("%d", &day);
    day--; 

    if (day < 0 || day > 6) 
        printf("Invalid day!\n");
    else   
          {  printf("Today's Reservations with patints ID and Time Slot :\n");
             printf("\nReservations for Day %d:\n", day + 1);
             printf("-------------------------------------------------\n");
             printf("|       Time Slot        |     Patient ID       |\n");
             printf("-------------------------------------------------\n"); 
        
             

            int flag = 0;  //<There is no Reservation if flag =0 >  < flag=1 Reservation >

  
        for (int slot = 0; slot < SLOTS_PER_DAY; slot++)
        {
            if (busySlots[day][slot] != 0) //<There is Reservation in Day>
                {
                    flag = 1;
                    printf("| ");
                    switch (slot)
                    {
                         case 0:  printf("Time: from 2:00 to 2:30  \t"); break;
                         case 1:  printf("Time: from 2:30 to 3:00  \t"); break;
                         case 2:  printf("Time: from 3:00 to 3:30  \t"); break;
                         case 3:  printf("Time: from 4:00 to 4:30  \t"); break;
                         case 4:  printf("Time: from 4:30 to 5:00  \t"); break;
                    }
                        printf("|        %d        |\n", busySlots[day][slot]);
                 }
        }
      if(!flag )
      {
                       printf("|     No reservations for today.               |\n");
        }
                       printf("-------------------------------------------------\n");
    }
}

//============================================================== Print_All_Emergency_Slots_Week =============================================================
void Print_All_Emergency_Slots_Week()
{
   printf("\n========================================================================================================================================\n");
   printf("\n|                                                             Emergency slots                                                           |\n");
   printf("\n========================================================================================================================================\n");
   printf("| Slot / Day     |     Saturday   |     Sunday     |     Monday     |    Tuesday     |    Wednesday   |     Thursday   | Friday         |\n");
   printf("|----------------|----------------|----------------|----------------|----------------|----------------|----------------|----------------|\n");
   const char timeSlots[2][13] = {"6:00 to 6:30", "6:30 to 7:00"};
   const char *str = NULL;
   for(int slot = 0 ; slot < Emergency_SLOTS_PER_DAY ; slot++ ) {

    printf("  %-14s|\n", str ? str : "(null)");
       for (int day = 0; day < 7 ; day++ ) 
       {
           if(busySlots[slot][day])
           printf(" %-14i |", EmergincySlots[slot][day]);
           else 
           {
            printf("  %-14s|\n", str ? str : "(null)");
           }


       }
       printf("\n|----------------|----------------|----------------|----------------|----------------|----------------|----------------|----------------|\n");
   }
}
//============================================================== print patient data ====================================================
void Print_Patient_Data(ID)
{
    printf("\n----------------------------------------\n");
    printf("| Details           | Value            |\n");
    printf("----------------------------------------\n");
    printf("| ID               | %d              |\n", patients[ID].patientID);
    printf("| Name             | %-15s |\n", patients[ID].name);
    printf("| Age              | %d              |\n", patients[ID].age);
    printf("| Gender           | %-10s     |\n", patients[ID].gender);
    // printf("| Consultation     | %-10s     ", (patients[ID].consult_flag == 1) );
        if(patients[ID].consult_flag)
        printf(" %-10i |\n", patients[ID].consult_flag);
        else 
        {
            const char *str = NULL;
            printf("  %-14s|\n", str ? str : "(null)");
        }

    printf("----------------------------------------\n");
}
//============================================================== Print_All_Slots_Week =============================================================
void Print_All_Slots_Week()
{
   printf("\n========================================================================================================================================\n");
   printf("\n|                                                             Weekly slots                                                             |\n");
   printf("\n========================================================================================================================================\n");
   printf("| Slot / Day     |     Saturday   |     Sunday     |     Monday     |    Tuesday     |    Wednesday   |     Thursday   | Friday         |\n");
   printf("|----------------|----------------|----------------|----------------|----------------|----------------|----------------|----------------|\n");
   const char timeSlots[5][13] = {"2:00 to 2:30", "2:30 to 3:00", "3:00 to 3:30", "4:00 to 4:30", "4:30 to 5:00"};
   
   for(int slot = 0 ; slot < 5 ; slot++ ) {
       printf("| %-14s |", timeSlots[slot]);
       for (int day = 0; day < 7 ; day++ ) 
       {
           if(busySlots[slot][day])
           printf(" %-14i |", busySlots[slot][day]);
           else 
           {
               const char *str = NULL;
               printf("  %-14s|\n", str ? str : "(null)");
           }


       }
       printf("\n|----------------|----------------|----------------|----------------|----------------|----------------|----------------|----------------|\n");
   }
}
