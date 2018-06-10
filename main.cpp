
#include "Player.hpp"

int main() {
    WINDOW * space;
    
    initscr();
    noecho();
    cbreak();
	curs_set(0);

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);
    space = newwin(yMax, xMax, 0, 0);
    refresh();
    wrefresh(space);

    
    Player * p = new Player(space, 5, 10, '8');
    
    while(p->getPlayerInput() != 'q')
    {
		box(space,0,0);
        p->display();  
        wrefresh(space);
    }
    getch();
    endwin();
    
    return 0;
}