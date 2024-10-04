#include "DoubleDice.h"

// Конструктор класса DoubleDice, который инициализирует базовые классы PenaltyDice и BonusDice
DoubleDice::DoubleDice(Dice& dice)
    : PenaltyDice(dice), BonusDice(dice) {}

// Метод roll, который возвращает среднее между PenaltyDice::roll() и BonusDice::roll()
unsigned DoubleDice::roll() {
    return (PenaltyDice::roll() + BonusDice::roll()) / 2;
}

// Метод для вычисления математического ожидания (average) на основе количества бросков
double DoubleDice::expected_value(unsigned number_of_rolls) {
    unsigned long long sum = 0;
    for (unsigned i = 0; i < number_of_rolls; ++i) {
        sum += this->roll();
    }
    return static_cast<double>(sum) / number_of_rolls;
}