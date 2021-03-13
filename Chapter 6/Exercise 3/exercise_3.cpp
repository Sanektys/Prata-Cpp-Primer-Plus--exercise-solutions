#include <iostream>


inline void menu();
bool event(char);

int main() {
    menu();
    {
        bool isCorrect = false;
        char choice = '\0';
        do {
            std::cin >> choice;
            isCorrect = event(choice);
        } while (!isCorrect);
    }


    return 0;
}

inline void menu() {
    std::cout << "Please enter one of the following choices:\n";
    std::cout << "c) carnivore     p) pianist\n"
              << "t) tree          g) game\n";
}

bool event(char choice) {
    switch (choice) {
    case 'c' :
		case 'C' :
        std::cout << "Owl Yoll scattered seals again!\n";
        return true;
		case 'p' :
		case 'P' :
        std::cout << "Pianist Matsuev urges everyone to vote.\n";
        return true;
		case 't' :
		case 'T' :
        std::cout <<
        "                        / / /\n"
        "       /        /  /     //    /\n"
        "    /                 /         /  /\n"
        "                    /\n"
        "                   /                //\n"
        "   /          /            /              /\n"
        "   /            '/,        /               /\n"
        "   /              'b      *\n"
        "    /              '$    //                //\n"
        "   /    /           $:   /:               /\n"
        " //      /  //      */  @):        /   / /\n"
        "              /     :@,@):   ,/**:'   /\n"
        "  /      /,         :@@*: //**'      /   /\n"
      R"(           '/o/    /:(@'/@*"'  /)" << std::endl <<
        "   /  /       'bq,//:,@@*'   ,*      /  /\n"
        "              ,p$q8,:@)'  /p*'      /\n"
        "       /     '  / '@@Pp@@*'    /  /\n"
        "        /  / //    Y7'.'     /  /\n"
        "                  :@):.\n"
        "                 .:@:'.\n"
        "               .::(@:.      -Sam Blumenstein-\n";
        return true;
		case 'g' :
		case 'G' :
        std::cout <<
        "================================================\n"
        "     .-.   .-.     .--.                         |\n"
        "    | OO| | OO|   / _.-' .-.   .-.  .-.   .''.  |\n"
      R"(    |   | |   |   \  '-. '-'   '-'  '-'   '..'  |)" << std::endl <<
        "    '^^^' '^^^'    '--'                         |\n"
        "===============.  .-.  .================.  .-.  |\n"
        "               | |   | |                |  '-'  |\n"
        "               | |   | |                |       |\n"
        "               | ':-:' |                |  .-.  |\n"
        "l42            |  '-'  |                |  '-'  |\n"
        "==============='       '================'       |\n";
        return true;
		default :
        std::cout << "Please enter c, p, t, or g: ";
        return false;
    }
}
