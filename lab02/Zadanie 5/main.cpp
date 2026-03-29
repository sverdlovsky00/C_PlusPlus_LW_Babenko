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

double rowSum(double m[N][N], int row)
{
    double s = 0;
    for (int j = 0; j < N; j++)
        s += m[row][j];
    return s;
}

double rowMin(double m[N][N], int row)
{
    double mn = m[row][0];
    for (int j = 1; j < N; j++)
        if (m[row][j] < mn) mn = m[row][j];
    return mn;
}

double rowMax(double m[N][N], int row)
{
    double mx = m[row][0];
    for (int j = 1; j < N; j++)
        if (m[row][j] > mx) mx = m[row][j];
    return mx;
}

double rowAvg(double m[N][N], int row)
{
    return rowSum(m, row) / N;
}

int main()
{
    setlocale(LC_ALL, "");

    // Zadanie 5 - inform po strokam matric
    double m[N][N];
    fillRandom(m);
    printMatrix(m);

    for (int i = 0; i < N; i++)
    {
        cout << "Stroka " << i
             << ": sum = " << rowSum(m, i)
             << ", min = " << rowMin(m, i)
             << ", max = " << rowMax(m, i)
             << ", avg = " << rowAvg(m, i) << endl;
    }
    return 0;
}
