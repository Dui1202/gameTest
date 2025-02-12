#pragma once

class Vector2f {
public:
	float x;
	float y;
	Vector2f();
	Vector2f(float p_x, float p_y);
	void print();
	Vector2f operator+(const Vector2f& other) const;
	Vector2f operator-(const Vector2f& other) const;
	Vector2f operator*(float other) const;
	Vector2f operator/(float other) const;
};