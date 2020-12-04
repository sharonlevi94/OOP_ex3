#include "Image.h"
#include "Pixel.h"
#include <iostream>
#include <cmath>
//========================================================================
Image::Image() {}
//========================================================================
Image::Image(int height, int width){
	this->m_imageData = ImageDataStracture(height, width, WHITE);
}
//========================================================================
Image::Image(int height, int width, unsigned char pixel){
	this->m_imageData = ImageDataStracture(height, width, pixel);
}
//========================================================================
Image::Image(const Image& other) {
	*this = other;
} //copy constructor
//========================================================================
Image::~Image(){
	this->m_imageData.~ImageDataStracture();
}
//========================================================================
unsigned int Image::getHight()const { return this->m_imageData.getHeight(); }
unsigned int Image::getWidth()const { return this->m_imageData.getWidth(); }
//========================================================================
std::ostream& operator<<(std::ostream& os, const Image& A) {
	for (unsigned int i = 0; i < A.getHight(); i++) {
		for (unsigned int j = 0; j < A.getWidth(); j++)
			os << A(i, j);
		os << std::endl;
	}
	return os;
}
//========================================================================
bool operator==(const Image& A, const Image& B) {
	for (unsigned int i = 0; i < A.getHight(); i++)
		for (unsigned int j = 0; j < A.getWidth(); j++)
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
	for (unsigned int i = 0; i < A.getHight(); i++)
		for (unsigned int j = 0; j < A.getWidth(); j++) {
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
	if (this->getHight() == other.getHight() &&
		this->getWidth() == other.getWidth() &&
		*this != other) {
		this->~Image(); //realse memory
		for (unsigned int i = 0; i < other.getHight(); i++)
			for (unsigned int j = 0; j < other.getWidth(); j++)
				this->m_imageData(i, j) = other(i, j);
	}
}
//========================================================================
Image operator+(const Image& A, const Image& B) {
	unsigned int nHeight = (unsigned int)fmax(A.getHight(), B.getHight());
	unsigned int nWidth = A.getWidth() + B.getWidth();
	Image nImage(nHeight, nWidth);

	for (unsigned int i = 0; i < A.getHight(); i++)
		for (unsigned int j = 0; j < A.getWidth(); j++)
			nImage(i, j) = A(i, j);

	for (unsigned int i = 0; i < B.getHight(); i++)
		for (unsigned int j = 0; j < B.getWidth(); j++)
			nImage(i, j + A.getWidth()) = B(i, j);

	return nImage;
}
//========================================================================
Image operator|(const Image& A, const Image& B) {
	unsigned int nHeight = (unsigned int)fmax(A.getHight(), B.getHight());
	unsigned int nWidth = (unsigned int)fmax(A.getWidth() , B.getWidth());
	Image nImage(nHeight, nWidth);

	for (unsigned int i = 0; i < A.getHight(); i++)
		for (unsigned int j = 0; j < A.getWidth(); j++)
			nImage(i, j) |= A(i, j);

	for (unsigned int i = 0; i < B.getHight(); i++)
		for (unsigned int j = 0; j < B.getWidth(); j++)
			nImage(i, j) |= B(i, j);

	return nImage;
}
//========================================================================
Image operator&(const Image& A, const Image& B) {
	unsigned int nHeight = (unsigned int)fmin(A.getHight(), B.getHight());
	unsigned int nWidth = (unsigned int)fmin(A.getWidth(), B.getWidth());
	Image nImage(nHeight, nWidth);

	for (unsigned int i = 0; i < A.getHight(); i++)
		for (unsigned int j = 0; j < A.getWidth(); j++)
			nImage(i, j) &= A(i, j);

	for (unsigned int i = 0; i < B.getHight(); i++)
		for (unsigned int j = 0; j < B.getWidth(); j++)
			nImage(i, j) &= B(i, j);

	return nImage;
}
//========================================================================
Image operator*(const Image& A, unsigned int n) {
	if (n == 0) {
		return Image();
	}
	Image nImage(A.getHight(), A.getWidth() * n);
	for (unsigned int i = 0; i < n; i++)
		nImage += A;
	return nImage;
}
//========================================================================
Image operator*(unsigned int n, const Image& A) {
	if (n == 0) {
		return Image();
	}
	Image nImage(A.getHight(), A.getWidth() * n);
	for (unsigned int i = 0; i < n; i++)
		nImage += A;
	return nImage;
}
//========================================================================
void operator*=(Image& A, unsigned int n) {
	A = A * n;
}
