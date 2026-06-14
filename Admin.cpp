#include <iostream>
#include "Admin.h"
using namespace std;
Admin::Admin(BusSystem &system):system(system){}
void Admin::Adminmenu(){
    int choice;
do{
   cout << "========= SKYLINE ADMIN PANEL==========" << endl;
   cout << "press 1 to view all Buses" << endl;
   cout << "Press 2 to Add Bus" << endl;
   cout << "Press 3 to Update Bus" << endl;
   cout << "Press 4 to Delete Bus" << endl;
   cout << "Press 5 to view all fares" << endl;
   cout << "Press 6 to view Booked seats" << endl;
   cout << "Press 7 for Exiting..." << endl;
   cout << "Enter your choice:" << endl;
   cin >> choice;
  try{
    switch(choice){
        case 1:
          system.viewallbuses();
           break;
        case 2:{
          int busno;
          string route,timing,busname;
        cout << "Enter Bus number:"<< endl;
        cin  >> busno;
        cin.ignore();
        cout << "Enter Bus Name:" << endl;
        getline(cin, busname);
        cout << "Enter Route:" << endl;
        getline(cin, route);
        cout << "Enter Timings:" << endl;
        getline(cin , timing);
        system.addbus(busno , busname, route, timing);
          break;  
        }  
        case 3:{
           int busno;
          string route,timing,busname;
        cout << "Enter Bus number:"<< endl;
        cin  >> busno;
        cin.ignore();
        cout << "Enter Bus Name:" << endl;
        getline(cin, busname);
        cout << "Enter Route:" << endl;
        getline(cin, route);
        cout << "Enter Timings:" << endl;
        getline(cin , timing);
        system.updatebus(busno, busname, route, timing);
         break;
        } 
        case 4:{
          int busno;
        cout << "Enter Bus Number to Delete:" << endl;
        cin  >> busno;
        system.deletebus(busno);
         break;  
        }
        case 5:
          system.viewfares();
            break;
        case 6:{
            int busno;
         cout << "Enter Bus Number:" << endl;
         cin  >> busno;
           system.viewbookedseats(busno);
             break;   
        }
        case 7:
          cout << "Thanks!! Exiting....." << endl;
            break;
        default:
          cout << "Invalid Input...." << endl;          

    }
  }
   catch(const char*error){
     cout << "Error:" << error << endl;
   }
}  while(choice!=7);  
}
