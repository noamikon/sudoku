#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "opencv.hpp"

using namespace cv;

void OpenImage(std::string& path, Mat& img)
{
    img = imread(path);
}

void ShowImage(Mat& img)
{
    imshow("Image", img);
    waitKey(0);
}

void ConvertToGray(Mat& imgSrc, Mat& imgDst)
{
    cvtColor(imgSrc, imgDst, COLOR_BGR2GRAY);               // Convert to grayscale
}

void ConvertToBinary(Mat& imgSrc, Mat& imgDst)
{
    threshold(imgSrc, imgDst, 128, 255, THRESH_BINARY_INV | THRESH_OTSU);     // Convert to binary
}

void BlurImage(Mat& imgSrc, Mat& imgDst)
{
    GaussianBlur(imgSrc, imgDst, Size(3, 3), 3, 0);         // Blur the image
}

void CannyImage(Mat& imgSrc, Mat& imgDst)
{
    Canny(imgSrc, imgDst, 50, 150);                         // Apply Canny edge detection
}

void DilateImage(Mat& imgSrc, Mat& imgDst, int kernelSize)
{
    Mat kernel = getStructuringElement(MORPH_RECT, Size(kernelSize, kernelSize));
    dilate(imgSrc, imgDst, kernel);                         // Dilate the image
}

void ResizeImage(Mat& imgSrc, Mat& imgDst, float scale)
{
    int width = imgSrc.size().width * scale;
    int height = imgSrc.size().height * scale;
    Size imgSize(width, height);
    resize(imgSrc, imgDst, imgSize);                        // Resize the image
}

void CropImage(Mat& imgSrc, Mat& imgDst, int x, int y, int width, int height)
{
    Rect roi(x, y, width, height);
    imgDst = imgSrc(roi);                                   // Crop the image
}

bool isSquareEmpty(Mat& square)
{
    Mat imgGray;
    Mat imgThresh;
    if (square.channels() == 1)
    {
        imgGray = square.clone();
    }
    else
    {
        cvtColor(square, imgGray, COLOR_BGR2GRAY); // Convert to grayscale
    }
    ConvertToBinary(imgGray, imgThresh);    // Convert to binary

    // Count non-zero pixels
    double nonZeroCount = countNonZero(imgThresh);
    // Define a threshold for what counts as "empty"
    double area = square.rows * square.cols;
    double emptyThreshold = area * 0.08; // 10% of the area, adjust as needed

    return area - nonZeroCount < emptyThreshold;
}


bool SortContours(const std::vector<Point>& contour1, const std::vector<Point>& contour2)
{
    Rect bbox1 = boundingRect(contour1);
    Rect bbox2 = boundingRect(contour2);
    // Sort by row first, and by column if the row is the same
    return (bbox1.y < bbox2.y) || (bbox1.y == bbox2.y && bbox1.x < bbox2.x);
}

void GetContours(Mat& imgSrc, Mat& imgDst)
{
    std::vector<std::vector<Point>> contours;
    std::vector<Vec4i> hierarchy;
    findContours(imgSrc, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);
    
    double maxArea = contourArea(contours[0]);
    double singleSquareSize = maxArea / 81;

    std::vector<std::vector<Point>> sortedContours;

    for (int i = 0; i < contours.size(); ++i)
    {
        double area = contourArea(contours[i]);
        if (area > (singleSquareSize / 2) && area < (singleSquareSize * 2))
        {
            sortedContours.push_back(contours[i]);
        }
    }

    std::sort(sortedContours.begin(), sortedContours.end(), SortContours);

    for (int i = 0; i < sortedContours.size(); ++i)
    {
        // drawContours(imgDst, sortedContours, i, Scalar(255, 0, 255), 2);
        Rect bbox = boundingRect(sortedContours[i]);
        Mat square = imgSrc(bbox);
        if (isSquareEmpty(square))
        {
            // Point center = Point(bbox.x + bbox.width / 2, bbox.y + bbox.height / 2);
            Point textOrg((bbox.x + bbox.width / 2), (bbox.y + bbox.height / 2));
            // drawContours(imgDst, sortedContours, i, Scalar(255, 0, 255), 2);
            String text = "0";
            int FontFace = FONT_HERSHEY_SIMPLEX;
            double fontScale = bbox.width / 33.0;
            int thickness = 3;
            int baseline = 0;
            Size textSize = getTextSize(text, FontFace, fontScale, thickness, &baseline);
            // Point textOrg = center - Point(textSize.width / 2, textSize.height / 2);

            textOrg.x = textOrg.x - textSize.width / 2;
            textOrg.y = textOrg.y + textSize.height / 2;

            putText(imgDst, text, textOrg, FontFace, fontScale, Scalar(0, 0, 0), thickness);
        }
        // ShowImage(imgDst);
    }
}

void SaveImage(std::string path, Mat& imgSrc)
{
    bool success = imwrite(path, imgSrc);

    if (success)
    {
        std::cout << "Image saved successfully." << std::endl;
    } else
    {
        std::cout << "Error: Could not save the image." << std::endl;
    }
}

void FillSudokuWithZeros(std::string srcPath, std::string dstPath)
{
    Mat img = imread(srcPath);
    Mat imgGray;
    Mat imgBlur;
    Mat imgCanny;
    Mat imgDilate;

    ConvertToGray(img, imgGray);
    BlurImage(imgGray, imgBlur);
    CannyImage(imgGray, imgCanny);
    DilateImage(imgCanny, imgDilate, 2);
    GetContours(imgDilate, img);

    SaveImage(dstPath, img);
}



void OpenVideo(std::string path)
{
    VideoCapture cap(path);
    Mat img;

    while (true)
    {
        cap.read(img);
        imshow("Image", img);
        waitKey(1);
    }
}

