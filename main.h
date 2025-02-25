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
void Home_Menu();//Team ========================= works well
void Admin_Login();//Omar&Eslam ========================= works well
void Admin_Menu();//Team ========================= works well
void Edit_Patient_Record();//Mohamed
void Reserve_Slot();//Eslam&omar
void Delete_Patient_Data(int PatientLocation);//Amir
void Cancel_Reservation();//Amir
void New_Patient();//omar ==================================== works well
void Choose_Slot(int ID);//Eslam
void Edit_Reserve(int ID , int Index );//mohamed
void Existing_Patient();//Eslam
void Emergency_Patient();
void Choose_Emergency_Slot(int ID );
//==========================check============================================
// void Check_gender_Available();//Eslam========================= works well
int Search_Patient(int patientID);//mohamed ========================= works well
int Check_Patient_researve(int patientID);//Amir
int Check_ID_Available(int ID);//Eslam========================= works well
int First_Empty_Index();//omar========================= works well
//==========================User============================================
void User_Mood();//Team========================= works well
void View_Patient_Data();//rawda ============================ works well
void view_Day_Reservations();//rawda ========================= works well
void Print_All_Emergency_Slots_Week();
void Print_Patient_Data(int ID);//Rawda========================= works well
void Print_All_Slots_Week();//eslam
