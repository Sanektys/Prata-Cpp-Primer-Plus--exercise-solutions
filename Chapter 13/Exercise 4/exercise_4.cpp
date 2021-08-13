#include "vintagePort.h"


int main(void) {
    Port portwein("Gelendzshik", "tsar", 20);
    portwein.show();
    VintagePort vintage("Glazgo", 16, "Contagen", 1895);
    Port* vintageWein = &vintage;
    vintageWein->show();
    *vintageWein += 16;
    std::cout << "Bottles: " << vintageWein->bottleCount() << std::endl;
    (Port&)vintage = portwein;
    std::cout << (const VintagePort&)*vintageWein << std::endl;


    return 0;
}
