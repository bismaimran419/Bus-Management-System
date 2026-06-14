#include "BusSystem.h"
#include <iostream>
#include <fstream>
using namespace std;
BusSystem::BusSystem(){
    buses[0]={1 , "SKYGO 1", "Karachi to Islamabad" , "2:00PM" ,{} , 3000};
    buses[1]={2 , "SKYGO 2" , "Karachi to Rawalpindi" , "4:15PM" , {}, 2900};
    buses[2]={3, "SKYGO 3", "Karachi to Multan" , "5:00PM" , {}, 2700};
    buses[3]={4 , "SKYGO 4" , "Karachi to Quetta" , "5:50PM", {} , 2800};
    buses[4]={5 , "SKYGO 5", "Karachi to Hyderabad", "3:30PM", {}, 1900};
     for(int i=0; i<5; i++){
        loadbusseats(i);
     }
} 
void BusSystem::loadbusseats(int busindex){
    string filename= "bus_"+ to_string(buses[busindex].busno)+ ".txt";
    ifstream infile(filename);
    if(infile){
        for(int i=0; i<32; i++){
            infile >> buses[busindex].seats[i];
        }
    }else{
        for(int i=0; i<32; i++){
           buses[busindex].seats[i]=0;
        }
    }
}
void BusSystem::savebusseats(int busindex){
    string filename= "bus_"+ to_string(buses[busindex].busno)+".txt";
    ofstream outfile(filename);
      for(int i=0; i<32; i++){
        outfile << buses[busindex].seats[i] << " ";
      }
      outfile.close();
}
void BusSystem::viewallbuses(){
cout << "====================== SKYLINE BUSES ===========================" << endl;
 for(int i=0; i<buscount; i++){
   cout << "Bus" << buses[i].busno << ":" << buses[i].busname << endl;
   cout << "Route:" << buses[i].route << endl;
   cout << "Timing:" << buses[i].timing << endl;
   cout << "Fare:"   << buses[i].fare << "PKR" << endl;
   cout << "================================================================="<< endl; 
 }
}
void BusSystem::viewfares(){
cout << "============== BUS FARES ================" << endl;
for(int i=0; i<buscount; i++){
 cout << buses[i].busname << "from" << buses[i].route << "Fare:" << buses[i].fare << "PKR" << endl;
}
}
bool BusSystem::bookseat(int busno , int seatno){
 if(busno <1 || busno >buscount )
    throw "Invalid bus number!";
if(seatno <1 || seatno >32)
   throw "Invalid seat number!";
 int index= busno-1;
 if(buses[index].seats[seatno-1]==1)
    throw "Seat already booked:(";
 buses[index].seats[seatno-1] = 1;
 savebusseats(index);
 return true;
}
bool BusSystem::cancelseat(int busno , int seatno){
     if(busno <1 || busno >buscount )
       throw "Invalid bus number!!";
     if(seatno <1 || seatno >32)
       throw "Invalid seat number";
 int index= busno-1;
 if(buses[index].seats[seatno-1]==0)
       throw "Seat is already Vacant";
 buses[index].seats[seatno-1] = 0;
 savebusseats(index);
 return true;
}
void BusSystem::viewbookedseats(int busno){
    if(busno <1 || busno >buscount){
        return;
    }
    int index = busno-1;
cout << "Booked Seats in" << buses[index].busname << ":";
bool booked= false;
for(int i=0; i<32; i++){
    if(buses[index].seats[i]==1){
        cout << i+1 << " ";
        booked = true;
    }
}  
if(!booked){
    cout << "No Seats Booked!!!";
}  
cout << endl;
}
void BusSystem::viewAvalibleseats(int busno){
  if(busno<1 || busno>buscount)
    throw "Invalid Bus Number!";
  int index= busno-1;
  bool avalible = false;
  cout << "Avalible Seats In" << buses[index].busname << ":";
   for(int i=0; i<32; i++){
    if(buses[index].seats[i]==0){
      cout << i+1 << " ";
       avalible = true;
    }
   }
    if(!avalible){
      cout << "NO Seats avalible!";
    }
    cout << endl;
}
fareinfo BusSystem::calculatefare(int busno , int age){
    fareinfo f;
    f.basefare= buses[busno-1].fare;
    f.discountpercent=0.0;
    if(age < 13){
        f.discountpercent=50;
    }else if(age >=50){
        f.discountpercent= 30;
    }else{
        int choice;
    cout << "Press 1 if you are student:"<< endl;
    cout << "Press 2 for something exciting(game):" << endl;
    cout << "Press 3 for exiting:" << endl;
    cout << "Please enter your choice:" << endl;
    cin >> choice;
    switch(choice){
        case 1:
          f.discountpercent= 20;
          cout << "Student discount applied(20%)" << endl;
            break;
        case 2:{
            int secretno = 36;
             int guess;
            bool win =false;
          cout << "GUESSING GAME" << endl;
          cout << "Guess a number betweem (1-40)" << endl;
          cout << "You will get only 3 tries!!!" << endl;
          for(int i=0; i<3; i++){
            cout << "Attempt" << i+1 << ":";
            cin  >> guess;
            if(guess== secretno){
                win = true;
                break;
            }
          }
          if(win){
            f.discountpercent=10;
            cout <<"Congratulations! you got extra 10%discount" << endl;
          }else{
            f.discountpercent=0;
             cout << "You got 0 discount better luck next time!";
          }
          break;
        }
        case 3:
           f.discountpercent=0;
         cout << "NO discount applied!"<< endl;
            break;
        default:
          cout << "Invalid input!" << endl;             
    }
    }
    f.finalfare = f.basefare - (f.basefare * f.discountpercent / 100);
    return f;
}
void BusSystem::printTicket(int busno, int seatno, string passengername , int age, fareinfo f){
    int index = busno-1;
cout << "============ SKYLINE BUS TICKET ============="<< endl;
cout << "Passenger Name:" << passengername << endl;
cout << "Age:"            << age           << endl;
cout << "Bus No:"         << buses[index].busno << endl;
cout << "Bus Name:"       << buses[index].busname << endl;
cout << "Route:"          <<buses[index].route << endl;
cout << "Timing:"         << buses[index].timing << endl;
cout << "Seatno:"         << seatno << endl;
cout << "-----------------------------------------------" << endl;
cout << "Original Fare:"    << f.basefare << "PKR" << endl;
cout << "Discount Applied:" << f.discountpercent << "%" << endl;
cout << "FarePaid:"         << f.finalfare << "PKR" << endl;
cout << "=================================================" << endl;
}
void BusSystem::addbus(int busno, string busname, string route, string timing){
  if(buscount>10){
    cout << "No Slot Avalible to add new Bus!"<< endl;
     return;
  }
   for(int i=0; i<buscount; i++){
     if(buses[i].busno == busno){
      cout << "Bus Already Exsit" << endl;
        return;
     }
   }
   buses[buscount].busno = busno;
   buses[buscount].busname = busname;
   buses[buscount].route = route;
   buses[buscount].timing = timing;
   buses[buscount].fare= 3000;
    for(int j=0; j<32; j++){
      buses[buscount].seats[j] =0;
    }
     savebusseats(buscount);
      buscount++;
    cout << "Bus Added Successfully!"<< endl;
  
}
void BusSystem::updatebus(int busno, string busname , string route , string timing){
  for(int i=0; i<buscount; i++){
    if(buses[i].busno== busno){
      buses[i].busname= busname;
      buses[i].route= route;
      buses[i].timing= timing;
      cout << "Bus Updated Successfully!"<< endl;
      return;
    }
  }
  cout << "Bus Number not found!" << endl;
}
void BusSystem::deletebus(int busno){
  for(int i=0; i<buscount; i++){
    if(buses[i].busno == busno){
      for(int j=i; j<buscount-1; j++){
        buses[j] = buses[j+1];
      }
      buscount--;
      cout << "Bus Deleted Successfully!" << endl;
      return;
    }
  }
  cout << "Bus Number Not Found!" << endl;
}
