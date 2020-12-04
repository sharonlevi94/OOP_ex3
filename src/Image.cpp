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
	int nHeight = fmax(A.getHight(), B.getHight());
	int nWidth = A.getWidth() + B.getWidth();
	Image nImage(nHeight, nWidth);

	for (int i = 0; i < A.getHight(); i++)
		for (int j = 0; j < A.getWidth(); j++)
			nImage(i, j) = A(i, j);

	for (int i = 0; i < B.getHight(); i++)
		for (int j = 0; j < B.getWidth(); j++)
			nImage(i, j + A.getWidth()) = B(i, j);

	return nImage;
}
//========================================================================
Image& operator|(const Image& A, const Image& B) {
	int nHeight = fmax(A.getHight(), B.getHight());
	int nWidth = fmax(A.getWidth() , B.getWidth());
	Image nImage(nHeight, nWidth);

	for (int i = 0; i < A.getHight(); i++)
		for (int j = 0; j < A.getWidth(); j++)
			nImage(i, j) |= A(i, j);

	for (int i = 0; i < B.getHight(); i++)
		for (int j = 0; j < B.getWidth(); j++)
			nImage(i, j) |= B(i, j);

	return nImage;
}
//========================================================================
Image& operator&(const Image& A, const Image& B) {
	int nHeight = fmin(A.getHight(), B.getHight());
	int nWidth = fmin(A.getWidth(), B.getWidth());
	Image nImage(nHeight, nWidth);

	for (int i = 0; i < A.getHight(); i++)
		for (int j = 0; j < A.getWidth(); j++)
			nImage(i, j) &= A(i, j);

	for (int i = 0; i < B.getHight(); i++)
		for (int j = 0; j < B.getWidth(); j++)
			nImage(i, j) &= B(i, j);

	return nImage;
}
//========================================================================
Image operator*(const Image& A, unsigned int n) {
	if (n == 0) {
		return Image();
	}
	Image nImage(A.getHight(), A.getWidth() * n);
	for (int i = 0; i < n; i++)
		nImage += A;
	return nImage;
}
//========================================================================
Image operator*(unsigned int n, const Image& A) {
	if (n == 0) {
		return Image();
	}
	Image nImage(A.getHight(), A.getWidth() * n);
	for (int i = 0; i < n; i++)
		nImage += A;
	return nImage;
}
//========================================================================
void Image::operator*=(unsigned int n) {
	*this = *this * n;
}
