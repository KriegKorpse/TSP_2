#include "rational.h"
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

void factorize(vector<int>& a_factorize, int a, int div);
int mult_vector(vector<int>& a_factorize);

   rational::rational() {
      this->a = 1;
      this->b = 1;
   }

   rational::rational(const int a_, const int b_) {
      int a_temp = 1;
      int b_temp = 1;
      if (0 == b_)
         throw exception("«наменатель дроби не должен быть равен нулю");

      if (0 == a_ % b_)
         throw exception("¬ведена не дробь, а целое число");

      a_temp = a_ % b_;
      if (0 == a_temp)
         a_temp = 1;

      b_temp = b_;


      vector<int> a_factorize;
      vector<int> b_factorize;

      factorize(a_factorize, a_temp, 2);
      factorize(b_factorize, b_temp, 2);

      vector<int>::iterator a1 = a_factorize.begin();
      while (a_factorize.end() != a1 && !a_factorize.empty() && !b_factorize.empty()) {
         vector<int>::iterator b1 = find(b_factorize.begin(), b_factorize.end(), *a1);
         if (b_factorize.end() != b1) {
            a1 = a_factorize.erase(a1);
            b1 = b_factorize.erase(b1);
         }
         else
            a1++;
      }

      a = mult_vector(a_factorize);
      b = mult_vector(b_factorize);

      //copy(a_factorize.begin(), a_factorize.end(), std::ostream_iterator<int>(std::cout, ", "));
      //cout << endl;
      //copy(b_factorize.begin(), b_factorize.end(), std::ostream_iterator<int>(std::cout, ", "));
   }

   void rational::set(int a_, int b_) {
      rational tmp(a_, b_);
      this->a = tmp.a;
      this->b = tmp.b;
   }

   void rational::show() {
      cout << "ƒробь вида a/b = " << this->a << "/" << this->b << endl;
   }

void factorize(vector<int>& a_factorize, int a, int div)
{
   if (a == 1) return;
   if (a % div == 0)
   {
      a_factorize.push_back(div);
      factorize(a_factorize, a / div, div);
   }
   else
      if (div == 2)
         factorize(a_factorize, a, div + 1);
      else
         factorize(a_factorize, a, div + 2);
}

int mult_vector(vector<int>& a_factorize) {
   int a_temp = 1;
   if (!a_factorize.empty()) {

      for (int i = 0; i < a_factorize.size(); i++)
         a_temp *= a_factorize[i];
   }
   return a_temp;
}