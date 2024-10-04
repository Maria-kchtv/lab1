#include "Rollable.h"

// Конструктор класса Rollable
Rollable::Rollable(ThreeDicePool& pool) : pool(pool) { }

// Метод roll() использует метод roll() из ThreeDicePool
unsigned Rollable::roll() {
    return pool.roll();
}