#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <windows.h>
#include <time.h>



// Объявление необходимых макросов
#define M_PI 3.14159265358979323846
#define width 60
#define height 21


// Объяление типов Игрок и Шайба
typedef struct {
	int x, y, w;
	char skin;
} TPlayer;
typedef struct {
	float x, y;
	int ix, iy;
	float alpha;
	float speed;
	char skin;
} TPuck;


// Инициализация объектов
TPlayer player1, player2;
TPuck puck;
char array[height][width + 1];
// Для циклов
int i, startPuck, RUN = 0, OFF = 0, countGoalsPlayer1 = 0, countGoalsPlayer2 = 0;


//___________Доп функции___________
void showPanelMenu()
{
	system("cls");

	//Вывод заготовленного меню
	char menu[4][25] = { ".....МЕНЮ ИГРЫ.....", "ВОЗОБНОВИТЬ\tESC", "НАСТРОЙКИ\t'S'", "ВЫЙТИ ИЗ ИГРЫ\t'C'", };
	for (i = 0; i < 4; i++)
		printf("%s\n", menu[i]);

	Sleep(250);
}
void resGame()
{
	for (i = 3; i >= 1; i--)
	{
		system("cls");
		printf("Возобновление игры через: %d", i);
		Sleep(1000);
	}
}
void byebye()
{
	system("cls");

	OFF = 1;
	char bb[] = "Bye Bye!\n";
	int len = strlen(bb);

	for (i = 0; i < len; i++)
	{
		printf("%c", bb[i]);
		Sleep(120);
	}
}
void showPanelSettings()
{
	system("cls");

	char settings[4][25] = { ".....НАСТРОЙКИ.....", "ИЗМ. СКИНЫ\t'S'", "ИЗМ. ПАРАМЕТРЫ\t'P'", "ВЕРНУТЬСЯ\tESC" };
	for (i = 0; i < 4; i++)
		printf("%s\n", settings[i]);

	Sleep(250);
}
void showPanelChoicePlayer()
{
	system("cls");

	char choicePlayerSkin[4][25] = { ".....ИЗМ.СКИНЫ.....", "ИГРОК(ЛЕВЫЙ)\t'1'", "ИГРОК(ПРАВЫЙ)\t'2'", "ВЕРНУТЬСЯ\tESC" };
	for (i = 0; i < 4; i++)
		printf("%s\n", choicePlayerSkin[i]);

	Sleep(250);
}
void showPanelChoiceSkin()
{
	system("cls");

	char skins[7][25] = { "....ВЫБОР СКИНА....", "-DOGY- (@)\t'1'", "-ALIEN- (&)\t'2'","-SECRET- (?)\t'3'", "-WALL- (#)\t'4'", "-MAJOR- ($)\t'5'", "ВЕРНУТЬСЯ\tESC" };
	for (i = 0; i < 7; i++)
		printf("%s\n", skins[i]);

	Sleep(250);
}
void choiceSkinPlayer(TPlayer* player)
{
	do {
		if (GetKeyState('1') < 0)
		{
			(*player).skin = '@';
			system("cls");
			printf("Успешно!\n");
			Sleep(1000);
			break;
		}
		if (GetKeyState('2') < 0)
		{
			(*player).skin = '&';
			system("cls");
			printf("Успешно!\n");
			Sleep(1000);
			break;
		}
		if (GetKeyState('3') < 0) {
			(*player).skin = '?';
			system("cls");
			printf("Успешно!\n");
			Sleep(1000);
			break;
		}
		if (GetKeyState('4') < 0)
		{
			(*player).skin = '#';
			system("cls");
			printf("Успешно!\n");
			Sleep(1000);
			break;
		}
		if (GetKeyState('5') < 0)
		{
			(*player).skin = '$';
			system("cls");
			printf("Успешно!\n");
			Sleep(1000);
			break;
		}
		if (GetKeyState(VK_ESCAPE) < 0) break;

	} while (1);
}
void showPanelParametrs()
{
	system("cls");

	char parametr[4][25] = { "...ИЗМ.ПАРАМЕТРЫ...", "СКОРОСТЬ ШАЙБЫ\t'S'", "РАЗМЕРЫ ИГРОКОВ\t'R'","ВЕРНУТЬСЯ\tESC" };
	for (i = 0; i < 4; i++)
		printf("%s\n", parametr[i]);

	Sleep(250);
}
void showPanelChoiceSpeedPuck()
{
	system("cls");

	char parametr[5][25] = { "..СКОРОСТЬ  ШАЙБЫ..", "МАЛЕНЬКАЯ\t'1'", "СРЕДНЯЯ\t\t'2'", "БОЛЬШАЯ\t\t'3'", "ВЕРНУТЬСЯ\tESC" };
	for (i = 0; i < 5; i++)
		printf("%s\n", parametr[i]);

	Sleep(250);
}
void changeSpeedPuck(TPuck* puck)
{
	do {
		if (GetKeyState('1') < 0)
		{
			system("cls");
			(*puck).speed = 0.5;
			printf("Успешно!");
			Sleep(1000);
			break;
		}
		if (GetKeyState('2') < 0)
		{
			system("cls");
			(*puck).speed = 0.75;
			printf("Успешно!");
			Sleep(1000);
			break;
		}
		if (GetKeyState('3') < 0)
		{
			system("cls");
			(*puck).speed = 1;
			printf("Успешно!");
			Sleep(1000);
			break;
		}
		if (GetKeyState(VK_ESCAPE) < 0) break;

	} while (1);
}
void showPanelChoiceSizePlayers()
{
	system("cls");

	char sizePlayers[5][25] = { "..РАЗМЕРЫ ИГРОКОВ..", "МАЛЕНЬКИЙ\t'1'", "СТАНДАРТНЫЙ\t'2'", "БОЛЬШОЙ\t\t'3'", "ВЕРНУТЬСЯ\tESC" };
	for (i = 0; i < 5; i++)
		printf("%s\n", sizePlayers[i]);

	Sleep(250);
}
void changeSizePlayers(TPlayer* playerOne, TPlayer* playerTwo)
{
	do {
		if (GetKeyState('1') < 0)
		{
			system("cls");
			(*playerOne).w = (*playerTwo).w = 3;
			printf("Успешно!");
			Sleep(1000);
			break;
		}
		if (GetKeyState('2') < 0)
		{
			system("cls");
			(*playerOne).w = (*playerTwo).w = 5;
			printf("Успешно!");
			Sleep(1000);
			break;
		}
		if (GetKeyState('3') < 0)
		{
			system("cls");
			(*playerOne).w = (*playerTwo).w = 7;
			printf("Успешно!");
			Sleep(1000);
			break;
		}
		if (GetKeyState(VK_ESCAPE) < 0) break;

	} while (1);



}
void showTotalGoals()
{
	system("cls");
	printf("....СЧЁТ ИГРЫ....\nPLAYER 1:\t%d\nPLAYER 2:\t%d\nВОЗОБНОВИТЬ   TAB", countGoalsPlayer1, countGoalsPlayer2);
	Sleep(250);
}


