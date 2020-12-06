// oop3.cpp : Defines the entry point for the application.
//
#include "iostream"
#include "Image.h"

using ::std::endl;
int main()
{
	Image p1(1, 5);
	Image p2(1, 5, GRAY);
	Image p3(1, 5, BLACK);
	std::cout << "                    " << p1 * 7 << endl
		<< "               " << p1 + p2 + p3 * 5 + p2 + p1 << endl
		<< "          " << p1 + p3 * 9 + p1 << endl
		<< "     " << p1 + p2 + p3 * 2 + p1 * 5 + p3 * 2 + p2 + p1 << endl
		<< p1 + p2 + p3 + p1 * 3 + p3 + p1 + p3 + p1 * 3 + p2 * 2 + p1 << endl
		<< p1 + p3 * 4 + p1 * 5 + p3 * 2 + p2 * 2 + p1 << endl
		<< p1 + p3 * 4 + p1 * 5 + p3 * 2 + p2 * 2 + p1 << endl
		<< p1 + p3 * 4 + p1 * 5 + p3 * 2 + p2 * 2 + p1 << endl
		<< p1 + p2 + p3 * 4 + p1 * 3 + p3 * 2 + p2 * 3 + p1 << endl
		<< p1 + p2 + p3 * 9 + p2 * 3 + p1 << endl
		<< "     " << p1 + p2 + p3 * 7 + p2 * 3 + p1 << endl
		<< "     " << p1 + p2 * 2 + p3 * 2 + p2 + p3 + p2 * 5 + p1 << endl
		<< "          " << p1 * 2 + p2 * 7 + p1 * 2 << endl
		<< "                    " << p1 * 2 + p2 + p1 + p2 + p1 * 2 << endl
		<< "                         " << p1 + p2 + p1 + p2 + p1 << endl
		<< "                         " << p1 * 5;
	return EXIT_SUCCESS;
}
