#ifndef _RECTANGLE_H
#define _RECTANGLE_H

// A simple utility template class which contains information for
// an axis-aligned rectangle.
template <class T>
class Rectangle
{
public:
    Rectangle () : m_Top(0), m_Bottom(0), m_Left(0), m_Right(0)   { }
    Rectangle (T top, T bottom, T left, T right)
        : m_Top(top), m_Bottom(bottom), m_Left(left), m_Right(right)   { }
    ~Rectangle()  { }

    T getWidth()  const  { return m_Right - m_Left;  }
    T getHeight() const  { return m_Bottom - m_Top;  }

    // Check if this rectangle intersects with the rectangle 
    // passed as argument. Returns true if that's the case.
    bool intersect(const Rectangle& rect) const
    {
        return ((m_Left < rect.m_Right) && (m_Right > rect.m_Left ) &&
                (m_Bottom > rect.m_Top) && (m_Top < rect.m_Bottom) );
    }

    // Returns true if this is a valid rectangle (has a width and
    // a height).
    bool isValid() const
    {
        if ( (m_Top > m_Bottom) || (m_Left > m_Right) )
            return false;
        return true;
    }

    T m_Top;
    T m_Bottom;
    T m_Left;
    T m_Right;
};

// Typdefs for the most used types.
typedef Rectangle<int>    Rectanglei;
typedef Rectangle<float>  Rectanglef;
typedef Rectangle<double> Rectangled;

#endif  // _RECTANGLE_H

