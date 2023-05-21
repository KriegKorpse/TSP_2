#include "rational.h"
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

void factorize(vector<int>& a_factorize, int a, int div);
void reduce_vectors(vector<int>& a_factorize, vector<int>& b_factorize);
int mult_vector(vector<int>& a_factorize);
void reduce_rat(int &a, int &b);

   rational::rational() {
      this->a = 1;
      this->b = 1;
      this->sign = true;
   }

   rational::rational(const int a_, const int b_) {
      int a_temp = 1;
      int b_temp = 1;
      if (0 == abs(b_))
         throw exception("«наменатель дроби не должен быть равен нулю");

      //if (0 == abs(a_))
      //   throw exception("„ислитель дроби не должен быть равен нулю");

      //if (0 == abs(a_) % abs(b_))
      //  throw exception("¬ведена не дробь, а целое число");

      
      if ((0 != abs(a_) % abs(b_)) && 1 != b)
         a_temp = abs(a_) % abs(b_);
      else
         a_temp = abs(a_);

      b_temp = abs(b_);

      reduce_rat(a_temp, b_temp);

      this->a = a_temp;
      this->b = b_temp;
      this->set_sign(a_, b_);

      //copy(a_factorize.begin(), a_factorize.end(), std::ostream_iterator<int>(std::cout, ", "));
      //cout << endl;
      //copy(b_factorize.begin(), b_factorize.end(), std::ostream_iterator<int>(std::cout, ", "));
   }

   void rational::set_sign(int a_, int b_) {
      if ((a_ > 0 && b_ > 0) || ((a_ < 0 && b_ < 0)))
         this->sign = true;
      else
         this->sign = false;
   }

   void rational::set(int a_, int b_) {
      rational tmp(a_, b_);
      this->a = tmp.a;
      this->b = tmp.b;
      this->sign = tmp.sign;
   }

   void rational::show() {
      char ch = '+';
      if (!this->sign)
         ch = '-';
      cout << "ƒробь вида a/b = " << ch << this->a << "/" << this->b << endl;
   }

   rational rational::operator + (const rational &rat) {
      int mult_this = 1;
      if (true == this->sign)
         mult_this = abs(this->a);
      else
         mult_this = -abs(this->a);

      int mult_rat = 1;
      if (true == rat.sign)
         mult_rat = abs(rat.a);
      else
         mult_rat = -abs(rat.a);
      
      int mult_b = abs(this->b);
      if (abs(this->b) != abs(rat.b)) {
         mult_this *= abs(rat.b);
         mult_rat *= abs(this->b);
         mult_b *= abs(rat.b);
      }

      int a_res = mult_this + mult_rat;
      int sign_res = true;
      if (a_res < 0)
         sign_res = false;
      a_res = abs(a_res);
      int b_res = mult_b;

      if (a_res == b_res) {
         a_res = 1;
         b_res = 1;
      }
      else if((0 != a_res % b_res) && (1 != b))
         a_res %= b_res;

      reduce_rat(a_res, b_res);

      rational tmp;
      tmp.a = a_res;
      tmp.b = b_res;
      tmp.sign = sign_res;
      return tmp;
   }

   rational operator - (const rational& rat_1, const rational& rat_2) {
      rational rat_1_tmp = rat_1;
      rational rat_2_tmp = rat_2;
      rat_2_tmp.sign = !rat_2_tmp.sign;
      rational tmp = rat_1_tmp + rat_2_tmp;
      return tmp;
   }

   rational& rational::operator ++ () {
      rational tmp = *this + rational(1, this->b);
      this->set(tmp.a, tmp.b);
      this->sign = tmp.sign;
      return *this;
   }

   rational& rational::operator ++ (int d) {
      return ++*this;
   }

   bool rational::operator == (const rational rat) {
      return (this->a == rat.a) && (this->b == rat.b) && (this->sign == rat.sign);
   }

   bool rational::operator > (const rational rat) {
      if (this->sign == rat.sign) {
         if (this->sign)
            return (*this - rat).sign && ((*this - rat).a != 0);
         else
            return !(*this - rat).sign && ((*this - rat).a != 0);
      }
      else {
         if (this->sign)
            return true;
         else
            return false;
      }
      return 0;
   }

   rational rational::operator = (rational const& rat) {
      this->a = rat.a;
      this->b = rat.b;
      this->sign = rat.sign;
      return *this;
   }

void factorize(vector<int>& a_factorize, int a, int div)
{
   a = abs(a);
   if ((1 == a) || (0 == a)) return;
   if (a % div == 0)
   {
      a_factorize.push_back(div);
      //cout << "div " << div << endl;
      factorize(a_factorize, a / div, div);
   }
   else
      if (div == 2){
         //cout << "div " << div << endl;
         factorize(a_factorize, a, div + 1);
      }
      else if (div >= sqrt(a)) {
         factorize(a_factorize, a, a);
      }
      else {
         //cout << "div " << div << endl;
         factorize(a_factorize, a, div + 2);
      }
}

void reduce_vectors(vector<int> &a_factorize, vector<int> &b_factorize) {
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
}

int mult_vector(vector<int>& a_factorize) {
   int a_temp = 1;
   if (!a_factorize.empty()) {
      for (int i = 0; i < a_factorize.size(); i++)
         a_temp *= a_factorize[i];
   }
   return a_temp;
}

void reduce_rat(int& a, int& b) {
   if (1 != abs(b)) {
      vector<int> a_factorize;
      vector<int> b_factorize;

      factorize(a_factorize, abs(a), 2);
      factorize(b_factorize, abs(b), 2);
      reduce_vectors(a_factorize, b_factorize);

      if(0 != a)
         a = mult_vector(a_factorize);
      if(0 != b)
         b = mult_vector(b_factorize);
   }
}