#include <iostream>

#if defined(WIN32) || defined(_WIN64)
using llong = long long;    //here long = 4 bytes and long long = 8 bytes
#elif defined(__unix__)
using llong = long;         //here long = 8 bytes and long long = 8 bytes too
#endif


int main() {
    const int HOURS_IN_DAY = 24;
    const int MINUTES_IN_HOUR = 60;
    const int SECONDS_IN_MINUTE = 60;

    setlocale(LC_ALL, "");
    std::wcout << L"Программа переводит введённые секунды "
                  L"в дни, часы, минуты.\n";
    std::wcout << L"Введите количество секунд: ";
    llong seconds = 0;
    std::cin >> seconds;

    std::wcout << seconds << L" секунд = ";
    int days = int(seconds / (HOURS_IN_DAY * MINUTES_IN_HOUR
                                           * SECONDS_IN_MINUTE));
    seconds = seconds - (llong(days) * HOURS_IN_DAY
                                     * MINUTES_IN_HOUR * SECONDS_IN_MINUTE);

    int hours = int(seconds / (MINUTES_IN_HOUR * SECONDS_IN_MINUTE));
    seconds = seconds - (llong(hours) * MINUTES_IN_HOUR
                                            * SECONDS_IN_MINUTE);

    int minutes = int(seconds / SECONDS_IN_MINUTE);
    seconds = seconds - (llong(minutes) * SECONDS_IN_MINUTE);

    std::wcout << days << L" дней, " << hours << L" часов, "
               << minutes << L" минут, " << seconds << L" секунд\n";


    return 0;
}
