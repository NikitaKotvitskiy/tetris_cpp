#include <iostream>
#include <vector>
#include <string>
#include "tetromino_generator.h"

using namespace std;

int main()
{
    TetrominoGenerator gen(10, 1);
    for (int i = 0; i < 1000; i++)
        cout << gen.GenerateNewTetro() << endl;
    gen.PrintStats();
}