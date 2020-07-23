#pragma once

#include "..\GinPch.h"
#include "../Graphics/Texture2D.h"

namespace Gin
{
    namespace ECS
    {
        namespace Components
        {
            struct Sprite
            {
                Graphics::Texture2D Texture;

                Sprite() = default;
                Sprite(const Sprite &) = default;
                Sprite(const Graphics::Texture2D &sprite)
                    : Texture(sprite) {}
            };

        } // namespace Components

    } // namespace ECS

} // namespace Gin