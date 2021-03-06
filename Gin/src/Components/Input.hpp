#pragma once

#include <string>
#include "..\GinPch.h"


namespace Gin::ECS::Components
{
    struct Input
    {
        Input() = default;
        Input(const Input &) = default;

        std::map<std::string, short> Actions;
        //std::map<string, bool> Actions;
    };

} // namespace Gin::ECS::Components