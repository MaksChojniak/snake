#include <iostream>
#include <cstdlib>

#include "Vector2Int.h"
#include "Map.h"
#include "Input.h"
#include "Move.h"
#include "GameObject.h"

using namespace std;

int main()
{
    Map* map = new Map(Vector2Int(11, 11));

    InputComponent* input = new InputComponent();
    MoveComponent* move = new MoveComponent(map, input);
    GameObject* obj = new GameObject(Vector2Int(5, 6), { input, move });

    map->set_player(obj, move);

    set_non_blocking();
    while (input->direction() != Vector2Int::Zero) 
    {
        obj->Update();
        
        system("clear");
        map->display();
    }

    delete map;

    return 0;
}
