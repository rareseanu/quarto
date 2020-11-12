#include "Player.h"

Player::Player(const std::string& name) 
	: m_name(name)
{

}

Piece Player::PickPiece(std::istream& is, UnusedPieces& unusedPieces) const
{
	std::string pickedPieceName;
	is >> pickedPieceName;
	Piece pickedPiece = unusedPieces.PickPiece(pickedPieceName);
	return pickedPiece;
}

Board::Position Player::PlacePiece(Piece&& piece, std::istream& in, Board& b) const
{
	uint16_t line = 4;
	uint16_t column = 4;
	if (in >> line && in >> column) {
		Board::Position pos = { static_cast<uint8_t>(line), static_cast<uint8_t>(column) };
		auto& optionalPiece = b[pos];
		if (optionalPiece)
			throw "The position is not empty";
		optionalPiece = std::move(piece);
		return pos;
	}
	throw "Please enter numbers between 0 and 3.";
}

std::ostream& operator<<(std::ostream& out, const Player& p)
{
	return out << p.m_name;
}
