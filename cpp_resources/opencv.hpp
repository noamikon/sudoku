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

void OpenImage(std::string& path, Mat& img);
/* 
    Description: Open an image from a file path and store it in a matrix (Mat).

    Arguments: 
    - path: A string representing the file path of the image.
    - img: A matrix (Mat) to store the image.

    Returns: None.
 */

void ShowImage(Mat& img);
/* 
    Description: Display an image.

    Arguments: 
    - img: A matrix (Mat) representing the image to be displayed.

    Returns: None.

 */

void ConvertToGray(Mat& imgSrc, Mat& imgDst);
/* 
    Description: Convert an image to grayscale.

    Arguments: 
    - imgSrc: A matrix (Mat) representing the source image.
    - imgDst: A matrix (Mat) to store the grayscale image.

    Returns: None.

 */

void ConvertToBinary(Mat& imgSrc, Mat& imgDst);
/* 
    Description: Convert an image to binary.

    Arguments: 
    - imgSrc: A matrix (Mat) representing the source image.
    - imgDst: A matrix (Mat) to store the binary image.

    Returns: None.

 */

void BlurImage(Mat& imgSrc, Mat& imgDst);
/*
    Description: Blur an image.

    Arguments:
    - imgSrc: A matrix (Mat) representing the source image.
    - imgDst: A matrix (Mat) to store the blurred image.

    Returns: None.
*/

void CannyImage(Mat& imgSrc, Mat& imgDst);
/*
    Description: Apply Canny edge detection to an image.

    Arguments:
    - imgSrc: A matrix (Mat) representing the source image.
    - imgDst: A matrix (Mat) to store the edge-detected image.

    Returns: None.
*/

void DilateImage(Mat& imgSrc, Mat& imgDst, int kernelSize);
/*
    Description: Dilate an image.

    Arguments:
    - imgSrc: A matrix (Mat) representing the source image.
    - imgDst: A matrix (Mat) to store the dilated image.
    - kernelSize: An integer representing the size of the kernel.

    Returns: None.
*/

void ResizeImage(Mat& imgSrc, Mat& imgDst, float scale);
/*
    Description: Resize an image.

    Arguments:
    - imgSrc: A matrix (Mat) representing the source image.
    - imgDst: A matrix (Mat) to store the resized image.
    - scale: A float representing the scale factor.

    Returns: None.
*/

void CropImage(Mat& imgSrc, Mat& imgDst, int x, int y, int width, int height);
/*
    Description: Crop an image.

    Arguments:
    - imgSrc: A matrix (Mat) representing the source image.
    - imgDst: A matrix (Mat) to store the cropped image.
    - x: An integer representing the x-coordinate of the top-left corner of the crop region.
    - y: An integer representing the y-coordinate of the top-left corner of the crop region.
    - width: An integer representing the width of the crop region.
    - height: An integer representing the height of the crop region.

    Returns: None.
*/

bool isSquareEmpty(Mat& square);
/*
    Description: Check if a square region of an image is empty (i.e., contains no significant content).

    Arguments:
    - square: A matrix (Mat) representing the square region of the image.

    Returns: A boolean value indicating whether the square region is empty.
*/


bool SortContours(const std::vector<Point>& contour1, const std::vector<Point>& contour2);
/*
    Description: Sort contours based on their area.

    Arguments:
    - contour1: A vector of points representing the first contour.
    - contour2: A vector of points representing the second contour.

    Returns: A boolean value indicating whether the first contour has a larger area than the second contour.
*/

void GetContours(Mat& imgSrc, Mat& imgDst);
/*
    Description: detect squares within a provided sudoku puzzle image,
    write "0" into the empty squares, and save it to a new file.

    Arguments:
    - imgSrc: A matrix (Mat) representing the source image.
    - imgDst: A matrix (Mat) to store the processed image with zeros drawn on it.

    Returns: None.
*/

void SaveImage(std::string path, Mat& imgSrc);
/*
    Description: Save an image to a file.

    Arguments:
    - path: A string representing the file path to save the image.
    - imgSrc: A matrix (Mat) representing the source image.

    Returns: None.
*/



void OpenVideo(std::string path);
/* 
    Description: Open a video from a file path and display it.

    Arguments: 
    - path: A string representing the file path of the video.

    Returns: None.
 */


#endif // OPENCV_HPP