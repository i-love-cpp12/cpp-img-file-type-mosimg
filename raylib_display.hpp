#pragma once
#include"image.hpp"
#include<string>
#include<stdexcept>
#include"raylib.h"
class Application
{
    public:
    Application(const std::string& imgPath);
    void draw() const;
    private:
    unsigned int windowWidth;
    unsigned int windowHeight;
    double width_height_window_ratio;
    double pixelSize;
    my::Image img;
    double width_height_img_ratio;
    double marginLeft;
    double marginTop;
};