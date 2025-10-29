#include "RegisterTypes.hpp"
#include "CameraSpring/CameraSpring.hpp"
#include "Utils/Utils.hpp"

#include <gdextension_interface.h>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/classes/input_map.hpp>
#include <godot_cpp/classes/texture2d.hpp>
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/project_settings.hpp>

using namespace godot;

static Utils *utils_singleton = nullptr;

void register_types(ModuleInitializationLevel p_level)
{
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE)
    {
        return;
    }

    ClassDB::register_class<CameraSpring>();
    ClassDB::register_class<Utils>();

    // Registrando Utils como singleton
    utils_singleton = memnew(Utils);
    Engine::get_singleton()->register_singleton("Utils", utils_singleton);
}

void unregister_types(ModuleInitializationLevel p_level)
{
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE)
    {
        // Removendo Utils
        if (utils_singleton)
        {
            Engine::get_singleton()->unregister_singleton("Utils");
            memdelete(utils_singleton);
            utils_singleton = nullptr;
        }

        return;
    }
}

extern "C"
{
    GDExtensionBool GDE_EXPORT register_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization)
    {
        godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

        init_obj.register_initializer(register_types);
        init_obj.register_terminator(unregister_types);
        init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

        return init_obj.init();
    }
}
