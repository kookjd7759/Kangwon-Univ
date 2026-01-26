#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int filter[3][3]{
    -1, -1, -1,
    -1, 8, -1,
    -1, -1, -1
};

void HPF(const Mat& image, Mat& result) {
    auto cal = [&](int y, int x) -> int {
        double ret(0);
        for (int yy = 0; yy < 3; ++yy) for (int xx = 0; xx < 3; ++xx)
            ret += (double)image.at<uchar>(y + yy, x + xx) * filter[xx][yy];
        return ret;
        };

    for (int y = 0; y < result.rows - 2; ++y) for (int x = 0; x < result.cols - 2; ++x)
        result.at<uchar>(y, x) = saturate_cast<uchar>(cal(y, x));
}

int main() {
    Mat image(imread("./tibetfox.bmp", IMREAD_GRAYSCALE)), result_image;
    result_image.create(Size(image.cols - 2, image.rows - 2), CV_8UC1);

    HPF(image, result_image);

    for (int yy = 0; yy < 3; ++yy) for (int xx = 0; xx < 3; ++xx)
        cout << filter[yy][xx] << ' ';


    imshow("Original image", image);
    imshow("Result image", result_image);
    imwrite("tibetfox _hpf.bmp", result_image);
    waitKey(0);

    return 0;
}