#pragma once

template <class T>
struct Vec3 {

    T x, y, z;

    Vec3() : x(T(0)), y(T(0)), z(T(0)) {}
    Vec3(const T& value) : x(value), y(value), z(value)
    {

    }
    Vec3(const T& x, const T& y, const T& z) : x(x), y(y), z(z) {}

    Vec3& operator += (const Vec3& other)
    {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }

    Vec3& operator -= (const Vec3& other)
    {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        return *this;
    }

    Vec3& operator *= (const T& scalar)
    {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        return *this;
    }

    Vec3& operator /= (const T& scalar)
    {
        x /= scalar;
        y /= scalar;
        z /= scalar;
        return *this;
    }

    Vec3 operator - () const
    {
        return { -x, -y, -z };
    }
};


template<class T> Vec3<T> operator + (const Vec3<T>& a, const Vec3<T>& b) { return Vec3<T>{a} += b; }
template<class T> Vec3<T> operator - (const Vec3<T>& a, const Vec3<T>& b) { return Vec3<T>{a} -= b; }
template<class T> Vec3<T> operator * (const Vec3<T>& a, const Vec3<T>& b) { return Vec3<T>{a} *= b; }
template<class T> Vec3<T> operator / (const Vec3<T>& a, const Vec3<T>& b) { return Vec3<T>{a} /= b; }

template<class T> Vec3<T> operator * (const Vec3<T>& a, const T& scalar)  { return Vec3<T>{a} *= scalar; }
template<class T> Vec3<T> operator * (const T& scalar,  const Vec3<T>& a) { return Vec3<T>{a} *= scalar; }
template<class T> Vec3<T> operator / (const Vec3<T>& a, const T& scalar)  { return Vec3<T>{a} /= scalar; }

template <class T> bool operator == (const Vec3<T>& a, const Vec3<T>& b) { return a.x == b.x && a.y == b.y && a.z == b.z; }
template <class T> bool operator != (const Vec3<T>& a, const Vec3<T>& b) { return !(a == b); }


template <class T>
double length(const Vec3<T>& vec)
{
    return sqrt((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z));
}

template <class T>
double squared_length(const Vec3<T>& vec)
{
    return (vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z);
}


template <class T>
Vec3<T> normal(const Vec3<T>& vec)
{
    const auto magn = length(vec);
    return { vec / (T)magn };
}

template <class T>
double dot_product(const Vec3<T>& a, const Vec3<T>& b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

template <class T>
Vec3<T> cross_product(const Vec3<T>& a, const Vec3<T>& b)
{
    return {
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    };
}

template <class T>
Vec3<T> unit_vector(const Vec3<T>& vec)
{
    return vec / (T)length(vec);
}