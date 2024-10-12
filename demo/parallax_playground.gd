extends Node


# Called when the node enters the scene tree for the first time.
func _ready():
	pass # Replace with function body.


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(_delta):
	pass


func _on_area_2d_body_entered(body):
	print("Le joueur est entré dans l'Area2D")
	if body.name == "Player":
		print("Le corps détecté est bien le joueur")
		
		var animation_player = $ParallaxBackground/BackgroundAnimationPlayer
		if animation_player:
			print("AnimationPlayer trouvé, lancement de l'animation...")
			animation_player.play("ShroomsGrowAndDisappear")
		else:
			print("AnimationPlayer introuvable !")
