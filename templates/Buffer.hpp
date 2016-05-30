//
// Created by pirou_g on 28/03/16.
//

#ifndef CPP_ARCADE_BUFFER_HPP
#define CPP_ARCADE_BUFFER_HPP

#include <iostream>
#include <ostream>
#include <vector>
#include "Color.hpp"
#include "sprites.h"

#ifndef NULL
# define NULL 0
#endif

template <typename T>
class Buffer
{
public:
    Buffer<T>():
            _width(0),
            _height(0)
    {
    }
    Buffer<T>(std::size_t width, std::size_t height, T *array = NULL)
    {
        for (std::size_t i = 0; i < height; i++)
        {
            for (std::size_t j = 0; j < (width * 3); j += 3)
            {
                if (array != NULL)
                {
                    T r = array[(i * width * 3) + j];
                    T g = array[(i * width * 3) + j + 1];
                    T b = array[(i * width * 3) + j + 2];
                    _texture.push_back(Color<T>(r, g, b));
                }
                else
                    _texture.push_back(Color<T>(255, 255, 255));
            }
        }
        _width = width;
        _height = height;
    }
    Buffer<T>(CSprite const &sprite)
    {
        _width = sprite.width;
        _height = sprite.height;
        for (std::size_t i = 0; i < _height; i++)
        {
            for (std::size_t j = 0; j < (_width * 3); j += 3)
            {
                T r = sprite.pixel_data[(i * _width * 3) + j];
                T g = sprite.pixel_data[(i * _width * 3) + j + 1];
                T b = sprite.pixel_data[(i * _width * 3) + j + 2];
                _texture.push_back(Color<T>(r, g, b));
            }
        }
    }
    Buffer<T>(Buffer const &buffer):
            _width(buffer._width), _height(buffer._height)
    {
        for (std::size_t i = 0; i < _height; i++)
        {
            for (std::size_t j = 0; j < _width; j++)
            {
                _texture.push_back(buffer(j, i));
            }
        }
    }

    virtual Buffer<T> &operator=(Buffer const &buffer)
    {
        _width = buffer._width;
        _height = buffer._height;
        for (std::size_t i = 0; i < _height; i++)
        {
            for (std::size_t j = 0; j < _width; j++)
            {
                if ((i * _width + j) <= _texture.size())
                    _texture[(i * _width) + j] = buffer(j, i);
                else
                    _texture.push_back(buffer(j, i));
            }
        }
        return *this;
    }

    virtual Color<T> &operator()(std::size_t x, std::size_t y)
    {
        return _texture.at((y * _width) + x);
    }

    virtual Color<T> const &operator()(std::size_t x, std::size_t y) const
    {
        return _texture.at((y * _width) + x);
    }
    virtual ~Buffer() {}

    virtual std::size_t getWidth(void) const
    {
        return _width;
    }

    virtual std::size_t getHeight(void) const
    {
        return _height;
    }

    virtual std::vector<Color<T> > const &getTexture(void)
    {
        return _texture;
    }

    virtual Color<T> const &getPixel(std::size_t x, std::size_t y) const
    {
        return _texture.at((y * _width) + x);
    }

    std::vector<Color<T> > const &getPixels(void) const
    {
        return _texture;
    }

    virtual void setPixel(std::size_t x, std::size_t y, Color<T> const &color)
    {
        if (x < _width && y < _height)
            _texture[(y * _width) + x] = color;
    }

    virtual std::ostream &operator<<(std::ostream &out)
    {
        out << "Width of buffer = " << _width << std::endl;
        out << "Height of buffer = " << _height << std::endl;
        out << "Pixels data :" << std::endl;
        for (auto it = _texture.begin(); it != _texture.end(); it++)
            out << *it;
        return out;
    }

private:
    std::vector<Color<T> > _texture;
    std::size_t _width;
    std::size_t _height;
};

template <typename T>
std::ostream &operator<<(std::ostream &out, Buffer<T> const &buffer)
{
    const std::vector<Color<T> > pixels = buffer.getPixels();
    out << "Width of buffer = " << buffer.getWidth() << std::endl;
    out << "Height of buffer = " << buffer.getHeight() << std::endl;
    out << "Number of pixels = " << pixels.size() << std::endl;
    out << "Pixels data :" << std::endl;
    for (auto it = pixels.cbegin(); it != pixels.cend(); it++)
        out << *it;
    return out;
}

#endif //CPP_ARCADE_BUFFER_HPP
