#include <iostream>
#include <string.h>


int main() {
    setlocale(LC_ALL, "RUS");

    std::wcout << L"Вводите слова (для завершения введите слово done):\n";
    char word[16]{};
    short count = 0;

    std::cin >> word;
    while (strcmp(word, "done")) {
        ++count;
        std::cin >> word;
    }
    std::wcout << L"Вы ввели " << count << L" слов.\n";


    return 0;
}
