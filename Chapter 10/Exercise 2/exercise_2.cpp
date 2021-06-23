#include "person.h"


int main() {
    Person one;
    one.show();
    one.formalShow();

    Person two("Smythecraft");
    two.show();
    two.formalShow();

    Person three("Dimwiddy", "Sam");
    three.show();
    three.formalShow();


    return 0;
}
