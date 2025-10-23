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

    map->set_player(obj);

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



// const SLEEP_TIME = 1000000;

// int main() {
//     Direction dir = DOWN;
//     set_non_blocking();

//     cout << "Snake Input System (WASD to move, Q to quit)\n";

//     while (dir != STOP) {
//         dir = readInput(dir);

//         switch (dir) {
//             case UP:    cout << "UP\n"; break;
//             case DOWN:  cout << "DOWN\n"; break;
//             case LEFT:  cout << "LEFT\n"; break;
//             case RIGHT: cout << "RIGHT\n"; break;
//             case STOP:  cout << "QUIT\n"; break;
//             default: break;
//         }

//         usleep(SLEEP_TIME);
//     }

//     cout << "Game Ended!\n";
//     return 0;
// }

