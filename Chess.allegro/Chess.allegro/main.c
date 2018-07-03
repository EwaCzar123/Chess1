/*

#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
enum { empty, wP, wH, wB, wR, wQ, wK, bP, bH, bB, bR, bQ, bK };
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

void board_squares(int board[8][8]){


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



void ustaw_pionki(ALLEGRO_BITMAP* tablica_bitmapa[8][8], ALLEGRO_DISPLAY* okno, int board[8][8])
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board[i][j] == wP) {

			}

		}
	}

}
void pobierz_klikniecie(ALLEGRO_EVENT_QUEUE *event_queue, int *x, int *y, ALLEGRO_BITMAP* tablica_bitmapa[8][8],
	ALLEGRO_DISPLAY* okno, char co_na_polu[8][8], bool *czy_ruch_bia³ych, char*czy_wybrano_pionek, int *nr_k_pionka, int *nr_w_pionka)
{
	ALLEGRO_EVENT ev;
	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_mouse_event_source());
	//*******************************************************************

	while (true)
	{

		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			*x = ev.mouse.x;
			*y = ev.mouse.y;

			if ((*x > 30 && *x < 150) && (*y > 100 && *y < 140))//sprawdz czy u¿ytkownik kliknal "NOWA GRA"
			{
				stworz_plansze(tablica_bitmapa);
				ustaw_pionki(tablica_bitmapa, okno, co_na_polu);
				wyswietl_aktualna_plansze(tablica_bitmapa, okno);
				*czy_ruch_bia³ych = 1;
				*czy_wybrano_pionek = 'n';
				*nr_w_pionka = 10;
				*nr_k_pionka = 10;
			}
			else if ((*x > 200 && *x < 600) && (*y > 100 && *y < 500))
			{
				break;
			}
			printf("%d\n", *x);
			printf("%d\n", *y);

		}

	}
}
//*****************************************************************************************************************
void jakie_wybrano_pole(int x, int y, int *nr_kolumny, int *nr_wiersza)
{
	if (x > 200 && x < 250)
	{
		*nr_kolumny = 0;
	}
	else if (x > 250 && x < 300)
	{
		*nr_kolumny = 1;
	}
	else if (x > 300 && x < 350)
	{
		*nr_kolumny = 2;
	}
	else if (x > 350 && x < 400)
	{
		*nr_kolumny = 3;
	}
	else if (x > 400 && x < 450)
	{
		*nr_kolumny = 4;
	}
	else if (x > 450 && x < 500)
	{
		*nr_kolumny = 5;
	}
	else if (x > 500 && x < 550)
	{
		*nr_kolumny = 6;
	}
	else if (x > 550 && x < 600)
	{
		*nr_kolumny = 7;
	}

	if (y > 100 && y < 150)
	{
		*nr_wiersza = 0;
	}
	else if (y > 150 && y < 200)
	{
		*nr_wiersza = 1;
	}
	else if (y > 200 && y < 250)
	{
		*nr_wiersza = 2;
	}
	else if (y > 250 && y < 300)
	{
		*nr_wiersza = 3;
	}
	else if (y > 300 && y < 350)
	{
		*nr_wiersza = 4;
	}
	else if (y > 350 && y < 400)
	{
		*nr_wiersza = 5;
	}
	else if (y > 400 && y < 450)
	{
		*nr_wiersza = 6;
	}
	else if (y > 450 && y < 500)
	{
		*nr_wiersza = 7;
	}

}
int main()
{

	al_init(); // inicjowanie biblioteki allegro
	al_install_keyboard(); // instalowanie sterownika klawiatury
	ALLEGRO_KEYBOARD_STATE* klawiatura; // utworzenie struktury do odczytu stanu klawiatury
	ALLEGRO_DISPLAY* okno = al_create_display(800, 600);// tworzymy wskaŸnik okna, i podajemy jego szer. i wys
	al_set_window_title(okno, "GRA W WARCABY");// podajemy tytu³ okna
	al_set_target_bitmap(al_get_backbuffer(okno));
	al_clear_to_color(al_map_rgb_f(128, 128, 128));  // czyœci okno podanym kolorem.

	ALLEGRO_BITMAP* tablica_bitmapa[8][8];
	char co_na_polu[8][8], moja_damka, twoja_damka, moj_pionek, twoj_pionek, czy_wybrano_pionek = 'n';
	bool czy_ruch_bialych = 1;
	int x, y, nr_wiersza, nr_kolumny, nr_w_pionka = 10, nr_k_pionka = 10;

	//obsluga myszki

	al_install_mouse();
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;

	stworz_bitmape_z_napisem(okno);
	stworz_plansze(tablica_bitmapa);
	wyswietl_aktualna_plansze(tablica_bitmapa, okno);
	while (1)
	{
		pobierz_klikniecie(event_queue, &x, &y, tablica_bitmapa, okno, co_na_polu, &czy_ruch_bialych, &czy_wybrano_pionek, &nr_k_pionka, &nr_w_pionka);
		jakie_wybrano_pole(x, y, &nr_kolumny, &nr_wiersza);

		if (czy_ruch_bialych == 1)
		{
			moja_damka = 'B';
			twoja_damka = 'C';
			moj_pionek = 'b';
			twoj_pionek = 'c';
			int wiersz = -1;

			if (co_na_polu[nr_wiersza][nr_kolumny] == moj_pionek)//jesli jest ruch bia³ych i wybrano bialy pionek
			{	//sprawdzam mo¿liwosc ruchu tym pionkiem//if sprawdzaj¹cy czy jest mozliwe zbicie pionka
				//if(sprawdz czy ktores z pol jest puste)
				//jesli sa oba pelne to 
				if ((co_na_polu[nr_wiersza + wiersz][nr_kolumny + 1] == twoj_pionek && co_na_polu[nr_wiersza + 2 * wiersz][nr_kolumny + 2] == 'o') || (co_na_polu[nr_wiersza + wiersz][nr_kolumny - 1] == twoj_pionek && co_na_polu[nr_wiersza + 2 * wiersz][nr_kolumny - 2] == 'o') || (co_na_polu[nr_wiersza + wiersz][nr_kolumny + 1] == twoja_damka && co_na_polu[nr_wiersza + 2 * wiersz][nr_kolumny + 2] == 'o') || (co_na_polu[nr_wiersza + wiersz][nr_kolumny - 1] == twoja_damka && co_na_polu[nr_wiersza + 2 * wiersz][nr_kolumny - 2] == 'o'))
				{
					al_set_target_bitmap(tablica_bitmapa[nr_w_pionka][nr_k_pionka]);//zamalowujemy poprzedni potencjalny pionek do ruchu
					al_draw_filled_circle(25, 25, 20, al_map_rgba(200, 200, 200, 200));
					al_set_target_bitmap(al_get_backbuffer(okno));

					czy_wybrano_pionek = 'z';//wybrano pionek do zbicia innego
					nr_w_pionka = nr_wiersza;
					nr_k_pionka = nr_kolumny;

					al_set_target_bitmap(tablica_bitmapa[nr_wiersza][nr_kolumny]);//zamalowujemy nowy pionek zdolny do ruchu
					al_draw_filled_circle(25, 25, 20, al_map_rgba(100, 100, 100, 200));
					al_set_target_bitmap(al_get_backbuffer(okno));

					wyswietl_aktualna_plansze(tablica_bitmapa, okno);

				}
				else if (co_na_polu[nr_wiersza + wiersz][nr_kolumny + 1] == 'o' || co_na_polu[nr_wiersza + wiersz][nr_kolumny - 1] == 'o')
				{
					for (int i = 0; i < 8; i++)
					{
						for (int j = 0; j < 8; j++)
						{
							printf("%c", co_na_polu[i][j]);
						}
						printf("\n");
					}
					printf("%c\n", co_na_polu[nr_wiersza + wiersz][nr_kolumny + 1]);
					printf("%c", co_na_polu[nr_wiersza + wiersz][nr_kolumny - 1]);
					printf("\nNr wiersza: %d\nNr kolumny: %d\n", nr_wiersza, nr_kolumny);
					//zamalowujemy poprzedni potencjalny pionek do ruchu
					al_set_target_bitmap(tablica_bitmapa[nr_w_pionka][nr_k_pionka]);
					al_draw_filled_circle(25, 25, 20, al_map_rgba(200, 200, 200, 200));
					al_set_target_bitmap(al_get_backbuffer(okno));
					czy_wybrano_pionek = 'p';//wybrano pionek do przesuniecia
					nr_w_pionka = nr_wiersza;
					nr_k_pionka = nr_kolumny;
					//zamalowujemy nowy pionek zdolny do ruchu
					al_set_target_bitmap(tablica_bitmapa[nr_wiersza][nr_kolumny]);
					al_draw_filled_circle(25, 25, 20, al_map_rgba(100, 100, 100, 200));
					al_set_target_bitmap(al_get_backbuffer(okno));

					wyswietl_aktualna_plansze(tablica_bitmapa, okno);
				}



			}
			else if (co_na_polu[nr_wiersza][nr_kolumny] == moja_damka)
			{
				//sprawdzam czy jest mo¿liwy ruch damka
			}
			else if (czy_wybrano_pionek == 'p' && co_na_polu[nr_wiersza][nr_kolumny] == 'o'  && nr_wiersza == nr_w_pionka + wiersz && (nr_kolumny == nr_k_pionka + 1 || nr_kolumny == nr_k_pionka - 1))
			{
				co_na_polu[nr_w_pionka][nr_k_pionka] = 'o';//zeruje pole na ktorym byl pionek
				co_na_polu[nr_wiersza][nr_kolumny] = 'b';// wstawiamy pionka na nowe pole
														 //rysujemy nowy pionek
				al_set_target_bitmap(tablica_bitmapa[nr_wiersza][nr_kolumny]);
				al_draw_filled_circle(25, 25, 20, al_map_rgba(200, 200, 200, 200));
				al_set_target_bitmap(al_get_backbuffer(okno));
				//zamalowujemy pole na ktorym stal pionek
				al_set_target_bitmap(tablica_bitmapa[nr_w_pionka][nr_k_pionka]);
				al_clear_to_color(al_map_rgb(100, 50, 10));
				al_set_target_bitmap(al_get_backbuffer(okno));
				al_draw_bitmap(tablica_bitmapa[nr_w_pionka][nr_k_pionka], 350, 200, 0);

				wyswietl_aktualna_plansze(tablica_bitmapa, okno);
				nr_w_pionka = 10;
				nr_k_pionka = 10;

			}
		}
	}




	//***************************************************************************************8
	//***********NIEPOTRZEBNE RZECZY****************************************************8
	/*
	//obsluga myszki // nie mam pojecia co poszczególne funkcje robi¹, ale jak wszystkie je zamieœcisz to myszka dzia³a ;)
	int x, y;
	al_install_mouse();
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_EVENT ev;
	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_mouse_event_source());
	al_wait_for_event(event_queue, &ev);
	if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)//kiedy nast¹pi klikniêcie program wchodzi do funkcji i pobiera wspó³rzêdne x i y miejsca w które siê kliknê³o
	{
	x = ev.mouse.x;
	y = ev.mouse.y;
	}


	//funkcje potrzebne do stworzenia nowej bitmapy
	ALLEGRO_BITMAP* kwadrat2 = al_create_bitmap(200, 200);//"kwadrat2" to przyk³adowa nazwa bitmapy, 200, 200 to wielkoœæ bitmapy
	al_set_target_bitmap(kwadrat2);//wskazujemy do czego maj¹ siê odnosiæ kolejne funkcje (tutaj do naszej bitmapy "kwadrat2"
	al_clear_to_color(al_map_rgb(0, 0, 120));//0, 0, 120 to red-green-blue, czyli ustawiam kolory dla naszej bitmapy
	al_set_target_bitmap(al_get_backbuffer(okno));
	al_draw_bitmap(kwadrat2, 350, 200, 0); //rysuje bitmapê w oknie od naszej gry

	//funkcje potrzebne do mozliwosci pisania
	al_init_font_addon();
	ALLEGRO_FONT    *font8 = al_create_builtin_font();
	//funkcje potrzebne do napisania "allegro" na bitmapie
	al_set_target_bitmap(kwadrat2);
	al_draw_text(font8, al_map_rgb(0, 0, 0), 50, 50, 0, "allegro");
	al_set_target_bitmap(al_get_backbuffer(okno));
	al_draw_bitmap(kwadrat2, 350, 200, 0);
	*****************************************************
	//funkcje potrzebne do mo¿liwosci rysowania
	al_init_primitives_addon();
	//funkcje potrzebne do narysowania okrêgu na bitmapie
	al_set_target_bitmap(kwadrat2);
	al_draw_filled_circle(50, 120, 34, al_map_rgba(200, 28, 0, 60)); //ustawiasz gdzie chcesz zamieœciæ kó³ko na danej bitmapie ustawiasz kolor kólka
	al_set_target_bitmap(al_get_backbuffer(okno));
	al_draw_bitmap(kwadrat2, 350, 200, 0);

	al_flip_display();// odœwie¿am okno - wyœwietl wszystko od nowa

	//petla wyswietlajaca na konsoli tablice z pionkami
	for (int i = 0; i<8; i++)
	{
	for (int j = 0; j<8; j++)
	{
	printf("%c", co_na_polu[i][j]);
	}
	printf("\n");
	}
	
	//*******************************************************************************************************8
	//*********************************************************************************************************




	al_rest(20.0);
	//al_destroy_font(font8);
	al_destroy_display(okno);

	return 0;
}

*/