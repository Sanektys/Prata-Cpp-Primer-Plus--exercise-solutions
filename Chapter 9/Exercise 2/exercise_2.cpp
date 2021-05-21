#include <iostream>


void strcount(const std::string& str);

int main() {
    using namespace std;
    std::string input{};
    cout << "Enter a line:\n";
    std::getline(std::cin, input);
    while (input != "") {
        strcount(input);
        cout << "Enter next line (empty line to quit):\n";
        std::getline(std::cin, input);
    }
    cout << "Bye.\n";


    return 0;
}

void strcount(const std::string& str) {
    using namespace std;
    static int total = 0;
    int count = 0;
    cout << "\"" << str << "\" contains ";
    int i = 0;
    while (str[i++])
        count++;
    total += count;
    cout << count << " characters\n";
    cout << total << " characters total\n";
}
