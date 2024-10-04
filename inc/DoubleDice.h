#ifndef DOUBLEDICE_H
#define DOUBLEDICE_H

#include "PenaltyDice.h"
#include "BonusDice.h"

// Класс DoubleDice, наследующий одновременно PenaltyDice и BonusDice
class DoubleDice : public PenaltyDice, public BonusDice {
public:
    // Конструктор принимает один объект Dice и передает его в оба базовых класса
    DoubleDice(Dice& dice);

    // Метод roll возвращает среднее между PenaltyDice::roll() и BonusDice::roll()
    unsigned roll();

    // Метод для вычисления математического ожидания (average) на основе количества бросков
    double expected_value(unsigned number_of_rolls = 10000);
};

#endif // DOUBLEDICE_H