#include "Vector2.h"

Vector2& Vector2::Add(const Vector2& vector)
{
	this->X += vector.X;
	this->Y += vector.Y;

	return *this;
}

Vector2& Vector2::Subtract(const Vector2& vector)
{
	this->X -= vector.X;
	this->Y -= vector.Y;

	return *this;
}

Vector2& Vector2::Multiply(const Vector2& vector)
{
	this->X *= vector.X;
	this->Y *= vector.Y;

	return *this;
}

Vector2& Vector2::Divide(const Vector2& vector)
{
	this->X /= vector.X;
	this->Y /= vector.Y;

	return *this;
}

Vector2& Vector2::Add(float other)
{
	this->X += other;
	this->Y += other;

	return *this;
}

Vector2& Vector2::Subtract(float other)
{
	this->X -= other;
	this->Y -= other;

	return *this;
}

Vector2& Vector2::Multiply(float other)
{
	this->X *= other;
	this->Y *= other;

	return *this;
}

Vector2& Vector2::Divide(float other)
{
	this->X /= other;
	this->Y /= other;

	return *this;
}

Vector2 Vector2::Normalize() const
{
	float length = Magnitude();
	return Vector2(this->X / length, this->Y / length);
}

float Vector2::Magnitude() const
{
	return sqrt(SqrMagnitude());
}

float Vector2::SqrMagnitude() const
{
	return (this->X * this->X) + (this->Y * this->Y);
}

float Vector2::Distance(const Vector2& vector) const
{
	float a = (this->X - vector.X);
	float b = (this->Y - vector.Y);
	return sqrt((a * a) + (b * b));
}

float Vector2::Dot(const Vector2& vector) const
{
	return (this->X * vector.X) + (this->Y * vector.Y);
}

// Operators

Vector2 Vector2::operator+(const Vector2& right)
{
	return this->Add(right);
}

Vector2 Vector2::operator-(const Vector2& right)
{
	return this->Subtract(right);
}

Vector2 Vector2::operator*(const Vector2& right)
{
	return this->Multiply(right);
}

Vector2 Vector2::operator/(const Vector2& right)
{
	return this->Divide(right);
}

Vector2 Vector2::operator+(float value)
{
	return this->Add(value);
}

Vector2 Vector2::operator-(float value)
{
	return this->Subtract(value);
}

Vector2 Vector2::operator*(float value)
{
	return this->Multiply(value);
}

Vector2 Vector2::operator/(float value)
{
	return this->Divide(value);
}

Vector2& Vector2::operator+=(const Vector2& vector)
{
	return this->Add(vector);
}

Vector2& Vector2::operator-=(const Vector2& vector)
{
	return this->Subtract(vector);
}

Vector2& Vector2::operator*=(const Vector2& vector)
{
	return this->Multiply(vector);
}

Vector2& Vector2::operator/=(const Vector2& vector)
{
	return this->Divide(vector);
}

Vector2& Vector2::operator+=(float value)
{
	return this->Add(value);
}

Vector2& Vector2::operator-=(float value)
{
	return this->Subtract(value);
}

Vector2& Vector2::operator*=(float value)
{
	return this->Multiply(value);
}

Vector2& Vector2::operator/=(float value)
{
	return this->Divide(value);
}

bool Vector2::operator==(const Vector2& vector) const
{
	return (X == vector.X && Y == vector.Y);
}

bool Vector2::operator!=(const Vector2& vector) const
{
	return (X != vector.X && Y != vector.Y);
}

bool Vector2::operator<(const Vector2& vector) const
{
	return (X < vector.X && Y < vector.Y);
}

bool Vector2::operator<=(const Vector2& vector) const
{
	return (X <= vector.X && Y <= vector.Y);
}

bool Vector2::operator>(const Vector2& vector) const
{
	return (X > vector.X && Y > vector.Y);
}

bool Vector2::operator>=(const Vector2& vector) const
{
	return (X >= vector.X && Y >= vector.Y);
}

std::string Vector2::ToString() const
{
	return "Vector2: (" + std::to_string(this->X) + ", " + std::to_string(this->Y) + ")";
}

std::ostream& Vector2::operator<<(std::ostream& stream) const
{
	return (stream << this->ToString());
}