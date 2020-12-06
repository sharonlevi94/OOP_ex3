// oop3.cpp : Defines the entry point for the application.
//
#include "iostream"
#include "Image.h"

int main()
{
	Image image1 = Image(2, 2, WHITE);
	std::cout << (~image1 + Image(4, 4 , GRAY)) * 3;
	return EXIT_SUCCESS;
}
