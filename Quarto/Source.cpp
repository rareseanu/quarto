#include "Piece.h"

#include <iostream>

int main()
{
	Piece piece(Piece::Body::Full, Piece::Color::Dark, Piece::Height::Short, Piece::Shape::Square);
	std::cout << "Full, Dark, Short, Square piece: " << piece << std::endl;

	return 0;
}