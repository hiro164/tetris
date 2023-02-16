#define MINO_WIDTH 4
#define MINO_HEIGHT 4

enum {
    MINO_ANGLE_0,
    MINO_ANGLE_90,
    MINO_ANGLE_180,
    MINO_ANGLE_270,
    MINO_ANGLE_MAX
};

struct Mino {
    char mino_shapes_[MINO_ANGLE_MAX][MINO_WIDTH][MINO_HEIGHT];
};