//___________Игровое поле___________

// Создание игрового поля
void initMap()
{
	for (i = 0; i < width; i++)
		array[0][i] = '#';
	array[0][i] = '\0';

	strncpy(array[1], array[0], width + 1);
	for (i = 1; i < width - 1; i++)
		array[1][i] = ' ';
	array[1][i] = '#';

	for (i = 2; i < height - 1; i++)
		strncpy(array[i], array[1], width + 1);

	strncpy(array[height - 1], array[0], width + 1);

	int board = height / 10 + 1;
	char voidline[width + 1];
	for (i = 0; i < width; i++)
		voidline[i] = ' ';
	voidline[i] = '\0';

	for (i = 1 + board; i < (height - 1) - board; i++)
		strncpy(array[i], voidline, width + 1);
}
// Вывод игрового поля на экран
void showMap()
{
	for (i = 0; i < height; i++)
		printf("%s\n", array[i]);
}




//___________Игроки___________

// Инициализация
void initPlayers()
{
	player1.w = player2.w = 5;

	player1.skin = '@';
	player2.skin = '&';

	player1.x = 1;
	player1.y = (height - player1.w) / 2;

	player2.x = width - 2;
	player2.y = (height - player2.w) / 2;
}
// Добавление игроков на игровое поле
void placePlayers()
{
	for (i = player1.y; i < player1.y + player1.w; i++)
		array[i][1] = player1.skin;

	for (i = player2.y; i < player2.y + player2.w; i++)
		array[i][width - 2] = player2.skin;
}
// Перемещение игроков
void movePlayers(TPlayer* player, int y)
{
	(*player).y = y;
	if ((*player).y < 1) (*player).y = 1;
	if ((*player).y + (*player).w >= height) (*player).y = height - (*player).w - 1;
}
// Клавиатура пользователя
void keyboardPlayers()
{
	// Управление игрока 1
	if (GetKeyState('W') < 0) movePlayers(&player1, player1.y - 1);
	if (GetKeyState('S') < 0) movePlayers(&player1, player1.y + 1);

	// Управление игрока 2
	if (GetKeyState(VK_UP) < 0) movePlayers(&player2, player2.y - 1);
	if (GetKeyState(VK_DOWN) < 0) movePlayers(&player2, player2.y + 1);

	// Запуск шайбы
	if (GetKeyState(VK_SPACE) < 0) RUN = 1;

	// Вывод счета
	if (GetKeyState(VK_TAB) < 0)
	{
		showTotalGoals();

		do {
			if (GetKeyState(VK_TAB) < 0)
			{
				resGame();
				break;
			}
		} while (1);
	}

	// Меню игры
	if (GetKeyState(VK_ESCAPE) < 0)
	{
	FLAG_MENU:
		showPanelMenu();

		// Панель меню
		do {
			// Возобновить
			if (GetKeyState(VK_ESCAPE) < 0)
			{
				resGame();
				break;
			}

			// Настройки
			if (GetKeyState('S') < 0)
			{
			FLAG_SETTINGS:
				showPanelSettings();

				// Панель настроек
				do {
					// Изменить скины
					if (GetKeyState('S') < 0)
					{
					FLAG_SKINS:
						showPanelChoicePlayer();

						// Панель изменения скинов
						do {
							if (GetKeyState('1') < 0)
							{
								showPanelChoiceSkin();
								choiceSkinPlayer(&player1);
								goto FLAG_SKINS;
							}
							if (GetKeyState('2') < 0)
							{
								showPanelChoiceSkin();
								choiceSkinPlayer(&player2);
								goto FLAG_SKINS;
							}
							if (GetKeyState(VK_ESCAPE) < 0) goto FLAG_SETTINGS;

						} while (1);
					}

					// Изменить параметры
					if (GetKeyState('P') < 0)
					{
					FLAG_PARAMETR:
						showPanelParametrs();

						// Панель изменения параметров
						do {
							// Изменение скорости
							if (GetKeyState('S') < 0)
							{
								showPanelChoiceSpeedPuck();
								changeSpeedPuck(&puck);
								goto FLAG_PARAMETR;
							}

							// Изменение размеров игроков
							if (GetKeyState('R') < 0)
							{
								showPanelChoiceSizePlayers();
								changeSizePlayers(&player1, &player2);
								goto FLAG_PARAMETR;
							}

							// Вернуться
							if (GetKeyState(VK_ESCAPE) < 0) goto FLAG_SETTINGS;

						} while (1);
					}

					// Вернуться в главное меню
					if (GetKeyState(VK_ESCAPE) < 0) goto FLAG_MENU;

				} while (1);
			}

			// Выйти из игры
			if (GetKeyState('C') < 0)
			{
				byebye();
				break;
			}

		} while (1);
	}
}



