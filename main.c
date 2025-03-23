#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX_ROOMS 5  //  max number of rooms
 
 // Function prototypes
 void initializeSystem();
 void displayMenu();
 void controlLights();
 void readTemperature();
 void detectMotion();
 void securitySystem();
 void analyzeHouseStatus();
 
 int main() {
    int room, choice;
    printf("Enter the no of rooms:%d");
    scanf("%d",&room);
    int arr[4][room];
    int l=24;
    int h=35;
    for(int i=0;i<4;i++){
        for(int j=0;j<room;j++){
            if(i=0){
                arr[i][j]=0;
            }
            else if (i=2){
                arr[i][j]=(rand()%(h-l+1))+l;
            }
            else if(i=3){
                arr[i][j]=0;
            }
            else{
                arr[i][j]=1;
            }
        }
    }
    int arr_cpy[4][room];
    memcpy(arr_cpy,arr,sizeof(arr));
    initializeSystem(room,arr[4][room]);
    displayMenu();
    while(1){
        printf("Enter your choice: %d");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            controlLights(room,arr[4][room]);
            break;

        case 2:
            readTemperature(room,arr[4][room]);
            break;
        case 3:
            detectMotion(room, arr[4][room], arr_cpy[4][room]);
            break;

        case 4:
            securitySystem(room, arr[4][room]);
            break;

        case 5:
            analyzeHouseStatus(room, arr[4][room]);
            break;

        case 6:
            printf("Exiting ......");
            return 0;
        
        default:
            printf("Enter a valid choice");
            break;
        }

    }
    return 0;
 }
 
  
 void initializeSystem(int room,int arr[4][room]) {
    printf("Initializing Smart Home");
 }
 
 void displayMenu() {
    printf("=====SMART HOME MENU=====");
    printf("1. Toggle Light \n 2. Read Temperature \n 3. Check Motion Sensor  \n 4. Lock \ Unlock Security System \n 5. Home Status Summary  \n 6. Exit");
    
 }
 void controlLights(int room,int arr[4][room]) {
    int r_light;
    printf("Enter the Room number to toggle Light(1-%d):",room);
    scanf("%d",&r_light);
    if (arr[0][r_light-1]==1){
        arr[0][r_light-1]=0;
        printf("Light in room %d is OFF now",r_light);
    }
    else{
        arr[0][r_light-1]=1;
        printf("Light in room %d is ON now",r_light);
    } 
 
 }
 void readTemperature(int room, int arr[4][room]) {
    int r_temp;
    printf("Enter the Room number to display the temperature(1-%d):",room);
    scanf("%d",&r_temp);
    printf("The temperature is %d C",arr[1][r_temp-1]);
    if(arr[1][r_temp-1]>30){
        printf("Warning! The room %d is above 30 C!!!",r_temp);
    }

 }
 void detectMotion(int room, int arr[4][room], int arr_cpy[4][room]) {
    int movement=0;
    for(int i=0;i<4;i+3){
        for(int j=0;j<room;j++){
            if(arr[i][j]!=arr_cpy[i][j]){
                printf("Movement detected in Room %d",j+1);
                arr_cpy[i][j]=arr[i][j];
            }
            else{
                movement=1;
            }
            
        }
    }
    if(movement=1){
        printf("No Movement detected in any room");
    }
 }
 void securitySystem(int room, int arr[4][room]) {
    int r_lock,lock_status;
    char option;
    printf("Which Room do you want to Lock or Unlock(1-%d):",room);
    scanf("%d",r_lock);
    lock_status=arr[3][r_lock];
    if(lock_status=0){
    printf("The door is unlocked do you want to lock it?(Y/N):");
    scanf("%c",&option);
    if(option=='Y'){
        arr[3][r_lock]=1;
    }
    }
    else{
        printf("The door is locked do you want to unlock it?(Y/N):");
    scanf("%c",&option);
    if(option=='Y'){
        arr[3][r_lock]=0;
    }
    }
 
 }

 void analyzeHouseStatus(int room, int arr[4][room]) {
    printf("House Status:\n");
        for(int j=0;j<room;j++){
            printf("Room %d : Light %s , Temp %dC, %s , %s ",j,arr[0][j], (arr[0][j] == 0) ? "OFF" : "On",arr[1][j],arr[2][j], (arr[2][j] == 0) ? "No Movement Detected" : "Movement Detected",arr[3][j], (arr[3][j] == 0) ? "Door Is Not Locked" : "Door Is Locked" );

        }
 }
