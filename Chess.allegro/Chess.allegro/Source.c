#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
//#include "allegro.h"

enum { empty, wP, wH, wB, wR, wQ, wK, bP, bH, bB, bR, bQ, bK };

int startBoard[8][8] = { { wR, wH, wB, wK, wQ, wB, wH, wR },
{ wP,wP,wP,wP,wP,wP,wP,wP },
{ empty },
{ empty },
{ empty },
{ empty },
{ bP,bP,bP,bP,bP,bP,bP,bP },
{ bR,bH,bB,bK,bQ,bB,bH,bR } };

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


	//ALLEGRO_BITMAP *mainMenuImg;

	//ALLEGRO_BITMAP *promotionMenuImg;
	//ALLEGRO_BITMAP *endGameMenuImg;
}images;



void startgame_square(ALLEGRO_DISPLAY* window)
{
	//funkcje potrzebne do mozliwosci pisania
	al_init_font_addon();
	ALLEGRO_FONT    *font8 = al_create_builtin_font();
	//tworze bitmape z napisem
	ALLEGRO_BITMAP* square = al_create_bitmap(120, 40);
	al_set_target_bitmap(square);
	al_clear_to_color(al_map_rgb(0, 255, 0));
	al_draw_text(font8, al_map_rgb(0, 0, 255), 25, 15, 0, "NOWA GRA");
	al_set_target_bitmap(al_get_backbuffer(window));
	al_draw_bitmap(square, 30, 100, 0);
}

void board_squares(ALLEGRO_BITMAP *board[8][8]) {

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			board[i][j] = al_create_bitmap(50, 50);
		}
	}

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ((i == 0 || i == 2 || i == 4 || i == 6) && (j == 0 || j == 2 || j == 4 || j == 6))
			{
				al_set_target_bitmap(board[i][j]);
				al_clear_to_color(al_map_rgb(176, 176, 251));
			}
			else if ((i == 0 || i == 2 || i == 4 || i == 6) && (j == 1 || j == 3 || j == 5 || j == 7))
			{
				al_set_target_bitmap(board[i][j]);
				al_clear_to_color(al_map_rgb(45, 51, 83));
			}
			else if ((i == 1 || i == 3 || i == 5 || i == 7) && (j == 0 || j == 2 || j == 4 || j == 6))
			{
				al_set_target_bitmap(board[i][j]);
				al_clear_to_color(al_map_rgb(45, 51, 83));
			}
			else if ((i == 1 || i == 3 || i == 5 || i == 7) && (j == 1 || j == 3 || j == 5 || j == 7))
			{
				al_set_target_bitmap(board[i][j]);
				al_clear_to_color(al_map_rgb(176, 176, 251));
			}
		}
	}
}


void wyswietl_aktualna_plansze(ALLEGRO_BITMAP* tablica_bitmapa[8][8], ALLEGRO_DISPLAY* okno)
{
	int przesun_w_dol = 100;
	for (int i = 0; i < 8; i++)
	{
		int przesun_w_prawo = 200;

		for (int j = 0; j < 8; j++)
		{
			al_set_target_bitmap(al_get_backbuffer(okno));
			al_draw_bitmap(tablica_bitmapa[i][j], przesun_w_prawo, przesun_w_dol, 0);

			przesun_w_prawo += 50;
		}
		przesun_w_dol += 50;
	}
	al_flip_display(); //  wyœwietlamy wszystko na ekran
}


main() {
	al_init();
	al_init_image_addon();
	//ALLEGRO_DISPLAY *display = NULL;
	al_install_keyboard(); // instalowanie sterownika klawiatury
	ALLEGRO_KEYBOARD_STATE* klawiatura;
	ALLEGRO_BITMAP  *image = NULL;
	ALLEGRO_BITMAP *board[8][8];
	ALLEGRO_DISPLAY* window = NULL;

	ALLEGRO_DISPLAY* okno = al_create_display(800, 600);// tworzymy wskaŸnik okna, i podajemy jego szer. i wys
	al_set_window_title(okno, "GRA W WARCABY");// podajemy tytu³ okna
	al_set_target_bitmap(al_get_backbuffer(okno));
	al_clear_to_color(al_map_rgb_f(128, 128, 128));  // czyœci okno podanym kolorem.



	int image_height, image_width;
	
	//display = al_create_display(360, 360);
	image = al_load_bitmap("Pionki/bialyPion.png");

	image_height = al_get_bitmap_height(image);
	image_width = al_get_bitmap_width(image);

	al_clear_to_color(al_map_rgb(176, 176, 251));

	board_squares(board);
	startgame_square(okno);





	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (startBoard[i][j] == wP) {
				board[i][j] = al_load_bitmap("Pionki/bialyPion.png");
				al_draw_scaled_bitmap(board[i][j], 0, 0, image_width, image_height, 0, 0, 0.2,0.2 ,0);

			}

		}
	}

	
	wyswietl_aktualna_plansze(board, okno);

	//al_draw_scaled_bitmap(image,0,0,image_width,image_height,0,0,70,70,0 );
	//al_draw_bitmap(image, 50,50,0);
	//al_flip_display();
	al_rest(7);




	return 0;
}