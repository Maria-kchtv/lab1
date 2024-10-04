#include <iostream>
#include "Dice.h"
#include "Rollable.h"
#include "ThreeDicePool.h"
#include <iostream>
#include "DoubleDice.h"
#include <vector>
#include "PenaltyDice.h"
#include "BonusDice.h"
#include "value_probability.h"



template<typename T>
double expected_value(T& roller, unsigned number_of_rolls = 1) {
    auto accum = 0llu;
    for (unsigned cnt = 0; cnt != number_of_rolls; ++cnt) {
        accum += roller.roll();
    }
    return static_cast<double>(accum) / static_cast<double>(number_of_rolls);
}

int main() {

    //1
    Dice d(6, 1234);
    ThreeDicePool tdp(6, 123, 456, 789);

    std::cout << "Expected value for Dice: " << expected_value(d, 10000) << "\n";
    std::cout << "Expected value for ThreeDicePool: " << expected_value(tdp, 10000) << "\n";

    //1.3
    Dice dice1(6, 1234);  // Кубик с 6 гранями
    Dice dice2(6, 5678);  // Второй кубик с 6 гранями
    Dice dice3(6, 91011); // Третий кубик с 6 гранями

    ThreeDicePool threeDicePool(dice1, dice2, dice3);
    Rollable rollable(threeDicePool);
    std::cout << "Rollable result using ThreeDicePool: " << rollable.roll() << "\n";


    //2

    // Обычный кубик с диапазоном [1, 100]
    Dice dice(100, 38475);

    // Кубик со штрафом
    PenaltyDice penaltyDice(dice);

    // Кубик с преимуществом
    BonusDice bonusDice(dice);

    // Массивы для хранения вероятностей
    std::vector<double> normal_probabilities;
    std::vector<double> penalty_probabilities;
    std::vector<double> bonus_probabilities;

    // Вычисляем вероятность для каждого значения от 1 до 100
    for (unsigned value = 1; value <= 100; ++value) {
        normal_probabilities.push_back(value_probability(value, dice));
        penalty_probabilities.push_back(value_probability(value, penaltyDice));  // Используем penaltyDice для расчета вероятности
        bonus_probabilities.push_back(value_probability(value, bonusDice));  // Используем bonusDice для расчета вероятности
    }

    // Выводим вероятности для каждого значения
    for (unsigned value = 1; value <= 100; ++value) {
        std::cout << "Value: " << value
                  << " | Normal: " << normal_probabilities[value - 1]
                  << " | Penalty: " << penalty_probabilities[value - 1]
                  << " | Bonus: " << bonus_probabilities[value - 1] << std::endl;
    }

    //threedicepool
    std::vector<double> pool_probabilities;

    // Вычисляем вероятность для каждого значения от 3 до 18 (сумма трех кубиков)
    for (unsigned value = 3; value <= 18; ++value) {
        pool_probabilities.push_back(value_probability(value, threeDicePool));  // Вероятности для ThreeDicePool (сумма трех кубиков от 1 до 6)
    }
    std::cout << "\n\nPool result using ThreeDicePool:\n";

    // Выводим вероятности для каждого значения от 3 до 18 для ThreeDicePool и других кубиков
    for (unsigned value = 3; value <= 18; ++value) {
        std::cout << "Value: " << value
                  << " | ThreeDicePool: " << pool_probabilities[value - 3]
                  << std::endl;
    }

    std::cout << "\n\n";
    //3
    Dice dice_dd(100, 48675);

    // Создаем объект DoubleDice, который наследует PenaltyDice и BonusDice
    DoubleDice doubleDice(dice_dd);
    double expected = doubleDice.expected_value(10000);
    std::cout << "Expected value for DoubleDice: " << expected << std::endl;

    // Вычисляем математическое ожидание для DoubleDice
    std::vector<double> double_dice_probabilities;

    // Вычисляем вероятность для каждого значения от 1 до 100 для DoubleDice
    for (unsigned value = 1; value <= 100; ++value) {
        double_dice_probabilities.push_back(value_probability(value, doubleDice));
    }

    // Выводим вероятности для DoubleDice
    for (unsigned value = 1; value <= 100; ++value) {
        std::cout << "Value: " << value
                  << " | Double Dice Probability: " << double_dice_probabilities[value - 1]
                  << std::endl;
    }
    return 0;

}