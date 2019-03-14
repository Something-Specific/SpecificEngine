
#ifndef GAME_H
#define GAME_H

#include "../Core/MasterGame.h"

namespace Demo
{

	class Game : public Core::MasterGame
	{
	public:
		void Update(float dt);
		void Render(Core::Graphics::Renderer *renderer);

	private:
		void Init();
	};

}

#endif