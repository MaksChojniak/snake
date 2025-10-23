#ifndef MAP_H
#define MAP_H

#include <iostream>
#include "Vector2Int.h"
#include "GameObject.h"
#include "Move.h"

class Map
{
    private: Vector2Int size_;
    public: const Vector2Int& size() const;

    private: GameObject* player_;
    private: MoveComponent* player_mover_;

    public: Map(const Vector2Int& _size);
    public: ~Map();

    public: void set_player(GameObject* const player, MoveComponent* const player_mover);

    public: void display() const;
    public: bool is_in_bounds(const Vector2Int& pos);

    public: char get_char(const Vector2Int& pos) const;

    friend std::ostream& operator<<(std::ostream&, const Map&);
};

std::ostream& operator<<(std::ostream&, const Map&);

#endif