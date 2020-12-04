// oop3.cpp : Defines the entry point for the application.
//
#include "iostream"
#include "Image.h"

int main()
{
	Image image = Image(5, 5, WHITE);
	std::cout << image;
	image.~Image();
	return EXIT_SUCCESS;
}
