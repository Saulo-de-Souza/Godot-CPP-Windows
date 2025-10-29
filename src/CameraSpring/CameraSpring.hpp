#ifndef CAMERA_SPRING_H
#define CAMERA_SPRING_H

#include <godot_cpp/godot.hpp>
#include <godot_cpp/classes/spring_arm3d.hpp>
#include <godot_cpp/classes/camera3d.hpp>

namespace godot
{
    class CameraSpring : public SpringArm3D
    {
        GDCLASS(CameraSpring, SpringArm3D);

    protected:
        static void _bind_methods();

    public:
        SpringArm3D *spring_arm = nullptr;
        Camera3D *camera = nullptr;
        float speed;

        CameraSpring();
        ~CameraSpring();
        virtual void _ready() override;
        virtual void _physics_process(double delta) override;

        void set_speed(float _speed);
        float get_speed();
    };
}

#endif