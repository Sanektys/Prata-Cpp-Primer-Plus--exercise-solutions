#include <iostream>


int main() {
    const int HOURS_IN_DAY = 24;
    const int MINUTES_IN_HOUR = 60;
    const int SECONDS_IN_MINUTE = 60;

    setlocale(LC_ALL, "rus");
    std::wcout << L"Программа переводит введённые секунды в дни, часы, минуты.\n";
    std::wcout << L"Введите количество секунд: ";
    long long seconds = 0;
    std::cin >> seconds;

    std::wcout << seconds << L" секунд = ";
    int days = int(seconds / (HOURS_IN_DAY * MINUTES_IN_HOUR
                                           * SECONDS_IN_MINUTE));
    seconds = seconds - ((long long)(days) * HOURS_IN_DAY
                                           * MINUTES_IN_HOUR * SECONDS_IN_MINUTE);

    int hours = int(seconds / (MINUTES_IN_HOUR * SECONDS_IN_MINUTE));
    seconds = seconds - ((long long)(hours) * MINUTES_IN_HOUR
                                            * SECONDS_IN_MINUTE);

    int minutes = int(seconds / SECONDS_IN_MINUTE);
    seconds = seconds - (long long)(minutes) * SECONDS_IN_MINUTE;

    std::wcout << days << L" дней, " << hours << L" часов, "
               << minutes << L" минут, " << seconds << L" секунд\n";


    return 0;
}
