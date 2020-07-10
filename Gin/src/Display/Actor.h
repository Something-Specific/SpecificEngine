#pragma once

namespace Gin {
	namespace Display {
		class Actor
		{
		public:
			Actor();
			~Actor();
			void Update(Inputs::Processor* processor, float dt);
			void Render(Graphics::Renderer* renderer, float dt);
		private:
		};
	}
}