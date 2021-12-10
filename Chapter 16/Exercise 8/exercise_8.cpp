#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <cctype>


const char* firstPerson{"Met"};
const char* secondPerson{"Pet"};

void friendList(std::vector<std::string>&, const char*);


int main() {
    std::string lowFirstPerson(firstPerson);
    for (char& character : lowFirstPerson)
        character = std::tolower(character);
    std::string lowSecondPerson(secondPerson);
    for (auto& character : lowSecondPerson)
        character = std::tolower(character);
    
    std::cout << firstPerson << " and " << secondPerson << ", you can make "
              << "a list of friends invited to the party!\n";
    std::cout << "Who can start (" << firstPerson << '/' << secondPerson
              << ")?  ";
    std::string person;
    do {
        std::cin >> person;
        if (!std::cin.good()) {
            std::cout << "The input stream was forced closed.\n"
                      << "\nTerminate.\n";

            return 1;
        }
        std::string lowPerson(person);
        for (auto& character : lowPerson)
            character = std::tolower(character);
        if (lowPerson != lowFirstPerson && lowPerson != lowSecondPerson) {
            std::cout << "Who is it? I don't know you, "
                      << "introduce yourself again ("
                      << firstPerson << '/' << secondPerson << "): ";
            continue;
        }
        else {
            if (lowPerson != lowFirstPerson)
                std::swap(firstPerson, secondPerson);
            std::cout << "All right, " << firstPerson
                      << ", you go first...\n\n";
            break;
        }
    } while (true);

    std::vector<std::string> firstList;
    friendList(firstList, firstPerson);

    std::cout << "\nNow, the second list:\n";
    std::vector<std::string> secondList;
    friendList(secondList, secondPerson);

    std::cout << "\nExcellent, let's see the final list of invited friends:\n";
    std::vector<std::string> finalList(firstList);
    std::copy(secondList.begin(), secondList.end(),
              std::back_insert_iterator<std::vector<std::string>>(finalList));
    std::sort(finalList.begin(), finalList.end());
    finalList.erase(std::unique(finalList.begin(), finalList.end()),
                    finalList.end());
    for (auto name : finalList)
        std::cout << name << ", ";
    std::cout << "\b\b  \n";

    std::cout << "\nThat's it, invite them!\n";


    return 0;
}


void friendList(std::vector<std::string>& friends, const char* holderName) {
    std::cout << holderName << ", enter your list of invited friends, "
                               "separated by commas:\n"
                               " ->  ";
    std::string fullList;
    while (std::cin.peek() == '\n')
        std::cin.get();
    std::getline(std::cin, fullList);

    if (fullList.size() > 2) {
        std::string particularName;
        auto startingIter{fullList.begin()};   //Первый символ отдельного имени
        auto endingIter{fullList.begin()};     //Символ, следующий за последним
        auto prevCommaPos{fullList.begin()};   //Изначальная позиция запятой

        //Выделение отдельных имён из целой строки, имена разделяются запятыми.
        //Также удаляются пробелы с конца и начала имени.
        for (auto iter{fullList.begin()}; iter < fullList.end(); iter++) {
            //Если запятая или конец списка имён
            bool isComma{',' == *iter};
            bool isEnd{iter + 1 == fullList.end()};
            if (isComma || isEnd) {
                if (iter - startingIter < 2)  {//Слишком короткое имя
                    startingIter = endingIter = iter + 1; //Итераторы к запятой
                    continue;
                }
                
                prevCommaPos = iter;
                if (isComma)
                    --iter;
                while (' ' == *iter)  //Игнорирование пробелов в конце слова.
                    --iter;
                //Если имени нет или оно слишком короткое:
                if (startingIter >= iter || iter - startingIter < 2) {
                    iter = prevCommaPos;
                    startingIter = endingIter = iter + 1;
                    continue;
                }
                endingIter = ++iter;
                while (' ' == *startingIter) //Игнорирование пробелов
                    ++startingIter;          //в начале слова
                if (iter - startingIter < 3) {
                    iter = prevCommaPos;
                    startingIter = endingIter = iter + 1;
                    continue;
                }

                particularName = std::string(startingIter, endingIter);
                friends.push_back(particularName);

                //Сдвиг итераторов на позицию после изначальной запятой
                iter = prevCommaPos;
                startingIter = endingIter = iter + 1;
            }
        }
    }

    if (!std::cin.good()) {
        if (std::cin.eof()) {
            std::cin.clear();
            std::cin.putback('\n');
            std::cin.get();
        }
        else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max());
        }
    }

    std::sort(friends.begin(), friends.end());
    std::cout << "\nHere is your list, " << holderName << ":\n";
    for (auto name : friends)
        std::cout << name << ", ";
    std::cout << "\b\b  \n";
}