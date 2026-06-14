#ifndef BUSSYSTEM_H
#define BUSSYSTEM_H
#include <string>
using namespace std;
  struct fareinfo{
    float basefare;
    float discountpercent;
    float finalfare;
  };
class BusSystem{
  private:
    struct Bus{
       int busno;
       string busname;
       string route;
       string timing;
       int seats[32];
       int fare;
};
  Bus buses[10];
  int buscount = 5;
  void loadbusseats(int busindex);
  void savebusseats(int busindex);

    public:
      BusSystem();
      
      void viewallbuses();
      void viewfares();
      bool bookseat(int busno, int seatno);
      bool cancelseat(int busno, int seatno);
      void viewbookedseats(int busno);
      void viewAvalibleseats(int busno);
      fareinfo calculatefare(int busno , int age);
      void printTicket(int busno , int seattno , string passengername , int age , fareinfo f);
      void addbus(int busno, string name, string route , string timing);
      void updatebus(int busno, string name, string route, string timing);
      void deletebus(int busno);
};      
#endif