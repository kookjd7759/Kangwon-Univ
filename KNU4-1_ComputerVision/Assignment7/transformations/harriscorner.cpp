#include <algorithm>
#include "harriscorner.hpp"

transformations::HarrisCorner::HarrisCorner(cv::InputArray& original_image)
{
	cv::Mat src = original_image.getMat();
	confidence_map.create(src.size(), CV_32FC1);

	// 외곽 2개 픽셀의 Confidence는 0으로 가정
	for (int w = 0; w < src.cols; ++w)
	{
		confidence_map.at<float>(0, w) = 0.0;
		confidence_map.at<float>(1, w) = 0.0;
		confidence_map.at<float>(src.rows - 1, w) = 0.0;
		confidence_map.at<float>(src.rows - 2, w) = 0.0;
	}

	for (int h = 0; h < src.rows; ++h)
	{
		confidence_map.at<float>(h, 0) = 0.0;
		confidence_map.at<float>(h, 1) = 0.0;
		confidence_map.at<float>(h, src.cols - 1) = 0.0;
		confidence_map.at<float>(h, src.cols - 2) = 0.0;
	}
}


void transformations::HarrisCorner::FindConfidenceMap(cv::InputArray& original_image)
{
	cv::Mat src = original_image.getMat();

	/**
	 * src를 이용하여 해리스코너의  알고리즘의 Confidence를 계산한 뒤
	 * 이를 confidence_map에 저장하세요.
	 * (confidence_map은 클래스 멤버 변수로 선언되어 있습니다.)
	 * 가우시안 필터는 클래스의 멤버 변수 G로 선언되어 있습니다. 크기는 3x3입니다.
	 * 가장자리는 0으로 하시면 됩니다. 
	 * k값은 0.04로 하시면 됩니다. 
	 */
	 // ** 지금부터 코드를 작성하세요. 이 줄은 지우시면 안 됩니다 **

	src.convertTo(src, CV_32F);
	double my[3][3]{
		{-1.0, -2.0, -1.0 },
		{ 0.0,  0.0,  0.0 },
		{ 1.0,  2.0,  1.0 }};
	double mx[3][3] = {
		{-1.0, 0.0, 1.0 },
		{-2.0, 0.0, 2.0 },
		{-1.0, 0.0, 1.0 }};
	cv::Mat dx = cv::Mat::zeros(src.size(), CV_32F);
	cv::Mat dy = cv::Mat::zeros(src.size(), CV_32F);
	cv::Mat dxy = cv::Mat::zeros(src.size(), CV_32F);
	for (int y = 0; y < src.rows - 2; ++y)
		for (int x = 0; x < src.cols - 2; ++x) {
			double sumY(0.0), sumX(0.0);
			for (int yy = 0; yy < 3; ++yy) for (int xx = 0; xx < 3; ++xx)
				sumY += src.at<float>(y + yy, x + xx) * my[yy][xx],
				sumX += src.at<float>(y + yy, x + xx) * mx[yy][xx];

			dy.at<float>(y, x) = sumY;
			dx.at<float>(y, x) = sumX;
			dxy.at<float>(y, x) = sumX * sumY;
		}

	cv::Mat dx2 = dx.mul(dx);
	cv::Mat dy2 = dy.mul(dy);

	cv::Mat G_dx2 = cv::Mat::zeros(src.size(), CV_32F);
	cv::Mat G_dy2 = cv::Mat::zeros(src.size(), CV_32F);
	cv::Mat G_dxy = cv::Mat::zeros(src.size(), CV_32F);
	for (int y = 0; y < src.rows - 2; ++y)
		for (int x = 0; x < src.cols - 2; ++x) {
			double sumY(0.0), sumX(0.0), sumXY(0.0);
			for (int yy = 0; yy < 3; ++yy) for (int xx = 0; xx < 3; ++xx)
				sumY += dy2.at<float>(y + yy, x + xx) * G[yy][xx],
				sumX += dx2.at<float>(y + yy, x + xx) * G[yy][xx],
				sumXY += dxy.at<float>(y + yy, x + xx) * G[yy][xx];

			G_dy2.at<float>(y, x) = sumY;
			G_dx2.at<float>(y, x) = sumX;
			G_dxy.at<float>(y, x) = sumXY;
		}

	const float k(0.04);
	for (int y = 0; y < src.rows - 2; ++y) {
		for (int x = 0; x < src.cols - 2; ++x) {
			float p = G_dy2.at<float>(y, x);
			float q = G_dx2.at<float>(y, x);
			float r = G_dxy.at<float>(y, x);

			confidence_map.at<float>(y, x) = (p * q - r * r) - k * ((p + q) * (p + q));
		}
	}

	// ** 여기까지 코드를 작성하세요. 이 줄은 지우시면 안 됩니다 **
}




void transformations::HarrisCorner::DrawFeature(cv::OutputArray& result_image)
{
	cv::Mat dst = result_image.getMat();
	cv::Mat confidence_map_norm ;
	cv::normalize(confidence_map, confidence_map_norm, 0, 1, cv::NORM_MINMAX, CV_32FC1, cv::Mat());

	for (int h = 0; h < confidence_map_norm.rows; ++h)
	{
		for (int w = 0; w < confidence_map_norm.cols; ++w)
		{
			if (confidence_map_norm.at<float>(h, w) >= 0.3)
			{
				cv::circle(dst, cv::Point(w, h), 3, cv::Scalar(255, 0, 0));
			}
		}
	}
}
