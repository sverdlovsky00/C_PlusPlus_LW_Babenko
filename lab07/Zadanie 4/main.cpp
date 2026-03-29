#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

const int H = 22;
const int W = 60;
const double PI = 3.1415926;

struct Canvas
{
    vector<string> field;

    Canvas()
    {
        field.assign(H, string(W, '.'));
    }

    void put(int x, int y, char ch)
    {
        if (x >= 0 && x < W && y >= 0 && y < H)
            field[y][x] = ch;
    }

    void print() const
    {
        for (int i = 0; i < (int)field.size(); i++)
            cout << field[i] << endl;
    }
};

class Figure
{
protected:
    int x;
    int y;
    int radius;
    int sector;
    string color;

public:
    Figure(int px, int py, int r, const string &c)
    {
        x = px;
        y = py;
        radius = r;
        sector = 60;
        color = c;
    }

    virtual ~Figure() {}
    virtual void draw(Canvas &canvas) const = 0;

    void move(int dx, int dy)
    {
        x += dx;
        y += dy;
    }

    void sectorMore()
    {
        sector += 15;
        if (sector > 300) sector = 300;
    }

    void sectorLess()
    {
        sector -= 15;
        if (sector < 0) sector = 0;
    }

    void changeColor()
    {
        if (color == "red") color = "green";
        else if (color == "green") color = "blue";
        else if (color == "blue") color = "yellow";
        else color = "red";
    }

    string getColor() const { return color; }
    int getSector() const { return sector; }
};

class Krug : public Figure
{
public:
    Krug(int px, int py, int r, const string &c) : Figure(px, py, r, c) {}

    void draw(Canvas &canvas) const
    {
        for (int py = y - radius; py <= y + radius; py++)
        {
            for (int px = x - radius * 2; px <= x + radius * 2; px++)
            {
                double dx = (px - x) * 0.5;
                double dy = py - y;
                double dist = sqrt(dx * dx + dy * dy);

                // Prostaya proverka ugla dlya vyreza
                double ang = atan2(dy, dx) * 180.0 / PI;
                if (ang < 0) ang += 360.0;

                bool inCut = (ang >= 0 && ang <= sector);

                if (dist <= radius && !inCut)
                    canvas.put(px, py, 'O');
            }
        }
    }
};

class Ring : public Figure
{
private:
    int width;

public:
    Ring(int px, int py, int r, int w, const string &c) : Figure(px, py, r, c)
    {
        width = w;
    }

    void draw(Canvas &canvas) const
    {
        for (int py = y - radius; py <= y + radius; py++)
        {
            for (int px = x - radius * 2; px <= x + radius * 2; px++)
            {
                double dx = (px - x) * 0.5;
                double dy = py - y;
                double dist = sqrt(dx * dx + dy * dy);

                double ang = atan2(dy, dx) * 180.0 / PI;
                if (ang < 0) ang += 360.0;

                bool inCut = (ang >= 90 && ang <= 90 + sector);

                if (dist <= radius && dist >= radius - width && !inCut)
                    canvas.put(px, py, '@');
            }
        }
    }
};

void renderOne(const Figure &f)
{
    Canvas c;
    f.draw(c);
    c.print();
}

void render(const Krug &a, const Ring &b)
{
    Canvas canvas;
    a.draw(canvas);
    b.draw(canvas);
    canvas.print();

    cout << endl;
    cout << "Upravlenie: w/a/s/d - dvigat krug, i/j/k/l - dvigat kolco" << endl;
    cout << "+ / - - uvelichit/umenishit vyrez u kruga" << endl;
    cout << "] / [ - uvelichit/umenishit vyrez u kolca" << endl;
    cout << "c - smena cveta kruga, v - smena cveta kolca" << endl;
    cout << "q - vyhod" << endl;

    cout << "Cvet kruga: " << a.getColor()
         << ", sektor: " << a.getSector() << endl;
    cout << "Cvet kolca: " << b.getColor()
         << ", sektor: " << b.getSector() << endl;
}

int main()
{
    setlocale(LC_ALL, "");

    // Zadanie 4 - Interaktivnaya demonstraciya figur
    Krug krug(15, 8, 4, "red");
    Ring ring(40, 12, 6, 2, "green");

    char cmd;

    do
    {
        cout << string(40, '\n');
        render(krug, ring);

        cout << "Komanda: ";
        cin >> cmd;

        if (cmd == 'w') krug.move(0, -1);
        if (cmd == 's') krug.move(0, 1);
        if (cmd == 'a') krug.move(-1, 0);
        if (cmd == 'd') krug.move(1, 0);

        if (cmd == 'i') ring.move(0, -1);
        if (cmd == 'k') ring.move(0, 1);
        if (cmd == 'j') ring.move(-1, 0);
        if (cmd == 'l') ring.move(1, 0);

        if (cmd == '+') krug.sectorMore();
        if (cmd == '-') krug.sectorLess();

        if (cmd == ']') ring.sectorMore();
        if (cmd == '[') ring.sectorLess();

        if (cmd == 'c') krug.changeColor();
        if (cmd == 'v') ring.changeColor();

    } while (cmd != 'q');

    return 0;
}
