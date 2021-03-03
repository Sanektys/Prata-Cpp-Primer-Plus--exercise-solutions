#include <iostream>


int main() {
    setlocale(LC_ALL, "");

    std::wcout << L"Вводите слова (для завершения введите слово done):\n";
    std::string word{};
    short count = 0;

    std::cin >> word;
    while (word != "done") {
        ++count;
        std::cin >> word;
    }
    std::wcout << L"Вы ввели " << count << L" слов.\n";


    return 0;
}
