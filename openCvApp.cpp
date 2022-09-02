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
#define size w/w
using namespace cv;

class Mouse {
public:
    Mat image;
    char window[];
    Mouse() {
        Mat image = Mat::zeros(w, w, CV_8UC3);
        char window[] = "Screen For Mouse Handle";
    }
    void MyFilledCircle(int x, int y)
    {
        circle(image,
            Point(x, y),
            size,
            Scalar(0, 0, 255),
            FILLED,
            LINE_8);
        imshow(window, image);
    }
    void locator(int event, int x, int y, int flags, void* userdata) { //function to track mouse movement and click//
        if (event == EVENT_LBUTTONDOWN) { //when left button clicked//
            MyFilledCircle(x, y);
            cout << "Left click has been made, Position:(" << x << "," << y << ")" << endl;
        }
        else if (event == EVENT_RBUTTONDOWN) { //when right button clicked//
            MyFilledCircle(x, y);
            cout << "Rightclick has been made, Position:(" << x << "," << y << ")" << endl;
        }
        else if (event == EVENT_MBUTTONDOWN) { //when middle button clicked//
            MyFilledCircle(x, y);
            cout << "Middleclick has been made, Position:(" << x << "," << y << ")" << endl;
        }
        else if (event == EVENT_MOUSEMOVE) { //when mouse pointer moves//
            MyFilledCircle(x, y);
            cout << "Current mouse position:(" << x << "," << y << ")" << endl;
        }
    }
};
int main(void) {
    Mouse mt;
    namedWindow(mt.window);//declaring window to show image//
    setMouseCallback(mt.window, mt.locator, NULL);//Mouse callback function on define window
    imshow(mt.window, mt.image);
    waitKey(0);
    /*
    if (image.empty())
    {
        std::cout << "Could not read the image: " << std::endl;
        return 1;
    }
    */
    return(0);
}

