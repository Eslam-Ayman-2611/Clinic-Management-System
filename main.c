#include"User.c"

int main()
{ 
    char flag = '1';
    while (flag != '0') 
    {
        Wellcome();
        Home_Menu();
        printf("\nIf you want to close the program, Enter 0. Otherwise, enter anything else: ");
        scanf(" %c", &flag); 
    }
    return 0;
}
