// oop3.cpp : Defines the entry point for the application.
//
#include "iostream"
#include "Image.h"

int main()
{
	Image image1 = Image(5, 5, BLACK),
		image2 = Image(10,10, GRAY);
	std::cout << image1 << image2;
	return EXIT_SUCCESS;
}
