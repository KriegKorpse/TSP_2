#include <iostream>
#include "Ocean.h"
using namespace std;

   Ocean::Ocean() {
      mark = "";
      name = "";
      location = "";
      size = 0.0;
      depth = 0.0;
      surface_area = 0.0;
      info = "Empty";
   }

   Ocean::Ocean(string mark_, string name_, string location_, double size_, double depth_, double surface_area_) {
      mark = mark_;
      name = name_;
      location = location_;
      size = size_;
      depth = depth_;
      surface_area = surface_area_;
      info = "Empty";
   }

   void Ocean::set(string mark_, string name_, string location_, double size_, double depth_, double surface_area_) {
      mark = mark_;
      name = name_;
      location = location_;
      size = size_;
      depth = depth_;
      surface_area = surface_area_;
      info = "Empty";
   }

   void Ocean::set_info(string text) {
      info = text;
   }

   string Ocean::get_name() {
      return this->name;
   }

   istream& operator >> (istream& stream, Ocean& obj) {
      string mark_, name_, location_, info;
      double size_, depth_, surface_area_;
      cout << "Enter the mark, name, location, size, depth, surface_area" << endl;;
      cin >> mark_ >> name_ >> location_ >> size_ >> depth_ >> surface_area_;
      cout << "Enter the info of ocean" << endl;
      cin >> info;
      obj.set(mark_, name_, location_, size_, depth_, surface_area_);
      obj.set_info(info);
      return stream;
   }

   ostream& operator << (ostream& stream, Ocean& obj) {
      cout << "{ " << endl;
      cout << "Name Ocean: " << obj.name << endl;
      cout << "Location: " << obj.location << endl;
      cout << "Size : " << obj.size << endl;
      cout << "Depth: " << obj.depth << endl;
      cout << "Surface_area: " << obj.surface_area << endl;
      cout << "Mark: " << obj.mark << endl;
      cout << "Info: " << obj.info << endl;
      cout << "} ";
      return stream;
   }
