#pragma once
#include <string>
#include "./Keys.h"
#include "./InputType.hpp"

namespace Gin::Inputs {
   struct Action {
       InputType Type;
       std::string Name;
       int Value;
       int ID;

       Action(std::string name, Keys::Keys key ) {
           Name = name;
           Value = 0;
           ID = key;
           Type = KEYBOARD;
       }

       Action(std::string name, InputType type, int id, int value) {
           Name = name;
           Value = value;
           Type = type;
       }
   };
}