#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <iostream>
#include <vector>
#include "Vector2Int.h"
// #include "Component.h"
#include "Move.h"

class Component;

class GameObject
{
    private: Vector2Int position_;
    public: const Vector2Int& position() const;
    public: Vector2Int& position();

    private: std::vector<Component*> components_;
    public: int components_length() const;

    public: GameObject();
    public: GameObject(const Vector2Int& pos);
    public: GameObject(const Vector2Int& pos, const std::vector<Component*>& vec);

    public: ~GameObject();

    public: void Update();

    public: Component& operator[](int i);

    friend std::ostream& operator<<(std::ostream&, GameObject&);
};

std::ostream& operator<<(std::ostream&, GameObject&) ;

#endif