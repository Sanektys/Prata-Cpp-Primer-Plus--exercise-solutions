#include "plorg.h"


int main() {
    Plorg* plorg = new Plorg;
    plorg->show();
    plorg->setContentmentIndex(30);
    plorg->show();
    delete plorg;

    plorg = new Plorg("Danmor Van Delanirom", 90);
    plorg->show();
    delete plorg;


    return 0;
}
