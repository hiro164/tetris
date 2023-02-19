#include "mino.hpp"
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <time.h>

using namespace std;

#define FIELD_HEIGHT 22
#define FIELD_WIDTH 12

enum {
    MINO_TYPE_I,
    MINO_TYPE_O,
    MINO_TYPE_S,
    MINO_TYPE_Z,
    MINO_TYPE_J,
    MINO_TYPE_L,
    MINO_TYPE_T,
    MINO_TYPE_MAX
};

class Tetris {
private:
    Mino mino_[MINO_TYPE_MAX];
    char field_[FIELD_HEIGHT][FIELD_WIDTH];
    char buffer_[FIELD_HEIGHT][FIELD_WIDTH];
    time_t time_;
    int mino_x_;
    int mino_y_;
    int mino_type_;
    int mino_angle_;

    void init_();
    void set_field_();                                                              // フィールド初期化
    void set_mino_();                                                               // ミノ用意
    void spawn_mino_();                                                             // ミノをスポーン
    bool check_hit_(int argMinoX, int argMinoY, int argMinoType, int argMinoAngle); // 当たり判定
    void display_();                                                                // 表示

public:
    Tetris();
    void check_keyboard(); // もし、キーボードが操作されたらミノを動かす
    void check_erase();    // 消す判定
};