#pragma once
#include "ImageDataStracture.h"
#include <ostream>
#include "Pixel.h"
//========================================================================
class Image
{
public:
	Image();
	Image(int height, int width);
	Image(int height, int width, unsigned char pixel);
	Image(const Image& other); //copy constructor,call to operator =
	~Image();

	unsigned int getHight()const;
	unsigned int getWidth()const;

	void operator=(const Image& other); //like copy constructor but diff
	void operator|=(const Image& other);
	void operator&=(const Image& other);
	Pixel& operator()(unsigned int x, unsigned int y);
	const Pixel& operator()(unsigned int x, unsigned int y)const;

private:
	ImageDataStracture m_imageData;
};
//========================================================================
std::ostream& operator<<(std::ostream& os, const Image& A);
void operator+=(Image& A,const Image& B);
bool operator==(const Image& A,const Image& B);
bool operator!=(const Image& A,const Image& B);
Image& operator+(const Image& A, const Image& B);
Image& operator|(const Image& A, const Image& B);
Image& operator&(const Image& A, const Image& B);
Image operator*(const Image& A, unsigned int n);
Image operator*(unsigned int n, const Image& A);
Image operator~(const Image& A);


