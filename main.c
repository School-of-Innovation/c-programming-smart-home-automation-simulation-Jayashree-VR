#include <stdio.h>
#include<string.h>

#define MAX_ROOMS 5;

 void initializeSystem(int room,int arr[4][room]);
 void displayMenu();
 void controlLights(int room,int arr[4][room]);
 void readTemperature(int room,int arr[4][room]);
 void detectMotion(int room,int arr[4][room],int arr_cpy[4][room]);
 void securitySystem(int room,int arr[4][room]);
 void analyzeHouseStatus(int room,int arr[4][room]);
 
 int main() {
    int room, choice;
    printf("Enter the no of rooms(Max-5 Rooms):");
    scanf(" %d",&room);
    int arr[4][room];
    for(int i=0;i<4;i++){
        for(int j=0;j<room;j++){
            if(i==0){
                arr[i][j]=0;
            }
            else if (i==1){
                arr[i][j]=(i+3)*j*10;
            }
            else if(i==2){
                arr[i][j]=0;
            }
            else{
                arr[i][j]=0;
            }
        }
    }
    initializeSystem(room,arr);
    displayMenu();
    int arr_cpy[4][room];
    memcpy(arr_cpy,arr,sizeof(int)*4*room);
    while(1){
        printf("\n\nEnter your choice: ");
        scanf(" %d",&choice);
        switch (choice)
        {
        case 1:
            controlLights(room,arr);
            break;

        case 2:
            readTemperature(room,arr);
            break;
        case 3:
            detectMotion(room,arr,arr_cpy);
            break;

        case 4:
            securitySystem(room,arr);
            break;

        case 5:
            analyzeHouseStatus(room,arr);
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
    printf("Initializing Smart Home \n");
 }
 
 void displayMenu() {
    printf("=====SMART HOME MENU===== \n");
    printf("1. Toggle Light \n");
    printf("2. Read Temperature \n");
    printf("3. Check Motion Sensor \n");
    printf("4. Lock or Unlock Security System \n");
    printf("5. Home Status Summary \n");
    printf("6. Exit \n\n");
    
 }
 void controlLights(int room,int arr[4][room]) {
    int r_light;
    printf("Enter the Room number to toggle Light(1-%d):",room);
    scanf(" %d",&r_light);
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
    scanf(" %d",&r_temp);
    printf("The temperature is %dC \n",arr[1][r_temp-1]);
    if(arr[1][r_temp-1]>30){
        printf("Warning! The room %d is %dC !!!",r_temp,arr[1][r_temp-1]);
    }

 }
 void detectMotion(int room, int arr[4][room], int arr_cpy[4][room]) {
    int movement=0;
        for(int j=0;j<room;j++){
            if(arr_cpy[0][j]!=arr[0][j]){
                printf("Movement detected in Room %d \n",j+1);
                arr[2][j]=1;
                movement++;
                arr_cpy[0][j]=arr[0][j];
            }   
            if(arr_cpy[3][j]!=arr[3][j]){
                printf("Movement detected in Room %d \n",j+1);
                arr[2][j]=1;
                movement++;
                arr_cpy[3][j]=arr[3][j];

            }   
        }
    if(movement==0){
        printf("No Movement detected in any room");
    }
 }
 void securitySystem(int room, int arr[4][room]) {
    int r_lock,lock_status;
    printf("Which Room do you want to Lock or Unlock(1-%d):",room);
    scanf(" %d",&r_lock);
    lock_status=arr[3][r_lock-1];
    if(lock_status==0){
        arr[3][r_lock]=1;
        printf("The door of room %d is locked.",r_lock);
    }
    else{
        arr[3][r_lock]=0;
        printf("The door of room %d is Unlocked.",r_lock);
        }

 
 }

 void analyzeHouseStatus(int room, int arr[4][room]) {
    printf("House Status:\n");
        for(int j=0;j<room;j++){
            printf("Room %d : Light %s, Temp %dC, %s, %s\n", j + 1,
            (arr[0][j] == 0) ? "OFF" : "ON",
            arr[1][j],
            (arr[2][j] == 0) ? "No Movement Detected" : "Movement Detected",
            (arr[3][j] == 0) ? "Door Is Not Locked" : "Door Is Locked");

        }
 }
