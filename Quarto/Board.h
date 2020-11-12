#pragma once

#include "Piece.h"

#include <array>
#include <optional>

class Board
{
public:
	using Position = std::pair<uint8_t, uint8_t>;

public:
	Board() = default;

	std::optional<Piece>& operator[] (const Position& pos);

private:
	static const size_t kWidth = 4;
	static const size_t kHeight = 4;
	static const size_t kSize = kWidth * kHeight;

private:
	std::array<std::optional<Piece>, kSize> m_pieces;
};

