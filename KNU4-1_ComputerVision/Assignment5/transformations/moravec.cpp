#include <algorithm>
#include "moravec.hpp"

transformations::Moravec::Moravec(cv::InputArray& original_image)
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


void transformations::Moravec::FindConfidenceMap(cv::InputArray& original_image)
{
	cv::Mat src = original_image.getMat();
	
	/**
	 * src를 이용하여 모라벡 알고리즘의 Confidence를 계산한 뒤
	 * 이를 confidence_map에 저장하세요.
	 * (confidence_map은 클래스 멤버 변수로 선언되어 있습니다.)
	 */
	// ** 지금부터 코드를 작성하세요. 이 줄은 지우시면 안 됩니다 **

	const int dx[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
	const int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

	for (int y = 2; y < src.rows - 2; ++y) {
		for (int x = 2; x < src.cols - 2; ++x) {
			float map[3][3] = { 0.0f };

			for (int dir = 0; dir < 8; ++dir) {
				float sum(0.0);
				for (int u = -1; u <= 1; ++u) {
					for (int v = -1; v <= 1; ++v) {
						float p1 = static_cast<float>(src.at<uchar>(y + v, x + u));
						float p2 = static_cast<float>(src.at<uchar>(y + v + dy[dir], x + u + dx[dir]));
						float diff = p1 - p2;
						sum += diff * diff;
					}
				}
				map[dy[dir] + 1][dx[dir] + 1] = sum;
			}

			float confidence = std::min(map[0][1], std::min(map[1][0], std::min(map[2][1], map[1][2])));

			confidence_map.at<float>(y, x) = confidence;
		}
	}

	// ** 여기까지 코드를 작성하세요. 이 줄은 지우시면 안 됩니다 **
}


void transformations::Moravec::DrawFeature(cv::OutputArray& result_image)
{
	cv::Mat dst = result_image.getMat();

	for (int h = 0; h < confidence_map.rows; ++h)
	{
		for (int w = 0; w < confidence_map.cols; ++w)
		{
			if (confidence_map.at<float>(h, w) >= 15000)
			{
				cv::circle(dst, cv::Point(w, h), 3, cv::Scalar(255, 0, 0));
			}
		}
	}
}