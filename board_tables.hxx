#ifndef _BOARD_TABLES_
#define _BOARD_TABLES_

#include <string>

using namespace std;

extern const bool IS_KNIGHT_OR_KING[13+2];
extern const bool IS_PAWN_OR_KING[13+2];
extern const bool IS_KING[13+2];
extern const bool IS_SHORT_DISTANCE_PIECE[13+2];
extern const bool IS_LONG_DISTANCE_PIECE[13+2];

#define EAST 1
// (index 0)
#define WEST  -1
// (index 4)
#define NORTH 8
// (index 1)
#define SOUTH -8
// (index 5)
#define NORTH_EAST 8+1
// (index 2)
#define SOUTH_WEST -8-1
// (index 6)
#define NORTH_WEST 8-1
// (index 3)
#define SOUTH_EAST -8+1
// (index 7)
extern const int DIRECTIONS[9];
extern const string SDIRECTION_NAME[8];
extern const string UDIRECTION_NAME[4];

extern const int direction_dc[8];
extern const int direction_dr[8];

extern const bool BORDER_COLUMN[8];
extern const unsigned char BORDER_DISTANCE[64];//counted in number of king moves

#endif
