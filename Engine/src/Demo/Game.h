

#ifndef GAME_H
#define GAME_H

namespace Demo
{
	class Game
	{
		public:
			Game();
			~Game();
			void Init();
			void Update(float dt);
			void Render();
	};
}

#endif