#ifndef JNP1ZAD4_PIE_H
#define JNP1ZAD4_PIE_H

#include <cmath>

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
        // we use formula from Achimedes "Measurement of a Circle"
        cirsc = 2 * insc * cirsc / (insc + cirsc);
        insc = sqrt(insc * cirsc);
    }

    return (cirsc + insc) / 4;
}

/**
 * Approximation of PI. Most accurate that it is possible in type double.
 */
constexpr double PI = pi_approx(8);



#endif //JNP1ZAD4_PIE_H