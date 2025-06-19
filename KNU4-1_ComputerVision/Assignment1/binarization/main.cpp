#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
    Mat image(imread("./cat.bmp", IMREAD_GRAYSCALE)), result_image;
    image.copyTo(result_image);

    for (int y = 0; y < image.rows; ++y) {
        for (int x = 0; x < image.cols; ++x) {
            int pixel = image.at<uchar>(y, x);
            result_image.at<uchar>(y, x) = (pixel < 128) ? 0 : 255;
        }
    }

    imshow("Original image", image);
    imshow("Result image", result_image);
    imwrite("cat_binarized.jpg", result_image);
    cv::waitKey(0);

    return 0;
}