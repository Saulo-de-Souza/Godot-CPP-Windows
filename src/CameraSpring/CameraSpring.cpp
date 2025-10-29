
#include "CameraSpring.hpp"
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/sphere_shape3d.hpp>
#include <godot_cpp/classes/input_event_mouse.hpp>
#include <godot_cpp/classes/input_event_action.hpp>
#include <godot_cpp/classes/input_event.hpp>
#include <godot_cpp/classes/input.hpp>

using namespace godot;

void CameraSpring::_bind_methods()
{
    ADD_GROUP("Camera Spring", "");
    ADD_SUBGROUP("Physics", "");
    ClassDB::bind_method(D_METHOD("set_speed", "_speed"), &CameraSpring::set_speed);
    ClassDB::bind_method(D_METHOD("get_speed"), &CameraSpring::get_speed);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "speed", godot::PROPERTY_HINT_RANGE, "0.0, 20.0, 0.1, or_greater, suffix:m/s"), "set_speed", "get_speed");
}

CameraSpring::CameraSpring()
{
    speed = 5.0f;
}

CameraSpring::~CameraSpring()
{
}

void CameraSpring::_ready()
{
    if (Engine::get_singleton()->is_editor_hint())
    {
        set_process(false);
        set_physics_process(false);
    }

    spring_arm = Object::cast_to<SpringArm3D>(get_node_or_null("SpringArm3D"));
    camera = Object::cast_to<Camera3D>(get_node_or_null("Camera3D"));

    if (!this->spring_arm)
    {
        spring_arm = memnew(SpringArm3D);
        spring_arm->set_name("SpringArm3D");
        UtilityFunctions::print("SpringArm3D criado e adicionado!");
    }

    if (!this->camera)
    {
        camera = memnew(Camera3D);
        camera->set_name("Camera3D");
        UtilityFunctions::print("Camera3D criado e adicionado!");
    }
    spring_arm->set_shape(memnew(SphereShape3D));
    spring_arm->add_child(this->camera);
    add_child(spring_arm);
}

void CameraSpring::_physics_process(double delta)
{
    Vector2 direction2d = Input::get_singleton()->get_vector("ui_left", "ui_right", "ui_up", "ui_down");
    Vector3 direction3d = Vector3(direction2d.x, 0, direction2d.y);

    if (direction3d.length() > 0)
    {
        direction3d = direction3d.normalized() * speed * delta;
        set_global_position(get_global_position() + direction3d);
    }
}

void CameraSpring::set_speed(float _speed)
{
    speed = _speed;
}
float CameraSpring::get_speed()
{
    return speed;
}