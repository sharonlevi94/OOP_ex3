#pragma once
#include "Pixel.h"
class ImageDataStracture
{
public:
	ImageDataStracture(unsigned int height=0, unsigned int width=0 );
	~ImageDataStracture();

	unsigned int getHight()const;
	unsigned int getWidth()const;
 Pixel& operator()(unsigned int x, unsigned int y);
const Pixel& Image::operator()(unsigned int x, unsigned int y)const;
	

private:
	Pixel** m_imageData;
	unsigned int m_height = 0, m_width = 0;
};
