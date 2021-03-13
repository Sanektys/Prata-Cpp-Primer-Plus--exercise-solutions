#include <iostream>
#include <cctype>


int main() {
#if defined(WIN32) || defined(_WIN64)
    system("chcp 1251");   //change code page в консоли Windows
                           //с DOS 866 на Windows 1251
#endif                     //для корректного ввода в поток cin с консоли
    setlocale(LC_ALL, "");

    std::wcout << L"Вводите строки, затем программа "
                  L"преобразует их следующим образом:\n"
                  L"- заменит строчные буквы заглавными и наоборот;\n"
                  L"- пропустит введённые цифры;\n"
                  LR"(- при встрече символа "@" отбросит дальнейшие символы.)"
               << std::endl;

    std::wcout << L"Для завершения ввода используйте комбинацию ";
#if defined(WIN32) || defined(_WIN64)
    std::wcout << L"ctrl+z\n\n";
#elif defined(__unix__)
    std::wcout << L"ctrl+d\n\n";
#endif

    wchar_t symbol = 0;
    while (std::wcin.get(symbol).good() && symbol != '@') {
        bool isDigit = symbol >= L'0' && symbol <= L'9';
        if (!isDigit) {
            bool engAlphaLow = symbol >= L'a' && symbol <= L'z';
            bool engAlphaUpper = symbol >= L'A' && symbol <= L'Z';
            bool rusAlphaLow = symbol >= L'а' && symbol <= L'я';
            bool rusAlphaUpper = symbol >= L'А' && symbol <= L'Я';
            if (engAlphaLow || rusAlphaLow || engAlphaUpper || rusAlphaUpper)
                if (engAlphaLow)
                    std::wcout << wchar_t(symbol - (L'a' - L'A'));
                else
                    if (rusAlphaLow)
                        std::wcout << wchar_t(symbol - (L'а' - L'А'));
                    else
                        if (engAlphaUpper)
                            std::wcout << wchar_t(symbol + (L'a' - L'A'));
                        else
                            if (rusAlphaUpper)
                                std::wcout << wchar_t(symbol + (L'а' - L'А'));
                            else;
            else
                std::wcout << symbol;
        }
    }
    std::wcout << std::endl;


    return 0;
}
