#include "Image.h"
#include "Pixel.h"
#include <iostream>
//========================================================================
Image::Image() {}
//========================================================================
Image::Image(int height, int width){
	m_imageData(height, width);
}
//========================================================================
Image::Image(int height, int width, unsigned char pixel){
	m_imageData(height, width, pixel);
}
//========================================================================
Image::Image(const Image& other) {
	*this = other;
} //copy constructor
//========================================================================
Image::~Image()
{
	this->m_imageData.~ImageDataStracture;
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
			case BLACK: {
				newImage(i, j) = WHITE;
				break;
			}
			case WHITE: {
				newImage(i, j) = BLACK;
				break;
			}
			default: break;
			}
		}
			return newImage;
}
//========================================================================
Pixel& Image::operator()(unsigned int x, unsigned int y) {
	return this->m_imageData(x, y);
}
//========================================================================
const Pixel& Image::operator()(unsigned int x, unsigned int y)const {
	return this->m_imageData(x, y);
}
//========================================================================
void operator+=(Image& A, const Image& B) {
	A = A + B;
}
//========================================================================
void Image::operator|=(const Image& other) {
	*this = *this | other;
}
//========================================================================
void Image::operator&=(const Image& other) {
	*this = *this & other;
}
//========================================================================
void Image::operator=(const Image& other) {

}
//========================================================================
Image& operator+(const Image& A, const Image& B) {

}
//========================================================================
Image& operator|(const Image& A, const Image& B) {

}
//========================================================================
Image& operator&(const Image& A, const Image& B) {

}
//========================================================================
Image operator*(const Image& A, unsigned int n) {

}
//========================================================================
Image operator*(unsigned int n, const Image& A) {

}
