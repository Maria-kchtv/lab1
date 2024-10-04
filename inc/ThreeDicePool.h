#ifndef THREEDICEPOOL_H
#define THREEDICEPOOL_H

#include "Dice.h"

class ThreeDicePool {
public:
    // Конструктор
    ThreeDicePool(unsigned max, unsigned seed_1, unsigned seed_2, unsigned seed_3);
    ThreeDicePool(Dice d1, Dice d2, Dice d3);

    // Метод для броска всех трех кубиков и возврата суммы
    unsigned roll();

private:
    Dice dice1, dice2, dice3;
};

#endif // THREEDICEPOOL_H