#include "Player.hpp"
#include <cstdlib>

Player::Player(WINDOW * win, int x, int y, char c) : Entity(win, x, y, c){
}

Player::~Player(void) {
}

Player::Player(Player const & src) : Entity(src){
}

Player & Player::operator=(Player const & src){
    LocX = src.getX();
    LocY = src.getY();
    xMax = src.getXMax();
    yMax = src.getYMax();
    character = src.getCharater();
    currentWindow = src.getCurrentWindow();
    keypad(currentWindow, true);
    return *this;
}

void Player::moveUp(void) {
    mvwaddch(currentWindow, getY(), getX(), ' ');
    move(0, -SPEED);
    if (getY() < 1)
        LocY = 1;
}

void Player::moveDown(void) {
    mvwaddch(currentWindow, getY(), getX(), ' ');
    move(0, SPEED);
    if (getY() > yMax - 2)
        LocY = yMax - 2;
}

void Player::moveBackwards(void) {
    mvwaddch(currentWindow, getY(), getX(), ' ');
    move(SPEED, 0);
    if (getX() > xMax - 2)
        LocX = xMax - 2;
}

int Player::getPlayerInput(void) {
    int input = wgetch(currentWindow);
    switch(input)
    {
        case 65: // KEY_UP
            moveUp();
            break;
        case 66: // KEY_DOWN
            moveDown();
            break;
        case 67: //KEY_LEFT
            moveBackwards();
            break;
        case 68: // KEY_RIGHT
            moveForward(-SPEED);
            break;
        default:
            break;
    }
    return input;
}