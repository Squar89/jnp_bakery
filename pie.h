#ifndef JNP1ZAD4_PIE_H
#define JNP1ZAD4_PIE_H

#include <cassert>

/**
 * @return Approximation of PI
 * Leibnitz`s method -
 * Calculates (@param n)-th partial sum of Maclaurin`s series for function y = arctg(x) and x = 1
 */
constexpr double pi_approx(unsigned int n) {
    double pi = 0;
  
    for (unsigned int i = 0; i < n; i++) {
        pi += 4 / (2 * (double) i + 1) * (1 - 2 * (i % 2));
    }
    return pi;
}

/**
 * Approximation of PI. Most accurate that it is possible in type double.
 */
constexpr double PI = pi_approx(160000);

template<typename R, R radius, bool isSellable, typename P = float>
class Pie {
    static_assert(std::is_integral<R>::value, "R type has to be integral");
    static_assert(std::is_floating_point<P>::value, "P type has to be floating point");

private:
    int stock;
    P price;

    template<bool b = isSellable>
    typename std::enable_if<b, void>::type restockPies(int amount) {
        stock += amount;
    }

public:
    /*template<bool b = isSellable>
    static constexpr bool isSellable = b;//TODO potrzebujemy tego?
    */

    typedef R SizeType;

    typedef P PriceType;

    //CherryPie constructor
    template<bool b = isSellable, typename std::enable_if<!b, bool>::type = false>
    Pie(int initialStock) :
            stock(initialStock) {
        assert(initialStock >= 1);
    }

    //ApplePie constructor
    template<bool b = isSellable, typename std::enable_if<b, bool>::type = false>
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

    template<bool b = isSellable>
    typename std::enable_if<b, P>::type getPrice() {
        return price;
    }

    template<bool b = isSellable>
    typename std::enable_if<b, void>::type sell() {
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