#include "tetris.hpp"
#include "conio.h"

Tetris::Tetris()
    : time_(time(NULL)),
      mino_x_(0),
      mino_y_(0),
      mino_type_(0),
      mino_angle_(0) {
    init_();
    set_field_();
    set_mino_();
    spawn_mino_();
}

void Tetris::init_() {
    for (int i = 0; i < FIELD_HEIGHT; i++) {
        for (int j = 0; j < FIELD_WIDTH; j++) {
            field_[i][j] = 0;
            buffer_[i][j] = 0;
        }
    }
}

void Tetris::set_field_() {
    for (int i = 0; i < FIELD_HEIGHT; i++) {
        field_[i][0] = 1;
        field_[i][FIELD_WIDTH - 1] = 1;
    }

    for (int i = 0; i < FIELD_WIDTH; i++) {
        field_[FIELD_HEIGHT - 1][i] = 1;
    }
}

void Tetris::set_mino_() {
    mino_[MINO_TYPE_I] = {{// MINO_ANGLE_0
                           {0, 1, 0, 0,
                            0, 1, 0, 0,
                            0, 1, 0, 0,
                            0, 1, 0, 0},
                           // MINO_ANGLE_90
                           {0, 0, 0, 0,
                            0, 0, 0, 0,
                            1, 1, 1, 1,
                            0, 0, 0, 0},
                           // MINO_ANGLE_180
                           {0, 0, 1, 0,
                            0, 0, 1, 0,
                            0, 0, 1, 0,
                            0, 0, 1, 0},
                           // MINO_ANGLE_270
                           {0, 0, 0, 0,
                            1, 1, 1, 1,
                            0, 0, 0, 0,
                            0, 0, 0, 0}}};
    mino_[MINO_TYPE_O] = {{// MINO_ANGLE_0
                           {0, 0, 0, 0,
                            0, 1, 1, 0,
                            0, 1, 1, 0,
                            0, 0, 0, 0},
                           // MINO_ANGLE_90
                           {0, 0, 0, 0,
                            0, 1, 1, 0,
                            0, 1, 1, 0,
                            0, 0, 0, 0},
                           // MINO_ANGLE_180
                           {0, 0, 0, 0,
                            0, 1, 1, 0,
                            0, 1, 1, 0,
                            0, 0, 0, 0},
                           // MINO_ANGLE_270
                           {0, 0, 0, 0,
                            0, 1, 1, 0,
                            0, 1, 1, 0,
                            0, 0, 0, 0}}};
    mino_[MINO_TYPE_S] = {{// MINO_ANGLE_0
                           {0, 0, 0, 0,
                            0, 1, 1, 0,
                            1, 1, 0, 0,
                            0, 0, 0, 0},
                           // MINO_ANGLE_90
                           {0, 1, 0, 0,
                            0, 1, 1, 0,
                            0, 0, 1, 0,
                            0, 0, 0, 0},
                           // MINO_ANGLE_180
                           {0, 0, 0, 0,
                            0, 1, 1, 0,
                            1, 1, 0, 0,
                            0, 0, 0, 0},
                           // MINO_ANGLE_270
                           {0, 0, 0, 0,
                            0, 1, 0, 0,
                            0, 1, 1, 0,
                            0, 0, 1, 0}}};
    mino_[MINO_TYPE_Z] = {{// MINO_ANGLE_0
                           {0, 0, 0, 0,
                            1, 1, 0, 0,
                            0, 1, 1, 0,
                            0, 0, 0, 0},
                           // MINO_ANGLE_90
                           {0, 0, 0, 0,
                            0, 0, 1, 0,
                            0, 1, 1, 0,
                            0, 1, 0, 0},
                           // MINO_ANGLE_180
                           {0, 0, 0, 0,
                            0, 1, 1, 0,
                            0, 0, 1, 1,
                            0, 0, 0, 0},
                           // MINO_ANGLE_270
                           {0, 0, 1, 0,
                            0, 1, 1, 0,
                            0, 1, 0, 0,
                            0, 0, 0, 0}}};
    mino_[MINO_TYPE_J] = {{// MINO_ANGLE_0
                           {0, 0, 1, 0,
                            0, 0, 1, 0,
                            0, 1, 1, 0,
                            0, 0, 0, 0},
                           // MINO_ANGLE_90
                           {0, 0, 0, 0,
                            1, 1, 1, 0,
                            0, 0, 1, 0,
                            0, 0, 0, 0},
                           // MINO_ANGLE_180
                           {0, 0, 0, 0,
                            0, 1, 1, 0,
                            0, 1, 0, 0,
                            0, 1, 0, 0},
                           // MINO_ANGLE_270
                           {0, 0, 0, 0,
                            0, 1, 0, 0,
                            0, 1, 1, 1,
                            0, 0, 0, 0}}};
    mino_[MINO_TYPE_L] = {{// MINO_ANGLE_0
                           {0, 1, 0, 0,
                            0, 1, 0, 0,
                            0, 1, 1, 0,
                            0, 0, 0, 0},
                           // MINO_ANGLE_90
                           {0, 0, 0, 0,
                            0, 0, 1, 0,
                            1, 1, 1, 0,
                            0, 0, 0, 0},
                           // MINO_ANGLE_180
                           {0, 0, 0, 0,
                            0, 1, 1, 0,
                            0, 0, 1, 0,
                            0, 0, 1, 0},
                           // MINO_ANGLE_270
                           {0, 0, 0, 0,
                            0, 1, 1, 1,
                            0, 1, 0, 0,
                            0, 0, 0, 0}}};
    mino_[MINO_TYPE_T] = {{// MINO_ANGLE_0
                           {0, 0, 0, 0,
                            1, 1, 1, 0,
                            0, 1, 0, 0,
                            0, 0, 0, 0},
                           // MINO_ANGLE_90
                           {0, 0, 0, 0,
                            0, 1, 0, 0,
                            0, 1, 1, 0,
                            0, 1, 0, 0},
                           // MINO_ANGLE_180
                           {0, 0, 0, 0,
                            0, 0, 1, 0,
                            0, 1, 1, 1,
                            0, 0, 0, 0},
                           // MINO_ANGLE_270
                           {0, 0, 1, 0,
                            0, 1, 1, 0,
                            0, 0, 1, 0,
                            0, 0, 0, 0}}};
}

