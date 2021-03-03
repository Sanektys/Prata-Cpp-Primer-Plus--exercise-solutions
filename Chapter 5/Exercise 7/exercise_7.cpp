#include <iostream>


struct Car {
    char brandName[32];
    short releaseYear;
};

int main() {
    setlocale(LC_ALL, "");

    std::wcout << L"Программа запрашивает название и год выпуска автомобиля\n"
                  L"а также сколько подобных записей "
                  L"нужно занести в каталог\n\n";
    std::wcout << L"Сколько автомобилей поместить в католог? ";
    short amount{};
    (std::cin >> amount).get();
    
    Car* carCatalog = new Car[amount];
    for (short i = 0; i < amount; i++) {
        std::wcout << L"Автомобиль №" << i + 1 << ":\n";
        std::wcout << L"Введите производителя: ";
        std::cin.getline((*(carCatalog + i)).brandName, 31);
        std::wcout << L"Укажите год выпуска: ";
        (std::cin >> carCatalog[i].releaseYear).get();
    }

    std::wcout << L"\nВы ввели следующий каталог:\n";
    for (short i = 0; i < amount; ++i)
        std::wcout << carCatalog[i].releaseYear << ' '
                   << carCatalog[i].brandName << std::endl;
    delete[] carCatalog;


    return 0;
}
