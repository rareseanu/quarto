#include "Board.h"

std::optional<Piece>& Board::operator[](const Position& position)
{
	const auto&[line, column] = position;
	if (line < kHeight && column < kWidth) {
		return m_pieces[line * kWidth + column];
	}
	else
		throw("Index out of bounds.");
}

const std::optional<Piece>& Board::operator[](const Position& position) const
{
	const auto& [line, column] = position;
	if (line >= kHeight || column >= kWidth)
		throw("Index out of bounds.");
	return m_pieces[line * kWidth + column];
}

const char emptyBoardPiece = '_';

std::ostream& operator<<(std::ostream & os, const Board & b)
{
	Board::Position position;
	auto& [line, column] = position;
	for (line = 0; line < Board::kHeight; ++line)
	{
		for (column = 0; column < Board::kWidth; ++column)
		{
			auto& pieceOrNot = b[position];
			if (pieceOrNot)
				os << *pieceOrNot;
			else
				os << emptyBoardPiece;
			os << ' ';
		}
		os << '\n';
	}
	return os;
} 
