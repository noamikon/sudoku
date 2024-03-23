#include <iostream>

#include "opencv.hpp"

int main()
{
    std::string srcPath = "../uploads/Sudoku2.png";
    std::string dstPath = "../uploads/Sudoku2withZeros.png";

    FillSudokuWithZeros(srcPath, dstPath);

    std::cout << "Sudoku processed and saved to " << dstPath << std::endl;

    return 0;
}