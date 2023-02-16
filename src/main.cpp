#include "tetris.hpp"

int main() {
    Tetris tetris;
    while (1) {
        tetris.check_keyboard();
        tetris.check_erase();
    }
    return 0;
}