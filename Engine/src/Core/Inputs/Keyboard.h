
#ifndef  KEYBOARD_H
#define KEYBOARD_H

namespace Core
{
	namespace Inputs
	{
		class Keyboard
		{
		public:
			Keyboard();
			~Keyboard();

			void UpdateState(int key, int action);

		};
	}
}

#endif // ! KEYBOARD_H
