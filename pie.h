#ifndef JNP1ZAD4_PIE_H
#define JNP1ZAD4_PIE_H

#include <cmath>
#include <cassert>
#include <iostream>

/**
 * @return Approximation of PI
 * Calculates perimeters of regular polygons inscribed and circumscribed on circle
 * Returns half of mean of perimeters of polygons of (6 * 2^(@param n)) sides
 */
constexpr double pi_approx(unsigned int n) {
    //perimeter of polygon INSCRIBED in unit circle. Starting with hexagon.
    double insc = 6;
    //perimeter of polygon CIRCUMSCRIBED on unit circle. Starting with hexagon.
    double cirsc = 6 * 2 / sqrt(3); // TODO - sqrt też musimy samemu przybliżać?

    for (int i = 0; i < n; i++) {
        // we use formula from Archimedes "Measurement of a Circle"
        cirsc = 2 * insc * cirsc / (insc + cirsc);
        insc = sqrt(insc * cirsc);
    }

    return (cirsc + insc) / 4;
}

/**
 * Approximation of PI. Most accurate that it is possible in type double.
 */
constexpr double PI = pi_approx(8);




template<typename R, R radius, bool isSellable, typename P = void>
class Pie {
};

template<typename R, R radius>
class Pie<R, radius, false> {
    static_assert(std::is_integral<R>::value, "R type has to be integral");
private:
    int stock;

public:
    static constexpr bool isSellable = false;

    typedef R SizeType;

    Pie(int initialStock) :
            stock(initialStock) {
        assert(initialStock >= 1);
    }

    static constexpr double getArea() {
        return (PI * radius * radius);
    }

    int getStock() {
        return stock;
    }
};

template<typename R, R radius, typename P>
class Pie<R, radius, true, P> {
    static_assert(std::is_integral<R>::value, "R type has to be integral");
    static_assert(std::is_floating_point<P>::value, "P type has to be floating point");
private:
    int stock;
    P price;
public:
    static constexpr bool isSellable = true;

    typedef R SizeType;

    typedef P PriceType;

    Pie(int initialStock, P price) :
            stock(initialStock),
            price(price) {
        assert(initialStock >= 1);
    }

    static constexpr double getArea() {
        return (PI * radius * radius);
    }

    int getStock() {
        return stock;
    }

    P getPrice() {
        return price;
    }

    void sell() {
        if (stock >= 1) {
            stock--;
        }
        else {
            std::cerr << "Stock is empty. Nothing to sell." << std::endl;
        }
    }
};

template<typename R, R radius>
using CherryPie = Pie<R, radius, false>;

template<typename R, R radius, typename P>
using ApplePie = Pie<R, radius, true, P>;


#endif //JNP1ZAD4_PIE_H