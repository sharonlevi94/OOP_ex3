#pragma once
#include "Pixel.h"
class ImageDataStracture
{
public:
	ImageDataStracture(unsigned int height = 0, unsigned int width = 0,
		unsigned char color = WHITE);
	~ImageDataStracture();
	//========================== gets section ================================
	
	unsigned int getHeight()const;
	unsigned int getWidth()const;
	//======================= operators section ==============================

	Pixel& operator()(unsigned int x, unsigned int y);
	const Pixel& operator()(unsigned int x, unsigned int y)const;
	void operator=(const ImageDataStracture& source);

private:
	Pixel** m_imageData;
	unsigned int m_height, m_width;
};
