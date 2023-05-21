#include <iostream>
#include "sea.h"
   
   Sea::Sea() :Ocean() {
      is_valid = false;
      belongs_to_ocean = NULL;
      num_species = 0;
   }

   Sea::Sea(string name_, string location_, double size_, double depth_, double surface_area_, int num_species_) : Ocean("", name_, location_, size_, depth_, surface_area_) {
      is_valid = true;
      belongs_to_ocean = NULL;
      num_species = num_species_;
   }

   void Sea::set(string name_, string location_, double size_, double depth_, double surface_area_, int num_species_) {
      Ocean::set("", name_, location_, size_, depth_, surface_area_);
      is_valid = true;
      belongs_to_ocean = NULL;
      num_species = num_species_;
   }

   void Sea::set_parent(Ocean* obj) {
      this->belongs_to_ocean = obj;
   }

   string Sea::get_name() {
      return this->name;
   }

istream& operator >> (istream& stream, Sea& obj) {
   string name_, location_, info;
   double size_, depth_, surface_area_;
   int num_species;
   cout << "Enter the name, location, size, depth, surface_area, num_species" << endl;;
   cin >> name_ >> location_ >> size_ >> depth_ >> surface_area_ >> num_species;
   cout << "Enter the info of sea" << endl;
   cin >> info;
   obj.set(name_, location_, size_, depth_, surface_area_, num_species);
   obj.set_info(info);
   return stream;
}

ostream& operator << (ostream& stream, Sea& obj) {
   cout << "{ " << endl;
   cout << "Name Sea: " << obj.name << endl;
   cout << "Location: " << obj.location << endl;
   cout << "Size : " << obj.size << endl;
   cout << "Depth: " << obj.depth << endl;
   cout << "Surface_area: " << obj.surface_area << endl;
   if (NULL != obj.belongs_to_ocean)
      cout << "Belongs to Ocean: " << obj.belongs_to_ocean->get_name() << endl;
   cout << "num_species" << obj.num_species << endl;
   cout << "Info: " << obj.info << endl;
   cout << "} ";
   return stream;
}