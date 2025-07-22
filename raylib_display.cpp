#include "raylib_display.hpp"

Application::Application(const std::string& imgPath):
    windowWidth(1200), windowHeight(700),
    width_height_window_ratio(windowWidth / static_cast<double>(windowHeight)),
    pixelSize(0),
    marginLeft(0),
    marginTop(0)
{
    size_t left = imgPath.rfind("/");
    left = left == std::string::npos ? 0:left;
    InitWindow(1200, 700, imgPath.substr(left).c_str());
    SetTargetFPS(20);
    if(!img.load(imgPath)) throw std::runtime_error("image falied to load");
    width_height_img_ratio = img.width / static_cast<double>(img.height);

    if(width_height_img_ratio < width_height_window_ratio)
    {
        pixelSize = static_cast<double>(windowHeight) / img.height;
        marginLeft = (windowWidth / 2.0) - ((img.width * pixelSize) / 2);
    }
    else
    {
        pixelSize =  static_cast<double>(windowWidth) / img.width;
        marginTop = (windowHeight / 2.0) - ((img.height * pixelSize) / 2);
    }
}

void Application::draw() const
{
    BeginDrawing();
        ClearBackground(BLACK);
        for(size_t y = 0; y < img.height; ++y)
        {
            for(size_t x = 0; x < img.width; ++x)
            {
                const my::Pixel color = img.get(x, y);
                DrawRectangle(pixelSize * x + marginLeft, pixelSize * y + marginTop,
                    pixelSize, pixelSize, {color.R, color.G, color.B, 255});
            }
        }
    EndDrawing();
}
