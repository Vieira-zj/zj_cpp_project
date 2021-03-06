#include <iostream>

using std::cout;
using std::endl;

class Top
{
protected:
    int x;
public:
    Top() { cout << "Default Top" << endl; }
    Top(int n) : x(n) { cout << "Top" << endl; }
};

class Left : public Top
{
protected:
    int y;
public:
    Left() { cout << "Default Left" << endl; }
    Left(int m, int n) : Top(m) { y = n; cout << "Left" << endl; }
};

class Right : public Top
{
protected:
    int z;
public:
    Right() { cout << "Default Right" << endl; }
    Right(int m, int n) : Top(m) { z = n; cout << "Right" << endl; }
};

class Bottom : public Left, public Right
{
    int w;
public:
    Bottom() { cout << "Default Bottom" << endl; }
};

int class_derived_main(void)
//int main(void)
{
    Bottom b;
    cout << "sizeof(b) " << sizeof(b) << "," << sizeof(Bottom) << endl; // 20
    cout << sizeof(Left) << "," << sizeof(Right) << "," << sizeof(Top) << endl; // 8,8,4

    return 0;
}
