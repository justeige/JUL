#pragma once

template <class T>
struct Vec2 {

	T x, y;

	Vec2() : x(T(0)), y(T(0)) {}
	Vec2(const T& value) : x(value), y(value) 
	{
		
	}
	Vec2(const T& x, const T& y) : x(x), y(y) {}

	Vec2& operator += (const Vec2& other) 
	{ 
		x += other.x; 
		y += other.y; 
		return *this; 
	}

	Vec2& operator -= (const Vec2& other) 
	{ 
		x -= other.x; 
		y -= other.y; 
		return *this; 
	}

	Vec2& operator *= (const T& scalar) 
	{ 
		x *= scalar; 
		y *= scalar; 
		return *this; 
	}

	Vec2& operator /= (const T& scalar) 
	{ 
		x /= scalar; 
		y /= scalar; 
		return *this; 
	}

	Vec2 operator - () const
	{
		return { -x, -y };
	}
};


template<class T> Vec2<T> operator + (const Vec2<T>& a, const Vec2<T>& b) { return Vec2<T>{a} += b; }
template<class T> Vec2<T> operator - (const Vec2<T>& a, const Vec2<T>& b) { return Vec2<T>{a} -= b; }
template<class T> Vec2<T> operator * (const Vec2<T>& a, const Vec2<T>& b) { return Vec2<T>{a} *= b; }
template<class T> Vec2<T> operator / (const Vec2<T>& a, const Vec2<T>& b) { return Vec2<T>{a} /= b; }

template<class T> Vec2<T> operator * (const Vec2<T>& a, const T& scalar)  { return Vec2<T>{a} *= scalar; }
template<class T> Vec2<T> operator * (const T& scalar,  const Vec2<T>& a) { return Vec2<T>{a} *= scalar; }
template<class T> Vec2<T> operator / (const Vec2<T>& a, const T& scalar)  { return Vec2<T>{a} /= scalar; }

template <class T> bool operator == (const Vec2<T>& a, const Vec2<T>& b) { return a.x == b.x && a.y == b.y; }
template <class T> bool operator != (const Vec2<T>& a, const Vec2<T>& b) { return !(a == b); }


template <class T>
double length(const Vec2<T>& vec)
{
	return sqrt((vec.x * vec.x) + (vec.y * vec.y));
}

template <class T>
double squared_length(const Vec2<T>& vec)
{
    return (vec.x * vec.x) + (vec.y * vec.y);
}

template <class T>
Vec2<T> normal(const Vec2<T>& vec)
{
	const auto magn = length(vec);
	return { vec / (T)magn };
}

template <class T>
double dot_product(const Vec2<T>& a, const Vec2<T>& b)
{
	return a.x * b.x + a.y * b.y;
}

template <class T>
Vec2<T> unit_vector(const Vec2<T>& vec)
{
    return vec / length(vec);
}