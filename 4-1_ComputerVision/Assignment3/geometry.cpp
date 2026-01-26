/*
 * 과제4: Rotation using Homogeneous Matrix
 */

 #include "geometry.hpp"
 #include "opencv2\opencv.hpp"
 
 void GeometryTransformator::ForwardTransformation(cv::InputArray& srcMat, cv::OutputArray& dstMat) {
	 if (!hasMatrixSet)
		 throw "동차 행렬이 정의되지 않았습니다. 동차 행렬을 먼저 정의해주세요.";
 
	 cv::Mat input_image, output_image;
 
	 // 인자로부터 Mat 이미지 로드
	 input_image = srcMat.getMat();
	 if (dstMat.empty())
		 dstMat.create(input_image.size(), input_image.type());
	 output_image = dstMat.getMat();
 
	 /**
	  * input_image의 이미지를 Forward Tranformation하는 코드를 구현하세요.
	  * input_image와 H 변수를 이용하여 Transformation하고, 결과를 output_image에 저장하세요.
	  */
	  // ** 지금부터 코드를 작성하세요. 이 줄은 지우시면 안 됩니다 **
 
	 for (int y = 0; y < input_image.rows; y++) {
		 for (int x = 0; x < input_image.cols; x++) {
			 int dst_y = int(H[0][0] * y) + int(H[1][0] * x) + (int)H[2][0];
			 int dst_x = int(H[0][1] * y) + int(H[1][1] * x) + (int)H[2][1];
 
			 if (dst_x >= 0 && dst_x < input_image.cols && dst_y >= 0 && dst_y < input_image.rows) {
				 output_image.at<uchar>(dst_y, dst_x) = input_image.at<uchar>(y, x);
			 }
		 }
	 }
 
	 // ** 여기까지 코드를 작성하세요. 이 줄은 지우시면 안 됩니다 **
 }
 
 void GeometryTransformator::BackwardTransformation(cv::InputArray& srcMat, cv::OutputArray& dstMat) {
	 if (!hasMatrixSet)
		 throw "동차 행렬이 정의되지 않았습니다. 동차 행렬을 먼저 정의해주세요.";
 
	 cv::Mat input_image, output_image;
 
	 // 인자로부터 Mat 이미지 로드
	 input_image = srcMat.getMat();
	 if (dstMat.empty())
		 dstMat.create(input_image.size(), input_image.type());
	 output_image = dstMat.getMat();
 
	 double H_inverse[3][3] = {};
	 InverseHmatrix(H_inverse);
 
	 /**
	  * input_image의 이미지를 Backward Tranformation하는 코드를 구현하세요.
	  * input_image와 H_inverse 변수를 이용하여
	  * GeometryTransformator::ForwardTransformation과 동일하게 구현하면 됩니다.
	  */
	  // ** 지금부터 코드를 작성하세요. 이 줄은 지우시면 안 됩니다 **
 
	 for (int y = 0; y < input_image.rows; y++) {
		 for (int x = 0; x < input_image.cols; x++) {
			 int dst_y = int(H[0][0] * y) + int(H[0][1] * x) + (int)H[0][2];
			 int dst_x = int(H[1][0] * y) + int(H[1][1] * x) + (int)H[1][2];
 
			 if (dst_x >= 0 && dst_x < input_image.cols && dst_y >= 0 && dst_y < input_image.rows) {
				 output_image.at<uchar>(y, x) = input_image.at<uchar>(dst_y, dst_x);
			 }
		 }
	 }
 
	 // ** 여기까지 코드를 작성하세요. 이 줄은 지우시면 안 됩니다 **
 }
 
 void GeometryTransformator::SetMoveMatrix(double y, double x) {
	 ClearMatrix();
 
	 H[0][0] = 1;
	 H[1][1] = 1;
	 H[2][0] = y;
	 H[2][1] = x;
	 H[2][2] = 1;
 
	 hasMatrixSet = true;
 }
 
 void GeometryTransformator::SetRotateMatrix(double degree) {
	 ClearMatrix();
	 /**
	  * 3*3 행렬 변수 H에 이동 동차 행렬을 작성하세요.
	  * 변수의 인자마다 값을 할당하면 됩니다.
	  * cos() 함수나 sin() 함수의 인자는 degree가 아닌 radian을 입력받는 점에 유의하고
	  * PI 변수를 활용하여 변환합니다.
	  */
 
	  // ** 지금부터 코드를 작성하세요. 이 줄은 지우시면 안 됩니다 **
 
	 double radian = degree * PI / 180.0;
 
	 H[0][0] = cos(radian);
	 H[0][1] = -sin(radian);
	 H[0][2] = 0.0;
 
	 H[1][0] = sin(radian);
	 H[1][1] = cos(radian);
	 H[1][2] = 0.0;
 
	 H[2][0] = 0.0;
	 H[2][1] = 0.0;
	 H[2][2] = 1.0;
 
	 // ** 여기까지 코드를 작성하세요. 이 줄은 지우시면 안 됩니다 **
 
	 hasMatrixSet = true;
 }
 
 void GeometryTransformator::InverseHmatrix(double result[3][3]) {
	 double determinant = 0;
 
	 for (int i = 0; i < 3; i++)
		 determinant += (H[0][i] * (H[1][(i + 1) % 3] * H[2][(i + 2) % 3] - H[1][(i + 2) % 3] * H[2][(i + 1) % 3]));
 
	 for (int i = 0; i < 3; i++) {
		 for (int j = 0; j < 3; j++) {
			 result[i][j] = (
				 (H[(j + 1) % 3][(i + 1) % 3] * H[(j + 2) % 3][(i + 2) % 3]) -
				 (H[(j + 1) % 3][(i + 2) % 3] * H[(j + 2) % 3][(i + 1) % 3])
				 ) / determinant;
		 }
	 }
 }
 
 void GeometryTransformator::ClearMatrix() {
	 memset(H, 0, sizeof(H));
	 hasMatrixSet = false;
 }
 