#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct 
{
    char name[30];
    char pass[30];

    union  userState
    {
        int active;
        bool isActive;
    }state;

} userData;

userData singleUser[60];
int count = 0;
// ----------------------
bool checkBooleanInput(const char *input)
{
    if (strcmp(input, "true") == 0 || strcmp(input, "1") == 0)
    {
        return true;
    }
    else if (strcmp(input, "false") == 0 || strcmp(input, "0") == 0)
    {
        return false;
    }
    else
    {
        return false;
    }
}

// register
void registery()
{
    userData regisitUser;
    printf("Enter your username:  ");
    scanf("%s", regisitUser.name);

    printf("Enter your password:  ");
    scanf("%s", regisitUser.pass);

    char input[10];
    printf("Enter status (true or 1 for active, false or 0 for inactive): ");
    scanf("%s", input);

    regisitUser.state.isActive = checkBooleanInput(input);
    singleUser[count] = regisitUser;

    count++;
}
// login
int login()
{
    char username[50];
    char userPass[50];

    strcpy(singleUser[0].name, "yasmeen");
    strcpy(singleUser[0].pass, "123");
    singleUser[0].state.active = 1;

    strcpy(singleUser[1].name, "ahmed");
    strcpy(singleUser[1].pass, "150");
    singleUser[1].state.isActive = false;

    printf("Enter userName : ");
    scanf("%s", username);

    printf("Enter password : ");
    scanf("%s", userPass);

    for (int i = 0; i < count; i++)
    {
        if (strcmp(username, singleUser[i].name) == 0 && strcmp(userPass, singleUser[i].pass) == 0)
        {
            if (singleUser[i].state.active == 1 || singleUser[i].state.isActive == true)
            {
                printf("Login done successfully!\n");
                return 1;
            }
            else
            {
                printf("Sorry You Are Not Active!\n");
                return 0;
            }
        }
    }
    printf("Invalid userName or password.\n");
    return 0;
}

int main()
{
    int chooseNum;
    char userName[30];
    char password[30];

    while (1)
    {
        printf("choose service: 1-> register  2-> login   ");
        scanf("%i",&chooseNum);
        switch (chooseNum){
            case 1:
                registery();
                break;

            case 2:
                login();
                break;
            default:
                printf("Invalid choose number,try again.\n");
        }

    }
    
    
        

    return 0;
}