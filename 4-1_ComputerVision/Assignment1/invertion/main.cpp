#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int rev(int n) {
	return (255 - n);
}

int main(void) {
	Mat image(imread("./cat.bmp", IMREAD_UNCHANGED)), result_image;
	image.copyTo(result_image);

	for (int y = 0; y < image.rows; ++y) {
		for (int x = 0; x < image.cols; ++x) {
			int b(image.at<Vec3b>(y, x)[0]);
			int g(image.at<Vec3b>(y, x)[1]);
			int r(image.at<Vec3b>(y, x)[2]);

			b = rev(b);
			g = rev(g);
			r = rev(r);

			result_image.at<Vec3b>(y, x)[0] = saturate_cast<uchar>(b);
			result_image.at<Vec3b>(y, x)[1] = saturate_cast<uchar>(g);
			result_image.at<Vec3b>(y, x)[2] = saturate_cast<uchar>(r);
		}
	}

	imshow("Original image", image);
	imshow("Result image", result_image);
	imwrite("cat_inverted.jpg", result_image);

	waitKey();
	return 0;
}