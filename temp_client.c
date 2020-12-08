//Work in progress - Jazz
#include <stdio.h>
#include <string.h>
#include "server_window.c"


int main(void) {
    char user_type;
    
    puts("Welcome to our server!");
    printf("Are you an Admin or User? ");
    scanf("%s", &user_type);
    
    if (user_type == "User" || user_type == "user"){
        int user_ID;
        char pwd[30];
        printf("Enter your account ID number: ");
        scanf("%d", &user_ID);
        printf("Enter your password: ");
        scanf("%s", pwd);
    
        server(user_ID, pwd);
    }
    
    if (user_type=="Admin" || user_type=="admin") {
        //char pwd[30];
        
        admin();
    }
}
