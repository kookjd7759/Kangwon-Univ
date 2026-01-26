/*
 * 과제5: Weight Pyramid and Sobel Mask
 */

 #include "opencv2/opencv.hpp"

 void getSimpleDownscaledPyramid(const int Q, const cv::InputArray& input_image, std::vector<cv::Mat>& output_vector)
 {
     cv::Mat input_mat = input_image.getMat();
     int width = input_mat.cols;
     int height = input_mat.rows;
 
     cv::Mat temp;
     input_mat.copyTo(temp);
 
     for (int q = 0; q < Q; ++q)
     {
         cv::Mat dst(cv::Size(width / 2, height / 2), CV_8UC1);
 
         for (int h = 0; h < dst.rows; ++h)
         {	for (int w = 0; w < dst.cols; ++w)
             {
                 dst.at<uchar>(h, w) = temp.at<uchar>(h * 2, w * 2);
             }
         }
         output_vector.push_back(dst);
         dst.copyTo(temp);
 
         width = width / 2;
         height = height / 2;
     }
 }
 
 void getWeightPyramid(const int Q, const cv::InputArray& input_image, std::vector<cv::Mat>& output_vector)
 {
     cv::Mat input_mat = input_image.getMat();
     int width = input_mat.cols;
     int height = input_mat.rows;
 
     double weight[5][5] = {
         0.0025, 0.0125, 0.02, 0.0125, 0.0025,
         0.0125, 0.0625, 0.1,  0.0625, 0.0125,
         0.02,   0.1,    0.16, 0.1,    0.02,
         0.0125, 0.0625, 0.1,  0.0625, 0.0125,
         0.0025, 0.0125, 0.02, 0.0125, 0.0025
     };
 
     /**
      * Weight Pyramid를 구현합니다.
      * 위에 주어진 weight kernel을 이용하여 Convolution 연산을 구현합니다.
      * 구현하여 만들어진 결과 이미지는 output_vector에 저장합니다.
      *
      * Q는 결과 피라미드 이미지의 갯수입니다. Q번만큼 다운스케일링을 진행하면 됩니다.
      */
      // ** 지금부터 코드를 작성하세요. 이 줄은 지우시면 안 됩니다 **
 
     cv::Mat temp;
     input_mat.copyTo(temp);
 
     for (int q = 0; q < Q; ++q) {
         cv::Mat dst(cv::Size(width / 2, height / 2), CV_8UC1);
 
         for (int y = 0; y < dst.rows; ++y) {
             for (int x = 0; x < dst.cols; ++x) {
                 double sum = 0.0;
 
                 for (int i = -2; i < 3; ++i) {
                     int idxY = (y * 2) + i;
                     if (idxY < 0) idxY = 0;
                     if (idxY >= temp.rows) idxY = temp.rows - 1;
 
                     for (int j = -2; j < 3; ++j) {
                         int idxX = (x * 2) + j;
                         if (idxX < 0) idxX = 0;
                         if (idxX >= temp.cols) idxX = temp.cols - 1;
 
                         sum += (temp.at<uchar>(idxY, idxX) * weight[2 + i][2 + j]);
                     }
                 }
                 dst.at<uchar>(y, x) = cv::saturate_cast<uchar>(sum);
             }
         }
 
         output_vector.push_back(dst);
         dst.copyTo(temp);
 
         width /= 2;ms-appid:undefined
         height /= 2;
     }
 
     // ** 여기까지 코드를 작성하세요. 이 줄은 지우시면 안 됩니다 **
 }
 
 int main1()
 {
     std::vector<cv::Mat> octave_image;
     cv::Mat original_image;
     original_image = cv::imread("cat.bmp", cv::IMREAD_GRAYSCALE);
 
     getSimpleDownscaledPyramid(4, original_image, octave_image);
     getWeightPyramid(4, original_image, octave_image);
 
     int idx = 0;
     for (auto& v : octave_image)
     {
         std::string str = std::to_string(idx++);
         cv::namedWindow(str.c_str(), cv::WINDOW_NORMAL);
         cv::imshow(str.c_str(), v);
         cv::resizeWindow(str.c_str(), cv::Size(640, 360));
 
         // 이미지를 파일로 저장한다.
         cv::imwrite("cat_q" + std::to_string(idx) + ".bmp", v);
     }
     cv::waitKey();
 
     return 0;
 
 }