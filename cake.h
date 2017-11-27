#ifndef JNP1ZAD4_CAKE_H
#define JNP1ZAD4_CAKE_H

/**
 * @return Approximation of ln(@param a)
 * Calculates (@param n)-th partial sum of Taylor`s series:
 * ln((1 + x) / (1 - x)) = 2 * (x + (x^3)/3 + (x^5)/5 + ...),
 * where we take such x that ((1 + x) / (1 - x)) = @param a
 */
constexpr double ln_approx(double a, unsigned int n) {
    double x = (a - 1) / (a + 1);

    double xpow = x;
    double sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += xpow / (2 * i - 1);
        xpow *= x*x;
    }

    return (2 * sum);
}

/**
 * Approximation of ln(2). Most accurate that it is possible in type double.
 */
constexpr double LN2 = ln_approx(2, 6);

template<typename T, T length, T width, bool isSellable, typename P = void>
class Cake {

};

template<typename T, T length, T width>
class Cake<T, length, width, false> {
    static_assert(std::is_integral<T>::value, "T type has to be integral");
private:
    int stock;
public:
    static constexpr bool isSellable = false;

    typedef T SizeType;

    Cake(int initialStock) :
            stock(initialStock) {
        assert(initialStock >= 1);
    }

    static constexpr double getArea() {
        return LN2 * length * width;
    }

    int getStock() {
        return stock;
    }
};

template<typename T, T length, T width, typename P>
class Cake<T, length, width, true, P> {
    static_assert(std::is_integral<T>::value, "T type has to be integral");
    static_assert(std::is_floating_point<P>::value, "P type has to be floating point");
private:
    int stock;
    P price;
public:
    static constexpr bool isSellable = true;

    typedef T SizeType;

    typedef P PriceType;

    Cake(int initialStock, P price) :
            stock(initialStock),
            price(price) {
        assert(initialStock >= 1);
    }

    static constexpr double getArea() {
        return LN2 * length * width;
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

template<typename T, T length, T width>
using CheeseCake = Cake<T, length, width, false>;

template<typename T, T length, T width, typename P>
using CreamCake = Cake<T, length, width, true, P>;

#endif //JNP1ZAD4_CAKE_H