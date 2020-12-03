#include "Image.h"
#include "Pixel.h"

Image::Image() {}
Image::Image(int height, int width){}
Image::Image(int height, int width, unsigned char pixel){}
Image::Image(const Image& other) {} //copy constructor

Image::~Image()
{
}

unsigned int Image::GetHight()const { return this->m_height; }
unsigned int Image::GetWidth()const { return this->m_width;  }
