#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Name:ABD ElHAKEEM Said Fathy Attallah Groub:2
union State{
	char isActive[5];
}; 
struct User{
    char userName[50],Email[50],Password[50];
   union State s;
    
};


struct User users[10];
int index = 0;

struct User Register(){
    struct User user;
    printf("Enter User Name: ");
    scanf("%s",&user.userName);

    printf("Enter Email: ");
    scanf("%s",&user.Email);

    printf("Enter Password: ");
    scanf("%s",&user.Password);
	
	printf("Enter Profile State: ");
    scanf("%s",&user.s.isActive);
    return user;
}


int Login(char _userName[],char _password[]){
    int j;
    for(j = 0;j <= index;j++){
        if((strcmp(users[j].userName,_userName) == 0  && strcmp(users[j].Password,_password) == 0)){
			if(strcmp(users[j].s.isActive,"true") == 0 ||(strcmp(users[j].s.isActive,"1") == 0 )){
		
            return 1;	}
    }
	}
    return 0;
}

int main()
{
    do{
        printf("Please Enter \n1- Register\n2- Login\n3- Exit\n--------------------\n");
        int i;
        scanf("%d",&i);

        if(i == 1){
            struct User user;
            user = Register();
            users[index++] = user;
            printf("Register success\n");
        }else if(i == 2){
            char _userName[50],_password[50];
            printf("Enter User Name: ");
            scanf("%s",&_userName);

            printf("Enter Password: ");
            scanf("%s",&_password);
            
            int check = Login(_userName,_password);
            if(check == (int)1){
			
			
                printf("Login Success\n Hello %s \n",_userName);
            }
            else{
		
                printf("Wrong Username or Password \n");
			}
        }else if(i == 3){
            return 0;
        }else{
            printf(" Value\n");
        }
        printf("--------------------\n");
    }while(1 == 1);
    return 0;
}
