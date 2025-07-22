#pragma once

#include<fstream>
#include<vector>
#include<string>
#include<stdexcept>
#include<iostream>
namespace my
{
    struct Pixel
    {
        unsigned char R;
        unsigned char G;
        unsigned char B;
    };

    class Image
    {
        public:
        static std::string fileExtention;
        Image() = default;
        Image(size_t width, size_t height, std::vector<Pixel> pixels);
        static bool validExention(const std::string& path);
        bool load(const std::string& path);
        void save(const std::string& path) const;
        size_t width;
        size_t height;
        Pixel get(size_t x, size_t y) const;
        private:
        std::vector<Pixel> pixelVector;
    };
};