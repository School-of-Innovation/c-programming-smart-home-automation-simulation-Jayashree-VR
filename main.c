/*SAMPLE OUTPUT

Enter number of rooms: 3
Initializing system...

===== Smart Home Menu =====

Toggle Light
Read Temperature
Check Motion Sensor
Lock/Unlock Security System
House Status Summary
Exit
Enter your choice: 1
Enter room number to toggle light (1-3): 2
Light in Room 2 is now ON.
Enter your choice: 5
House Status:

Room 1: Light OFF, Temp 22°C, No Motion, Locked
Room 2: Light ON, Temp 25°C, Motion Detected, Locked
Room 3: Light OFF, Temp 24°C, No Motion, Unlocked
Enter your choice: 6
Exiting...*/
 
 
 
 #include <stdio.h>
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
    initializeSystem(room);
    displayMenu();
    

    while(1){
        scanf("Enter your choice: %d",&choice);
        switch (choice)
        {
        case 1:
            controlLights();
            break;

        case 2:
            readTemperature();
            break;
        case 3:
            detectMotion();
            break;

        case 4:
            securitySystem();
            break;

        case 5:
            analyzeHouseStatus();
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
 
  
 void initializeSystem() {
    printf("Initializing Smart Home");
   
 }
 
 void displayMenu() {
    printf("=====SMART HOME MENU=====");
    printf("1. Toggle Light \n 2. Read Temperature \n 3. Check Motion Sensor  \n 4. Lock \ Unlock Security System \n 5. Home Status Summary  \n 6. Exit");
    
 }
 void controlLights() {
 
 }
 void readTemperature() {
 
 }
 void detectMotion() {
 
 }
 void securitySystem() {
 
 }
 void analyzeHouseStatus() {
 
 }
