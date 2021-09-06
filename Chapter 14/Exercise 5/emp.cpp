#include "emp.h"


///////////////////////////////////////////////////////////
// class AbstrEmp
AbstrEmp::AbstrEmp() {}

AbstrEmp::AbstrEmp(const std::string& fn, const std::string& ln,
                   const std::string& j) 
                   : firstName_(fn), lastName_(ln), job_(j) {}

void AbstrEmp::showAll() const {
    std::cout << "First name: \""  << firstName_ << "\"  "
              << "Last name: \""   << lastName_ << "\"\n"
              << "Job:" << job_ << std::endl;
}

AbstrEmp::~AbstrEmp() {}

void AbstrEmp::setAll() {
    std::cout << "Enter first name: ";
    std::getline(std::cin, firstName_);
    std::cout << "Enter last name: ";
    std::getline(std::cin, lastName_);
    std::cout << "Enter type of job: ";
    std::getline(std::cin, job_);
}

std::ostream& operator<<(std::ostream& output, const AbstrEmp& employee) {
    output << "First name: \""  << employee.firstName_ << "\"  "
           << "Last name: \""   << employee.lastName_ << "\"\n"
           << "Job: " << employee.job_ << std::endl;

    return output;
}


///////////////////////////////////////////////////////////
// class Employee
Employee::Employee() {}

Employee::Employee(const std::string& fn, const std::string& ln,
                   const std::string& j) : AbstrEmp(fn, ln, j) {}


///////////////////////////////////////////////////////////
// class Manager
Manager::Manager() {}

Manager::Manager(const std::string& fn, const std::string& ln,
                 const std::string& j, int ico) : AbstrEmp(fn, ln, j),
                                                  inChargeOf_(ico) {}

Manager::Manager(const AbstrEmp& e, int ico) : AbstrEmp(e), inChargeOf_(ico) {}

Manager::Manager(const Manager& m) : AbstrEmp(m), inChargeOf_(m.inChargeOf_) {}


void Manager::showAll() const {
    AbstrEmp::showAll();
    std::cout << "In charge of " << inChargeOf_ << std::endl;
}

void Manager::setAll() {
    AbstrEmp::setAll();
    std::cout << "Enter number of dependencies: ";
    std::cin >> inChargeOf_;
}


///////////////////////////////////////////////////////////
// class Fink
Fink::Fink() {}

Fink::Fink(const std::string& fn, const std::string& ln,
           const std::string& j, const std::string& rpo)
           : AbstrEmp(fn, ln, j), reportsTo_(rpo) {}

Fink::Fink(const AbstrEmp& e, const std::string& rpo)
           : AbstrEmp(e), reportsTo_(rpo) {}

Fink::Fink(const Fink& e) : AbstrEmp(e), reportsTo_(e.reportsTo_) {}


void Fink::showAll() const {
    AbstrEmp::showAll();
    std::cout << "Reports to " << reportsTo_ << std::endl;
}

void Fink::setAll() {
    AbstrEmp::setAll();
    std::cout << "Enter to whom does the reports go: ";
    std::getline(std::cin, reportsTo_);
}


///////////////////////////////////////////////////////////
// class Highfink
Highfink::Highfink() {}

Highfink::Highfink(const std::string& fn, const std::string& ln,
                   const std::string& j, const std::string& rpo, int ico)
                   : Manager(fn, ln, j, ico), Fink(fn, ln, j, rpo),
                     AbstrEmp(fn, ln, j) {}

Highfink::Highfink(const AbstrEmp& e, const std::string& rpo, int ico)
                   : Manager(e, ico), Fink(e, rpo), AbstrEmp(e) {}

Highfink::Highfink(const Fink& f, int ico)
                   : Manager(f, ico), Fink(f), AbstrEmp(f) {}

Highfink::Highfink(const Manager& m, const std::string& rpo)
                   : Manager(m), Fink(m, rpo), AbstrEmp(m) {}

Highfink::Highfink(const Highfink& h)
                   : Manager(h), Fink(h), AbstrEmp(h) {}

void Highfink::showAll() const {
    AbstrEmp::showAll();
    std::cout << "In charge of " << inChargeOf() << std::endl;
    std::cout << "Reports to " << reportsTo() << std::endl;
}

void Highfink::setAll() {
    AbstrEmp::setAll();
    std::cout << "Enter number of dependencies: ";
    (std::cin >> inChargeOf()).get();
    std::cout << "Enter to whom does the reports go: ";
    std::getline(std::cin, reportsTo());
}