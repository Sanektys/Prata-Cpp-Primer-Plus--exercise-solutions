#include <iostream>
#include <string>

#include "dma.h"


const int COUNT{4};


int main() {
    using std::cout;
    using std::cin;
    using std::endl;

    AbstractDma* abstractBase[COUNT];
    std::string tempLabel{};
    int tempRating{0};
    char kind{'\0'};
    for (int i = 0; i < COUNT; i++) {
        cout << "Enter label: ";
        std::getline(cin, tempLabel);
        cout << "Enter rating: ";
        cin >> tempRating;
        cout << R"(Enter "1" for baseDma class)" << endl
             << R"(Enter "2" for lackDma class)" << endl
             << R"(Enter "3" for hasDma class)" << endl;
        while ((cin >> kind).good() &&
               (kind != '1' && kind != '2' && kind != '3'))
            cout << R"(Enter "1", "2" or "3")";
        std::string addProperty{};
        while (cin.get() != '\n')
            continue;
        switch (kind) {
            case '1' :
                abstractBase[i] = new BaseDma(tempLabel.c_str(), tempRating);
                break;
            case '2' :
                cout << "Enter color: ";
                std::getline(cin, addProperty);
                abstractBase[i] = new LackDma(addProperty.c_str(),
                                              tempLabel.c_str(), tempRating);
                break;
            case '3' :
                cout << "Enter style: ";
                std::getline(cin, addProperty);
                abstractBase[i] = new HasDma(addProperty.c_str(),
                                             tempLabel.c_str(), tempRating);
                break;
        }
    }
    cout << endl;
    for (int i = 0; i < COUNT; i++) {
        abstractBase[i]->view();
        cout << endl;
        delete abstractBase[i];
    }
    cout << "Done!\n";


    return 0;
}
