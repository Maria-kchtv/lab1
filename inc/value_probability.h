#ifndef VALUE_PROBABILITY_H
#define VALUE_PROBABILITY_H

// Шаблонная функция для вычисления вероятности попадания в определённое значение
template <typename T>
double value_probability(unsigned value, T& dice, unsigned number_of_rolls = 10000) {
    unsigned count = 0;
    for (unsigned i = 0; i < number_of_rolls; ++i) {
        if (dice.roll() == value) {
            ++count;
        }
    }
    return static_cast<double>(count) / static_cast<double>(number_of_rolls);
}

#endif // VALUE_PROBABILITY_H