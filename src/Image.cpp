#include "Image.h"
#include "Pixel.h"
#include <iostream>
//========================================================================
Image::Image() {}
Image::Image(int height, int width){}
Image::Image(int height, int width, unsigned char pixel){}
Image::Image(const Image& other) {} //copy constructor
//========================================================================
Image::~Image()
{
	delete this->m_imageData;
}
//========================================================================
unsigned int Image::getHight()const { return this->m_imageData.getHight(); }
unsigned int Image::getWidth()const { return this->m_imageData.getWidth(); }
//========================================================================
std::ostream& operator<<(std::ostream& os, const Image& A) {
	for (int i = 0; i < A.getHight(); i++)
		for (int j; j < A.getWidth(); j++)
			std::cout << A(i, j);
	return os;
}
//========================================================================
bool operator==(const Image& A, const Image& B) {
	for (int i = 0; i < A.getHight(); i++)
		for (int j; j < A.getWidth(); j++)
			if (A(i, j) != B(i, j))
				return false;
	return true;
}
//========================================================================
bool operator!=(const Image& A, const Image& B) {
	return !(A == B);
}
//========================================================================
Image operator~(const Image& A) {
	Image newImage(A.getHight(), A.getWidth());
	for (int i = 0; i < A.getHight(); i++)
		for (int j; j < A.getWidth(); j++) {
			switch (A(i, j).getColor()) {
			case BLACK:
				
			}
		}

			return newImage;
}
//========================================================================
Pixel& Image::operator()(unsigned int x, unsigned int y) {
	return this->m_imageData(x, y);
}