#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include "Vector2Int.cpp"
#include "Component.cpp"

using namespace std;

struct termios orig_termios;

void reset_terminal();
void set_non_blocking();
bool is_key_pressed();
const Vector2Int& readInput(const Vector2Int&);

class InputComponent : public Component
{
    const int SLEEP_TIME = 1000000;

    private: Vector2Int direction_;
    public: const Vector2Int& direction() const { return direction_; }

    public: InputComponent(): direction_(Vector2Int::Down) {}

    public: void Update() override
    {
        direction_ = readInput(direction_);

        if(direction_ == Vector2Int::Up)
            cout << "UP" << endl;
        else if(direction_ == Vector2Int::Down)
            cout << "DOWN" << endl;
        else if(direction_ == Vector2Int::Left)
            cout << "LEFT" << endl;
        else if(direction_ == Vector2Int::Right)
            cout << "RIGHT" << endl;

        usleep(SLEEP_TIME);
    }


};

void reset_terminal() {
    tcsetattr(STDIN_FILENO, TCSANOW, &orig_termios);
}

void set_non_blocking() {
    termios new_termios;
    tcgetattr(STDIN_FILENO, &orig_termios);
    new_termios = orig_termios;

    new_termios.c_lflag &= ~(ICANON | ECHO);
    new_termios.c_cc[VMIN] = 0;
    new_termios.c_cc[VTIME] = 0;

    tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);
    atexit(reset_terminal);
}

bool is_key_pressed() {
    timeval tv = {0, 0};
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);
    select(STDIN_FILENO + 1, &fds, nullptr, nullptr, &tv);
    return FD_ISSET(STDIN_FILENO, &fds);
}

const Vector2Int& readInput(const Vector2Int& current) {
    if (is_key_pressed()) {
        char key;
        read(STDIN_FILENO, &key, 1);

        switch (key) {
            case 'w': case 'W': if (current != Vector2Int::Down)  return Vector2Int::Up; break;
            case 's': case 'S': if (current != Vector2Int::Up)    return Vector2Int::Down; break;
            case 'a': case 'A': if (current != Vector2Int::Right) return Vector2Int::Left; break;
            case 'd': case 'D': if (current != Vector2Int::Left)  return Vector2Int::Right; break;
            case 'q': case 'Q': return Vector2Int::Zero;
        }
    }
    return current;
}
