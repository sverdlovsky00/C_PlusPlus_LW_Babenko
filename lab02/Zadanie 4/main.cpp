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

double avgMatrix(double m[N][N])
{
    double s = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            s += m[i][j];
    return s / (N * N);
}

double avgLower(double m[N][N])
{
    double s = 0;
    int k = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= i; j++)
        {
            s += m[i][j];
            k++;
        }
    return s / k;
}

double avgUpper(double m[N][N])
{
    double s = 0;
    int k = 0;
    for (int i = 0; i < N; i++)
        for (int j = i; j < N; j++)
        {
            s += m[i][j];
            k++;
        }
    return s / k;
}

double sumLower(double m[N][N])
{
    double s = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= i; j++)
            s += m[i][j];
    return s;
}

double sumUpper(double m[N][N])
{
    double s = 0;
    for (int i = 0; i < N; i++)
        for (int j = i; j < N; j++)
            s += m[i][j];
    return s;
}

double closestToAverage(double m[N][N])
{
    double avg = avgMatrix(m);
    double best = m[0][0];
    double diff = fabs(m[0][0] - avg);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            double curDiff = fabs(m[i][j] - avg);
            if (curDiff < diff)
            {
                diff = curDiff;
                best = m[i][j];
            }
        }

    return best;
}

int main()
{
    setlocale(LC_ALL, "");

    // Zadanie 4 - srednie summy i element blizkii k srednemy
    double m[N][N];
    fillRandom(m);
    printMatrix(m);

    cout << "Srednee vsei matricy: " << avgMatrix(m) << endl;
    cout << "Srednee nizhnei chasti: " << avgLower(m) << endl;
    cout << "Srednee verkhnei chasti: " << avgUpper(m) << endl;
    cout << "Summa nizhnei chasti: " << sumLower(m) << endl;
    cout << "Summa verkhnei chasti: " << sumUpper(m) << endl;
    cout << "Element, blizkii k srednemu: " << closestToAverage(m) << endl;
    return 0;
}
