extends Node3D
@onready var static_body_3d: StaticBody3D = $StaticBody3D
@onready var camera_spring: CameraSpring = $CameraSpring

func _ready() -> void:
	Utils.mensagem("Olá! Estou printando direto do c++")
	pass
	
func _physics_process(_delta: float) -> void:
#	usando raycast direto do c++. está criando uma linha raycast da camera_spring até static_body_3d na cena
	var result = Utils.raycast(camera_spring.global_position, static_body_3d.global_position, self)

	if result:
		Utils.mensagem(result.position)
		
	pass
