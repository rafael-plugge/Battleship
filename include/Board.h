#ifndef BOARD_H
#define BOARD_H

#include "Square.h"

class Board
{
public:
	Board();
	~Board();

	bool checkPlaceIsValid(const int &, const int &) const;
private:
	static const int s_BOARD_ROWS = 5;
	static const int s_BOARD_COLS = 5;

	int m_numOfRows;
	int m_numOfCollumns;

	Square m_squares[s_BOARD_ROWS][s_BOARD_COLS];
};

#endif // !BOARD_H