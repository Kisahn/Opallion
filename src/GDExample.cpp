#include "GDExample.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

godot::GDExample::GDExample()
{
	time_passed = 0.0;
	amplitude = 10.0;
	speed = 1.0;
}

godot::GDExample::~GDExample()
{
}

void godot::GDExample::_process(double _delta)
{
	time_passed += speed * _delta;

	Vector2 new_position = Vector2(
			amplitude + (amplitude * sin(time_passed * 2.0)),
			amplitude + (amplitude * cos(time_passed * 1.5))
	);

	set_position(new_position);

	time_emit += _delta;
	if (time_emit > 1.0) {
		emit_signal("position_changed", this, new_position);
		time_emit = 0.0;
	}
}

double godot::GDExample::getAmplitude() const
{
	return amplitude;
}

double godot::GDExample::getSpeed() const
{
	return speed;
}

void godot::GDExample::setAmplitude(const double p_amplitude)
{
	amplitude = p_amplitude;
}

void godot::GDExample::setSpeed(const double p_speed)
{
	speed = p_speed;
}

void godot::GDExample::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("getAmplitude"), &GDExample::getAmplitude);
	ClassDB::bind_method(D_METHOD("setAmplitude", "p_amplitude"), &GDExample::setAmplitude);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "amplitude"), "setAmplitude", "getAmplitude");

	ClassDB::bind_method(D_METHOD("getSpeed"), &GDExample::getSpeed);
	ClassDB::bind_method(D_METHOD("setSpeed", "p_speed"), &GDExample::setSpeed);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "speed", PROPERTY_HINT_RANGE, "0,20,0.01"), "setSpeed", "getSpeed");

	ADD_SIGNAL(MethodInfo("position_changed", PropertyInfo(Variant::OBJECT, "node"), PropertyInfo(Variant::VECTOR2, "new_pos")));
}
