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
