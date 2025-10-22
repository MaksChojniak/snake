#include <iostream>

using namespace std;

struct Vector2Int
{
    public: static const Vector2Int Zero;// = Vector2Int(0, 0);
    public: static const Vector2Int Up;// = Vector2Int(0, 1);
    public: static const Vector2Int Down;// = Vector2Int(0, -1);
    public: static const Vector2Int Right;// = Vector2Int(1, 0);
    public: static const Vector2Int Left;// = Vector2Int(-1, 0);

    public: int x;
    public: int y;

    public: Vector2Int(): x(0), y(0) {}
    public: Vector2Int(const int& _x, const int& _y): x(_x), y(_y) {}
    public: Vector2Int(const Vector2Int& obj): x(obj.x), y(obj.y) {}


    public: const Vector2Int& operator=(const Vector2Int& obj)
    {
        if(this == &obj)
            return *this;
        
        x = obj.x;
        y = obj.y;
        
        return *this;
    } 
    
    public: Vector2Int operator+(const Vector2Int& obj) const
        { return Vector2Int(x + obj.x, y + obj.y); } 
    
    public: Vector2Int operator-(const Vector2Int& obj) const
        { return Vector2Int(x - obj.x, y - obj.y); } 
    
    public: Vector2Int operator*(const int& a) const
        { return Vector2Int(x * a, y * a); } 

    public: Vector2Int operator/(const int& a) const
        { return Vector2Int(x / a, y / a); } 

    public: bool operator==(const Vector2Int& obj) const 
        { return x == obj.x && y == obj.y; }
    public: bool operator!=(const Vector2Int& obj) const 
        { return x != obj.x || y != obj.y;}

    friend ostream& operator<<(ostream&, const Vector2Int&);
};

ostream& operator<<(ostream& out, const Vector2Int& obj) { return out << "(" << obj.x << "\t" << obj.y << ")"; }