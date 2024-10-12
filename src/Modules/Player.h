#ifndef PLAYER_H
#define PLAYER_H

#include <godot_cpp/classes/character_body2d.hpp>
#include <godot_cpp/classes/input_event_key.hpp>

#include <godot_cpp/core/binder_common.hpp>
#include <godot_cpp/core/class_db.hpp>

namespace godot {

	class Player : public CharacterBody2D
	{
		GDCLASS(Player, CharacterBody2D)

		public:
			Player();
			~Player();

			void _physics_process(double delta) override;
			void _input(const Ref<InputEvent> &event);

		protected:
			static void _bind_methods();

		private:
			Vector2 m_Velocity;

			float m_MoveSpeed;
			float m_JumpForce;
			float m_Gravity;
			bool m_IsJumping;
	};

}

#endif // !PLAYER_H
