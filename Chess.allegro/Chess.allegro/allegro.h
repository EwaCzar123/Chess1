/*
#ifndef ALLEGRO_H
#define ALLEGRO_H

#include "allegro5/allegro.h"
//#include "Game.h"
//#include "ChessPiece.h"

typedef struct images {
	//Chess Pieces
	ALLEGRO_BITMAP *wPImg;
	ALLEGRO_BITMAP *bPImg;
	ALLEGRO_BITMAP *wRImg;
	ALLEGRO_BITMAP *bRImg;
	ALLEGRO_BITMAP *wHImg;
	ALLEGRO_BITMAP *bHImg;
	ALLEGRO_BITMAP *wBImg;
	ALLEGRO_BITMAP *bBImg;
	ALLEGRO_BITMAP *wQImg;
	ALLEGRO_BITMAP *bQImg;
	ALLEGRO_BITMAP *wKImg;
	ALLEGRO_BITMAP *bKImg;

}images;

void LoadImages() {
	imgs = malloc(sizeof(images));

	//Chess Pieces
	imgs->wPImg = al_load_bitmap("Pionki/bialyPion.png");
	imgs->bPImg = al_load_bitmap("Pionki/czarnyPion.png");
	imgs->wRImg = al_load_bitmap("Pionki/bialaWieza.png");
	imgs->bRImg = al_load_bitmap("Pionki/czarnaWieza.png");
	imgs->wHImg = al_load_bitmap("Pionki/czarnaWieza.png");
	imgs->bHImg = al_load_bitmap("Pionki/czarnyKon.png");
	imgs->wBImg = al_load_bitmap("resources/images/pieces/whiteBishopPiece.png");
	imgs->bBImg = al_load_bitmap("resources/images/pieces/blackBishopPiece.png");
	imgs->wQImg = al_load_bitmap("resources/images/pieces/whiteQueenPiece.png");
	imgs->bQImg = al_load_bitmap("resources/images/pieces/blackQueenPiece.png");
	imgs->wKImg = al_load_bitmap("resources/images/pieces/whiteKingPiece.png");
	imgs->bKImg = al_load_bitmap("resources/images/pieces/blackKingPiece.png");
}
#endif ALLEGRO_h
*/