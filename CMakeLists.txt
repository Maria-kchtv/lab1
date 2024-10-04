# Устанавливаем минимальную версию CMake
cmake_minimum_required(VERSION 3.10)

# Устанавливаем имя проекта
project(random_variable)

# Добавляем исполняемый файл и его исходные файлы
add_executable(random_variable
        src/main.cpp
        src/Dice.cpp
        src/ThreeDicePool.cpp
        inc/Rollable.h
        src/Rollable.cpp
        src/PenaltyDice.cpp
        inc/PenaltyDice.h
        src/BonusDice.cpp
        inc/BonusDice.h
        inc/value_probability.h
        src/DoubleDice.cpp
        inc/DoubleDice.h
)

# Указываем директорию с заголовочными файлами
target_include_directories(random_variable PUBLIC inc)