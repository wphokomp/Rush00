#include "Entity.hpp"

Entity::Entity(WINDOW * win, int x, int y, char c) {
    currentWindow = win;
    LocX = x;
    LocX = y;
    getmaxyx(currentWindow, yMax, xMax);
    character = c;
}

Entity::~Entity() {
    
}

Entity::Entity(Entity const & src) {
    LocX = src.getX();
    LocY = src.getY();
    xMax = src.getXMax();
    yMax = src.getYMax();
    character = src.getCharater();
    currentWindow = src.getCurrentWindow();
}

Entity & Entity::operator = (Entity const & src){
    LocX = src.getX();
    LocY = src.getY();
    xMax = src.getXMax();
    yMax = src.getYMax();
    character = src.getCharater();
    currentWindow = src.getCurrentWindow();
    return *this;
}

bool Entity::comparePos(Entity const & src) const{
    if (LocY == src.getX() && LocY == src.getY())
        return true;
    else
        return false;
}

void Entity::display(void) const{
    mvwaddch(currentWindow, LocY, LocX, character);
}

int Entity::getX(void) const{
    return LocX;
}

int Entity::getY(void) const{
    return LocY;
}

int     Entity::getXMax(void) const{
    return xMax;
}

int     Entity::getYMax(void) const{
    return yMax;
}

char    Entity::getCharater(void) const{
    return character;
}

WINDOW *    Entity::getCurrentWindow(void) const{
    return currentWindow;
}

void    Entity::move(int xIncr, int yIncr){
    LocX += xIncr;
    LocY += yIncr;
}

void    Entity::moveForward(int xIncr) {
    mvwaddch(currentWindow, getY(), getX(), ' ');
    move(xIncr, 0);
    if (getX() < 1)
        LocX = 1;
}