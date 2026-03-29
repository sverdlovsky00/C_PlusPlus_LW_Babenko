#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

const int N = 5;

// Vspomogatelnoe zapolnenie matricy
void fillRandom(double m[N][N])
{
    srand((unsigned)time(NULL));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            m[i][j] = (rand() % 200 - 50) / 10.0;
}

// Vspomogatelnyi vyvod matricy
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

double matrixMin(double m[N][N])
{
    double mn = m[0][0];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (m[i][j] < mn) mn = m[i][j];
    return mn;
}

double matrixMax(double m[N][N])
{
    double mx = m[0][0];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (m[i][j] > mx) mx = m[i][j];
    return mx;
}

int main()
{
    setlocale(LC_ALL, "");

    // Zadanie 1 - vvod, vyvod, minimum i maksimum vsei matricy
    double m[N][N];
    fillRandom(m);
    printMatrix(m);

    cout << "Minimum matricy: " << matrixMin(m) << endl;
    cout << "Maksimum matricy: " << matrixMax(m) << endl;
    return 0;
}
