#include "image.hpp"

std::string my::Image::fileExtention = "mosimg";

my::Image::Image(size_t width, size_t height, std::vector<Pixel> pixels): width(width), height(height), pixelVector(pixels)
{
    if(pixels.size() != width * height) throw std::runtime_error("width x height != pixels.size()");
}

bool my::Image::validExention(const std::string &path)
{
    return path.substr(path.size() - Image::fileExtention.size()) == Image::fileExtention;
}

bool my::Image::load(const std::string &path)
{
    if(!my::Image::validExention(path)) return false;

    std::ifstream in(path.c_str(), std::ios::binary);
    if(!in.is_open()) return false;

    in.read(reinterpret_cast<char*>(&width), sizeof(width));
    in.read(reinterpret_cast<char*>(&height), sizeof(height));
    pixelVector.resize(width * height);
    if(!in.read(reinterpret_cast<char*>(pixelVector.data()), pixelVector.size() * sizeof(my::Pixel))) return false;
    // pixelVector = std::vector<my::Pixel>{
    //     {20, 66, 55},
    //     {0, 44, 255},
    //     {0, 45, 0},

    //     {20, 66, 255},
    //     {255, 0, 0},
    //     {20, 1, 1},

    //     {54, 50, 255},
    //     {45, 100, 55},
    //     {20, 50, 255},
    //     {20, 50, 255},
    //     {20, 50, 255}
    // };//temp
    // height = 1;//temp
    std::cout<<"load success\n";
    in.close();
    return true;
}

void my::Image::save(const std::string &path) const
{
    if(!my::Image::validExention(path)) throw std::runtime_error("Invalid file extention");

    std::ofstream out(path.c_str(), std::ios::binary);
    if(!out.is_open()) throw std::runtime_error("Unable to open file");

    out.write(reinterpret_cast<const char*>(&width), sizeof(width));
    out.write(reinterpret_cast<const char*>(&height), sizeof(height));
    out.write(reinterpret_cast<const char*>(pixelVector.data()), pixelVector.size() * sizeof(my::Pixel));
    out.close();
    std::cout<<"save success\n";
}

my::Pixel my::Image::get(size_t x, size_t y) const
{
    return pixelVector[y * width + x];
}
