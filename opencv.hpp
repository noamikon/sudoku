#ifndef OPENCV_HPP
#define OPENCV_HPP

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <string>
#include <vector>

using namespace cv;

void FillSudokuWithZeros(std::string srcPath, std::string dstPath);
/* 
    Description: detect squares within a provided sudoku puzzle image,
    write "0" into the empty squares, and save it to a new file.

    Arguments:
    - srcPath: A string representing the file path of the source image.
    - dstPath: A string representing the file path to save the processed image.

    Returns: None.
 */

#endif // OPENCV_HPP