#include <iostream>
#include <string>


int main() {
    using namespace std;
    //const int ArSize = 20;
    //char name[ArSize];
    //char dessert[ArSize];
    string name;
    string dessert;

    cout << "Enter your name:\n";
    getline(std::cin, name);
    cout << "Enter your favorite dessert:\n";
    getline(std::cin, dessert);
    cout << "I have some delicious " << dessert;
    cout << " for you, " << name << ".\n";
    

    return 0;
}
