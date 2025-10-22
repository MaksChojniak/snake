#include <iostream>
// #include "Vector2Int.cpp"
#include "Input.cpp"
#include "GameObject.cpp"

using namespace std;

class TestComponent : public Component
{
    private: string str_;

    public: TestComponent(const string& str = "0"): Component(), str_(str) {}

    public: void Test() const { cout << "test method" << endl; }

    public: ostream& view(ostream& out) const override { return out << "[TestComponent " << str_ << "]"; }
};

const Vector2Int Vector2Int::Zero = Vector2Int(0, 0);
const Vector2Int Vector2Int::Up = Vector2Int(0, 1);
const Vector2Int Vector2Int::Down = Vector2Int(0, -1);
const Vector2Int Vector2Int::Right = Vector2Int(1, 0);
const Vector2Int Vector2Int::Left = Vector2Int(-1, 0);

int main()
{
    InputComponent* input = new InputComponent();
    GameObject obj(Vector2Int(1, 1), { input });

    set_non_blocking();
    while (input->direction() != Vector2Int::Zero) 
    {
        obj.Update();
    }

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

