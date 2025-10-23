#include <iostream>
#include "Move.h"
#include "Vector2Int.h"
#include "Map.h"
#include "Input.h"
#include "Component.h"

using namespace std;

MoveComponent::MoveComponent(Map* map, InputComponent* input): map_(map), input_(input)  {}

void MoveComponent::Update()
{
    Vector2Int newPos = owner_->position() + input_->direction();
    if(map_->is_in_bounds(newPos))
        set_position(owner_, newPos);
    else
        input_->direction() = Vector2Int::Zero;
}

void MoveComponent::set_position(GameObject* const obj, const Vector2Int& pos) { obj->position() = pos; }
char MoveComponent::get_char() const
{
    if(input_->direction() == Vector2Int::Up)
        return '^';
    if(input_->direction() == Vector2Int::Down)
        return 'v';
    if(input_->direction() == Vector2Int::Right)
        return '>';
    if(input_->direction() == Vector2Int::Left)
        return '<';
}

ostream& MoveComponent::view(ostream& out) const { return out << "[MoveComponent]"; }

