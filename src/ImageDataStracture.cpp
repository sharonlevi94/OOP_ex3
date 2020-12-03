#include "ImageDataStracture.h"
#include "Pixel.h"
#include "Utilities.h"
#include <new>

ImageDataStracture::ImageDataStracture(unsigned int height, unsigned int width) {
	Pixel** newArr = nullptr;
	
	newArr = new(std::nothrow) Pixel * [height];
	if (newArr == nullptr)
		terminate("Memory allocation error!");
	
	for (int i = 0; i < height; ++i) {
		newArr[i] = nullptr;

		newArr[i] = new(std::nothrow) Pixel[width];
		if (newArr == nullptr)
			terminate("Memory allocation error!");
	}

	this->m_imageData = newArr;
}
ImageDataStracture::~ImageDataStracture() {
	for (int i = 0; i < this->m_height; ++i) {
		delete[] this->m_imageData[i];
	}
	this->m_imageData = nullptr;
	this->m_height = m_height;
	this->m_width = m_width;
}

unsigned int ImageDataStracture::getHight()const { return this->m_height; }
unsigned int ImageDataStracture::getWidth()const { return this->m_width; }
const Pixel& ImageDataStracture::operator()(unsigned int x, unsigned int y) {
	if (this->m_height <= x || this->m_width <= y)
		terminate("tried to access an unallocated memory");
	return this->m_imageData[x][y];
}