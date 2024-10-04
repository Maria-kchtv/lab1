#include "PenaltyDice.h"

// Конструктор
PenaltyDice::PenaltyDice(Dice& dice) : dice(dice) {}

// Метод roll, который возвращает наименьший из двух бросков
unsigned PenaltyDice::roll() {
    unsigned roll1 = dice.roll();
    unsigned roll2 = dice.roll();
    return (roll1 < roll2) ? roll1 : roll2;
}