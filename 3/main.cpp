#include <iostream>//убрана лишн€€ библиотека stl

inline std::wstring get_ceasar_string(std::wstring str)//функци€ вызываетс€ один раз, делаем еЄ инлайн
{

     const wchar_t shift = 3;

     const unsigned short int n = 26;

     std::wstring res;

     for (auto i : str)
     {

         if (i >= L'a' && i <= L'z') {
             res += L'a' + (i - L'a' + shift) % n;//приведение типов, заменили на константу, обозначающую мощность алфавита 
         }//убрал оператор continue
         else if (i >= L'A' && i <= L'Z') {
             res += L'A' + (i - L'A' + shift) % n;
         }
         else
            res += i;
     }

     return res;
}

int main() 
{
     std::wstring str = L"Somebody once told me the world is gonna roll me!";
     std::wstring str_crypted = get_ceasar_string(str);
     std::wcout << str_crypted << std::endl;

     return 0;
}