//
// Created by pirou_g on 28/03/16.
//

#ifndef CPP_ARCADE_COLOR_HPP
#define CPP_ARCADE_COLOR_HPP

#include <ostream>

template <typename T>
class Color
{
public:
    Color<T>(): _r(0), _g(0), _b(0) {}
    Color<T>(T r, T g, T b): _r(r), _g(g), _b(b) {}
    Color<T>(Color<T> const &color): _r(color._r),
                                     _g(color._g),
                                     _b(color._b) {}
    Color<T> &operator=(Color<T> const &color) {
        _r = color._r;
        _g = color._g;
        _b = color._b;
        return *this;
    }
    virtual ~Color() {}

    T getRed(void) const { return _r; }
    T getGreen(void) const { return _g; }
    T getBlue(void) const { return _b; }

    void setRed(T r) { _r = r; }
    void setGreen(T g) { _g = g; }
    void setBlue(T b) { _b = b; }

private:
    T _r;
    T _g;
    T _b;
};

template<typename T>
std::ostream &operator<<(std::ostream &out, Color<T> const &color)
{
    out << color.getRed() << color.getGreen() << color.getBlue();
    return out;
}

#endif //CPP_ARCADE_COLOR_HPP
