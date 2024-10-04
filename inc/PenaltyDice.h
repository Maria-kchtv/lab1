#ifndef PENALTYDICE_H
#define PENALTYDICE_H

#include "Dice.h"

// Класс PenaltyDice для работы со штрафом
class PenaltyDice {
public:
    // Конструктор принимает объект Dice
    PenaltyDice(Dice& dice);

    // Метод roll возвращает наименьший результат из двух бросков
    unsigned roll();

private:
    Dice& dice;  // Ссылка на объект Dice
};

#endif // PENALTYDICE_H