#include "Board.h"

std::optional<Piece>& Board::operator[](const Position& position)
{
	const auto&[line, column] = position;
	return m_pieces[line * kWidth + column];
}

