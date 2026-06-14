#include "Passenger.h"
#include <iostream>
using namespace std;
Passenger::Passenger(BusSystem &system):system(system){}
void Passenger::Passengermenu(){
    int choice;
 do{
    cout << "========= SKYLINE PASSENGER PANEL ===========" << endl;
    cout << "press 1 to view Routes and timings" << endl;
    cout << "press 2 for view current Fares" << endl;
    cout << "press 3 to book a seat" << endl;
    cout << "press 4 to cancel a seat" << endl;
    cout << "Press 5 to View Avalible Seats" << endl;
    cout << "press 6 for exit" << endl;
    cout << "Enter your choice:" << endl;
    cin  >> choice;
    switch(choice){
        case 1:    
          system.viewallbuses();
           break;
        case 2:
           system.viewfares();
            break;
        case 3:{
          int busno , seatno , age;
          string name;
           cout << "Enter Bus Number:" << endl;
           cin  >> busno;
           cout << "Enter Seat Number:" << endl;
           cin  >> seatno;
           cout << "Enter your Age:" << endl;
           cin  >> age;
           cout << "Enter Passenger Name:" << endl;
           cin.ignore();
           getline(cin,name);
           try{    
              fareinfo f=system.calculatefare(busno,age);
              system.bookseat(busno , seatno);
              system.printTicket(busno , seatno , name , age , f);
              cout << "Seat Booked Successfully!!"<<endl;
        } 
            catch(const char*error){
            cout << "Error:" << error << endl;
        }
         break;
    }
        case 4:{
          int busno, seatno;
         cout << "Enter Bus Number:" << endl;
         cin  >> busno;
         cout << "Enter Seat NUmber:" << endl;
         cin  >> seatno;
         try{   
           system.cancelseat(busno , seatno);
             cout << "Seat Cancelled!!"<<endl;
        }   
        catch(const char*error){
            cout << "Error:" << error << endl;
        }  
         break;
    }
        case 5:{
          int busno;
          cout << "Enter Bus Number:" << endl;
          cin >> busno;
          try{
            system.viewAvalibleseats(busno);
          }
          catch(const char*error){
            cout << "Error:" << error <<endl;
          }
          break;
        }
        case 6:
          cout << "Exiting......" << endl;
            break;
        default:
          cout << "Invalid input.." << endl;                    
    }
 }while(choice !=5);   
}