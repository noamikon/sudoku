#include <iostream>

#include "opencv.hpp"

int main()
{
    std::string srcPath = "./uploads/BWSudoku.png";
    std::string dstPath = "./uploads/BWSudokuwithZeros.png";

    FillSudokuWithZeros(srcPath, dstPath);

    std::cout << "Sudoku processed and saved to " << dstPath << std::endl;

    return 0;
}