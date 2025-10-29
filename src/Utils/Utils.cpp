#include "Utils.hpp"
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/physics_ray_query_parameters3d.hpp>
#include <godot_cpp/classes/world3d.hpp>
#include <godot_cpp/classes/physics_direct_space_state3d.hpp>

using namespace godot;

void Utils::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("lerp", "from", "to", "t"), &Utils::lerp);
    ClassDB::bind_method(D_METHOD("mensagem", "msg"), &Utils::mensagem);
    ClassDB::bind_method(D_METHOD("raycast", "from", "to", "parent", "collision_mask"), &Utils::raycast, DEFVAL(1 << 0));
}

Utils::Utils()
{
}

Utils::~Utils()
{
}

float Utils::lerp(float from, float to, float t)
{
    return (to - from) * t;
}

void Utils::mensagem(Variant msg)
{
    UtilityFunctions::print(msg);
}

Dictionary Utils::raycast(const Vector3 &from, const Vector3 &to, const Node3D *parent, int collision_mask) const
{
    if (!parent)
    {
        UtilityFunctions::printerr("Utils::raycast — parent nulo!");
        return Dictionary();
    }

    Ref<World3D> world = parent->get_world_3d();
    if (world.is_null())
    {
        UtilityFunctions::printerr("Utils::raycast — mundo 3D nulo!");
        return Dictionary();
    }

    PhysicsDirectSpaceState3D *space_state = world->get_direct_space_state();
    if (!space_state)
    {
        UtilityFunctions::printerr("Utils::raycast — direct_space_state nulo!");
        return Dictionary();
    }

    Ref<PhysicsRayQueryParameters3D> params;
    params.instantiate();
    params->set_from(from);
    params->set_to(to);
    params->set_collide_with_areas(false);
    params->set_collide_with_bodies(true);
    params->set_collision_mask(collision_mask);

    Dictionary result = space_state->intersect_ray(params);

    return result;
}
