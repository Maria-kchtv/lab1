#ifndef BONUSDICE_H
#define BONUSDICE_H

#include "Dice.h"

// Класс BonusDice для работы с преимуществом
class BonusDice {
public:
    // Конструктор принимает объект Dice
    BonusDice(Dice& dice);

    // Метод roll возвращает наибольший результат из двух бросков
    unsigned roll();

private:
    Dice& dice;  // Ссылка на объект Dice
};

#endif // BONUSDICE_H