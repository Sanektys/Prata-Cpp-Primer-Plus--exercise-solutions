#include <iostream>

#include "emp.h"


int main(void) {
    Employee employee("Trip", "Harris", "Thumper");
    std::cout << employee << std::endl;
    employee.showAll();
    
    std::cout << std::endl;
    Manager manager("Amorphis", "Spindragon", "Nuancer", 5);
    std::cout << manager << std::endl;
    manager.showAll();

    std::cout << std::endl;
    Fink fink("Matt", "Oggs", "Oiler", "Juno Barr");
    std::cout << fink << std::endl;
    fink.showAll();

    std::cout << std::endl;
    Highfink highfink(manager, "Curly Kew");
    highfink.showAll();

    std::cout << "\nPress a key for next phase:\n";
    std::cin.get();
    Highfink highfinkTwo;
    highfinkTwo.setAll();
    std::cout << "\n\nUsing an AbstrEmp* pointer:\n";
    AbstrEmp* tri[4]{&employee, &fink, &highfink, &highfinkTwo};
    for (int i = 0; i < 4; i++) {
        tri[i]->showAll();
        std::cout << std::endl;
    }


    return 0;
}