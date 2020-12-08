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
                    printf("Hello, %s %s! You are now in the system.\n", first, last);
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

int admin( ) {
    char action;
    
    puts("Actions: \nUser count = 'u'\nCredit for user = 'c'\nAdd user = 'a'\nRemove user = 'r'\nExit = 'x'");
        printf("What action would you like to perform: ");
        scanf("%s", &action);
        action = tolower(action);
        
        if (action=="u") {
            user_count();
        }
        
        if (action=="c") {
            puts("incomplete data");
        }
        
        if (action=="a") {
            puts("incomplete data");
        }
        
        if (action=="r") {
            puts("incomplete data");
        }
        
        if (action=="x") {
            puts("Thank you for using our system today! Goodbye.");
//           break;
        }
        
        else {
            puts("Incorrect input.");
//            break;
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
            if (c=="\n")
                count += 1;
    }
    
    fclose(infile);
    printf("There are %d users in the system.", count);
}
