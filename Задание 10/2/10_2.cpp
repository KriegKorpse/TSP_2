#include <iostream>
#include <windows.h>
#include <algorithm>
#include <vector>
using namespace std;

template<class T> void Swap(T& x, T& y) {
   T z = x;
   x = y;
   y = z;
}

void OutArr(vector<string>& arr) {
   cout << "{ " << endl;
   for (int i = 0; i < arr.size(); i++) {
      cout << i + 1 << ") " << arr[i] << endl;
   }
   cout << "}" << endl;
}

void BubbleSort(vector<string>& arr_orig) {
   vector<string> arr;
   for (int i = 0; i < arr_orig.size(); i++) {
      arr.push_back(arr_orig[i]);
      transform(arr[i].begin(), arr[i].end(), arr[i].begin(), ::tolower);
   }
      
   //OutArr(arr);
   for (int i = 0; i < arr.size() - 1; i++)
      for (int j = 0; j < arr.size() - i - 1; j++)
         if (arr[j] > arr[j + 1]) {
            Swap(arr[j], arr[j + 1]);
            Swap(arr_orig[j], arr_orig[j + 1]);
         }
};

template<class T> void BubbleSort(vector<T>& arr) {
   for (int i = 0; i < arr.size() - 1; i++)
      for (int j = 0; j < arr.size() - i - 1; j++)
         if (arr[j] > arr[j + 1]){
            Swap(arr[j], arr[j + 1]);
         }
};

template<class T> void OutArr(vector<T>& arr) {
   cout << "{ ";
   for (int i = 0; i < arr.size(); i++) {
      cout << arr[i] << " ";
   }
   cout << "}" << endl;
}

int main()
{
   SetConsoleCP(1251);
   SetConsoleOutputCP(1251);
   setlocale(LC_ALL, "Russian");

   vector<int> arr_int = { 11, 1, 3, 4, 9, 5, 2, -1, 0, 15, 14 };
   BubbleSort(arr_int);
   cout << "Отсортированный массив целых: ";
   OutArr(arr_int);

   vector<double> arr_double = { 11.5, 1.11, 3.567, 4.34, 9.89, 5.0, 2.2, -1.1, 0.99, 15.34, 14.89 };
   BubbleSort(arr_double);
   cout << "Отсортированный массив double: ";
   OutArr(arr_double);

   vector<char> arr_char = { 'x', 'h', 'a', 'y', 's', '1', 'k', '9', 'm', 'd', 'e' };
   BubbleSort(arr_char);
   cout << "Отсортированный массив char: ";
   OutArr(arr_char);

   vector<string> arr_string = { 
      "Владимиров, В. В. Применение инновационных агромелиоративных материалов: передовой опыт и экономическая оценка: монография / В. В. Владимиров, И. П. Стуканова, А. В. Агафонов.– Чебоксары: Политех, 2019. – 116 с.",
      "Розенталь Д.Э. Большой справочник по русскому языку. – М. : Издательство Оникс: Издательство «Мир и образование», 2008. – 1008 с.",
      "Ушаков Д.Н. Толковый словарь современного русского языка. – М. : Альта-Принт, ДОМ, XXI век, 2008. – 512 с.",
      "Сухова Г.М. Планирование в экономике / Г.М. Сухова, А.А. Григорян. – М. : Печатное слово, 2012. – 248 с.",
      "Домоводство : учеб. пособие для средней школы / А.И. Завальнюк, У.Е. Петрова, Н.А. Гордеева, Н.А. Сом. – Саратов : Изд-во СГУ, 2014. – 120 с.",
      "Петров И.А. Современная концепция маркетинга // Путь к лидерству для маркетолога. – М., 2015. – С. 25–39.",
      "Гранович Д.М. Занимательная теорема Пифагора // Математика в школе. – 2005. – № 3. – С. 15–17.",
      "Петрушевич Г.А. Особенности обучения детей с задержкой речевого развития // Дошкольное образование. – 2005. – № 5. – С. 42–49; № 6. – С. 54–67.",
      "Конституция Российской Федерации : офиц. текст. – СПб. : Сатурн, 2019. – 56 с.",
      "Ганина-Новикова Г. Владимир Касютин – о проблемах журналистики: «Дело не только в деньгах». – М. : [б.и.], 2019 / [Электронный ресурс]. – Режим доступа: https://gubernia74.ru/articles/society/1090352/.",
      "петрова, И. В. Производство строительных работ: учебное пособие / И. В. Петрова, Н. Г. Мамаев. –  Чебоксары: "
      };
   BubbleSort(arr_string);
   cout << "Отсортированный массив string: ";
   OutArr(arr_string);
}

