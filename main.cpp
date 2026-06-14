#include<iostream>
#include "BusSystem.h"
#include "Passenger.h"
#include "Admin.h"
int main(){
    BusSystem system;
    Passenger passenger(system);
    Admin admin(system);
    int choice;
do{
    cout << "========= SKYLINE MANAGEMENT SYSTEM =========" << endl;
    cout << "Press 1 for Passenger Panel..." << endl;
    cout << "Press 2 for Admin Panel...." << endl;
    cout << "Enter your choice:" << endl;
    cin  >> choice;
    switch(choice){
        case 1:
          passenger.Passengermenu();
           break;
        case 2:
           admin.Adminmenu();
             break;
        default:
          cout << "Invalid Input >> Try again..." << endl;        
    }
}  while(choice!=2);
 return 0;  
}