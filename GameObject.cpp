#include <iostream>
#include <vector>
#include <algorithm> 
#include "GameObject.h"
// #include "Vector2Int.h"
#include "Component.h"
#include "Move.h"

using namespace std;

const Vector2Int& GameObject::position() const { return position_; }
Vector2Int& GameObject::position() { return position_; }

int GameObject::components_length() const { return components_.size(); }

GameObject::GameObject(): position_(), components_() {}
GameObject::GameObject(const Vector2Int& pos): position_(pos), components_() {}
GameObject::GameObject(const Vector2Int& pos, const vector<Component*>& vec): position_(pos), components_(vec) 
{
    for(int i = 0; i < components_length(); i++)
        components_[i]->set_owner(this);
}

GameObject::~GameObject()
{
    for(int i = 0; i < components_length(); i++)
    {
        if(components_[i])
            delete components_[i];
    }
}

void GameObject::Update()
{
    for(int i = 0; i < components_length(); i++)
    {
        components_[i]->Update();
        
    }
}

Component& GameObject::operator[](int i) { return *components_[i]; }



ostream& operator<<(ostream& out, GameObject& obj) 
{
    out << "[" << obj.components_length() << "]" << "\t";
    for(int i = 0; i < obj.components_length(); i++)
        out << obj.components_[i] << "\t";
    return out;
}