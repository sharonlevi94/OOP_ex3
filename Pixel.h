#pragma once

const unsigned char BLACK = (unsigned char)219;
const unsigned char GRAY = (unsigned char)176;
const unsigned char WHITE = (unsigned char)' ';

class Pixel
{
public:
	Pixel(unsigned char pixel=' ');
	~Pixel();

	unsigned char getColor()const;
	Pixel getDarker(const Pixel&)const;
	Pixel getLighter(const Pixel& p)const;

	Pixel operator|=(const Pixel& p);
	Pixel operator&=(const Pixel& p);

private:
	unsigned char m_color;
};
std::ostream& operator<<(std::ostream& os, const Pixel& p);
bool operator==(const Pixel& p1, const Pixel& p2);
bool operator!=(const Pixel& p1, const Pixel& p2);
Pixel operator|(const Pixel& p1, const Pixel& p2);
Pixel operator&(const Pixel& p1, const Pixel& p2);

