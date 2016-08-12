#ifndef _ENGINE_VECTOR2_H
#define _ENGINE_VECTOR2_H

#include <cmath>
#include "..\Engine.h"

struct Vector2
{
	float X, Y;

	inline Vector2() : Vector2(0.0f, 0.0f) { }
	inline Vector2(float x, float y) : X(x), Y(y) { }

	Vector2& Add(const Vector2& vector);
	Vector2& Subtract(const Vector2& vector);
	Vector2& Multiply(const Vector2& vector);
	Vector2& Divide(const Vector2& vector);

	Vector2& Add(float value);
	Vector2& Subtract(float value);
	Vector2& Multiply(float value);
	Vector2& Divide(float value);

	Vector2 Normalize() const;
	float Magnitude() const;
	float SqrMagnitude() const;
	float Distance(const Vector2& vector) const;
	float Dot(const Vector2& vector) const;

	// Arithmetic operators
	Vector2 operator+(const Vector2& right);
	Vector2 operator-(const Vector2& right);
	Vector2 operator*(const Vector2& right);
	Vector2 operator/(const Vector2& right);
	
	Vector2 operator+(float right);
	Vector2 operator-(float right);
	Vector2 operator*(float right);
	Vector2 operator/(float right);

	Vector2& operator+=(const Vector2& vector);
	Vector2& operator-=(const Vector2& vector);
	Vector2& operator*=(const Vector2& vector);
	Vector2& operator/=(const Vector2& vector);

	Vector2& operator+=(float value);
	Vector2& operator-=(float value);
	Vector2& operator*=(float value);
	Vector2& operator/=(float value);

	// Comparitive operators
	bool operator==(const Vector2& vector) const;
	bool operator!=(const Vector2& vector) const;
	
	bool operator<(const Vector2& vector) const;
	bool operator<=(const Vector2& vector) const;
	bool operator>(const Vector2& vector) const;
	bool operator>=(const Vector2& vector) const;

	std::string ToString() const;

	std::ostream& operator<<(std::ostream& stream) const;
};

#endif