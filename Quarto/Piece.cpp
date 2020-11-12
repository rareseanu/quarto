#include "Piece.h"

Piece::Piece(Body body, Color color, Height height, Shape shape) : 
	m_body(body),
	m_color(color),
	m_height(height),
	m_shape(shape)
{
	
	static_assert(sizeof(*this) <= 1, "This class should be 1 byte in size");
}

Piece::Piece(const Piece& piece)
{
	*this = piece;
}

Piece::Piece(Piece&& piece)
{
	*this = std::move(piece);
}

Piece::Body Piece::GetBody() const
{
	return m_body;
}

Piece::Color Piece::GetColor() const
{
	return m_color;
}

Piece::Height Piece::GetHeight() const
{
	return m_height;
}

Piece::Shape Piece::GetShape() const
{
	return m_shape;
}

Piece& Piece::operator=(const Piece& other)
{
	this->m_body = other.m_body;
	this->m_color = other.m_color;
	this->m_height = other.m_height;
	this->m_shape = other.m_shape;
	return *this;
}

Piece& Piece::operator=(Piece&& other)
{
	this->m_body = other.m_body;
	this->m_color = other.m_color;
	this->m_height = other.m_height;
	this->m_shape = other.m_shape;
	new (&other)Piece;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Piece& piece)
{
	return os << 
		static_cast<int>(piece.m_body) << 
		static_cast<int>(piece.m_color) << 
		static_cast<int>(piece.m_height) << 
		static_cast<int>(piece.m_shape);
}
