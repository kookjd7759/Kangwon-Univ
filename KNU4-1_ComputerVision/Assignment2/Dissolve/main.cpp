#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

Mat dissolve(const Mat& from, const Mat& to, const double& alpha) {
    Mat result;
    from.copyTo(result);

    for (int y = 0; y < result.rows; ++y) {
        for (int x = 0; x < result.cols; ++x) {
            int b = (alpha * result.at<Vec3b>(y, x)[0]) + ((1 - alpha) * to.at<Vec3b>(y, x)[0]);
            int g = (alpha * result.at<Vec3b>(y, x)[1]) + ((1 - alpha) * to.at<Vec3b>(y, x)[1]);
            int r = (alpha * result.at<Vec3b>(y, x)[2]) + ((1 - alpha) * to.at<Vec3b>(y, x)[2]);

            result.at<Vec3b>(y, x) = Vec3b(b, g, r);
        }
    }

    return result;
}

int main() {
    Mat from_image(imread("./cat.bmp", IMREAD_COLOR)),
        to_image(imread("./tibetfox.bmp", IMREAD_COLOR)),
        result03_image, result07_image;

    if (from_image.empty() || to_image.empty()) {
        cout << "image load failed\n";
        return 0;
    }

    /* realTime version
    for (int i = 10; i >= 0; --i) {
        double alpha = (double)i / 10.0;
        Mat result(dissolve(from_image, to_image, alpha));
        imshow("image", result);
        waitKey(500);
    }
    */

    double alpha03(0.3), alpha07(0.7);

    result03_image = dissolve(from_image, to_image, alpha03);
    result07_image = dissolve(from_image, to_image, alpha07);

    imshow("Original image", from_image);
    imshow("dissolve 0.3 image", result03_image);
    imshow("dissolve 0.7 image", result07_image);
    imwrite("dissolve_3.bmp", result03_image);
    imwrite("dissolve_7.bmp", result07_image);
    waitKey(0);
    
    return 0;
}