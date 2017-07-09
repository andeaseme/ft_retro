
#include "Level.h"
#include <signal.h>

void
termination_handler (int signum)
{
	endwin();
	std::cout << "Segmentation Fault I mean piuuuuu piuuuuu..." << std::endl;
	std::exit(1);
}

int				main()
{
	struct sigaction action;

	action.sa_handler = termination_handler;
	sigaction(SIGSEGV, &action, NULL);
	std::srand(std::time(NULL));
	Level::init();
	Level::loop();
	endwin();
}
