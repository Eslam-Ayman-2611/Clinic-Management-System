//===================== Pre_Defined Macros =======================================================
#define MAX_PATIENTS 35
#define MAX_SLOTS 35
#define DAYS_IN_WEEK 7
#define SLOTS_PER_DAY 5

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
int availableSlots[DAYS_IN_WEEK][SLOTS_PER_DAY] = { {1} }; // 1 ->avilable | 0-> busy 
int busySlots[DAYS_IN_WEEK][SLOTS_PER_DAY] = { {0000} };      // 0000-> avilable | ID -> busy
//==========================Global variables============================================
int patientCount = 0;
int slotCount = 0;

//==========================Functions Declrations============================================
void Home_Menu();//Team
void adminLogin();//Omar&Eslam
void adminMenu();//Team
int searchPatientID(int patientID);//mohamed
void UserMood();//Team
void reserveSlot();//Eslam&omar
void editPatientRecord();//Mohamed
void cancelReservation();//Amir
void viewPatientRecord();//rawda
void viewReservations();//rawda
int checkpatientresearve(int patientID);//Amir
void NewPatient();//omar
void ExistingPatient();//Eslam
void reserveingSlot();//Wating....
int checkIDavailable(int ID);
