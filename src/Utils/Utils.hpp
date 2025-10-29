#ifndef UTILS_H
#define UTILS_H

#include <godot_cpp/godot.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/node3d.hpp>

namespace godot
{
    class Utils : public Object
    {
        GDCLASS(Utils, Object);

    protected:
        static void _bind_methods();

    public:
        Utils();
        ~Utils();
        float lerp(float from, float to, float t);
        void mensagem(Variant msg);
        Dictionary raycast(const Vector3 &from, const Vector3 &to, const Node3D *parent, int collision_mask = (1 << 0)) const;
    };

}

#endif