#ifndef GDEXAMPLH_H
#define GDEXAMPLE_H

#include <godot_cpp/classes/sprite2d.hpp>

using namespace godot;

class GDExample : public Sprite2D
{
	GDCLASS(GDExample, Sprite2D)

public:
	GDExample();
	~GDExample();

	void _process(double delta) override;

	void set_amplitude(const double p_amplitude);
	double get_amplitude() const;

protected:
	static void _bind_methods();

private:
	double time_passed;
	double amplitude;
	double time_emit;
};

#endif
