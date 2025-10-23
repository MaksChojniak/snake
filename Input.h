#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include "Component.h"
#include "Vector2Int.h"

class InputComponent : public Component
{
    static constexpr int SLEEP_TIME = 1000000;

    private: Vector2Int direction_;

    public:InputComponent();
    public:const Vector2Int& direction() const;
    public:Vector2Int& direction();

    public:void Update() override;
    public:std::ostream& view(std::ostream& out) const override;
};

void reset_terminal();
void set_non_blocking();
bool is_key_pressed();
const Vector2Int& readInput(const Vector2Int&);


#endif