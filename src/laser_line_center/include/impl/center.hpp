// Copyright 2019 Zhushi Tech, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef IMPL__CENTER_HPP_
#define IMPL__CENTER_HPP_

#include <map>
#include <vector>

#include "opencv2/opencv.hpp"

/**
 * @brief A map between ksize and normalized scalar for sobel.
 *
 */
std::map<int, double> SCALAR {
  {1, 1.},
  {3, 1. / 4.},
  {5, 1. / 48.},
  {7, 1. / 640.},
  {-1, 1. / 16.}
};

/**
 * @brief The algorithm to extract laser line center row by row.
 *
 * For more details of the algorithm, refer to the README.md.
 * @param img The input opencv image.
 * @param buf The buffer to use.
 * @return PointCloud2::UniquePtr Point cloud message to publish.
 */
std::vector<float> center(
  const cv::Mat & img,
  cv::Mat & buf,
  int ksize = 5,
  int threshold = 35,
  double width_min = 1.,
  double width_max = 30.)
{
  std::vector<float> pnts;
  if (img.empty()) {return pnts;}

  pnts.reserve(img.rows * 2);

  cv::Sobel(img, buf, CV_16S, 1, 0, ksize, SCALAR[ksize]);

  for (decltype(img.rows) r = 0; r < img.rows; ++r) {
    auto pRow = buf.ptr<short>(r);  // NOLINT
    auto minmax = std::minmax_element(pRow, pRow + img.cols);

    auto minEle = minmax.first;
    auto maxEle = minmax.second;

    auto minVal = *minEle;
    auto maxVal = *maxEle;

    auto minPos = minEle - pRow;
    auto minP = minPos == 0 ? pRow[minPos + 1] : pRow[minPos - 1];
    auto minN = minPos == img.cols - 1 ? pRow[minPos - 1] : pRow[minPos + 1];

    auto maxPos = maxEle - pRow;
    auto maxP = maxPos == 0 ? pRow[maxPos + 1] : pRow[maxPos - 1];
    auto maxN = maxPos == img.cols - 1 ? pRow[maxPos - 1] : pRow[maxPos + 1];

    auto a1 = maxP + maxN - maxVal * 2;
    auto b1 = maxP - maxN;
    auto s1 = (a1 < 0 ? 0.5 * b1 / a1 : 0.5 * b1);

    auto a2 = minP + minN - minVal * 2;
    auto b2 = minP - minN;
    auto s2 = (a2 > 0 ? 0.5 * b2 / a2 : 0.5 * b2);

    auto c = (maxPos + minPos + s1 + s2) / 2.;
    auto width = minPos + s2 - maxPos - s1;
    // std::cout << width << " " << minPos << " " << s2 << " " << maxPos << " " << s1 << "\n";
    if (
      maxVal >= threshold &&
      minVal <= -threshold &&
      width >= width_min &&
      width <= width_max &&
      maxPos > 0 &&
      minPos < img.cols - 1)
    {
      pnts.push_back(c);
    } else {
      pnts.push_back(-1.);
    }
  }

  /*
  cv::Mat imgtemp;
  imgtemp=img.clone();
  cv::cvtColor(imgtemp, imgtemp, cv::COLOR_GRAY2BGR);
  for(int n=0;n<pnts.size();n++)
  {
    int y=n;
    int x=pnts[n];
    uchar *ptr = imgtemp.ptr<uchar>(y);
    if(x>=0&&x<img.cols)
    {
        ptr[x*3]=0;
        ptr[x*3+1]=0;
        ptr[x*3+2]=255;
    }
    else
    {
        ptr[img.cols/2*3]=0;
        ptr[img.cols/2*3+1]=0;
        ptr[img.cols/2*3+2]=255;
    }
  }
  cv::imwrite("/home/qubo/mysunny/src/camera_test/bmp/1.bmp",imgtemp);
  */



  return pnts;
}

#endif  // IMPL__CENTER_HPP_
