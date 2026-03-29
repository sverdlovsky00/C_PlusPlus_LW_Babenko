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

double colSum(double m[N][N], int col)
{
    double s = 0;
    for (int i = 0; i < N; i++)
        s += m[i][col];
    return s;
}

double colMin(double m[N][N], int col)
{
    double mn = m[0][col];
    for (int i = 1; i < N; i++)
        if (m[i][col] < mn) mn = m[i][col];
    return mn;
}

double colMax(double m[N][N], int col)
{
    double mx = m[0][col];
    for (int i = 1; i < N; i++)
        if (m[i][col] > mx) mx = m[i][col];
    return mx;
}

double colAvg(double m[N][N], int col)
{
    return colSum(m, col) / N;
}

int main()
{
    setlocale(LC_ALL, "");

    // Zadanie 6 - inform po stolbcam matrici
    double m[N][N];
    fillRandom(m);
    printMatrix(m);

    for (int j = 0; j < N; j++)
    {
        cout << "Stolbec " << j
             << ": sum = " << colSum(m, j)
             << ", min = " << colMin(m, j)
             << ", max = " << colMax(m, j)
             << ", avg = " << colAvg(m, j) << endl;
    }
    return 0;
}
