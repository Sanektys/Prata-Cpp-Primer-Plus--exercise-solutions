#include <iostream>


const int SLEN = 30;

struct student
{
    char fullname[SLEN];
    char hobby[SLEN];
    int ooplevel;
};

int getInfo(student[], int);
void display1(student);
void display2(const student *);
void display3(const student[], int);

int main() {
    std::cout << "Enter group size: ";
    int classSize{};
    std::cin >> classSize;
    if (classSize < 0) {
        std::cout << "Incorrect entered number of students. Terminate.\n";
        return 1;
    }

    student* ptrStu = new student[classSize];
    int entered = getInfo(ptrStu, classSize);
    if (0 == entered) {
        std::cout << "There are no students. Terminate.\n";
        return 0;
    }

    for (int i = 0; i < entered; i++) {
        display1(ptrStu[i]);
        std::cout << std::endl;
        display2(&ptrStu[i]);
        std::cout << std::endl << std::endl;
    }
    display3(ptrStu, entered);

    delete[] ptrStu;
    ptrStu = nullptr;
    std::cout << "Done\n";


    return 0;
}

int getInfo(student stud[], int size) {
    std::cout << "Enter information about students below:\n";
    int i{0};
    char dummy{};
    for (i = 0; i < size; i++) {
        std::cout << "(To complete the entry, press Enter "
                     "without typing the full name)\n";
        std::cout << "\nStudent " << i + 1 << ":\n";
        std::cout << "- fullname: ";
        std::cin.get(dummy).get(stud[i].fullname, SLEN - 1).get();
        if (*stud[i].fullname == '\0') {
            std::cout << "\nEnd of data entry\n";
            break;
        }
        std::cout << "- his hobby: ";
        std::cin.getline(stud[i].hobby, SLEN - 1);
        std::cout << "- level of OOP: ";
        std::cin >> stud[i].ooplevel;

        if (!std::cin) {
            std::cin.clear();
            std::cout << "\nIncorrect entered data of student "
                      << i + 1 << "!\n";
            break;
        }
        std::cout << std::endl;
    }


    return i;
}

void display1(student stud) {
    std::cout << stud.fullname << std::endl;
    std::cout << "Hobby - " << stud.hobby << std::endl;
    std::cout << "OOP level - " << stud.ooplevel << std::endl;
}

void display2(const student* studPoint) {
    std::cout << studPoint->fullname << std::endl;
    std::cout << "Hobby - " << studPoint->hobby << std::endl;
    std::cout << "OOP level - " << studPoint->ooplevel << std::endl;
}

void display3(const student studGroup[], int number) {
    std::cout << "--==Student group==--\n";
    for (int i = 0; i < number; i++) {
        std::cout << "--Student " << i + 1 << ":\n";
        std::cout << studGroup[i].fullname << std::endl;
        std::cout << "Hobby - "     << studGroup[i].hobby    << std::endl;
        std::cout << "OOP level - " << studGroup[i].ooplevel << std::endl;
        std::cout << std::endl;
    }
}
