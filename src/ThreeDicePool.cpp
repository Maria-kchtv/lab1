#include "ThreeDicePool.h"

// Инициализация трех кубиков через список инициализаторов
ThreeDicePool::ThreeDicePool(unsigned max, unsigned seed_1, unsigned seed_2, unsigned seed_3)
    : dice1(max, seed_1), dice2(max, seed_2), dice3(max, seed_3) { }

ThreeDicePool::ThreeDicePool(Dice d1, Dice d2, Dice d3)
    : dice1(d1), dice2(d2), dice3(d3) { }

// Метод броска всех трех кубиков и возвращение суммы
unsigned ThreeDicePool::roll() {
    return dice1.roll() + dice2.roll() + dice3.roll();
}