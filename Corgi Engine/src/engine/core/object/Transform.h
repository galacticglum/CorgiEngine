#ifndef _ENGINE_TRANSFORM_H
#define _ENGINE_TRANSFORM_H

#include "../../maths/Vector2.h"

class Transform
{
public:
	Transform(const Vector2& position = Vector2::Zero()) : m_Position(position), m_Parent(nullptr) {}

	Vector2* GetPosition() { return &this->m_Position; }
	const Vector2& GetPositon() const { return this->m_Position; }

	void Translate(const Vector2& position) { this->m_Position += position; }
	void Translate(float x, float y) { this->m_Position += Vector2(x, y); }

	void SetPosition(const Vector2& position) { this->m_Position = position; }
	void SetPosition(float x, float y) { this->m_Position = Vector2(x, y); }

	void SetParent(Transform* parent) { this->m_Parent = parent; }
private:
	Vector2 m_Position;
	Transform* m_Parent;
};

#endif
