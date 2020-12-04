#include "ImageDataStracture.h"
#include "Pixel.h"
#include "Utilities.h"
#include <new>
//========================================================================
ImageDataStracture::ImageDataStracture(unsigned int height, 
	unsigned int width, unsigned char color): m_height(height), m_width(width),
	m_imageData(nullptr){
	this->m_imageData = nullptr;
	
	this->m_imageData = new(std::nothrow) Pixel*[height];
	if (this->m_imageData == nullptr)
		terminate("Memory allocation error!");
	
	for (unsigned int i = 0; i < height; ++i) {
		this->m_imageData[i] = nullptr;

		this->m_imageData[i] = new(std::nothrow) Pixel[width];
		if (this->m_imageData[i] == nullptr)
			terminate("Memory allocation error!");
		for (unsigned int j = 0; j < width; ++j)
			this->m_imageData[i][j] = Pixel(color);
	}
}
ImageDataStracture::~ImageDataStracture() {
	for (unsigned int i = 0; i < this->m_height; ++i) {
		delete this->m_imageData[i];
	}
	delete this->m_imageData;
	this->m_imageData = nullptr;
}
//========================================================================
unsigned int ImageDataStracture::getHeight()const { return this->m_height; }
unsigned int ImageDataStracture::getWidth()const { return this->m_width; }
//========================================================================
Pixel& ImageDataStracture::operator()(unsigned int x, unsigned int y) {
	if (this->m_height <= x || this->m_width <= y)
		terminate("tried to access an unallocated memory");
	return this->m_imageData[x][y];
}
//============================================================================
const Pixel& ImageDataStracture::operator()(unsigned int x, unsigned int y)
const {
	if (this->m_height <= x || this->m_width <= y)
		terminate("tried to access an unallocated memory");
	return this->m_imageData[x][y];
}
//============================================================================
void ImageDataStracture::operator=(const ImageDataStracture& source) {
	this->~ImageDataStracture();
	this->m_imageData = new(std::nothrow) Pixel * [source.getHeight()];
	if (this->m_imageData == nullptr)
		terminate("Memory allocation error!");

	for (unsigned int i = 0; i < source.getHeight(); ++i) {
		this->m_imageData[i] = nullptr;

		this->m_imageData[i] = new(std::nothrow) Pixel[source.getWidth()];
		if (this->m_imageData[i] == nullptr)
			terminate("Memory allocation error!");

		for (unsigned j = 0; j < source.getWidth(); ++j)
			this->m_imageData[i][j] = source(i, j);
	}
	this->m_height = source.getHeight();
	this->m_width = source.getWidth();
}