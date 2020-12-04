#pragma once
#include "Pixel.h"
class ImageDataStracture
{
public:
	ImageDataStracture(unsigned int height = 0, unsigned int width = 0,
		unsigned char color = WHITE);
	~ImageDataStracture();

	unsigned int getHeight()const;
	unsigned int getWidth()const;
	void operator=(const ImageDataStracture& source);
	Pixel& operator()(unsigned int x, unsigned int y);
	const Pixel& operator()(unsigned int x, unsigned int y)const;

private:
	Pixel** m_imageData;
	unsigned int m_height, m_width;
};
