#include "Player.h"

godot::Player::Player() :
	m_Velocity(0, 0),
	m_MoveSpeed(100.0),
	m_JumpForce(200.0),
	m_Gravity(500.0),
	m_IsJumping(false)
{
}

godot::Player::~Player()
{
}

void godot::Player::_physics_process(double delta)
{

	if (!is_on_floor())
		m_Velocity.y += m_Gravity + delta;
	else
	{
		m_Velocity.y = 0;
		m_IsJumping = false;
	}

	set_velocity(m_Velocity);
	move_and_slide();
}

void godot::Player::_input(const Ref<InputEvent> &event)
{
	Ref<InputEventKey> key_event = event;

	if (key_event.is_valid() && key_event->is_pressed()) {
		if (key_event->get_keycode() == KEY_Z || key_event->get_keycode() == KEY_UP) {
			if (is_on_floor() && !m_IsJumping) {
				m_Velocity.y = m_JumpForce; // Appliquer la force de saut
				m_IsJumping = true;
			}
		} else if (key_event->get_keycode() == KEY_Q || key_event->get_keycode() == KEY_LEFT) {
			m_Velocity.x = m_MoveSpeed; // Déplacement vers la gauche
		} else if (key_event->get_keycode() == KEY_D || key_event->get_keycode() == KEY_RIGHT) {
			m_Velocity.x = m_MoveSpeed; // Déplacement vers la droite
		}
	}

	if (key_event.is_valid() && !key_event->is_pressed()) {
		if (key_event->get_keycode() == KEY_Q || key_event->get_keycode() == KEY_LEFT ||
				key_event->get_keycode() == KEY_D || key_event->get_keycode() == KEY_RIGHT) {
			m_Velocity.x = 0; // Arrêt du déplacement horizontal
		}
	}
}

void godot::Player::_bind_methods()
{
}
