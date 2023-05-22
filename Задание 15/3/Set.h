#ifndef _SET_H_
#define _SET_H_
#include <iostream>
#include "algorithm"
#include <windows.h>
using namespace std;

template <class AType>
class Set {
private:
   AType* a;
   int len;
   int size;

public:
   Set();
   Set(int size);
   Set& operator = (const Set& arr);
   Set(const Set& right);
   ~Set();
   bool Is_Empty();
   bool Is_Full();
   bool Add(const AType& T);
   int In_Set(const AType& T) const;
   AType Get(const AType& T);
   template<class AType>
   friend ostream& operator << (ostream& stream, const Set<AType>& arr);
   Set operator + (const Set& arr);
   Set operator * (const Set& arr);
   bool operator <= (const Set& arr);
};

template<class Atype>  Set<Atype>::Set() {
   len = 0;
   size = 0;
   a = NULL;
}

template<class Atype>
Set<Atype>::Set(int len_) {
   len = len_;
   size = 0;
   a = new Atype[len];
}

template<class AType>
Set<AType>& Set<AType>::operator =(const Set<AType>& arr) {
   size = arr.size;
   len = arr.len;
   delete[] a;
   a = new AType[len];
   for (int i = 0; i < size; i++) {
      a[i] = arr.a[i];
   }
   return *this;
}

template <class AType>
Set<AType>::Set(const Set<AType>& arr)
{
   size = arr.size;
   len = arr.len;
   a = new AType[len];
   for (int i = 0; i < size; i++) {
      a[i] = arr.a[i];
   }
}

template<class Atype>
Set<Atype>::~Set() {
   delete[] a;
}

template<class AType>
bool Set<AType>::Is_Empty() {
   if (0 == size)
      return true;
   return false;
}

template<class AType>
bool Set<AType>::Is_Full() {
   if (len == size)
      return true;
   return false;
}

template<class AType>
bool Set<AType>::Add(const AType& T) {
   if (!Is_Full()) {
      if (-1 == In_Set(T)) {
         a[size] = T;
         ++size;
      }
      return true;
   }
   return false;
}

template<class AType>
int Set<AType>::In_Set(const AType& T) const {
   for (int i = 0; i < this->size; i++)
      if (T == this->a[i])
         return i;
   return -1;
}

template<class AType>
AType Set<AType>::Get(const AType& T) {
   int curr_id = In_Set(T);
   AType curr_item = a[curr_id];
   try {
      if (Is_Empty())
         throw std::out_of_range("set is empty");
      if (-1 == curr_id)
         throw std::out_of_range("index out of range");

      int i = curr_id;
      while (i < size - 1) {
         a[i] = a[i + 1];
         ++i;
      }
      --size;
      return curr_item;
   }
   catch (std::out_of_range& e) {
      std::cerr << "Error: " << e.what() << "; value: " << T << std::endl;
      return false;
   }
}

template<class AType>
ostream& operator << (ostream& stream, const Set<AType>& arr) {
   stream << "{ ";
   for (int i = 0; i < arr.size; i++) {
      stream << arr.a[i];
      if (i != arr.size - 1)
         cout << "; ";
   }
   stream << " }";
   return stream;
}

template<class AType>
Set<AType> Set<AType>::operator +(const Set<AType>& arr) {

   int count = size;
   for (int i = 0; i < arr.size; i++)
      if (-1 == In_Set(arr.a[i]))
         count++;

   Set<AType> result(count);
   for (int i = 0; i < size; i++)
      result.Add(a[i]);

   for (int i = 0; i < arr.size; i++)
      if (-1 == In_Set(arr.a[i]))
         result.Add(arr.a[i]);
   return result;
}

template<class AType>
Set<AType> Set<AType>::operator *(const Set<AType>& arr) {

   int count = 0;
   for (int i = 0; i < arr.size; i++) {
      if (-1 != In_Set(arr.a[i]))
         count++;
   }
   Set<AType> result(count);
   for (int i = 0; i < arr.size; i++) {
      if (-1 != In_Set(arr.a[i]))
         result.Add(arr.a[i]);
   }
   return result;
}

template<class AType>
bool Set<AType>::operator <=(const Set<AType>& arr) {
   for (int i = 0; i < size; i++) {
      if (-1 == arr.In_Set(a[i]))
         return false;
   }
   return true;
}

#endif // _SET_H_

