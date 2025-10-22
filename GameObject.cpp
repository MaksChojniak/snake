#include <iostream>
#include <vector>
#include <algorithm> 
// #include "Component.cpp"

using namespace std;

class GameObject
{
    private: Vector2Int position_;
    public: const Vector2Int& position() const { return position_; }

    private: vector<Component*> components_;
    public: int components_length() const { return components_.size(); }

    public: GameObject(): position_(), components_() {}
    public: GameObject(const Vector2Int& pos): position_(pos), components_() {}
    public: GameObject(const Vector2Int& pos, const vector<Component*>& vec): position_(pos), components_(vec) {}

    public: ~GameObject()
    {
        for(int i = 0; i < components_length(); i++)
        {
            if(components_[i])
                delete components_[i];
        }
    }

    public: void Update()
    {
        for(int i = 0; i < components_length(); i++)
        {
            components_[i]->Update();
            
        }
    }

    public: Component& operator[](int i) { return *components_[i]; }

    friend ostream& operator<<(ostream&, GameObject&);
};

ostream& operator<<(ostream& out, GameObject& obj) 
{
    out << "[" << obj.components_length() << "]" << "\t";
    for(int i = 0; i < obj.components_length(); i++)
        out << obj.components_[i] << "\t";
    return out;
}