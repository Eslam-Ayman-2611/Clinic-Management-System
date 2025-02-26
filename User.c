#include"Admin.c"
//==Eslam====================================================== User mood  ============================================================
void User_Mood()
{
    system("clear");
    int choice;
    do
    {
        printf("\n User  Menu\n");
        printf("1. view Patient Data \n");
        printf("2. view Reservations in day  \n");
        printf("3. view all Reservations in week \n");
        printf("4. view all Emergency slots in week \n");
        printf("5. Back \n");

        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: Clear_Screen();View_Patient_Data(); break;
            case 2: Clear_Screen();view_Day_Reservations(); break;
            case 3: Clear_Screen();Print_All_Slots_Week(); break;
            case 4: Clear_Screen();Print_All_Emergency_Slots_Week(); break;
            case 5: Clear_Screen();printf("Logging out...\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while(choice != 5);

}
//==Rawda====================================================== View_Patient_Data ============================================================
void View_Patient_Data()
{
    int patientID;
    printf("PLEASE ENTER YOUR ID: \n");
    fflush(stdin);
    scanf("%d",&patientID);
    clear_input_buffer();

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
void view_Day_Reservations() {
    int day;

    printf("\n============================================\n");
    printf("         View Daily Reservations\n");
    printf("============================================\n");
    printf("Enter the day number:\n");
    printf("  1 - Saturday\n  2 - Sunday\n  3 - Monday\n  4 - Tuesday\n  5 - Wednesday\n  6 - Thursday\n  7 - Friday\n");
    printf("============================================\n");
    printf("Your choice: ");

    if (scanf("%d", &day) != 1) {
        printf("  Invalid input! Please enter a number between 1 and 7.\n");
        while (getchar() != '\n'); // Clear input buffer
        return;
    }
    
    while (getchar() != '\n'); // Clear input buffer after valid input
    day--; // Adjust for zero-based indexing

    if (day < 0 || day > 6) {
        printf("  Invalid day selection! Please enter a number between 1 and 7.\n");
        return;
    }

    printf("\n  Reservations for Day %d:\n", day + 1);
    printf("-------------------------------------------------\n");
    printf("|         Time Slot       |     Patient ID     |\n");
    printf("-------------------------------------------------\n");

    int flag = 0; // 0 = No reservations, 1 = Found reservations

    for (int slot = 0; slot < SLOTS_PER_DAY; slot++) {
        if (busySlots[day][slot] != 0) { // If there's a reservation
            flag = 1;
            printf("| ");
            switch (slot) {
                case 0:  printf(" 2:00 - 2:30 PM   "); break;
                case 1:  printf(" 2:30 - 3:00 PM   "); break;
                case 2:  printf(" 3:00 - 3:30 PM   "); break;
                case 3:  printf(" 4:00 - 4:30 PM   "); break;
                case 4:  printf(" 4:30 - 5:00 PM   "); break;
            }
            printf("|        %d        |\n", busySlots[day][slot]);
        }
    }

    if (!flag) {
        printf("|       No reservations for today.            |\n");
    }

    printf("-------------------------------------------------\n");
}

//============================================================== print patient data ====================================================
void Print_Patient_Data(int ID) 
{

    printf("\n----------------------------------------\n");
    printf("| %-18s | %-15s |\n", "Details", "Value");
    printf("----------------------------------------\n");
    printf("| %-18s | %-15d |\n", "ID", patients[ID].patientID);
    printf("| %-18s | %-15s |\n", "Name", patients[ID].name);
    printf("| %-18s | %-15d |\n", "Age", patients[ID].age);
    printf("| %-18s | %-15s |\n", "Gender", patients[ID].gender);

    if (patients[ID].consult_flag) {
        printf("| %-18s | %-15d |\n", "Consult Flag", patients[ID].consult_flag);
    } else {
        printf("| %-18s | %-15s |\n", "Consult Flag", "(not set)");
    }

    printf("----------------------------------------\n");
}
//============================================================== Print_All_Emergency_Slots_Week =============================================================
void Print_All_Emergency_Slots_Week(int EmergencySlots[Emergency_SLOTS_PER_DAY][7]) {
    printf("\n========================================================================================================================================\n");
    printf("\n|                                                             Emergency slots                                                           |\n");
    printf("\n========================================================================================================================================\n");
    printf("| Slot / Day     |     Saturday   |     Sunday     |     Monday     |    Tuesday     |    Wednesday   |     Thursday   |     Friday     |\n");
    printf("|----------------|----------------|----------------|----------------|----------------|----------------|----------------|----------------|\n");

    const char timeSlots[Emergency_SLOTS_PER_DAY][13] = {"6:00 to 6:30", "6:30 to 7:00"};

    for (int slot = 0; slot < 2; slot++) {
        printf("| %-14s |", timeSlots[slot]);
        for (int day = 0; day < 7; day++) {
            if (EmergencySlots[slot][day])
                printf(" %-14d |", EmergencySlots[slot][day]);  
            else 
                printf(" %-14s |", "Available");  
        }
        printf("\n|----------------|----------------|----------------|----------------|----------------|----------------|----------------|----------------|\n");
    }
}
//============================================================== Print_All_Slots_Week =============================================================
void Print_All_Slots_Week() {
    printf("\n========================================================================================================================================\n");
    printf("\n|                                                             Weekly slots                                                             |\n");
    printf("\n========================================================================================================================================\n");
    printf("| Slot / Day     |     Saturday   |     Sunday     |     Monday     |    Tuesday     |    Wednesday   |     Thursday   |     Friday     |\n");
    printf("|----------------|----------------|----------------|----------------|----------------|----------------|----------------|----------------|\n");

    const char timeSlots[5][13] = {"2:00 to 2:30", "2:30 to 3:00", "3:00 to 3:30", "4:00 to 4:30", "4:30 to 5:00"};
    
    for (int slot = 0; slot < 5; slot++) {
        printf("| %-14s |", timeSlots[slot]);
        for (int day = 0; day < 7; day++) {
            if (busySlots[day][slot]) 
            {
                printf(" %-14d |", busySlots[day][slot]);
            } 
            else 
            {  
                printf(" %-14s |", "Available");
            }
        }
        printf("\n|----------------|----------------|----------------|----------------|----------------|----------------|----------------|----------------|\n");
    }
}
