#include "LevelD.h"
#include "Utility.h"

#define LEVEL_WIDTH 11
#define LEVEL_HEIGHT 280

unsigned int LEVEL_3_DATA[] =
{
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 7, 0, 0, 0, 7, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 7, 0, 0, 0, 7, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 7, 0, 0, 0, 7, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 7, 0, 0, 0, 7, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 7, 0, 0, 0, 7, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 7, 0, 0, 0, 7, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 7, 0, 0, 0, 7, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 7, 0, 0, 0, 7, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 7, 0, 0, 0, 7, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 7, 0, 0, 0, 7, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 7, 0, 0, 0, 7, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 7, 0, 0, 0, 7, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 7, 0, 0, 0, 7, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 7, 0, 0, 0, 7, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 7, 0, 0, 0, 7, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 7, 0, 0, 0, 7, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 7, 0, 0, 0, 7, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 7, 0, 0, 0, 7, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 7, 0, 0, 0, 7, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 7, 0, 0, 0, 7, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 7, 0, 0, 0, 7, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 7, 0, 0, 0, 7, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 7, 0, 0, 0, 7, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 7, 0, 0, 0, 7, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 7, 0, 0, 0, 7, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 7, 0, 0, 0, 7, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 7, 0, 0, 0, 7, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 7, 0, 0, 0, 7, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 7, 0, 0, 0, 7, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 7, 0, 0, 0, 7, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 7, 0, 0, 0, 7, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 7, 0, 0, 0, 7, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 7, 0, 0, 0, 7, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 7, 0, 0, 0, 7, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 7, 0, 0, 0, 7, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 7, 0, 0, 0, 7, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 7, 0, 0, 0, 0, 0, 7, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 7, 0, 0, 0, 0, 0, 0, 0, 7, 3,
};
LevelD::~LevelD()
{
    delete[] m_state.enemies;
    delete    m_state.player;
    delete    m_state.map;
    Mix_FreeChunk(m_state.jump_sfx);
    Mix_FreeMusic(m_state.bgm);
}

void LevelD::initialise()
{
    GLuint map_texture_id = Utility::load_texture("assets/mini-spritesheet-thumbnail.png");
    m_state.map = new Map(LEVEL_WIDTH, LEVEL_HEIGHT, LEVEL_3_DATA, map_texture_id, 1.0f, 4, 4);
    // Code from main.cpp's initialise()
    /**
     George's Stuff
     */
     // Existing
    m_state.player = new Entity();
    m_state.player->set_entity_type(PLAYER);
    m_state.player->set_position(glm::vec3(5.0f, 0.0f, 0.0f));
    m_state.player->set_velocity(glm::vec3(0.0f, -3.0f, 0.0f));
    m_state.player->set_movement(glm::vec3(0.0f, 0.0f, 0.0f));
    m_state.player->m_texture_id = Utility::load_texture("assets/player.png");
    m_state.player->set_height(1.0f);
    m_state.player->m_walking[m_state.player->LEFT] = new int[6] { 0, 1, 2, 3, 4, 5 };
    m_state.player->m_walking[m_state.player->RIGHT] = new int[6] { 6, 7, 8, 9, 10, 11};
    m_state.player->m_walking[m_state.player->UP] = new int[6] { 12, 13, 14, 15, 16, 17 };
    m_state.player->m_walking[m_state.player->DOWN] = new int[6] { 18, 19, 20, 21, 22, 23 };

    m_state.player->m_animation_indices = m_state.player->m_walking[m_state.player->RIGHT];  // start George looking left
    m_state.player->m_animation_frames = 6;
    m_state.player->m_animation_index = 0;
    m_state.player->m_animation_time = 0.0f;
    m_state.player->m_animation_cols = 6;
    m_state.player->m_animation_rows = 10;
    /**
     Enemies' stuff */
    std::srand(std::time(0));
    GLuint enemy_texture_id = Utility::load_texture("assets/testkeyboard.png");
    glm::vec3 new_note_position = glm::vec3(5.0f, -1.5f, 0.0f);
    m_state.enemies = new Entity[ENEMY_COUNT];
    for (int i = 0; i < ENEMY_COUNT; i++) {
        m_state.enemies[i].set_entity_type(ENEMY);
        m_state.enemies[i].set_ai_type(NOTE); // set to Note
        m_state.enemies[i].set_ai_state(IDLE);
        m_state.enemies[i].m_texture_id = enemy_texture_id;
        m_state.enemies[i].set_height(0.6f);
        m_state.enemies[i].set_width(0.6f);
        m_state.enemies[i].set_position(new_note_position);
        m_state.enemies[i].m_walking[m_state.enemies[i].LEFT] = new int[1] {59};
        m_state.enemies[i].m_walking[m_state.enemies[i].RIGHT] = new int[1] {29};
        m_state.enemies[i].m_walking[m_state.enemies[i].UP] = new int[1] {14};
        m_state.enemies[i].m_walking[m_state.enemies[i].DOWN] = new int[1] {44};
        int random_num = std::rand() % 4;
        if (random_num == 0) {
            m_state.enemies[i].m_animation_indices = m_state.enemies[i].m_walking[m_state.enemies[i].LEFT];  // start George looking left
            m_state.enemies[i].setDirection("Left");
        }
        else if (random_num == 1) {
            m_state.enemies[i].m_animation_indices = m_state.enemies[i].m_walking[m_state.enemies[i].RIGHT];  // start George looking left
            m_state.enemies[i].setDirection("Right");
        }
        else if (random_num == 2) {
            m_state.enemies[i].m_animation_indices = m_state.enemies[i].m_walking[m_state.enemies[i].UP];  // start George looking left
            m_state.enemies[i].setDirection("Up");
        }
        else if (random_num == 3) {
            m_state.enemies[i].m_animation_indices = m_state.enemies[i].m_walking[m_state.enemies[i].DOWN];  // start George looking left
            m_state.enemies[i].setDirection("Down");
        }
        m_state.enemies[i].m_animation_frames = 1;
        m_state.enemies[i].m_animation_index = 0;
        m_state.enemies[i].m_animation_time = 0.0f;
        m_state.enemies[i].m_animation_cols = 15;
        m_state.enemies[i].m_animation_rows = 5;
        new_note_position.y -= 1.5f;
    }
    /**
     BGM and SFX
     */
    Mix_OpenAudio(48000, MIX_DEFAULT_FORMAT, 2, 4096);

    m_state.bgm = Mix_LoadMUS("assets/hikarunarashort.wav");
    Mix_PlayMusic(m_state.bgm, -1);

    m_state.jump_sfx = Mix_LoadWAV("assets/bounce.wav");
    Mix_VolumeMusic(20);
    //Mix_VolumeChunk(m_state.jump_sfx, MIX_MAX_VOLUME / 2);
}

void LevelD::update(float delta_time)
{
    m_state.player->update(delta_time, m_state.player, m_state.enemies, ENEMY_COUNT, m_state.map);

    for (int i = 0; i < ENEMY_COUNT; i++)
    {

        m_state.enemies[i].update(delta_time, m_state.player, NULL, NULL, m_state.map);
    }
}


void LevelD::render(ShaderProgram* program)
{
    m_state.map->render(program);
    m_state.player->render(program);
    for (int i = 0; i < ENEMY_COUNT; i++) {
        m_state.enemies[i].render(program);
    }
}