#pragma once
class Rect
{
private:
	float length;
	float width;
public:
	float getlength();
	float getwidth();
	void setlength(float l);
	void setwidth(float w);
	float getarea();
	Rect(float w, float l);
	~Rect();
};

