#ifndef VEC2_H
#define VEC2_H

#include <cmath>
#include <iostream>
using std::sqrt;

class vec2 {
public:
    vec2()
        : e { 0, 0 }
    {
    }
    vec2(double e1, double e2)
        : e { e1, e2 }
    {
    }

    double x() { return e[0]; }
    double y() { return e[1]; }

    vec2 operator-() const { return vec2(-e[0], -e[1]); }
    double operator[](int i) const { return e[i]; }
    double& operator[](int i) { return e[i]; }

    vec2& operator+=(const vec2& v)
    {
        e[0] += v.e[0];
        e[1] += v.e[1];
        return *this;
    }

    vec2& operator*=(const double t)
    {
        e[0] *= t;
        e[1] *= t;
        return *this;
    }

    vec2& operator/=(const double t)
    {
        return *this *= (1 / t);
    }

    vec2& operator*=(vec2 v)
    {
        e[0] *= v.x();
        e[1] *= v.y();
        return *this;
    }

    vec2& operator*(vec2 v)
    {
        return *this *= v;
    }

    double lenght() const
    {
        return sqrt(length_squared());
    }

    double length_squared() const
    {
        return e[0] * e[0] + e[1] * e[1];
    }

public:
    double e[2];
};

inline std::ostream& operator<<(std::ostream& out, const vec2& v)
{
    return out << v.e[0] << " " << v.e[1];
}

inline vec2 operator+(const vec2& v1, const vec2& v2)
{
    return vec2(v1.e[0] + v2.e[0], v1.e[1] + v2.e[1]);
}

inline vec2 operator-(const vec2& v1, const vec2& v2)
{
    return vec2(v1.e[0] - v2.e[0], v1.e[1] - v2.e[1]);
}

inline vec2 operator*(const vec2& v, const double x)
{
    return vec2(v.e[0] * x, v.e[1] * x);
}

inline vec2 operator*(const double x, const vec2& v)
{
    return vec2(v.e[0] * x, v.e[1] * x);
}

inline vec2 operator/(const vec2& v, const double x)
{
    return v * (1 / x);
}

inline double dot(const vec2& v1, const vec2& v2)
{
    return v1.e[0] * v2.e[0] + v1.e[1] * v2.e[1];
}

inline vec2 unit_vector(vec2 v)
{
    return v / v.lenght();
}

#endif
