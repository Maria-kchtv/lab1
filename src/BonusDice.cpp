#include "BonusDice.h"

// Конструктор
BonusDice::BonusDice(Dice& dice) : dice(dice) {}

// Метод roll, который возвращает наибольший из двух бросков
unsigned BonusDice::roll() {
    unsigned roll1 = dice.roll();
    unsigned roll2 = dice.roll();
    return (roll1 > roll2) ? roll1 : roll2;
}