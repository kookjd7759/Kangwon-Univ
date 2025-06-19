#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void LPF(const Mat& image, Mat& result) {
    auto cal = [&](int y, int x) -> int {
        double ret(0);
        for (int yy = 0; yy < 3; ++yy) for (int xx = 0; xx < 3; ++xx)
            ret += (double)image.at<uchar>(y + yy,x + xx) * (1.0 / 9.0);
        return ret;
        };

    for (int y = 0; y < result.rows - 2; ++y) for (int x = 0; x < result.cols - 2; ++x) 
        result.at<uchar>(y, x) = cal(y, x);
}

int main() {
    Mat image(imread("./salt_pepper.bmp", IMREAD_GRAYSCALE)), result_image;
    result_image.create(Size(image.cols - 2, image.rows - 2), CV_8UC1);

    LPF(image, result_image);

    imshow("Original image", image);
    imshow("Result image", result_image);
    imwrite("salt_pepper_lpf.bmp", result_image);
    waitKey(0);

    return 0;
}