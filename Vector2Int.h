#ifndef VECTOR2INT_H
#define VECTOR2INT_H

#include <iostream>

struct Vector2Int
{
    public: static const Vector2Int Up, Down, Left, Right, Zero;
    public: int x;
    public: int y;

    public: Vector2Int();
    public: Vector2Int(const int& _x, const int& _y);
    public: Vector2Int(const Vector2Int& obj);


    public: const Vector2Int& operator=(const Vector2Int& obj);
    
    public: Vector2Int operator+(const Vector2Int& obj) const;
    public: Vector2Int operator-(const Vector2Int& obj) const;
    public: Vector2Int operator*(const int& a) const;
    public: Vector2Int operator/(const int& a) const;
    public: bool operator==(const Vector2Int& obj) const;
    public: bool operator!=(const Vector2Int& obj) const;

    friend std::ostream& operator<<(std::ostream&, const Vector2Int&);
};

std::ostream& operator<<(std::ostream&, const Vector2Int&);

#endif