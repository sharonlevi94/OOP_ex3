#include "Pixel.h"
#include <ostream>

std::ostream& operator<<(std::ostream& os, const Pixel& p)
{
	os << p.getColor();
	return os;
}