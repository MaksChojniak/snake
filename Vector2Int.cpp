#include <iostream>

using namespace std;

struct Vector2Int
{
    public: int x;
    public: int y;

    public: Vector2Int(): x(0), y(0) {}
    public: Vector2Int(const int& x_, const int& y_): x(x_), y(y_) {}

    friend ostream& operator<<(ostream&, Vector2Int&);
};

ostream& operator<<(ostream& out, Vector2Int& obj) { return out << "(" << obj.x << "\t" << obj.y << ")"; }