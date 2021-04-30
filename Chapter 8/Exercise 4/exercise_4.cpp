#include <iostream>
#include <cstring>

using namespace std;


struct stringy
{
    char* str;
    int ct;
};

void set(stringy&, const char[]);
inline void show(const stringy&, const int = 1);
inline void show(const char[], const int = 1);

int main() {
    stringy beany;
    char testing[] = "Reality isn't what it used to be.";
    set(beany, testing);
    show(beany);
    show(beany, 2);
    testing[0] = 'D';
    testing[1] = 'u';
    show(testing);
    show(testing, 3);
    show("Done!");
    delete beany.str;


    return 0;
}

void set(stringy& stry, const char string[]) {
    int size = 0;
    while (string[size++]);
    stry.str = new char[size];
    stry.ct = size - 1;
    for (int i = 0; i < size; i++)
        *(stry.str + i) = string[i];
}

void show(const stringy& stry, const int times) {
    for (int i = 1; i <= times; i++)
        cout << stry.str << endl;
}

void show(const char string[], const int times) {
    for (int i = 1; i <= times; i++)
        cout << string << endl;
}
