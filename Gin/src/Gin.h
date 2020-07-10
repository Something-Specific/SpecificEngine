#pragma once

//Helper functions
#include "Utils\Log.h"
#include "Graphics\Renderer.h"
#include "Graphics\Screen.h"
#include "Graphics\Texture2d.h"
#include "Graphics\Shader.h"
#include "Inputs\Controller.h"
#include "Inputs\Keyboard.h"
#include "Inputs\Mouse.h"
#include "Resources\ResourceLoader.h"
#include "Inputs\Processor.h"
#include "Display\Stage.h"
#include "Display\Actor.h"

//Engine Contracts
#include "ECS\Contracts\IComponent.h"
#include "ECS\Contracts\INode.h"
#include "ECS\Contracts\IRenderableSystem.h"
#include "ECS\Contracts\IUpdateableSystem.h"

//Engine core
#include "Core\MasterGame.h"
#include "ECS\Engine.h"
#include "ECS\Entity.h"

#include "ECS\System\SystemTypes.h"
#include "ECS\Components\ComponentType.h"

#include "ECS\Events\EventManager.h"
#include "ECS\SystemContext.h"


//Systems
#include "ECS\System\RenderSystem.h"

//Components
#include "ECS\Components\DisplayComponent.h"
#include "ECS\Components\IdentityComponent.h"
#include "ECS\Components\PositionComponent.h"
#include "ECS\Components\VelocityComponent.h"
#include "ECS\Components\RigidbodyComponent.h"
