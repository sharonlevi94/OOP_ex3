// oop3.cpp : Defines the entry point for the application.
//
#include "oop3.h"
#include "Image.h"
#include <cstdlib>
using namespace std;

int main()
{
	Image A(4,5,WHITE);
	cout << A;
	return EXIT_SUCCESS;
}
