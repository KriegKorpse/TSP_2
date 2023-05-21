#ifndef _OCEAN_
#define _OCEAN_

#include <iostream>
using namespace std;

class Ocean {
private:
   string mark;

protected:
   string name;
   string location;
   string info;
   double size;
   double depth;
   double surface_area;

public:
   Ocean();

   Ocean(string mark_, string name_, string location_, double size_, double depth_, double surface_area_);

   void set(string mark_, string name_, string location_, double size_, double depth_, double surface_area_);
   void set_info(string text);
   string get_name();

   friend istream& operator >> (istream& stream, Ocean& obj);
   friend ostream& operator << (ostream& stream, Ocean& obj);

};


#endif // _OCEAN_