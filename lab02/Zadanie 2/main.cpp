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

// vspomogatelnyi vyvod matrici
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

double lowerMin(double m[N][N])
{
    double mn = m[0][0];
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= i; j++)
            if (m[i][j] < mn) mn = m[i][j];
    return mn;
}

double lowerMax(double m[N][N])
{
    double mx = m[0][0];
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= i; j++)
            if (m[i][j] > mx) mx = m[i][j];
    return mx;
}

double upperMin(double m[N][N])
{
    double mn = m[0][0];
    for (int i = 0; i < N; i++)
        for (int j = i; j < N; j++)
            if (m[i][j] < mn) mn = m[i][j];
    return mn;
}

double upperMax(double m[N][N])
{
    double mx = m[0][0];
    for (int i = 0; i < N; i++)
        for (int j = i; j < N; j++)
            if (m[i][j] > mx) mx = m[i][j];
    return mx;
}

int main()
{
    setlocale(LC_ALL, "");

    // Zadanie 2 - nizhnyaya i verkhnyaya treugolnye chasti
    double m[N][N];
    fillRandom(m);
    printMatrix(m);

    cout << "Minimum nizhnei chasti: " << lowerMin(m) << endl;
    cout << "Maksimum nizhnei chasti: " << lowerMax(m) << endl;
    cout << "Minimum verkhnei chasti: " << upperMin(m) << endl;
    cout << "Maksimum verkhnei chasti: " << upperMax(m) << endl;
    return 0;
}
