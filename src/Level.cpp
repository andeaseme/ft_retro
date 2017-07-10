
#include <chrono>
#include <thread>
#include <math.h>
#include <fstream>
#include "Level.h"
#include "PWeapon.h"

Player			*Level::_player = 0;
int				Level::_width = 81;
int				Level::_height = 71;
Place			**Level::_map = new Place*[Level::_width * Level::_height];
Collidable		**Level::_objects = new Collidable*[1200];
int				Level::_numObjects = 0;
int				Level::_highscore = 0;

Level::Level()
{
}

Level::Level(Level const &ref)
{
}

Level::~Level()
{
}

Level			&Level::operator =(Level const &rhs)
{
	return *this;
}

void			Level::init()
{
	for (int i = 0; i < Level::getWidth() * Level::getHeight(); ++i)
		Level::_map[i] = new Place(i % Level::getWidth(),
			i / Level::getWidth());
	for (int i = 0; i < 500; ++i)
		Level::_objects[i] = 0;
	Level::_player = new Player();
	Level::_player->switchWeapon(new PWeapon());
	Level::_setHighscore();
	initscr();
	cbreak();
	noecho();
	curs_set(false);
	clear();
	keypad(stdscr, true);

	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK); //default
	init_pair(2, COLOR_BLACK, COLOR_WHITE); //border
	init_pair(3, COLOR_CYAN, COLOR_BLACK); //player
	init_pair(4, COLOR_RED, COLOR_BLACK); //W enemy
	init_pair(5, COLOR_YELLOW, COLOR_BLACK); //bullet
	init_pair(6, COLOR_MAGENTA, COLOR_BLACK); //Y enemy
	init_pair(7, COLOR_GREEN, COLOR_BLACK); //Z enemy
	_startScreen();
	_addBorder();
	attron(COLOR_PAIR(1));
	nodelay(stdscr, true);
}

void			Level::addObject(Collidable *obj)
{
	if (obj == 0 || Level::_numObjects >= 500)
		return;
	for (int i = 0; i < Level::_numObjects; ++i)
		if (Level::_objects[i] == obj)
			return;
	Level::_objects[Level::_numObjects++] = obj;
}

void			Level::deleteObject(Collidable *obj)
{
	if (obj == 0 || Level::_numObjects <= 0)
		return;
	for (int i = 0; i < Level::_numObjects; ++i)
	{
		if (Level::_objects[i] == obj)
		{
			delete Level::_objects[i];
			Level::_numObjects--;
			Level::_objects[i] = Level::_objects[Level::_numObjects];
			Level::_objects[Level::_numObjects] = 0;
			return;
		}
	}
}

Place			*Level::getPlace(unsigned int const x, unsigned int const y)
{
	if (x >= Level::getWidth() || y >= Level::getHeight())
		return 0;
	return Level::_map[y * Level::getWidth() + x];
}

Player			*Level::getPlayer()
{
	return Level::_player;
}

int				Level::getWidth()
{
	return Level::_width;
}

int				Level::getHeight()
{
	return Level::_height;
}

#define P1 Level::_player

void			Level::updatePlayer()
{
	int			ch;

	ch = getch();
	attron(COLOR_PAIR(3));
	ADDCH(ROUND(P1->getY()), ROUND(P1->getX()), EMPTYSPACE);
	switch (ch)
	{
		case 'w':
		case KEY_UP:
			P1->setLocation(P1->getX(), ROUND(P1->getY() - 1.0));
			break;
		case 'a':
		case KEY_LEFT:
			P1->setLocation(ROUND(P1->getX() - 1.0), P1->getY());
			break;
		case 's':
		case KEY_DOWN:
			P1->setLocation(P1->getX(), ROUND(P1->getY() + 1.0));
			break;
		case 'd':
		case KEY_RIGHT:
			P1->setLocation(ROUND(P1->getX() + 1.0), P1->getY());
			break;
		case ' ':
			P1->getWeapon()->flipAutofire();
			break;
	}
	ADDCH(ROUND(P1->getY()), ROUND(P1->getX()), P1->getSprite());
	attron(COLOR_PAIR(1));
}

void			Level::updateObjects()
{
	for (int i = 0; i < Level::_numObjects; ++i)
		Level::_objects[i]->move();
}

void			Level::cleanupObjects()
{
	attron(COLOR_PAIR(1));
	for (int i = 0; i < Level::_numObjects; ++i)
		if (Level::_objects[i]->getHP() == 0)
		{
			ADDCH(ROUND(_objects[i]->getX()),
				ROUND(_objects[i]->getY()), EMPTYSPACE);
			if (Level::_objects[i] != Level::getPlayer())
				Level::deleteObject(Level::_objects[i]);
			else
			{
				Level::getPlayer()->loseLife();
				attron(COLOR_PAIR(3));
				ADDCH(ROUND(P1->getY()), ROUND(P1->getX()), EMPTYSPACE);
				if (Level::getPlayer()->getLives() <= 0)
				{
					Level::_saveHighscore();
					Level::_endScreen();
					endwin();
					std::cout << "Game Over!" << std::endl;
					std::exit(1);
				}
				else
				{
					Level::getPlayer()->setLocation( Level::getWidth() / 2,
						3 * Level::getHeight() / 4 );
				}
				ADDCH(ROUND(P1->getY()), ROUND(P1->getX()), P1->getSprite());
				attron(COLOR_PAIR(1));
			}
		}
}

