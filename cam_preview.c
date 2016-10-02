#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <stdio.h>


int main(int argc, char** argv)
{
    int CAM_ID = 0;
    IplImage* image = NULL;

    //open the CAM
    CvCapture* cap = cvCaptureFromCAM(CAM_ID); //카메라 생성

    //Check that the camera is opened
    if(cap == NULL){ //카메라 생성 확인
        printf("Can't open the CAM(%d)\n",CAM_ID);
        return -1;
    }

    // get the CAMERA resolution
    //카메라 이미지 해상도 얻기
    double width = cvGetCaptureProperty(cap, CV_CAP_PROP_FRAME_WIDTH);
    double height = cvGetCaptureProperty(cap, CV_CAP_PROP_FRAME_HEIGHT);
    printf("size = [%f, %f]\n",width, height);

    // create the window & change the window size
    //윈도우 생성 및 사이즈 변경
    cvNamedWindow("CAM_Window", 0);
    cvResizeWindow("CAM_Window", 1280, 720);

    while(1){
        //read the camera image
        //카메라에서 이미지 얻기
        image = cvQueryFrame(cap);

        //show the camera image
        //얻어온 이미지 윈도우에 표시
        cvShowImage("CAM_Window", image);

        //wait keyboard input until 10ms
        //10ms 동안 키입력 대기
        if(cvWaitKey(10) >= 0) break;

    }

    //close the window
    //윈도우 종료
    cvDestroyWindow("CAM_Window");
    return 0;
}
