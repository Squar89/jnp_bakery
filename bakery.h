#ifndef JNP1ZAD4_BAKERY_H
#define JNP1ZAD4_BAKERY_H

#include <utility>
#include <tuple>
#include "pie.h"
#include "cake.h"

/**
 * Provides the member constant value equal to sum of areas of all bakery products in bakery.
 * @tparam A type of shelf area
 * @tparam P type of first bakery product
 * @tparam Other types of other bakery products
 */
template<typename A, typename P, typename... Other>
struct sum_of_areas {
    //calculate sum of areas recursively
    static constexpr A value = P::getArea() + sum_of_areas<A, Other...>::value;
};

/**
 * Specialization for only one bakery product - base case.
 */
template<typename A, typename P>
struct sum_of_areas<A, P> {
    //base case
    static constexpr A value = P::getArea();
};

/**
 * Provides the member constant value equal to true, if type @tparam P is distinct from all other types (@tparam Q and @tparam Other)
 * Otherwise value == false
 */
template<typename P, typename Q, typename... Other>
struct is_first_unique {
    //recursive formula
    static constexpr bool value = (is_first_unique<P, Q>::value) && (is_first_unique<P, Other...>::value);
};

/**
 * Specialization for only 1 other type - base case
 */
template<typename P, typename Q>
struct is_first_unique<P, Q> {
    //base case
    static constexpr bool value = !std::is_same<P, Q>::value;
};

/**
 * Provides the member constant value equal to true, if all types (@tparam P @tparam Q @tparam Other) are pairwise distinct
 * O(n^2), where n is number of tparams
 */
template<typename P, typename Q = void, typename... Other>
struct are_unique {
    //recursive formula
    static constexpr bool value = (is_first_unique<P, Q, Other...>::value) && (are_unique<Q, Other...>::value);
};

/**
 * Specialization for only 2 types - base case
 */
template<typename P, typename Q>
struct are_unique<P, Q> {
    static constexpr bool value = !std::is_same<P, Q>::value;
};

/**
 * Specialization for only 1 type
 */
template<typename P>
struct are_unique<P> {
    static constexpr bool value = true;
};

/**
 * Checks if all of bakery products (@tparam P and @tparam Other) have size type equal to @tparam A.
 */
template<typename A, typename P, typename... Other>
struct have_good_size_type {
    static constexpr bool value = (have_good_size_type<A, P>::value) && (have_good_size_type<A, Other...>::value);
};

/**
 * Specialization for only 1 product type
 */
template<typename A, typename P>
struct have_good_size_type<A, P> {
    static constexpr bool value = std::is_same<A, typename P::SizeType>::value;
};

/**
 * Checks if all of bakery products (@tparam P and @tparam Other) have size type equal to @tparam A.
 */
template<typename C, typename P, typename... Other>
struct have_good_price_type {
    static constexpr bool value = (have_good_price_type<C, P>::value) && (have_good_price_type<C, Other...>::value);
};

/**
 * Specialization for only 1 product type
 */
template<typename C, typename P>
struct have_good_price_type<C, P> {
    static constexpr bool value = (!P::sellable) || (std::is_same<C, typename P::PriceType>::value);
};

/**
 * Provides field value equal to true if parameter pack @tparam First, P contains type @tparam Product
 * Otherwise value is false
 */
template<typename Product, typename First, typename... P>
struct contains {
    static constexpr bool value = contains<Product, First>::value || contains<Product, P...>::value;
};

template<typename Product, typename First>
struct contains<Product, First> {
    static constexpr bool value = std::is_same<Product, First>::value;
};

/**
 * Provides field value equal to first position of type @tparam Product in parameter pack @tparam First, P
 */
template<typename Product, typename First, typename... P>
struct first_position {
    static constexpr size_t value = std::is_same<Product, First>::value ? 0 : first_position<Product, P...>::value + 1;
};

template<typename Product, typename First>
struct first_position<Product, First> {
    static constexpr size_t value = 0;
};

template<typename C, typename A, A shelfArea, typename... P>
class Bakery {
    static_assert(std::is_floating_point<C>::value,
                  "C type has to be floating point");
    static_assert(std::is_integral<A>::value,
                  "A type has to be integral");
    static_assert(have_good_size_type<A, P...>::value,
                  "Size type of all products in bakery has to be A");
    static_assert(have_good_price_type<C, P...>::value,
                  "Price type of all sellable products in bakery has to be C");
    static_assert(sum_of_areas<A, P...>::value <= shelfArea,
                  "Sum of products areas can't exceed Bakery's available shelf space");
    static_assert(are_unique<P...>::value,
                  "Types in P have to be unique");

private:
    /**
     * Current Bakery's profits
     */
    C profits;

    /**
     * Tuple storing Bakery's products
     */
    std::tuple<P...> productsTuple;

    /**
     * @return Bakery's product of type @tparam Product
     */
    template<typename Product>
    Product& getProduct() {
        static_assert(contains<Product, P...>::value,
                      "Given type doesn't exist in this bakery");

        static constexpr size_t product_position = first_position<Product, P...>::value;
        return std::get<product_position>(productsTuple);
    }

public:
    explicit Bakery(P... products) :
            profits(0),
            productsTuple(products...) {}

    C getProfits() {
        return profits;
    }

    template<typename Product>
    void sell() {
        static_assert(contains<Product, P...>::value,
                      "Given type doesn't exist in this bakery");
        /* static_assert(Product::sellable,
                      "Product isn't sellable."); */

        auto& product = getProduct<Product>();
        if (product.getStock() >= 1) {
            product.sell();//TODO jeśli stock == 0 i produkt nie jest na sprzedaż, będzie error?
            profits += product.getPrice();
        }
    }

    template<typename Product>
    int getProductStock() {
        static_assert(contains<Product, P...>::value,
                      "Given type doesn't exist in this bakery");

        return getProduct<Product>().getStock();
    }

    template<typename Product>
    void restock(int additionalStock) {
        static_assert(contains<Product, P...>::value,
                      "Given type doesn't exist in this bakery");

        getProduct<Product>().restockPies(additionalStock);
    }
};

#endif //JNP1ZAD4_BAKERY_H