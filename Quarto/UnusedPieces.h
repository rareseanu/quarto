#pragma once
#include <unordered_map>
#include "Piece.h"

class UnusedPieces
{
public:
	UnusedPieces();
	Piece PickPiece(const std::string& name);

	friend std::ostream& operator<<(std::ostream& os, const UnusedPieces& unusedPieces);
private:
	std::unordered_map<std::string, Piece> m_pieces;
};

