#include"../../headerspace/WatershedAlg.h"
using namespace cv;

Mat WatershedAlg::antiInverseImage(Mat image) {
       // #pragma acc parallel loop
        
       #pragma acc data copy(image)
      {
       #pragma acc parallel  async 
       { 
        #pragma acc loop
	for(int i = 0; i < image.rows; i++) {
            #pragma acc loop
            for(int j = 0; j < image.cols; j++) {
                if( (int) image.at<uchar>(i,j) == ZERO ) {
                    image.at<uchar>(i,j) = ZERO;
                } else {
                    image.at<uchar>(i,j) = ONE;
                }
            }
        }
      }
}
         #pragma acc wait
        return image;  
    }
