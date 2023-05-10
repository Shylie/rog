#ifndef ROG_CAMERA_H
#define ROG_CAMERA_H

#include "coordinate.h"
#include "cell.h"

namespace rog
{
	class Camera
	{
		friend class Iter;
	public:
		class Iter
		{
			friend class Camera;
		public:
			inline Coordinate operator*() const { return cam[index]; }

			inline Iter& operator++()
			{
				index++;
				return *this;
			}

			inline friend bool operator==(const Iter& a, const Iter& b)
			{
				return a.index == b.index;
			}
			inline friend bool operator!=(const Iter& a, const Iter& b)
			{
				return a.index != b.index;
			}

		private:
			Iter(const Camera& c, unsigned int i) :
				cam(c),
				index(i)
			{ }

			const Camera& cam;
			unsigned int index;
		};

		Camera(unsigned int viewWidth, unsigned int viewHeight);
		Camera(unsigned int viewWidth, unsigned int viewHeight, Coordinate topLeft);

		Camera(const Camera&) = default;
		Camera(Camera&&) = default;
		
		Camera& operator=(const Camera&) = default;
		Camera& operator=(Camera&&) = default;

		inline Iter begin() const { return Iter(*this, 0); }
		inline Iter end() const { return Iter(*this, viewWidth * viewHeight); }

		Camera& operator+=(Coordinate);

	private:
		Coordinate tl;
		unsigned int viewWidth;
		unsigned int viewHeight;

		Coordinate operator[](unsigned int index) const;
	};
}

#endif//ROG_CAMERA_H