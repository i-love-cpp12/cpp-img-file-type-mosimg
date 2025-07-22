#include"raylib_display.hpp"
#include"raylib.h"
#include"image.hpp"
#include<ctime>
#include<cstdlib>

int main(int argc, char** argv)
{
    if(argc < 2) return 1;
    Application app{std::string(argv[1])};
    while (!WindowShouldClose())
    {
        app.draw();
    }
    
    // srand(std::time(nullptr));
    // std::vector<my::Pixel> pixelVector;
    // for(int i = 0;  i < 250000; ++i)
    // {
    //     const unsigned char R = std::rand() % 256;
    //     const unsigned char G = std::rand() % 256;
    //     const unsigned char B = std::rand() % 256;
    //     pixelVector.emplace_back(my::Pixel{R, G, B});
    // }
    // my::Image image(500, 500, pixelVector);
    // image.save("myimg2.mosimg");
    // return 0;
}