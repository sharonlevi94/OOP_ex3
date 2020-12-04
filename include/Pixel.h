#pragma once

const unsigned char BLACK = (unsigned char)219;
const unsigned char GRAY = (unsigned char)176;
const unsigned char WHITE = (unsigned char)' ';
//========================================================================
class Pixel
{
public:
	Pixel(unsigned char pixel);
	~Pixel();

	unsigned char getColor()const;
	Pixel& setColor(unsigned char color);

	Pixel operator|=(const Pixel& p);
	Pixel operator&=(const Pixel& p);
	Pixel getDarker(const Pixel&)const;
	Pixel getLighter(const Pixel& p)const;

private:
	unsigned char m_color = WHITE;
};
//========================================================================
std::ostream& operator<<(std::ostream& os, const Pixel& p);
bool operator==(const Pixel& p1, const Pixel& p2);
bool operator!=(const Pixel& p1, const Pixel& p2);
Pixel operator|(const Pixel& p1, const Pixel& p2);
Pixel operator&(const Pixel& p1, const Pixel& p2);