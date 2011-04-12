#ifndef _COLOUR_H
#define _COLOUR_H

class Colour
{
public:
	Colour();
	Colour(float r, float g, float b, float a=1.0);
	Colour(const Colour& c);
	~Colour();
	
	bool operator == (const Colour& c) const;
	bool operator != (const Colour& c) const;
	
public:
	float r, g, b, a;
	
	static Colour ZERO;
	static Colour White;
	static Colour Black;
	static Colour Red;
	static Colour Green;
	static Colour Blue;
};

#endif // _COLOUR_H
