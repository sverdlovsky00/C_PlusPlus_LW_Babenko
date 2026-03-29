#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

const int N = 5;

// vspomogatelnoe zapolnenie matrici
void fillRandom(double m[N][N])
{
    srand((unsigned)time(NULL));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            m[i][j] = (rand() % 200 - 50) / 10.0;
}

// Vspomogatelnyi vyvod matricy.
void printMatrix(double m[N][N])
{
    cout << endl << "Matrica:" << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << setw(8) << fixed << setprecision(2) << m[i][j];
        cout << endl;
    }
    cout << endl;
}

double mainDiagMin(double m[N][N])
{
    double mn = m[0][0];
    for (int i = 0; i < N; i++)
        if (m[i][i] < mn) mn = m[i][i];
    return mn;
}

double mainDiagMax(double m[N][N])
{
    double mx = m[0][0];
    for (int i = 0; i < N; i++)
        if (m[i][i] > mx) mx = m[i][i];
    return mx;
}

double secDiagMin(double m[N][N])
{
    double mn = m[0][N - 1];
    for (int i = 0; i < N; i++)
        if (m[i][N - 1 - i] < mn) mn = m[i][N - 1 - i];
    return mn;
}

double secDiagMax(double m[N][N])
{
    double mx = m[0][N - 1];
    for (int i = 0; i < N; i++)
        if (m[i][N - 1 - i] > mx) mx = m[i][N - 1 - i];
    return mx;
}

int main()
{
    setlocale(LC_ALL, "");

    // Zadanie 3 - glavnaya i vtorostepennaya diagonali
    double m[N][N];
    fillRandom(m);
    printMatrix(m);

    cout << "Minimum glavnoi diagonali: " << mainDiagMin(m) << endl;
    cout << "Maksimum glavnoi diagonali: " << mainDiagMax(m) << endl;
    cout << "Minimum vtorostepennoi diagonali: " << secDiagMin(m) << endl;
    cout << "Maksimum vtorostepennoi diagonali: " << secDiagMax(m) << endl;
    return 0;
}
