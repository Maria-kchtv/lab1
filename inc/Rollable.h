#ifndef ROLLABLE_H
#define ROLLABLE_H

#include "ThreeDicePool.h"

// Новый класс Rollable
class Rollable {
public:
    // Конструктор принимает объект ThreeDicePool
    Rollable(ThreeDicePool& pool);

    // Метод roll(), который использует ThreeDicePool для получения результата
    unsigned roll();

private:
    ThreeDicePool& pool;  // Ссылка на объект ThreeDicePool
};

#endif // ROLLABLE_H