#include <iostream>
#include "Vector2Int.h"

using namespace std;


Vector2Int::Vector2Int(): x(0), y(0) {}
Vector2Int::Vector2Int(const int& _x, const int& _y): x(_x), y(_y) {}
Vector2Int::Vector2Int(const Vector2Int& obj): x(obj.x), y(obj.y) {}

const Vector2Int& Vector2Int::operator=(const Vector2Int& obj)
{
    if(this == &obj)
        return *this;
    
    x = obj.x;
    y = obj.y;
    
    return *this;
} 
    
Vector2Int Vector2Int::operator+(const Vector2Int& obj) const
    { return Vector2Int(x + obj.x, y + obj.y); } 
    
Vector2Int Vector2Int::operator-(const Vector2Int& obj) const
    { return Vector2Int(x - obj.x, y - obj.y); } 
    
Vector2Int Vector2Int::operator*(const int& a) const
    { return Vector2Int(x * a, y * a); } 

Vector2Int Vector2Int::operator/(const int& a) const
    { return Vector2Int(x / a, y / a); } 

bool Vector2Int::operator==(const Vector2Int& obj) const 
    { return x == obj.x && y == obj.y; }
bool Vector2Int::operator!=(const Vector2Int& obj) const 
    { return x != obj.x || y != obj.y;}

const Vector2Int Vector2Int::Zero = Vector2Int(0, 0);
const Vector2Int Vector2Int::Up = Vector2Int(0, 1);
const Vector2Int Vector2Int::Down = Vector2Int(0, -1);
const Vector2Int Vector2Int::Right = Vector2Int(1, 0);
const Vector2Int Vector2Int::Left = Vector2Int(-1, 0);

ostream& operator<<(ostream& out, const Vector2Int& obj) { return out << "(" << obj.x << "\t" << obj.y << ")"; }