
#include "Level.h"
#include <signal.h>

void
termination_handler (int signum)
{
	endwin();
	std::exit(1);
}

int				main()
{
	struct sigaction action;

	action.sa_handler = termination_handler;
	sigaction(SIGSEGV, &action, NULL);
	Level::init();
	Level::loop();
	endwin();
}
