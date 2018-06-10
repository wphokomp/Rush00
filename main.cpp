
#include "Player.hpp"
#include "Enemy.hpp"
#include "Entity.hpp"
#include <cstdlib>
#include <unistd.h>

int main() {
    WINDOW * space;

    initscr();
    noecho();
    cbreak();
	curs_set(0);

    srand(time(0));
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);
    space = newwin(yMax - 2, xMax, 0, 0);
    refresh();
    wrefresh(space);
    
    Player * p = new Player(space, yMax, xMax/2, '^');
    Enemy  * _enemy = new Enemy(space, '*');
    box(space,0,0);
    p->display();
    p->moveDown();
    int i = 0;
    while(true)
    {
        _enemy->updatePos();
        _enemy->display();
        refresh();
        wrefresh(space);
        p->display();
    }
    getch();
    endwin();
    
    return 0;
}