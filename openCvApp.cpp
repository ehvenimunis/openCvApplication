/*
    Author: Muhammed Salih Aydoğan
    Date:  02/08/2022
*/
#include <ctime>
#include <iostream>     
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
using namespace std;
using namespace cv;
#define w 400
#define size w/w

class App
{
public:
    App();
    int max = 255, min = 0;
    void setWin(const std::string& _winname);
private:
    Mat image;
    std::string winname;
    void on_mouse_internal(int ev, int x, int y);
    void MyFilledCircle(int x, int y);
    friend void on_mouse(int ev, int x, int y, int, void* obj);
};
void on_mouse(int ev, int x, int y, int, void* obj)
{
    App* app = static_cast<App*>(obj);
    if (app)
        app->on_mouse_internal(ev, x, y);
}

App::App()
{
    srand(time(0));
    setWin("Screen For Mouse Handle");
}

void App::setWin(const std::string& _winname)
{
    cv::namedWindow(_winname);
    this->winname = _winname;
    this->image = Mat::zeros(w, w, CV_8UC3);
    cv::setMouseCallback(winname, on_mouse, this);
    imshow(winname, image);
    waitKey(0);
}
void App::MyFilledCircle(int x, int y)
{
    circle(image,
        Point(x, y),
        size,
        Scalar(rand() % (max - min + 1) + min, rand() % (max - min + 1) + min, rand() % (max - min + 1) + min),
        FILLED,
        LINE_8);
    imshow(winname, image);
}

void App::on_mouse_internal(int ev, int x, int y)
{
    if (ev == EVENT_LBUTTONDOWN) { //when left button clicked//
        MyFilledCircle(x,y);
        cout << "Left click has been made, Position:(" << x << "," << y << ")" << endl;
    }
    else if (ev == EVENT_RBUTTONDOWN) { //when right button clicked//
        MyFilledCircle(x, y);
        cout << "Rightclick has been made, Position:(" << x << "," << y << ")" << endl;
    }
    else if (ev == EVENT_MBUTTONDOWN) { //when middle button clicked//
        MyFilledCircle(x, y);
        cout << "Middleclick has been made, Position:(" << x << "," << y << ")" << endl;
    }
    else if (ev == EVENT_MOUSEMOVE) { //when mouse pointer moves//
        MyFilledCircle(x, y);
        cout << "Current mouse position:(" << x << "," << y << ")" << endl;
    }
}

int main(void) {
    App mt;
    return(0);
}