#include <iostream>
#include <string>
#include "SinglyList.h"

using namespace std;

struct Bus
{
    int number;
    string driver;
    int route;
};

bool operator==(const Bus &a, const Bus &b)
{
    return a.number == b.number;
}

void printBus(const Bus &b)
{
    cout << "Avtobus #" << b.number
         << ", voditel: " << b.driver
         << ", marshrut: " << b.route << endl;
}

void fillPark(SinglyList<Bus> &park)
{
    // Zagruzhaem nachalnye avtobusy v park
    Bus b;

    b.number = 101; b.driver = "Ivanov I.I."; b.route = 12; park.pushBack(b);
    b.number = 205; b.driver = "Petrov P.P."; b.route = 18; park.pushBack(b);
    b.number = 310; b.driver = "Sidorov S.S."; b.route = 7; park.pushBack(b);
    b.number = 411; b.driver = "Kozlov A.A."; b.route = 24; park.pushBack(b);
}

void moveBus(SinglyList<Bus> &from, SinglyList<Bus> &to, int number)
{
    Bus key;
    key.number = number;
    key.driver = "";
    key.route = 0;

    Bus temp;

    if (from.removeValue(key, &temp))
    {
        to.pushBack(temp);
        cout << "Avtobus #" << number << " peremeshchen." << endl;
    }
    else
    {
        cout << "Avtobus #" << number << " ne naiden." << endl;
    }
}

void showMenu()
{
    cout << endl;
    cout << "1 - pokazat avtobusy v parke" << endl;
    cout << "2 - pokazat avtobusy na marshrute" << endl;
    cout << "3 - avtobus vyehal iz parka" << endl;
    cout << "4 - avtobus vernulsya v park" << endl;
    cout << "0 - vyhod" << endl;
    cout << "Vash vybor: ";
}

int main()
{
    setlocale(LC_ALL, "");

    // Zadanie 2 - Uchet avtobusov v parke i na marshrute
    SinglyList<Bus> park;
    SinglyList<Bus> route;

    fillPark(park);

    int choice;

    do
    {
        showMenu();
        cin >> choice;

        if (choice == 1)
        {
            cout << endl << "Avtobusy v parke:" << endl;
            park.print(printBus);
        }
        else if (choice == 2)
        {
            cout << endl << "Avtobusy na marshrute:" << endl;
            route.print(printBus);
        }
        else if (choice == 3)
        {
            int number;
            cout << "Nomer avtobusa: ";
            cin >> number;
            moveBus(park, route, number);
        }
        else if (choice == 4)
        {
            int number;
            cout << "Nomer avtobusa: ";
            cin >> number;
            moveBus(route, park, number);
        }

    } while (choice != 0);

    return 0;
}
