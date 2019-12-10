#ifndef MINESWEEPER_H
#define MINESWEEPER_H
#include "mymath.h"

class Minesweeper : public MyMath
{
public:
    Minesweeper();
    string solve(string s);
};

#endif // MINESWEEPER_H
