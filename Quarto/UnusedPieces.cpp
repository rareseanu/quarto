#include "UnusedPieces.h"
#include <iostream>
#include <bitset>
#include <sstream>

UnusedPieces::UnusedPieces()
{
	for (auto index = 0U; index < 16U; ++index) 
	{
		const auto b = std::bitset<4>(index);
		//const std::string str = std::bitset<4>(index).to_string();
		std::stringstream ss;
		Piece piece = Piece(Piece::Body(b[3]), Piece::Color(b[2]), Piece::Height(b[1]), Piece::Shape(b[0]));
		ss << piece;
		m_pieces.insert(std::make_pair(ss.str(), std::forward<Piece&&>(piece)));
	}
}

Piece UnusedPieces::PickPiece(const std::string& name)
{
	auto node = m_pieces.extract(name);
	if (node)
		return std::move(node.mapped());
	else
		throw "Name not found.";
}

std::ostream& operator<<(std::ostream& os, const UnusedPieces& unusedPieces)
{
	for (const auto& [pieceName, piece] : unusedPieces.m_pieces) {
		os << pieceName << " ";
	}
	return os;
}
