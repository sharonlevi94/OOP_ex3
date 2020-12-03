#include "Image.h"
#include "Pixel.h"

Image::Image() {}
Image::Image(int height, int width){}
Image::Image(int height, int width, unsigned char pixel){}
Image::Image(const Image& other) {} //copy constructor

Image::~Image()
{
	delete this->m_imageData;
}

unsigned int Image::getHight()const { return this->m_imageData.getHight(); }
unsigned int Image::getWidth()const { return this->m_imageData.getWidth(); }
