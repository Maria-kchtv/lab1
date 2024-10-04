#ifndef DICE_H
#define DICE_H

#include <random>

class Dice {
public:
    Dice(unsigned max, unsigned seed);
    unsigned roll();

private:
    unsigned max;
    std::uniform_int_distribution<unsigned> dstr;
    std::default_random_engine reng;
};

#endif // DICE_H