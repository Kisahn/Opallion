#ifndef GDEXAMPLE_H
#define GDEXAMPLE_H

#include <godot_cpp/classes/sprite2d.hpp>

namespace godot {

	class GDExample : public Sprite2D
	{
		GDCLASS(GDExample, Sprite2D)

		public:
			GDExample();
			~GDExample();

			void _process(double _delta) override;

			double getAmplitude() const;
			double getSpeed() const;

			void setAmplitude(const double p_amplitude);
			void setSpeed(const double p_speed);

		protected:
			static void _bind_methods();

		private:
			double time_passed;
			double amplitude;
			double speed;
			double time_emit;
	};

}

#endif // !GDEXAMPLE_H
