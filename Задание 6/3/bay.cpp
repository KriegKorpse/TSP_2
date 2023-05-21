#include <iostream>
#include "bay.h"

Bay::Bay() : Sea() {
   index = 0;
   owner = "";
   belong_to_Sea = NULL;
}

Bay::Bay(string name_, string location_, double size_, double depth_, double surface_area_, int num_species_, string owner_) :Sea(name_, location_, size_, depth_, surface_area_, num_species_) {
   index = 1;
   owner = owner_;
   belong_to_Sea = NULL;
}

void Bay::set(string name_, string location_, double size_, double depth_, double surface_area_, int num_species_, string owner_) {
   index = 3;
   Sea::set(name_, location_, size_, depth_, surface_area_, num_species_);
   this->owner = owner_;
   belong_to_Sea = NULL;
}

void Bay::set_parent(Sea* obj) {
   index = 4;
   belong_to_Sea = obj;
}

void Bay::set_parent(Ocean* obj) {
   index = 4;
   belongs_to_ocean = obj;
}

unsigned long long int Bay::get_index() {
   return this->index;
}

istream& operator >> (istream& stream, Bay& obj) {
   string name_, location_, info, owner_;
   double size_, depth_, surface_area_;
   int num_species;
   cout << "Enter the name, location, size, depth, surface_area, num_species, owner" << endl;;
   cin >> name_ >> location_ >> size_ >> depth_ >> surface_area_ >> num_species >> owner_;
   cout << "Enter the info of sea" << endl;
   cin >> info;
   obj.set(name_, location_, size_, depth_, surface_area_, num_species, owner_);
   obj.set_info(info);
   return stream;
}

ostream& operator << (ostream& stream, Bay& obj) {
   cout << "{ " << endl;
   cout << "Index " << obj.get_index() << endl;
   cout << "Name Bay: " << obj.name << endl;
   cout << "Location: " << obj.location << endl;
   cout << "Size : " << obj.size << endl;
   cout << "Depth: " << obj.depth << endl;
   cout << "Surface_area: " << obj.surface_area << endl;
   if (NULL != obj.belong_to_Sea)
      cout << "Belongs to Sea: " << obj.belong_to_Sea->get_name() << endl;
   if (NULL != obj.belongs_to_ocean)
      cout << "Belongs to Ocean: " << obj.belongs_to_ocean->get_name() << endl;
   cout << "num_species: " << obj.num_species << endl;
   cout << "Owner: " << obj.owner << endl;
   cout << "Info: " << obj.info << endl;
   cout << "} ";
   return stream;
}