#include "Rectangle.h"

Rectangle::Rectangle(const Vector2& position, float width, float height) : m_Position(position), m_Width(width), m_Height(height) { }

Rectangle::Rectangle(Rectangle& rectangle)
{
	this->Copy(rectangle);
}

void Rectangle::Copy(const Rectangle& rectangle)
{
	this->m_Position = rectangle.GetPosition();
	this->m_Width = rectangle.GetWidth();
	this->m_Height = rectangle.GetHeight();
}

void Rectangle::Translate(const Vector2& position)
{
	this->m_Position += position;
}

void Rectangle::Scale(const Vector2& scale)
{
	if ((scale.X <= 0) || (scale.Y <= 0)) return;

	float oldWidth = this->m_Width;
	float oldHeight = this->m_Height;

	this->m_Width *=  scale.X;
	this->m_Height *= scale.Y;

	// Centralize rectangle on other
	this->m_Position.X += abs(oldWidth - this->m_Width) / 2;
	this->m_Position.Y += abs(oldHeight - this->m_Height) / 2;
}

bool Rectangle::Overlaps(Rectangle& rectangle) const
{
	if ((this->m_Position.X <= rectangle.GetRightMost()) && 
	    (rectangle.GetPosition().X <= this->GetRightMost()) && 
		(this->m_Position.Y <= rectangle.GetBottom() && 
        rectangle.GetPosition().Y <= this->GetBottom())) return true;
	
	return false;
}

void Rectangle::SetPosition(const Vector2& position)
{
	this->m_Position = position;
}