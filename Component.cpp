#include <iostream>

using namespace std;

class Component
{
    public: Component() {}
    public: virtual ~Component() {}

    public: virtual void Update() = 0;

    public: virtual ostream& view(ostream& out) const { return out << "[Component]"; }
};

ostream& operator<<(ostream& out, const Component& obj) { return obj.view(out); }
ostream& operator<<(ostream& out, Component* const obj) { return (*obj).view(out); }