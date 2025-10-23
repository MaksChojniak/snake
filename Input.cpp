#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include "Input.h"
// #include "Vector2Int.h"
// #include "Component.h"

using namespace std;


const Vector2Int& InputComponent::direction() const { return direction_; }
Vector2Int& InputComponent::direction() { return direction_; }

InputComponent::InputComponent(): direction_(Vector2Int::Down) {}

void InputComponent::Update()
{
    usleep(SLEEP_TIME);
    direction_ = readInput(direction_);
}

ostream& InputComponent::view(ostream& out) const { return out << "[InputComponent]"; }



struct termios orig_termios;

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
