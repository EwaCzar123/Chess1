/*#ifndef CHESS_h
#define CHESS_h

#define Board_num 64

enum { empty, wP, wH, wB, wR, wQ, wK, bP, bH, bB, bR, bQ, bK };

typedef enum movetype {
	None, Normal, Attack,
	EnPassant,
	Castling,
	PromotionMove
}MoveType;

enum {};
enum {};
enum { FALSE, TRUE };

int startBoard[8][8] = { { wR, wH, wB, wK, wQ, wB, wH, wR },
{ wP,wP,wP,wP,wP,wP,wP,wP },
{ empty },
{ empty },
{ empty },
{ empty },
{ bP,bP,bP,bP,bP,bP,bP,bP },
{ bR,bH,bB,bK,bQ,bB,bH,bR } };

typedef struct {

}board;
#endif 
*/