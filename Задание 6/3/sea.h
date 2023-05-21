#ifndef _SEA_H_
#define _SEA_H_
#include "ocean.h"

class Sea :public Ocean
{
private:
   bool is_valid;
protected:
   Ocean* belongs_to_ocean;
   int num_species;
public:
   Sea();

   Sea(string name_, string location_, double size_, double depth_, double surface_area_, int num_species_);

   void set(string name_, string location_, double size_, double depth_, double surface_area_, int num_species_);

   void set_parent(Ocean* obj);

   string get_name();

   friend istream& operator >> (istream& stream, Sea& obj);
   friend ostream& operator << (ostream& stream, Sea& obj);
};

#endif //_SEA_H_
