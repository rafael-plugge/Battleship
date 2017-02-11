#include "Board.h"



Board::Board()
	: m_numOfRows(5)
	, m_numOfCollumns(5)
	, m_squares()
{
	for (int row = 0; row < m_numOfRows; row++)
	{
		for (int col = 0; col < m_numOfCollumns; col++)
		{
			m_squares[row][col] = Square();
		}
	}
}


Board::~Board()
{
}

bool Board::checkPlaceIsValid(const int & row, const int & col) const
{
	bool isValid = false;

	if (row <= m_numOfRows && col <= m_numOfCollumns)
	{
		isValid = !m_squares[row][col].getOccupied();
	}

	return isValid;
}