void			Level::render()
{
	_win_resize();
	_addBorder(); //patch
	attron(COLOR_PAIR(2));
	mvprintw(0, BORDER_W, "High Score: %-10i Score: %-10i Lives: %-10i", Level::_highscore, Level::_player->getScore(), Level::_player->getLives());
	attron(COLOR_PAIR(1));
	refresh();
}

void			Level::loop()
{
	int			i;
	int			w_rate, y_rate, y_spawn, z_rate, z_spawn;

	Collidable 	*w, *y, *z;
	w_rate = 17;
	y_rate = 81;
	y_spawn = 300;
	z_rate = 41;
	z_spawn = 500;
	i = 0;
	while (++i)
	{
		if (i % w_rate == 0)
			w = new Enemy(std::rand() % (Level::getWidth() - 1) + 1, 0); //test enemy
		if (i % y_rate == 0 && i > y_spawn)
			y = new YEnemy(std::rand() % (Level::getWidth() - 1) + 1, 0);
		if (i % z_rate == 0 && i > z_spawn)
			z = new ZEnemy(std::rand() % (Level::getWidth() - 1) + 1, 0);
		if (i % 600 == 0)
		{
			if (w_rate > 5)
				w_rate--;
			if (y_rate > 15 && i > y_spawn)
				y_rate -= 2;
			if (z_rate > 10 && i > z_spawn)
				z_rate -= 2;
		}
		Level::updatePlayer();
		Level::updateObjects();
		Level::cleanupObjects();
		Level::render();
		std::this_thread::sleep_for(std::chrono::milliseconds(25));
	}
}

void			Level::_addBorder()
{
	attron(COLOR_PAIR(2));
	mvprintw(0, 0, "%*c", Level::getWidth() + 2 * BORDER_W, ' ');
	mvprintw(Level::getHeight() + BORDER_H, 0, "%*c", 
			Level::getWidth() + 2 * BORDER_W, ' ');
	for (int i = 1; i < Level::getHeight() + BORDER_H; ++i)
	{
		mvprintw(i, 0, "  ");
		mvprintw(i, Level::getWidth() + BORDER_W, "  ");
	}
	attron(COLOR_PAIR(1));
}

void	Level::_win_resize(void)
{
	static int	h_prev;
	static int	w_prev;
	int			h;
	int			w;

	getmaxyx(stdscr, h, w);
	if (h != h_prev || w != w_prev)
	{
		h_prev = h;
		w_prev = w;
		clear();
		_addBorder();
	}
}

void	Level::_startScreen(void)
{
	int		offset;
	int		i;

	i = Level::getHeight() / 3;
	offset = (Level::getWidth() - 41) / 2;
	clear();
	attron(COLOR_PAIR(1));
	mvprintw(i    , offset, "    ______                  __          ");
	mvprintw(i + 1, offset, "   / __/ /_      ________  / /__________");
	mvprintw(i + 2, offset, "  / /_/ __/     / ___/ _ \\/ __/ ___/ __ \\");
	mvprintw(i + 3, offset, " / __/ /_      / /  /  __/ /_/ /  / /_/ /");
	mvprintw(i + 4, offset, "/_/  \\__/_____/_/   \\___/\\__/_/   \\____/");
	mvprintw(i + 5, offset, "       /______/                          ");
	mvprintw(Level::getHeight() / 2, (Level::getWidth() - 23) / 2, "Press Any Key to Begin!");
	refresh();
	getch();
}

void	Level::_endScreen(void)
{
	int		offset;
	int		i;

	nodelay(stdscr, false);
	i = Level::getHeight() / 3;
	offset = (Level::getWidth() - 53) / 2;
	clear();
	attron(COLOR_PAIR(1));
	mvprintw(i    , offset, "  _____                         ____                 ");
	mvprintw(i + 1, offset, " / ____|                       / __ \\                ");
	mvprintw(i + 2, offset, "| |  __  __ _ _ __ ___   ___  | |  | |_   _____ _ __");
	mvprintw(i + 3, offset, "| | |_ |/ _` | '_ ` _ \\ / _ \\ | |  | \\ \\ / / _ \\ '__|");
	mvprintw(i + 4, offset, "| |__| | (_| | | | | | |  __/ | |__| |\\ V /  __/ |  ");
	mvprintw(i + 5, offset, " \\_____|\\__,_|_| |_| |_|\\___|  \\____/  \\_/ \\___|_|  ");
	mvprintw(i + 10, (Level::getWidth() - 11) / 2, "Score: %i", Level::getPlayer()->getScore());
	refresh();
	std::this_thread::sleep_for(std::chrono::milliseconds(3000));
	getch();
}

void	Level::_setHighscore()
{
	std::ifstream	file("HIGHSCORE.txt");

	if (0 == file)
	{
		Level::_highscore = 0;
		return ;
	}
	file >> Level::_highscore;
	file.close();
}

void	Level::_saveHighscore()
{
	std::ofstream	file("HIGHSCORE.txt");

	if (Level::getPlayer()->getScore() > Level::_highscore)
		file << Level::getPlayer()->getScore();

	file.close();
}