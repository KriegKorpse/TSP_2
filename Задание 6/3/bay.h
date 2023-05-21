#ifndef _BAY_H_
#define _BAY_H_

#include "sea.h"
#include <iostream>
using namespace std;

class Bay : public Sea {
private:
   unsigned long long int index;
protected:
   string owner;
   Sea* belong_to_Sea;
public:
   Bay();

   Bay(string name_, string location_, double size_, double depth_, double surface_area_, int num_species_, string owner);

   void set(string name_, string location_, double size_, double depth_, double surface_area_, int num_species_, string owner);

   void set_parent(Sea* obj);
   void set_parent(Ocean* obj);

   unsigned long long int get_index();

   friend istream& operator >> (istream& stream, Bay& obj);
   friend ostream& operator << (ostream& stream,Bay& obj);

};

#endif// _BAY_H_