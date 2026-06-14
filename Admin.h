#ifndef Admin_H
#define Admin_H
#include "BusSystem.h"
class Admin{
    BusSystem &system;
   public:
     Admin(BusSystem &system);
     void Adminmenu(); 
};
#endif