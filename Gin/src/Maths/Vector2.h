#pragma once


namespace Gin {
	namespace Maths {
		template <typename T>
		class Vector2
		{

		public:
			T x;
			T y;

			Vector2() {
				x = 0;
				y = 0;
			}
			Vector2(T x, T y) {
				this->x = x;
				this->y = y;
			}
			template <typename U>
			explicit Vector2(const Vector2<U>& vector) {
				x = vector.x;
				y = vector.y;
			}
		};
		
		template < typename T>
		Vector2<T>& operator +=(Vector2<T>& left, const Vector2<T>& right) {
			left.x += right.x;
			left.y += right.y;
		}
		
		template < typename T>
		Vector2<T>& operator -=(Vector2<T>& left, const Vector2<T>& right) {
			left.x -= right.x;
			left.y -= right.y;
		}
		
		template < typename T>
		Vector2<T> operator +(const Vector2<T>& left, const Vector2<T>& right) {
			return Vector2<T>(left.x + right.x, left.y + right.y);
		}
		
		template < typename T>
		Vector2<T> operator -(const Vector2<T>& left, const Vector2<T>& right) {
			return Vector2<T>(left.x - right.x, left.y - right.y);
		}
		
		template < typename T>
		Vector2<T> operator *=(const Vector2<T>& left, T right) {
			left.x *= right;
			left.y *= right;
		}
		
		template < typename T>
		Vector2<T> operator *=(T left, const Vector2<T>& right) {
			right.x *= left;
			right.y *= left;
		}
		
		template < typename T>
		Vector2<T>& operator *(Vector2<T>& left, T right) {
			return Vector2<T>(left.x * right, left.y * right);
		}

		template < typename T>
		Vector2<T>& operator *(T left, Vector2<T>& right) {
			return Vector2<T>(right.x * left, right.y * left);
		}

		template < typename T>
		Vector2<T>& operator /(Vector2<T>& left, T right) {
			return Vector2<T>(left.x / right, left.y / right);
		}

		template < typename T>
		Vector2<T>& operator /=(Vector2<T>& left, T right) {
			left.x /= right;
			left.y /= right;
		}
		
		template < typename T>
		bool operator ==(const Vector2<T>& left, const Vector2<T>& right) {
			return (left.x == right.x) && (left.y == right.y);
		}
		
		template < typename T>
		bool operator !=(const Vector2<T>& left, const Vector2<T>& right) {
			return (left.x != right.x) || (left.y != right.y);
		}

		template < typename T>
		T operator *(const Vector2<T>& left, const Vector2<T>& right) {
			return (right.x * left.x) + (left.y * right.y);
		}

		
		// Define the most common types
		typedef Vector2<int>			Vector2i;
		typedef Vector2<unsigned int>	Vector2u;
		typedef Vector2<long>			Vector2l;
		typedef Vector2<float>			Vector2f;
		typedef Vector2<double>			Vector2d;
	}
}
