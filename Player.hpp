

#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "Entity.hpp"

class Player : public Entity {
    public:
        Player(WINDOW * win, int x, int y, char c);
        ~Player(void);
        Player(Player const & src);
        Player & operator=(Player const & src);
        void moveUp(void);
        void moveDown(void);
        void moveBackwards(void);
        int getPlayerInput(void);
};

#endif