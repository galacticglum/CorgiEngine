#ifndef _ENGINE_RECTANGLE_H
#define _ENGINE_RECTANGLE_H

#include "../../maths/Vector2.h"

class Rectangle
{
public:
	// Creates a rectangle with 'x' and
	Rectangle(const Vector2& position, float width, float height);
	Rectangle(float x, float y, float width, float height) : Rectangle(Vector2(x, y), width, height) { }
	// Create rectangle from other rectangle
	Rectangle(Rectangle& rectangle);
	// Create empty rectangle
	Rectangle() : Rectangle(Vector2(0, 0), 0, 0) { }

	const Vector2& GetPosition() const { return this->m_Position; }
	const float GetWidth() const { return m_Width; }
	const float GetHeight() const { return m_Height; }

	// Getters
	const float GetTop() const { return this->m_Position.Y; }
	const float GetBottom() const { return this->m_Position.Y + this->m_Height; }
	const float GetLeftMost() const { return this->m_Position.X; }
	const float GetRightMost() const { return this->m_Position.X + this->m_Width; }
	 
	const Vector2 GetCentre() const { return Vector2(this->m_Position.X + (this->m_Width / 2), this->m_Position.Y + (this->m_Height / 2)); } 
	const Vector2 GetLeftCentre() const { return Vector2(this->GetLeftMost(), this->GetCentre().Y); } 
	const Vector2 GetRightCentre() const { return Vector2(this->GetRightMost(), this->GetCentre().Y); } 
	 
	const Vector2 GetTopLeft() const { return Vector2(this->m_Position.X, this->m_Position.Y); } 
	const Vector2 GetTopRight() const { return Vector2(this->m_Position.X + this->m_Width, this->m_Position.Y); } 
	const Vector2 GetTopCentre() const { return Vector2(this->GetCentre().X, GetTop()); } 
	 
	const Vector2 GetBottomLeft() const { return Vector2(this->m_Position.X, this->m_Position.Y + this->m_Height); } 
	const Vector2 GetBottomRight() const { return Vector2(this->m_Position.X + this->m_Width, this->m_Position.Y + this->m_Height); } 
	const Vector2 GetBottomCentre() const { return Vector2(GetCentre().X, GetBottom()); } 

	void Copy(const Rectangle& rectangle);

	void Translate(const Vector2& position);
	void Translate(float x, float y) { Translate(Vector2(x, y)); }

	void Scale(const Vector2& scale);
	void Scale(float scaleX, float scaleY) { Scale(Vector2(scaleX, scaleY)); }

	bool Overlaps(Rectangle& other) const;

	void SetPosition(const Vector2& position);
	void SetX(float x) { SetPosition(Vector2(x, this->m_Position.Y)); }
	void SetY(float y) { SetPosition(Vector2(this->m_Position.X, y)); }
private:
	Vector2 m_Position;
	float m_Width;
	float m_Height;
};

#endif