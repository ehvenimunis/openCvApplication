/*
    Author: Muhammed Salih Aydoğan
    Date:  31/08/2022
*/

#include <iostream>                        
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
using namespace std;
#define w 400
using namespace cv;

Mat image = Mat::zeros(w, w, CV_8UC3);
char window[] = "Screen For Mouse Handle";

void MyFilledCircle(int x, int y)
{
    circle(image,
        Point(x, y),
        1 / w ,
        Scalar(0, 0, 255),
        FILLED,
        LINE_8);
    imshow(window, image);
}

void locator(int event, int x, int y, int flags, void* userdata) { //function to track mouse movement and click//
    if (event == EVENT_LBUTTONDOWN) { //when left button clicked//
        cout << "Left click has been made, Position:(" << x << "," << y << ")" << endl;
        MyFilledCircle(x,y);
    }
    else if (event == EVENT_RBUTTONDOWN) { //when right button clicked//
        MyFilledCircle(x,y);
        cout << "Rightclick has been made, Position:(" << x << "," << y << ")" << endl;
    }
    else if (event == EVENT_MBUTTONDOWN) { //when middle button clicked//
        MyFilledCircle(x,y);
        cout << "Middleclick has been made, Position:(" << x << "," << y << ")" << endl;
    }
    else if (event == EVENT_MOUSEMOVE) { //when mouse pointer moves//
        cout << "Current mouse position:(" << x << "," << y << ")" << endl;
        MyFilledCircle(x,y);
    }    
}
int main(void) {

    if (image.empty())
    {
        std::cout << "Could not read the image: " << std::endl;
        return 1;
    }

    namedWindow(window);//declaring window to show image//
    setMouseCallback(window, locator, NULL);//Mouse callback function on define window
    imshow(window, image);
    waitKey(0);
    return(0);
}

