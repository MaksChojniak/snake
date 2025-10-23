#ifndef COMPONENT_H
#define COMPONENT_H

#include <iostream>
// #include "GameObject.h"

class GameObject;

class Component
{
    protected: GameObject* owner_;

    public: Component();
    public: virtual ~Component();

    public: virtual void Update() = 0;

    public: void set_owner(GameObject* const owner);

    public: virtual std::ostream& view(std::ostream& out) const;
};

std::ostream& operator<<(std::ostream&, const Component&);
std::ostream& operator<<(std::ostream&, Component* const);

#endif