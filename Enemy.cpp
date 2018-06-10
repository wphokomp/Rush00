#include "Enemy.hpp"

Enemy::Enemy(WINDOW * win, char ch) : Entity(win, 0, 0, ch) {
    LocX = (rand() % xMax - 2) + 2;
    LocY = yMax / 2;
}

Enemy::~Enemy() {

}

Enemy   &Enemy::operator=(Enemy const & enemy) {
    LocX = enemy.getX();
    LocY = enemy.getY();
    xMax = enemy.getXMax();
    yMax = enemy.getYMax();
    character = enemy.getCharater();
    currentWindow = enemy.getCurrentWindow();
    return *this;
}

void    Enemy::display() {
    mvwaddch(currentWindow, LocY, LocX, character);
    LocY++;
}

void    Enemy::updatePos() {
    mvwaddch(currentWindow, LocY - 1, getX(), ' ');
    // if (LocY >= yMax) {
    //     return (1);
    // }
    // return (0);
}