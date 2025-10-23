#include <iostream>
#include "Map.h"
// #include "Vector2Int.h"
// #include "GameObject.h"

using namespace std;

const Vector2Int& Map::size() const { return size_; }

Map::Map(const Vector2Int& _size): size_(_size) {}
Map::~Map()
{
    if(player_)
        delete player_;
}

void Map::set_player(GameObject* const player, MoveComponent* const player_mover)
{
    player_ = player;
    player_mover_ = player_mover;
    cout << "set player on position: " << player_->position() << endl;
}

void Map::display() const { cout << *this << endl; }

bool Map::is_in_bounds(const Vector2Int& pos) { return pos.x >= 0 && pos.x < size_.x && pos.y >= 0 && pos.y < size_.y; }

char Map::get_char(const Vector2Int& pos) const
{
    if(player_->position() == pos)
        return player_mover_->get_char(); 
    return ' '; 
}


ostream& operator<<(ostream& out, const Map& obj) 
{ 
    for(int y = obj.size().y-1; y >= 0 ; y--) 
    {
        for(int x = 0; x < obj.size().x; x++) 
        {
            if(x == 0)
                out << "|";
            out << obj.get_char(Vector2Int(x, y)) << "|";
        }
        out << endl;
    }
    return out;
}