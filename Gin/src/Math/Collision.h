#pragma once

#include <glm/glm.hpp>
#include "../Components/Collider.hpp"
#include "../Components/Transform.hpp"

namespace Gin::Math
{
    bool IsColliding(
        ECS::Components::Transform &t1,
        ECS::Components::Collider &c1,
        ECS::Components::Transform &t2,
        ECS::Components::Collider &c2);

    bool BoxIsCollidingBox(
        ECS::Components::Transform &t1,
        ECS::Components::BoxCollider &c1,
        ECS::Components::Transform &t2,
        ECS::Components::BoxCollider &c2);

    bool CircleIsCollidingBox(
        ECS::Components::Transform &t1,
        ECS::Components::CircleCollider &c1,
        ECS::Components::Transform &t2,
        ECS::Components::BoxCollider &c2);

    bool CircleIsCollidingCircle(
        ECS::Components::Transform &t1,
        ECS::Components::CircleCollider &c1,
        ECS::Components::Transform &t2,
        ECS::Components::CircleCollider &c2);


    bool IntersectCircleCircle(
        const glm::vec2& circlePosition1,
        float circleRadius1,
        const glm::vec2& circlePosition2,
        float circleRadius2);

    bool IntersectRectangleRectangle(
        const glm::vec2& rectanglePosition1,
        const glm::vec2& rectangleSize1,
        const glm::vec2& rectanglePosition2,
        const glm::vec2& rectangleSize2);

    bool IntersectCircleRectangle(
        const glm::vec2& circlePosition,
        float circleRadius,
        const glm::vec2& rectanglePosition,
        const glm::vec2& rectangleSize);

    bool IntersectLineCircle(
        const glm::vec2& segmentA,
        const glm::vec2& segmentB,
        const glm::vec2& circlePosition,
        float circleRadius);


    glm::vec2 ClosestPointOnSegment(
        const glm::vec2& point,
        const glm::vec2& segmentA,
        const glm::vec2& segmentB);


    bool IntersectPointRectangle(
        const glm::vec2& p,
        const glm::vec2& v1,
        const glm::vec2& v2);


} // namespace Gin::Math