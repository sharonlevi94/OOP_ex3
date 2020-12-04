#include "Pixel.h"
#include <ostream>
//========================================================================
Pixel::Pixel(unsigned char pixel) : m_color(pixel) {}
//========================================================================
unsigned char Pixel::getColor()const { return this->m_color; }
//========================================================================
bool operator==(const Pixel& p1, const Pixel& p2) {
	return (p1.getColor() == p2.getColor());
}
//========================================================================
bool operator!=(const Pixel& p1, const Pixel& p2) {
	return(!(p1 == p2));
}
//========================================================================
Pixel operator|(const Pixel& p1, const Pixel& p2){
	if (p1 == p2)
		return p1;
	else 
		return p1.getDarker(p2);
}
//========================================================================
Pixel Pixel::operator|=(const Pixel& p) {
	return *this = *this | p;
}
//========================================================================
Pixel operator&(const Pixel& p1, const Pixel& p2) {
	if (p1 == p2)
		return p1;
	else
		return p1.getLighter(p2);
}
//========================================================================
Pixel Pixel::operator&=(const Pixel& p) {
	return *this = *this & p;
}
//========================================================================
Pixel Pixel::getLighter(const Pixel& p)const {
	switch (this->getColor()) {
	case WHITE:
		return *this;
	case GRAY:
		if (p.getColor() == WHITE)
			return p;
		else 
			return *this;
	default: return p;
	}
}
//========================================================================
Pixel Pixel::getDarker(const Pixel& p)const {
	switch (this->getColor()) {
	case BLACK:
		return *this;
	case GRAY:
		if (p.getColor() == BLACK)
			return p;
		else 
			return *this;
	default: return p;
	}
}
//========================================================================
std::ostream& operator<<(std::ostream& os, const Pixel& p)
{
	os << p.getColor();
	return os;
}
//========================================================================
void Pixel::setColor(unsigned char color) {
	this->m_color = color;
}