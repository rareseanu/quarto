#pragma once
#include <string>
#include "Piece.h"
#include "UnusedPieces.h"
#include "Board.h"
class Player
{
public:
	Player(const std::string& name);

	Piece PickPiece(std::istream& in, UnusedPieces& unusedPieces) const;
	Board::Position PlacePiece(Piece&& piece, std::istream& in, Board& b) const;
	friend std::ostream& operator<<(std::ostream& out, const Player& p);

private:
	std::string m_name;
};

