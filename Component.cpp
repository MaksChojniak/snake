#include <iostream>
#include "Component.h"
// #include "GameObject.h"

using namespace std;


Component::Component() {}
Component::~Component() {}

void Component::set_owner(GameObject* const owner) { owner_ = owner; }

ostream& Component::view(ostream& out) const { return out << "[Component]"; }

ostream& operator<<(ostream& out, const Component& obj) { return obj.view(out); }
ostream& operator<<(ostream& out, Component* const obj) { return (*obj).view(out); }