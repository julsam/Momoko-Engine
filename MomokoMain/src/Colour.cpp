#include "../include/Colour.h"

Colour Colour::ZERO			= Colour(0.0, 0.0, 0.0, 0.0);
Colour Colour::White		= Colour(1.0, 1.0, 1.0);
Colour Colour::Black		= Colour(0.0, 0.0, 0.0);
Colour Colour::Red			= Colour(1.0, 0.0, 0.0);
Colour Colour::Green		= Colour(0.0, 1.0, 0.0);
Colour Colour::Blue			= Colour(0.0, 0.0, 1.0);

Colour::Colour()
	: r(1.0), g(1.0), b(1.0), a(1.0)
{
}

Colour::Colour(float r, float g, float b, float a)
	: r(r), g(g), b(b), a(a)
{
}

Colour::Colour(const Colour& c)
{
	r = c.r;
	g = c.g;
	b = c.b;
	a = c.a;
}

Colour::~Colour()
{
}

bool
Colour::operator == (const Colour& c) const
{
	return (r == c.r
		&& g == c.g
		&& b == c.b
		&& a == c.a);
}

bool
Colour::operator != (const Colour& c) const
{
	return !(*this == c);
}