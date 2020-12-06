// oop3.cpp : Defines the entry point for the application.
//
#include "iostream"
#include "Image.h"

using ::std::endl;
int main()
{
	std::cout << Image(19, 2, BLACK) +

		((Image(5, 2, BLACK) | Image(13, 1, WHITE) |
			~(Image(19, 2, WHITE) | Image(13, 2, BLACK)))) +

		(Image(4, 2, BLACK) | ~(Image(5, 2, BLACK) | ~(Image(9, 2, GRAY) |
			~(Image(10, 2, BLACK) | ~((((~((Image(19, 2, WHITE)) |
				Image(15, 2, BLACK)))) | Image(12, 2, GRAY)) |
				Image(11, 2, BLACK)))))) +

		(Image(3, 2, BLACK) | ~(Image(4, 2, BLACK) | ~(Image(9, 2, GRAY) |
			~(Image(10, 2, BLACK) | ~(Image(12, 2, BLACK) |
				(Image(14, 2, GRAY) | ~(Image(16, 2, BLACK) |
					~Image(19, 2, BLACK)))))))) +

		(Image(2, 2, BLACK) | ~(Image(3, 2, BLACK) | ~(Image(9, 2, GRAY) |
			~(Image(10, 2, BLACK) | ~(Image(13, 2, BLACK) |
				(Image(15, 2, GRAY) | ~(Image(17, 2, BLACK) |
					~Image(19, 2, BLACK)))))))) +

		(Image(1, 2, BLACK) | ~(Image(2, 2, BLACK) | (Image(4, 2, GRAY) |
			~((Image(6, 2, BLACK) | ~(~(Image(9, 2, GRAY) |
				~(Image(10, 2, BLACK) | ~(Image(14, 2, BLACK) |
					(Image(16, 2, GRAY) | ~(Image(18, 2, BLACK) |
						~Image(19, 2, BLACK)))))))))))) +

		(Image(1, 2, BLACK) | ~(Image(2, 2, BLACK) | (Image(3, 2, GRAY) | 
			~((Image(5, 2, BLACK) | ~(~(Image(8, 2, GRAY) | 
				~(Image(11, 2, BLACK) | ~(Image(15, 2, BLACK) | 
					(Image(17, 2, GRAY) | ~(Image(18, 2, BLACK) | 
						~Image(19, 2, BLACK)))))))))))) +

		(Image(1, 2, BLACK) | ~(Image(2, 2, BLACK) | (Image(3, 2, GRAY) |
			~((Image(4, 2, BLACK) | ~(~(Image(7, 2, GRAY) |
				~(Image(8, 2, BLACK) | ~(Image(11, 2, BLACK) |
					~(Image(12, 2, BLACK) | ~(Image(16, 2, BLACK) | 
						(Image(17, 2, GRAY) | ~(Image(18, 2, BLACK) |
							~Image(19, 2, BLACK)))))))))))))) +

		(Image(1, 2, BLACK) | ~(Image(2, 2, BLACK) | (~(Image(7, 2, GRAY) |
			~(Image(8, 2, BLACK) | ~(Image(9, 2, BLACK) 
				| ~(Image(10, 2, GRAY) | ~(Image(11, 2, BLACK) | 
					~(Image(12, 2, BLACK) | ~(Image(17, 2, BLACK) 
						| ~(Image(18, 2, BLACK) |  
							~Image(19, 2, BLACK)))))))))))) +

		(Image(1, 2, BLACK) | ~(Image(2, 2, BLACK) | (~(Image(7, 2, GRAY) |
			~(Image(8, 2, BLACK) | ~(Image(11, 2, BLACK) |
				~(Image(12, 2, BLACK) | ~(Image(17, 2, BLACK) |
					~(Image(18, 2, BLACK) | ~Image(19, 2, BLACK)))))))))) +

		(Image(1, 2, BLACK) | ~(Image(2, 2, BLACK) | (~(Image(8, 2, GRAY) |
			~(Image(11, 2, BLACK) | ~(Image(17, 2, BLACK) | 
				~(Image(18, 2, BLACK) | ~Image(19, 2, BLACK)))))))) +
		
		(Image(1, 2, BLACK) | ~(Image(2, 2, BLACK) | ~(Image(9, 2, GRAY) |
			~(Image(10, 2, BLACK) | ~(Image(16, 2, BLACK) |
				(~(Image(18, 2, BLACK) |
					~Image(19, 2, BLACK)))))))) +
		
		(Image(2, 2, BLACK) | ~(Image(3, 2, BLACK) | ~(Image(9, 2, GRAY) |
			~(Image(10, 2, BLACK) | ~(Image(15, 2, BLACK) |
				(~(Image(17, 2, BLACK) |
					~Image(19, 2, BLACK)))))))) +
		
		(Image(3, 2, BLACK) | ~(Image(4, 2, BLACK) | ~(Image(9, 2, GRAY) |
			~(Image(10, 2, BLACK) | ~(Image(14, 2, BLACK) |
				(~(Image(16, 2, BLACK) |
					~Image(19, 2, BLACK)))))))) +

		(Image(4, 2, BLACK) | ~(Image(5, 2, BLACK) | ~(Image(9, 2, GRAY) |
			~(Image(10, 2, BLACK) | ~(Image(12, 2, BLACK) |
				(~(Image(15, 2, BLACK) |
					~Image(19, 2, BLACK)))))))) +
		
		((Image(5, 2, BLACK) | Image(13, 1, WHITE) |
			~(Image(19, 2, WHITE) | Image(13, 2, BLACK)))) +
		
		Image(19, 2, BLACK);
	return EXIT_SUCCESS;
}
