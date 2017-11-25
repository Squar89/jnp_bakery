#ifndef JNP1ZAD4_BAKERY_H
#define JNP1ZAD4_BAKERY_H

#include <utility>
#include "pie.h"


/**
 * Provides the member constant value equal to sum of areas of all bakery products in bakery.
 * @tparam A type of shelf area
 * @tparam P type of first bakery product
 * @tparam Other types of other bakery products
 */
template<typename A, typename P, typename... Other>
struct SumOfAreas {
public:
    //calculate sum of areas recursively
    static constexpr A value = P::getArea() + SumOfAreas<A, Other...>::value;
};

/**
 * Specialization for only one bakery product - base case.
 */
template<typename A, typename P>
struct SumOfAreas<A, P> {
public:
    //base case
    static constexpr A value = P::getArea();
};



/**
 * Provides the member constant value equal to true, if type @tparam P is distinct from all other types (@tparam Q and @tparam Other)
 * Otherwise value == false
 */
template<typename P, typename Q, typename... Other>
struct IsFirstUnique {
public:
    //recursive formula
    static constexpr bool value = (IsFirstUnique<P, Q>::value) && (IsFirstUnique<P, Other...>::value);
};

/**
 * Specialization for only 1 other type - base case
 */
template<typename P, typename Q>
struct IsFirstUnique<P, Q> {
public:
    //base case
    static constexpr bool value = !std::is_same<P, Q>::value;
};

/**
 * Provides the member constant value equal to true, if all types (@tparam P @tparam Q @tparam Other) are pairwise distinct
 * O(n^2), where n is number of tparams
 */
template<typename P, typename Q = void, typename... Other>
struct AreUnique {
public:
    //recursive formula
    static constexpr bool value = (IsFirstUnique<P, Q, Other...>::value) && (AreUnique<Q, Other...>::value);
};

/**
 * Specialization for only 2 types - base case
 */
template<typename P, typename Q>
struct AreUnique<P, Q> {
public:
    static constexpr bool value = !std::is_same<P, Q>::value;
};

/**
 * Specialization for only 1 type
 */
template<typename P>
struct AreUnique<P> {
public:
    static constexpr bool value = true;
};


/**
 * Checks if all of bakery products (@tparam P and @tparam Other) have size type equal to @tparam A.
 */
template<typename A, typename P, typename... Other>
struct HaveGoodSizeType {
public:
    static constexpr bool value = (HaveGoodSizeType<A, P>::value) && (HaveGoodSizeType<A, Other...>::value);
};

/**
 * Specialization for only 1 product type
 */
template<typename A, typename P>
struct HaveGoodSizeType<A, P> {
public:
    static constexpr bool value = std::is_same<A, typename P::SizeType>::value;
};


/**
 * Checks if all of bakery products (@tparam P and @tparam Other) have size type equal to @tparam A.
 */
template<typename C, typename P, typename... Other>
struct HaveGoodPriceType {
public:
    static constexpr bool value = (HaveGoodPriceType<C, P>::value) && (HaveGoodPriceType<C, Other...>::value);
};

/**
 * Specialization for only 1 product type
 */
template<typename C, typename P>
struct HaveGoodPriceType<C, P> {
public:
    static constexpr bool value = (!P::isSellable) || (std::is_same<C, typename P::PriceType>::value);
    //TODO - trzeba zrobić jakoś, żeby się ewaluowało leniwie, albo wypiek zawsze miał PriceType
};


template<typename C, typename A, A shelfArea, typename... P>
class Bakery {
    static_assert(std::is_floating_point<C>::value,
                  "C type has to be floating point");
    static_assert(std::is_integral<A>::value,
                  "A type has to be integral");
    static_assert(HaveGoodSizeType<A, P...>::value,
                  "typ wymiaru wszystkich produktów w piekarni musi być taki sam jak typ A");
    //static_assert(HaveGoodPriceType<C, P...>::value,
      //            "typ ceny wszystkich produktów (przeznaczonych na sprzedaż) w piekarni musi być taki sam jak typ C");
    static_assert(SumOfAreas<A, P...>::value <= shelfArea,
                  "produkty w piekarni nie mogą mieć łącznej powierzchni większej niż przestrzeń na półkach");
    static_assert(AreUnique<P...>::value,
                  "typy zawarte w ramach parametru P muszą być unikatowe");

private:
    C profits;
public:
    Bakery(P... products) {
        profits = 0;
    }


};



#endif //JNP1ZAD4_BAKERY_H