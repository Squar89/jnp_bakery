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



#endif //JNP1ZAD4_CAKE_H