void Tetris::spawn_mino_() {
    mino_x_ = 5;
    mino_y_ = 0;
    mino_type_ = rand() % MINO_TYPE_MAX;
    mino_angle_ = rand() % MINO_ANGLE_MAX;
}

bool Tetris::check_hit_(int argMinoX, int argMinoY, int argMinoType, int argMinoAngle) {
    for (int i = 0; i < MINO_HEIGHT; i++) {
        for (int j = 0; j < MINO_WIDTH; j++) {
            if (mino_[argMinoType].mino_shapes[argMinoAngle][i][j] && field_[argMinoY + i][argMinoX + j]) {
                return true;
            }
        }
    }
    return false;
}

void Tetris::check_keyboard() {
    if (kbhit()) {
        switch (getch()) {
        case 's':
            if (!check_hit_(mino_x_, mino_y_ + 1, mino_type_, mino_angle_)) {
                ++mino_y_;
            }
            break;
        case 'a':
            if (!check_hit_(mino_x_ - 1, mino_y_, mino_type_, mino_angle_)) {
                --mino_x_;
            }
            break;
        case 'd':
            if (!check_hit_(mino_x_ + 1, mino_y_, mino_type_, mino_angle_)) {
                ++mino_x_;
            }
            break;
        case 'w':
            if (!check_hit_(mino_x_, mino_y_, mino_type_, (mino_angle_ + 1) % MINO_ANGLE_MAX)) {
                mino_angle_ = (mino_angle_ + 1) % MINO_ANGLE_MAX;
            }
            break;
        }
        display_();
    }
}

void Tetris::display_() {
    memcpy(buffer_, field_, sizeof(field_));

    for (int i = 0; i < MINO_HEIGHT; i++) {
        for (int j = 0; j < MINO_WIDTH; j++) {
            buffer_[mino_y_ + i][mino_x_ + j] |= mino_[mino_type_].mino_shapes[mino_angle_][i][j];
        }
    }

    system("clear");

    for (int i = 0; i < FIELD_HEIGHT; i++) {
        for (int j = 0; j < FIELD_WIDTH; j++) {
            if (1 == buffer_[i][j]) {
                std::cout << " ■";
            } else {
                std::cout << "　";
            }
        }
        std::cout << std::endl;
    }
}

void Tetris::check_erase() {
    if (time(NULL) != time_) {
        time_ = time(NULL);

        if (check_hit_(mino_x_, mino_y_ + 1, mino_type_, mino_angle_)) {
            for (int i = 0; i < MINO_HEIGHT; i++) {
                for (int j = 0; j < MINO_WIDTH; j++) {
                    field_[mino_y_ + i][mino_x_ + j] |= mino_[mino_type_].mino_shapes[mino_angle_][i][j];
                }
            }

            for (int i = 0; i < FIELD_HEIGHT - 1; ++i) {
                bool isLineFilled = true;
                for (int j = 1; j < FIELD_WIDTH - 1; ++j) {
                    if (1 != field_[i][j]) {
                        isLineFilled = false;
                    }
                }

                if (true == isLineFilled) {
                    for (int j = i; j > 0; --j) {
                        memcpy(field_[j], field_[j - 1], FIELD_WIDTH);
                    }
                }
            }
            spawn_mino_();
        } else {
            mino_y_++;
        }
        display_();
    }
}