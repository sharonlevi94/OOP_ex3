#pragma once
#include "ImageDataStracture.h"
class Image
{
public:
	Image();
	Image(int height, int width);
	Image(int height, int width, unsigned char pixel);
	Image(const Image& other); //copy constructor
	~Image();

	unsigned int GetHight()const;
	unsigned int GetWidth()const;

	bool operator==(const Image& other);
	bool operator!=(const Image& other);
	void operator=(const Image& other); //like copy constructor but diff
	void operator+=(const Image& other);
	void operator|=(const Image& other);
	void operator&=(const Image& other);
	Image& operator()(unsigned int x, unsigned int y);
	const Image& operator()(unsigned int x, unsigned int y)const;

private:
	unsigned int m_height = 0, m_width = 0;
};

Image& operator+(const Image& A, const Image& B);
Image& operator|(const Image& A, const Image& B);
Image& operator&(const Image& A, const Image& B);
Image operator*(const Image& A, unsigned int n);
Image operator*(unsigned int n, const Image& A);
Image operator~(const Image& A);


