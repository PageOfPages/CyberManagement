//WIP - Jazz
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int server(int user_ID, char pwd[30])
{
    FILE *infile;

    if ((infile = fopen("clients.txt", "r")) == NULL) {
        puts("File could not be accessed");
    }
    else 
    {
        int ID;
        char password[30];
        char first[30];
        char last[30];
        double credit;
        int user_found = 0;
        double time=0;

        fscanf(infile,"%d%29s%29s%29s%lf", &ID, first, last, password, &credit);

        while(!feof(infile) ){
            if (ID == user_ID & (strcmp(password, pwd) == 0)) {
                user_found = 1;
                if (credit == 0) {
                    printf("Sorry, %s %s! You have no credit remaining in your account.\n", first, last);
                }
                else {
                    printf("\nHello, %s %s! You are now in the system.\n", first, last);
                    printf("Your Current Credit is $%.2f\n", credit);
                    time = credit/5;
                    printf("You have %.1f hours on the system.\n", time);
                }
            }
            fscanf(infile,"%d%29s%29s%29s%lf", &ID, first, last, password, &credit);
        }
        if (user_found == 0) {
            puts("Sorry, your ID/password is incorrect or you do not have an account with us, try again.");
        }
        fclose(infile); 
    }
}

int user_count();
int credit_check();
//int add_user();
//int remove_user();

int admin(char apwd[30]) {
    if (strcmp(apwd, "password")!=0) {
        puts("Sorry, wrong password! Restart system to login as administrator");
    }
    
    else {
        char action=' ';
    
        puts("Actions: \nUser count = 'u'\nCredit for user = 'c'\nAdd user = 'a'\nRemove user = 'r'\nExit = 'x'");
    
        while (action != 'x') {
            printf("What action would you like to perform: ");
            scanf("%s", &action);
            action = tolower(action);
            switch(action) {
                case 'u':
                    user_count();
                    break;
                case 'c':
                    credit_check();
                    break;
                case 'a':
                    puts("incomplete data");
                    break;
                case 'r':
                    puts("incomplete data");
                    break;
                case 'x':
                    break;
                default:
                    puts("Invalid input.");
                    break;
            }
        }
        puts("Thank you for using our system today! Goodbye.");
    }
}

int user_count() {
    FILE *infile;
    int count = 0;
    char c;

    if ((infile = fopen("clients.txt", "r")) == NULL) {
        puts("File could not be accessed");
    }
    else {
        for (c=getc(infile); c != EOF; c=getc(infile)) {
            if (c=='\n')
                count += 1;
        }
    }
    
    fclose(infile);
    printf("There are %d users in the system.\n", count);
}

int credit_check() {
    FILE *infile;
    int count = 0;
    char c;

    if ((infile = fopen("clients.txt", "r")) == NULL) {
        puts("File could not be accessed");
    }
    else {
        int ID;
        char password[30];
        char first[30];
        char last[30];
        double credit;
        int user;

        fscanf(infile,"%d%29s%29s%29s%lf", &ID, first, last, password, &credit);
 
        printf("Please enter ID to check credit amount: ");
        scanf("%d", &user);
        while(!feof(infile) ){
            if (ID == user) {
                printf("User %d has the remaining credit: $%.2f\n", ID, credit);
                break;
            }
            else {
                printf("No user found with ID %d.\n", user);
                break;
            }
        }
        fclose(infile);
    }
}

int add_user() {
    FILE *infile;
    
    if ((infile = fopen("clients.txt", "a")) == NULL) {
        puts("File could not be accessed");
    }
    else {
        int ID;
        char password[30];
        char first[30];
        char last[30];
        double credit;
        int user;

        fscanf(infile,"%d%29s%29s%29s%lf", &ID, first, last, password, &credit);
        
        printf("Enter the User ID, First name, Last name, Password, and starting credit for the account you would like to create: ");
        scanf("%d%s%s%s%lf", &ID, first, last, password, &credit);
        
        fprintf(infile, "%d %s %s %s %.2lf\n", ID, first, last, password, credit);
    }
    fclose(infile);
    puts("Welcome to our server!");

/*
int remove_user() {
    FILE *infile;
    
    if ((infile = fopen("clients.txt", "r+")) == NULL) {
        puts("File could not be accessed");
    }
    else {
        int ID;
        char password[30];
        char first[30];
        char last[30];
        double credit;
        int user;

        fscanf(infile,"%d%29s%29s%29s%lf", &ID, first, last, password, &credit);
        
        printf("Enter a user ID to remove: ");
        scanf("%d", &user);
        
        while(!feof(infile) ){
            if (ID == user) {
                
            }
    }
    fclose(infile);
}

*/ 
