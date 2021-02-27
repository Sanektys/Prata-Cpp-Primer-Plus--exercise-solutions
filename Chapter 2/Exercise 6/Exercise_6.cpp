#include <iostream>


double lightYearToAstroUnit(double);

int main() {
    std::cout << "The program converts light years to astronomical units.\n";
    std::cout << "Enter the number of light years: ";
    double lightYears = 0.0;
    std::cin >> lightYears;
    
    std::cout << lightYears << " light years = "
              << lightYearToAstroUnit(lightYears) << " astronomical units.\n";


    return 0;
}

double lightYearToAstroUnit(double lightYear) {
    return lightYear * 63241.1;
}
