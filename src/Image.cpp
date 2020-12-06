//============================ include section ===============================
#include "Image.h"
#include "Pixel.h"
#include <iostream>
#include <cmath>

//========================== constractors section ============================
Image::Image():m_imageData(ImageDataStracture(0, 0, WHITE)) {}
//============================================================================
Image::Image(int height, int width) : 
	m_imageData(ImageDataStracture(height, width, WHITE)){}
//============================================================================
Image::Image(int height, int width, unsigned char pixel)
	: m_imageData(ImageDataStracture(height, width, pixel)) {}
//============================================================================
Image::Image(const Image& other) {
	*this = other;
} //copy constructor
//=========================== destructors section ============================
Image::~Image(){
	this->m_imageData.~ImageDataStracture();
}
//============================== get sections ================================
unsigned int Image::getHeight()const { return this->m_imageData.getHeight(); }
//============================================================================
unsigned int Image::getWidth()const { return this->m_imageData.getWidth(); }
//======================== public operators section ==========================
void Image::operator=(const Image& other) {
	this->m_imageData.~ImageDataStracture();
	this->m_imageData =
		ImageDataStracture(other.getHeight(), other.getWidth());
	for (unsigned int i = 0; i < other.getHeight(); ++i)
		for (unsigned int j = 0; j < other.getWidth(); ++j)
			(*this)(i, j) = other(i, j);
}
//============================================================================
void Image::operator|=(const Image& other) {
	*this = *this | other;
}
//============================================================================
void Image::operator&=(const Image& other) {
	*this = *this & other;
}
//============================================================================
Pixel& Image::operator()(unsigned int x, unsigned int y) {
	return this->m_imageData(x, y);
}
//============================================================================
const Pixel& Image::operator()(unsigned int x, unsigned int y)const {
	return this->m_imageData(x,y);
}
//======================== global operators section ==========================
std::ostream& operator<<(std::ostream& os, const Image& A) {
	for (unsigned int i = 0; i < A.getHeight(); i++) {
		for (unsigned int j = 0; j < A.getWidth(); j++)
			os << A(i, j);
		os << std::endl;
	}
	return os;
}
//============================================================================
bool operator==(const Image& A, const Image& B) {
	if (A.getHeight() != B.getHeight() ||
		A.getWidth() != B.getWidth())
		return false;
	for (unsigned int i = 0; i < A.getHeight(); i++)
		for (unsigned int j = 0; j < A.getWidth(); j++)
			if (A(i, j) != B(i, j))
				return false;
	return true;
}
//============================================================================
bool operator!=(const Image& A, const Image& B) {
	return !(A == B);
}
//============================================================================
Image operator~(const Image& A) {
	Image newImage(A.getHeight(), A.getWidth());
	for (unsigned int i = 0; i < A.getHeight(); i++)
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
			default: 
				break;
			}
		}
	return newImage;
}
//============================================================================
void operator+=(Image& A, const Image& B) {
	A = A + B;
}
//============================================================================
Image operator+(const Image& A, const Image& B) {
	Image ans = Image(
		(unsigned int)fmax(A.getHeight(),B.getHeight()),
		A.getWidth() + B.getWidth(), WHITE);

	for (unsigned int i = 0; i < A.getHeight(); ++i)
		for (unsigned int j = 0; j < A.getWidth(); ++j)
			ans(i, j) = A(i, j);
	for (unsigned int i = 0; i < B.getHeight(); ++i)
		for (unsigned int j = 0; j < B.getWidth(); ++j)
			ans(i, j + A.getWidth()) = B(i, j);
	return ans;
}
//============================================================================
Image operator|(const Image& A, const Image& B) {
	unsigned int nHeight = (unsigned int)fmax(A.getHeight(), B.getHeight());
	unsigned int nWidth = (unsigned int)fmax(A.getWidth() , B.getWidth());
	Image nImage(nHeight, nWidth);

	for(unsigned int i = 0; i < nHeight; ++i)
		for (unsigned int j = 0; j < nWidth; ++j) {
			if (A.getHeight() > i && A.getWidth() > j) {
				if (B.getHeight() > i && B.getWidth() > j)
					nImage(i, j) = A(i, j) | B(i, j);
				else
					nImage(i, j) = A(i, j);
			}
			else if (B.getHeight() > i && B.getWidth() > j)
				nImage(i, j) = B(i, j);
			else
				nImage(i, j) = Pixel(WHITE);
		}
	return nImage;
}
//============================================================================
Image operator&(const Image& A, const Image& B) {
	unsigned int nHeight = (unsigned int)fmin(A.getHeight(), B.getHeight());
	unsigned int nWidth = (unsigned int)fmin(A.getWidth(), B.getWidth());
	Image nImage(nHeight, nWidth);

	for (unsigned int i = 0; i < nHeight; ++i)
		for (unsigned int j = 0; j < nWidth; ++j)
			nImage(i, j) = A(i, j) & B(i, j);

	return nImage;
}
//============================================================================
Image operator*(const Image& A, unsigned int n) {
	Image nImage = Image();
	for (unsigned int i = 0; i < n; i++)
		nImage += A;
	return nImage;
}
//============================================================================
Image operator*(unsigned int n, const Image& A) {return (A * n);}
//============================================================================
void operator*=(Image& A, unsigned int n) {
	A = A * n;
}