// ___________Шайба___________

// Инициализация шайбы
void initPuck()
{
	startPuck = (0 + rand() % 2);

	if (startPuck)
	{
		puck.ix = player2.x - 1;
		puck.iy = player2.w / 2 + player2.y;
		puck.alpha = (float)(576 + rand() % 104) / 100.0 + M_PI;
	}
	else
	{
		puck.ix = player1.x + 1;
		puck.iy = (player1.w / 2) + player1.y;
		puck.alpha = (float)(576 + rand() % 104) / 100.0;
	}

	puck.skin = '*';
	puck.speed = 1;
}
// Добавление шайбы на карту
void placePuck()
{
	array[puck.iy][puck.ix] = puck.skin;
}
// Перемещение шайбы
void movePuck(float x, float y)
{
	puck.x = x;
	puck.y = y;

	puck.ix = (int)roundf(puck.x);
	puck.iy = (int)roundf(puck.y);
}
// Проверка на выход за границы (гол)
void movePuckCheck()
{
	if (puck.ix < player1.x || puck.ix > player2.x)
	{
		RUN = 0;
		if (puck.ix < player1.x)
		{
			startPuck = 0;
			puck.alpha = (float)(576 + rand() % 104) / 100.0;
			countGoalsPlayer2++;
		}
		else
		{
			startPuck = 1;
			puck.alpha = (float)(576 + rand() % 104) / 100.0 + M_PI;
			countGoalsPlayer1++;
		}
	}
}
// Если вышел за границу - перемещение к игроку
void placePuckOnPlayer(int RUN)
{
	if (!RUN) {
		if (startPuck) movePuck((float)(player2.x - 1), (float)(player2.y + player2.w / 2));
		else  movePuck((float)(player1.x + 1), (float)(player1.y + player1.w / 2));
	}
}
// Физика полета снаряда
void autoMovePuck()
{
	if (puck.alpha < 0) puck.alpha += 2 * M_PI;
	if (puck.alpha > 2 * M_PI) puck.alpha -= 2 * M_PI;

	TPuck copyPuck = puck;

	movePuck((float)(puck.x + cos(puck.alpha) * puck.speed), (float)(puck.y + sin(puck.alpha) * puck.speed));

	if (array[puck.iy][puck.ix] == '#' || array[puck.iy][puck.ix] == player1.skin || array[puck.iy][puck.ix] == player2.skin)
	{
		if (puck.ix != copyPuck.ix && puck.iy != copyPuck.iy)
		{
			if (array[copyPuck.iy][puck.ix] == array[puck.iy][copyPuck.ix]) copyPuck.alpha += M_PI;
			else if (array[copyPuck.iy][puck.ix] == ' ') copyPuck.alpha = 2 * M_PI - copyPuck.alpha;
			else copyPuck.alpha = 3 * M_PI - copyPuck.alpha;
		}
		else if (puck.ix == copyPuck.ix) copyPuck.alpha = 2 * M_PI - copyPuck.alpha;
		else copyPuck.alpha = M_PI - copyPuck.alpha;
	}
	if (copyPuck.alpha != puck.alpha)
	{
		puck = copyPuck;
		autoMovePuck();
	}
}




// Ускорение системы и удаление курсора из консоли
void turboCls(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void offCursor() {
	HANDLE  handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(handle, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(handle, &structCursorInfo);
}




int main()
{
	system("chcp 1251");
	system("cls");
	srand(time(NULL));
	initPlayers();
	initPuck();

	do {
		turboCls(0, 0);

		movePuckCheck();

		if (RUN) autoMovePuck();

		initMap();
		placePlayers();
		placePuck();
		showMap();
		offCursor();
		Sleep(8);

		keyboardPlayers();

		placePuckOnPlayer(RUN);


	} while (!OFF);

	return 0;
}