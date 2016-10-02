#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <stdio.h>


int main(int argc, char** argv)
{
    int CAM_ID = 0;

    IplImage* image = NULL;
    CvCapture* cap = cvCaptureFromCAM(CAM_ID); //카메라 생성

    if(cap == NULL){ //카메라 생성 확인
        printf("Can't open the CAM(%d)\n",CAM_ID);
        return -1;
    }
    //카메라 이미지 해상도 얻기
    double width = cvGetCaptureProperty(cap, CV_CAP_PROP_FRAME_WIDTH);
    double height = cvGetCaptureProperty(cap, CV_CAP_PROP_FRAME_HEIGHT);
    printf("size = [%f, %f]\n",width, height);

    //윈도우 생성 및 사이즈 변경
    cvNamedWindow("CAM_Window", 0);
    cvResizeWindow("CAM_Window", 1280, 720);

    while(1){
        //카메라에서 이미지 얻기
        image = cvQueryFrame(cap);

        //얻어온 이미지 윈도우에 표시
        cvShowImage("CAM_Window", image);

        //10ms 동안 키입력 대기
        if(cvWaitKey(10) >= 0) break;

    }

    //윈도우 종료
    cvDestroyWindow("CAM_Window");
    return 0;
}
