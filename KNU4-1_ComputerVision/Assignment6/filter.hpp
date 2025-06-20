/*
 * 과제9: LOG (Laplacian of Gaussian)
 */

 #pragma once
 #include "opencv2\opencv.hpp"
 
 class Filter
 {
 protected:
     int maskSize;
     double** mask;
     void AllocateMask();
 
 public:
     Filter() : maskSize(0), mask(NULL) {}
     ~Filter();
     virtual void CreateMask() = 0;
     void Convolute(cv::InputArray& input_image, cv::OutputArray& output_image);
 };
 
 class SobelFilterY : public Filter
 {
 public:
     void CreateMask();
 };
 
 class SobelFilterX : public Filter
 {
 public:
     void CreateMask();
 };
 
 class LOG : public Filter
 {
 public:
     void CreateMask();
     void CreateMask(double sigma);
     void FindZeroCrossing(cv::InputArray& input_image, cv::OutputArray& output_image);
     int CheckSign(const float& value);
 };
 