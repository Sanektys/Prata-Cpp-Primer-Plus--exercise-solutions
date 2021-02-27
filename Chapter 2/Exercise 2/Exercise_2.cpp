#include <iostream>


using namespace std;

int furToYard(int);
int furToMeter(int);

int main() {
    cout << "The program converts the entered\n"
            "furlongs to yards and meters.\n";
    cout << "Enter the distance in furlongs: ";
    int furlongs = 0;
    cin >> furlongs;
    cout << "In yards: " << furToYard(furlongs) << endl
         << "In meters: " << furToMeter(furlongs) << endl;


    return 0;
}

int furToYard(int furlongs) {
    return furlongs * 220;
}

int furToMeter(int furlongs) {
    return furlongs * 201168;
}
