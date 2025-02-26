//===================== Library =======================================================
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>

//===================== Pre_Defined Macros =======================================================
#define MAX_PATIENTS 35
#define MAX_EMERGENCY 14
#define MAX_SLOTS 35
#define DAYS_IN_WEEK 7
#define SLOTS_PER_DAY 5
#define Emergency_SLOTS_PER_DAY 2
#define price 200



//===================== Structs=======================================================

// Structure to store patient details
typedef struct patient_data
{
    char name[50];
    int age;
    char gender[10];
    int patientID;
    char consult_flag ;

} Patient;


//==========================Global arrays============================================
Patient patients[MAX_PATIENTS];
int availableSlots[DAYS_IN_WEEK][SLOTS_PER_DAY] = { {1,1,1,1,1},
                                                    {1,1,1,1,1},
                                                    {1,1,1,1,1},
                                                    {1,1,1,1,1},
                                                    {1,1,1,1,1},
                                                    {1,1,1,1,1},
                                                    {1,1,1,1,1} }; // 1 ->avilable | 0-> busy
int busySlots[DAYS_IN_WEEK][SLOTS_PER_DAY] ;      // 0000-> avilable | ID -> busy
int EmergincySlots[DAYS_IN_WEEK][Emergency_SLOTS_PER_DAY] ;      // 0000-> avilable | ID -> busy
//==========================Global variables============================================
int patientCount = 0;
int slotCount = 0;
int EmergencyCount=0;
//==========================Functions Declrations============================================
void Wellcome();
void Home_Menu();
void Admin_Login();
void Admin_Menu();
void Edit_Patient_Record();
void Reserve_Slot();
void Delete_Patient_Data(int PatientLocation);
void Cancel_Reservation();
void New_Patient();
void Choose_Slot(int ID);
void Edit_Reserve(int ID , int Index );
void Existing_Patient();
void Emergency_Patient();
void Choose_Emergency_Slot(int ID );
void Money_safe_view();
//==========================check============================================
void Input_Valid_Age(int index);
void Input_Valid_Name(int index);
void Input_Valid_Gander(int index);
void clear_input_buffer();
int Search_Patient(int patientID);
int Check_ID_Available(int ID);
int First_Empty_Index();
int Valid_String(const char* str);
void input_valid_check(int check);
void Clear_Screen();

//==========================User============================================
void User_Mood();
void View_Patient_Data();
void view_Day_Reservations();
void Print_All_Emergency_Slots_Week();
void Print_Patient_Data(int ID);
void Print_All_Slots_Week();
