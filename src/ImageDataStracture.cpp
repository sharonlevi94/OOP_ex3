#include "ImageDataStracture.h"
#include "Pixel.h"
#include "Utilities.h"
#include <new>
//========================================================================
ImageDataStracture::ImageDataStracture(unsigned int height, 
	unsigned int width, unsigned char color): m_height(height), m_width(width),
	m_imageData(nullptr){
	Pixel** newArr = nullptr;
	
	newArr = new(std::nothrow) Pixel*[height];
	if (newArr == nullptr)
		terminate("Memory allocation error!");
	
	for (unsigned int i = 0; i < height; ++i) {
		newArr[i] = nullptr;

		newArr[i] = new(std::nothrow) Pixel[width];
		if (newArr[i] == nullptr)
			terminate("Memory allocation error!");
		for (unsigned int j = 0; j < width; ++j)
			newArr[i][j] = Pixel(color);
	}

	this->m_imageData = newArr;
}
ImageDataStracture::~ImageDataStracture() {
	for (unsigned int i = 0; i < this->m_height; ++i) {
		delete[] this->m_imageData[i];
	}
	delete[] this->m_imageData;
	this->m_imageData = nullptr;
}
//========================================================================
unsigned int ImageDataStracture::getHight()const { return this->m_height; }
unsigned int ImageDataStracture::getWidth()const { return this->m_width; }
//========================================================================
Pixel& ImageDataStracture::operator()(unsigned int x, unsigned int y) {
	if (this->m_height <= x || this->m_width <= y)
		terminate("tried to access an unallocated memory");
	return this->m_imageData[x][y];
}
//========================================================================
const Pixel& ImageDataStracture::operator()(unsigned int x, unsigned int y)const {
	if (this->m_height <= x || this->m_width <= y)
		terminate("tried to access an unallocated memory");
	return this->m_imageData[x][y];
}
