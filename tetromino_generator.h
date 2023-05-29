#ifndef TETRO_GEN
#define TETRO_GEN

#include <iostream>
#include <vector>
#include <random>

enum TetrominoTypes {
    I, O, T, S, Z, J, L
};

class TetrominoGenerator {
    private:
        std::vector<int> chances;
        int tetrosCount;
        int X;
        int startChance;

    public:
        TetrominoGenerator(int chance, int x) {
            X = x;
            startChance = chance;
            for (int i = 0; i <= TetrominoTypes::L; i++)
                chances.push_back(chance);
        }

        TetrominoTypes GenerateNewTetro() {
            std::random_device rd;
            std::mt19937 generator(rd());
            std::uniform_int_distribution<int> distribution(1, startChance * (TetrominoTypes::L + 1));
            int random = distribution(generator);

            for (int i = 0; i <= TetrominoTypes::L; i++) {
                int sum = 0;
                for (int j = 0; j <= i; j++)
                    sum += chances[j];
                if (sum >= random) {
                    for (int w = 0; w <= TetrominoTypes::L; w++) {
                        if (w == i)
                            chances[w] -= TetrominoTypes::L * X;
                        else
                            chances[w] += X;
                    }
                    return (TetrominoTypes)i;
                }
            }
        }

        void PrintStats() {
            std::cerr << "#####################" << std::endl;
            std::cerr << "I: " << chances[0] << std::endl;
            std::cerr << "O: " << chances[1] << std::endl;
            std::cerr << "T: " << chances[2] << std::endl;
            std::cerr << "S: " << chances[3] << std::endl;
            std::cerr << "Z: " << chances[4] << std::endl;
            std::cerr << "J: " << chances[5] << std::endl;
            std::cerr << "L: " << chances[6] << std::endl;
            std::cerr << "#####################" << std::endl;
        }
};

#endif