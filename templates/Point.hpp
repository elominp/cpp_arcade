//
// Created by pirou_g on 28/03/16.
//

#ifndef CPP_ARCADE_POINT_HTT
#define CPP_ARCADE_POINT_HTT

template <typename T>
class Point
{
public:
    Point<T>(): _x(0), _y(0) {}
    Point<T>(T x, T y): _x(x), _y(y) {}
    Point<T>(Point<T> const &point) : _x(point._x), _y(point._y) {}
    Point<T> &operator=(Point<T> const &point) {
        _x = point._x;
        _y = point._y;
        return *this;
    }
    virtual ~Point() {}

    virtual T getX(void) const { return _x; }
    virtual T getY(void) const { return _y; }

    virtual void setX(T x) { _x = x; }
    virtual void setY(T y) { _y = y; }

private:
    T _x;
    T _y;
};

#endif //CPP_ARCADE_POINT_HTT