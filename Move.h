#ifndef MOVE_H
#define MOVE_H

#include <iostream>
#include "Vector2Int.h"
#include "GameObject.h"
#include "Component.h"
// #include "Map.h"
// #include "Input.h"

class Map;
class InputComponent;

class MoveComponent : public Component
{
    private: Map* map_;
    private: InputComponent* input_;

    public: MoveComponent(Map* map, InputComponent* input);

    public: void Update() override;

    private: void set_position(GameObject* const obj, const Vector2Int& pos);

    public: std::ostream& view(std::ostream& out) const override;
};

#endif