
#include "Collision.h"

namespace Gin::Math
{
    using namespace glm;
    using namespace ECS::Components;

    bool IsColliding(
        Transform &t1,
        Collider &c1,
        Transform &t2,
        Collider &c2)
    {
        if (c1.Type == BOX_TYPE && c2.Type == BOX_TYPE) {
            return BoxIsCollidingBox(
                t1, dynamic_cast<BoxCollider&>(c1),
                t2, dynamic_cast<BoxCollider&>(c2));
        }
        else if (c1.Type == CIRCLE_TYPE && c2.Type == BOX_TYPE) {
            return CircleIsCollidingBox(
                t1, dynamic_cast<CircleCollider&>(c1),
                t2, dynamic_cast<BoxCollider&>(c2));
        }
        else if (c1.Type == BOX_TYPE && c2.Type == CIRCLE_TYPE) {
            return CircleIsCollidingBox(
                t2, dynamic_cast<CircleCollider&>(c2),
                t1, dynamic_cast<BoxCollider&>(c1));
        }
        else {
            return CircleIsCollidingCircle(
                t1, dynamic_cast<CircleCollider&>(c1),
                t2, dynamic_cast<CircleCollider&>(c2));
        }
    }

    bool BoxIsCollidingBox(
        Transform &t1, BoxCollider &c1,
        Transform &t2, BoxCollider &c2)
    {
        return IntersectRectangleRectangle(
            t1.Position, c1.Size, t2.Position, c2.Size);
    }

    bool CircleIsCollidingBox(
        Transform &t1, CircleCollider &c1,
        Transform &t2, BoxCollider &c2)
    {
        return IntersectCircleRectangle(
            t1.Position, c1.Radius, t2.Position, c2.Size);
    }

    bool CircleIsCollidingCircle(
        Transform &t1,
        CircleCollider &c1,
        Transform &t2,
        CircleCollider &c2)
    {
        return IntersectCircleCircle(
            t1.Position, c1.Radius, t2.Position, c2.Radius);
    }



    bool IntersectCircleCircle(
        const vec2& circlePosition1, float circleRadius1,
        const vec2& circlePosition2, float circleRadius2)
    {
        return distance(circlePosition1, circlePosition2) <= (circleRadius1 + circleRadius2);
    }

    bool IntersectRectangleRectangle(
        const vec2& rectanglePosition1, const vec2& rectangleSize1,
        const vec2& rectanglePosition2, const vec2& rectangleSize2)
    {
        vec2 v1 = rectanglePosition1 - (rectangleSize1 / 2.f);
        vec2 v2 = rectanglePosition1 + (rectangleSize1 / 2.f);
        vec2 u1 = rectanglePosition2 - (rectangleSize2 / 2.f);
        vec2 u2 = rectanglePosition2 + (rectangleSize2 / 2.f);
        return !(
            u1.x >= v2.x ||
            u2.x <= v1.x ||
            u1.x >= v2.y ||
            u2.y <= v1.y
            );
    }

    bool IntersectCircleRectangle(
        const vec2& circlePosition, float circleRadius,
        const vec2& rectanglePosition, const vec2& rectangleSize)
    {
        vec2 half = rectangleSize / 2.f;
        vec2 v1 = vec2(rectanglePosition.x - half.x, rectanglePosition.y - half.y);
        vec2 v2 = vec2(rectanglePosition.x - half.x, rectanglePosition.y + half.y);
        vec2 v3 = vec2(rectanglePosition.x + half.x, rectanglePosition.y - half.y);
        vec2 v4 = vec2(rectanglePosition.x + half.x, rectanglePosition.y + half.y);

        // Checks if any rectangle segment intersects the circle, then if the 
        // circle is completely contained inside the rectangle. 
        return
            IntersectLineCircle(v1, v3, circlePosition, circleRadius) ||
            IntersectLineCircle(v1, v4, circlePosition, circleRadius) ||
            IntersectLineCircle(v2, v3, circlePosition, circleRadius) ||
            IntersectLineCircle(v3, v4, circlePosition, circleRadius) ||
            IntersectPointRectangle(circlePosition, v1, v4);
    }

    bool IntersectLineCircle(
        const vec2& segmentA, const vec2& segmentB,
        const vec2& circlePosition, float circleRadius)
    {
        vec2 closest = ClosestPointOnSegment(circlePosition, segmentA, segmentB);
        return distance(closest, circlePosition) <= circleRadius;
    }

    vec2 ClosestPointOnSegment(const vec2& point, const vec2& segmentA, const vec2& segmentB)
    {
        CORE_ASSERT(segmentA == segmentB, "ClosestPointOnSegment was passed non-unique segment points.");

        vec2 segmentV = segmentB - segmentA;
        vec2 pointV = point - segmentA;
        vec2 segVNorm = normalize(segmentV);
        float projection = dot(pointV, segmentV);

        if (projection <= 0) return segmentA;
        if (projection >= segmentV.length()) return segmentB;

        vec2 projectionV = segmentV * projection;
        vec2 closest = projectionV + segmentA;
        return closest;
    }

    bool IntersectPointRectangle(const vec2& p, const vec2& v1, const vec2& v2)
    {
        return
            p.x >= v1.x &&
            p.x <= v2.x &&
            p.y >= v1.y &&
            p.y <= v2.y;
    }


} // namespace Gin::Math