#include <iostream>
#include "bakery.h"
#include "cake.h"
#include "pie.h"

using std::cout;
using std::endl;

int passed = 0;
int notPassed = 0;

// STATIC ASSERTS
void uniqueTypeError() {
    // UNIQUE TYPES ERROR A
    /*auto bakeryUniqueTypesA = Bakery<float, int, 30,
    CherryPie<int, 1>,
    ApplePie<int, 1, float>,
    ApplePie<int, 2, float>,
    ApplePie<int, 1, float>,
    CheeseCake<int, 2, 3>
    >(
    CherryPie<int, 1>(3),
    ApplePie<int, 1, float>(3, 2.5f),
    ApplePie<int, 2, float>(2, 4.5f),
    ApplePie<int, 1, float>(1, 1.0f),
    CheeseCake<int, 2, 3>(3)
    );*/

    // UNIQUE TYPES ERROR B
    /*auto bakeryUniqueTypesB = Bakery<float, int, 30,
    CherryPie<int, 1>,
    ApplePie<int, 1, float>,
    CherryPie<int, 1>
    >(
    CherryPie<int, 1>(3),
    ApplePie<int, 1, float>(2, 4.5f),
    CherryPie<int, 1>(3)
    );*/

    /*auto bakeryUniqueTypesC = Bakery<float, int, 30,
        CherryPie<int, 1>,
        ApplePie<int, 1, float>,
        CherryPie<int, 1>
    >(
        CherryPie<int, 1>(3),
        ApplePie<int, 1, float>(2, 4.5f),
        CherryPie<int, 1>(2)
        );*/

    // UNIQUE TYPES OK
    auto bakeryUniqueTypes = Bakery<float, int, 30,
        CherryPie<int, 1>,
        ApplePie<int, 1, float>,
        CheeseCake<int, 1, 2>
    >(
        CherryPie<int, 1>(3),
        ApplePie<int, 1, float>(2, 4.5f),
        CheeseCake<int, 1, 2>(4)
    );
}

void dimTypesError() {
    /*auto bakeryDimTypesA = Bakery<float, char, 30,
        CherryPie<int, 1>,
        ApplePie<int, 1, float>
    >(
        CherryPie<int, 1>(3),
        ApplePie<int, 1, float>(2, 4.5f)
        );*/

    /*auto bakeryDimTypesB = Bakery<float, int, 30,
        CherryPie<int, 1>,
        ApplePie<bool, 1, float>
    >(
        CherryPie<int, 1>(3),
        ApplePie<bool, 1, float>(2, 4.5f)
        );*/

    /*auto bakeryDimTypesC = Bakery<float, int, 30,
        CherryPie<unsigned long long, 1>,
        ApplePie<int, 1, float>
    >(
        CherryPie<unsigned long long, 1>(3),
        ApplePie<int, 1, float>(2, 4.5f)
        );*/

    /*auto bakeryDimTypesD = Bakery<float, char, 30,
        CherryPie<unsigned long long, 1>,
        ApplePie<int, 1, float>
    >(
        CherryPie<unsigned long long, 1>(3),
        ApplePie<int, 1, float>(2, 4.5f)
        );*/

    auto bakeryDimTypes = Bakery<float, int, 30,
        CherryPie<int, 1>,
        ApplePie<int, 1, float>
    >(
        CherryPie<int, 1>(3),
        ApplePie<int, 1, float>(2, 4.5f)
        );
}

void priceTypesError() {
    /*auto bakeryPriceTypesA = Bakery<float, int, 30,
        CherryPie<int, 1>,
        ApplePie<int, 1, double>
    >(
        CherryPie<int, 1>(3),
        ApplePie<int, 1, double>(2, 4.5f)
        );*/

    /*auto bakeryPriceTypesB = Bakery<float, int, 30,
        CherryPie<int, 1>,
        ApplePie<int, 1, float>,
        CreamCake<int, 1, 2, double>
    >(
        CherryPie<int, 1>(3),
        ApplePie<int, 1, float>(2, 4.5f),
        CreamCake<int, 1, 2, double>(2, 4.5f)
        );*/

    /*auto bakeryPriceTypesC = Bakery<float, int, 30,
        CherryPie<int, 1>,
        ApplePie<int, 1, long double>,
        CreamCake<int, 1, 2, double>
    >(
        CherryPie<int, 1>(3),
        ApplePie<int, 1, long double>(2, 4.5f),
        CreamCake<int, 1, 2, double>(2, 4.5f)
        );*/

    auto bakeryPriceTypes = Bakery<float, int, 30,
        CherryPie<int, 1>,
        ApplePie<int, 1, float>,
        CreamCake<int, 1, 2, float>
    >(
        CherryPie<int, 1>(3),
        ApplePie<int, 1, float>(2, 4.5f),
        CreamCake<int, 1, 2, float>(2, 4.5f)
        );
}

void areaSpaceErrors() {
    using ChP = CherryPie<int, 1>;
    using ApP = ApplePie<int, 5, float>;
    using ChC = CheeseCake<int, 1, 1>;
    using CrC = CreamCake<int, 2, 5, float>;

    /*std::cout << "to ten tutaj:\n";
    auto bakerySpaceErrorsA = Bakery<float, int, 89,
        ChP,
        ApP,
        ChC,
        CrC
    >(
        ChP(3),
        ApP(2, 4.5f),
        ChC(2),
        CrC(2, 4.5f)
        );
    */

    auto bakerySpaceA = Bakery<float, int, 90,
        ChP,
        ApP,
        ChC,
        CrC
    >(
        ChP(3),
        ApP(2, 4.5f),
        ChC(2),
        CrC(2, 4.5f)
        );

    /*auto bakerySpaceErrorsB = Bakery<float, int, 1,
        ChP,
        ApP,
        ChC,
        CrC
    >(
        ChP(3),
        ApP(2, 4.5f),
        ChC(2),
        CrC(2, 4.5f)
        );*/

    /*auto bakerySpaceErrorsC = Bakery<float, int, 533,
        CherryPie<int, 13>,
        CreamCake<int, 3, 1, float>
    >(
        CherryPie<int, 13>(1),
        CreamCake<int, 3, 1, float>(1, 1.0f)
        );*/

    auto bakerySpaceC = Bakery<float, int, 534,
        CherryPie<int, 13>,
        CreamCake<int, 3, 1, float>
    >(
        CherryPie<int, 13>(1),
        CreamCake<int, 3, 1, float>(1, 1.0f)
        );

    /*auto bakerySpaceErrorsD = Bakery<float, int, 540,
        CherryPie<int, 13>,
        CreamCake<int, 7, 2, float>
    >(
        CherryPie<int, 13>(1),
        CreamCake<int, 7, 2, float>(1, 1.0f)
        );*/

    auto bakerySpaceD = Bakery<float, int, 541,
        CherryPie<int, 13>,
        CreamCake<int, 7, 2, float>
    >(
        CherryPie<int, 13>(1),
        CreamCake<int, 7, 2, float>(1, 1.0f)
        );

    auto bakerySpaceErrors = Bakery<float, int, 30,
        CherryPie<int, 1>,
        ApplePie<int, 1, float>,
        CreamCake<int, 1, 2, float>
    >(
        CherryPie<int, 1>(3),
        ApplePie<int, 1, float>(2, 4.5f),
        CreamCake<int, 1, 2, float>(2, 4.5f)
        );
}

bool profitsAndSell() {
    using ChP = CherryPie<int, 1>;
    using ApP = ApplePie<int, 5, float>;
    using ChC = CheeseCake<int, 1, 2>;
    using CrC = CreamCake<int, 1, 2, float>;
    auto bakery = Bakery<float, int, 1000, ChP, ApP, ChC, CrC>(
        ChP(1), ApP(1, 1.0f), ChC(1), CrC(1, 1.0f));

    bool testPassed = true;
    testPassed = testPassed && (bakery.getProfits() == 0);

    // bakery.sell<ChP>();

    bakery.sell<ApP>();
    testPassed = testPassed && (bakery.getProfits() == 1.0f);

    // bakery.sell<ChC>();

    bakery.sell<CrC>();
    testPassed = testPassed && (bakery.getProfits() == 2.0f);

    return testPassed;
}

bool stockAndSell() {
    using ChP = CherryPie<int, 1>;
    using ApP = ApplePie<int, 5, float>;
    using ChC = CheeseCake<int, 1, 2>;
    using CrC = CreamCake<int, 1, 2, float>;
    auto bakery = Bakery<float, int, 1000, ChP, ApP, ChC, CrC>(
        ChP(1), ApP(1, 1.0f), ChC(1), CrC(1, 1.0f));

    bool testPassed = true;
    testPassed = testPassed && (bakery.getProductStock<ChP>() == 1);
    testPassed = testPassed && (bakery.getProductStock<ApP>() == 1);
    testPassed = testPassed && (bakery.getProductStock<ChC>() == 1);
    testPassed = testPassed && (bakery.getProductStock<CrC>() == 1);

    bakery.sell<ApP>();
    testPassed = testPassed && (bakery.getProductStock<ApP>() == 0);

    bakery.sell<CrC>();
    testPassed = testPassed && (bakery.getProductStock<CrC>() == 0);

    bakery.sell<ApP>();
    testPassed = testPassed && (bakery.getProductStock<ApP>() == 0);

    return testPassed;
}

bool productArea() {
    using ChP = CherryPie<int, 1>;
    using ApP = ApplePie<int, 5, float>;
    using ChC = CheeseCake<int, 1, 1>;
    using CrC = CreamCake<int, 2, 5, float>;

    auto cherry = ChP(1);
    auto apple = ApP(1, 1.0f);
    auto cheese = ChC(1);
    auto cream = CrC(1, 1.0f);

    bool testPassed = true;
    testPassed = testPassed && (cherry.getArea() < 3.141593) && (cherry.getArea() >= 3.141592);
    testPassed = testPassed && (apple.getArea() >= 78.539816) && (apple.getArea() < 78.539825);
    testPassed = testPassed && (cheese.getArea() >= 0.693147) && (cheese.getArea() < 0.693148);
    testPassed = testPassed && (cream.getArea() >= 6.93147) && (cheese.getArea() < 6.93148);

    return testPassed;
}

bool productSell() {
    using ChP = CherryPie<int, 1>;
    using ApP = ApplePie<int, 5, float>;
    using ChC = CheeseCake<int, 1, 1>;
    using CrC = CreamCake<int, 2, 5, float>;

    auto cherry = ChP(1);
    auto apple = ApP(1, 1.0f);
    auto cheese = ChC(1);
    auto cream = CrC(1, 1.0f);

    bool testPassed = true;

    testPassed = testPassed && (cherry.getStock() == 1);
    testPassed = testPassed && (apple.getStock() == 1);
    testPassed = testPassed && (cheese.getStock() == 1);
    testPassed = testPassed && (cream.getStock() == 1);

    testPassed = testPassed && (apple.getPrice() == 1.0f);
    testPassed = testPassed && (cream.getPrice() == 1.0f);

    //cherry.getPrice();
    //cheese.getPrice();

    apple.sell();
    testPassed = testPassed && (apple.getStock() == 0);

    cream.sell();
    testPassed = testPassed && (cream.getStock() == 0);

    //apple.sell();

    return testPassed;
}

bool productRestock() {
    using ChP = CherryPie<int, 1>;
    using ApP = ApplePie<int, 5, float>;
    using ChC = CheeseCake<int, 1, 1>;
    using CrC = CreamCake<int, 2, 5, float>;

    auto cherry = ChP(1);
    auto apple = ApP(1, 1.0f);
    auto cheese = ChC(1);
    auto cream = CrC(1, 1.0f);

    bool testPassed = true;
    testPassed = testPassed && (apple.getStock() == 1);

    apple.restock(1);
    testPassed = testPassed && (apple.getStock() == 2);

    apple.sell();
    apple.sell();
    testPassed = testPassed && (apple.getStock() == 0);

    apple.restock(10);
    testPassed = testPassed && (apple.getStock() == 10);

    //cherry.restock(1);

    return testPassed;
}

bool bakeryRestock() {
    using ChP = CherryPie<int, 1>;
    using ApP = ApplePie<int, 5, float>;
    using ChC = CheeseCake<int, 1, 2>;
    using CrC = CreamCake<int, 1, 2, float>;
    auto bakery = Bakery<float, int, 1000, ChP, ApP, ChC, CrC>(
        ChP(1), ApP(1, 1.0f), ChC(1), CrC(1, 1.0f));

    bool testPassed = true;
    testPassed = testPassed && (bakery.getProductStock<ApP>() == 1);

    bakery.restock<ApP>(1);
    testPassed = testPassed && (bakery.getProductStock<ApP>() == 2);

    bakery.sell<ApP>();
    bakery.sell<ApP>();
    testPassed = testPassed && (bakery.getProductStock<ApP>() == 0);

    //bakery.restock<ChP>(1);
    //bakery.restock<ChC>(1);
    //bakery.restock<CrC>(1);

    return testPassed;
}

void test(bool condition, const char* testName) {
    if (condition) {
        cout << testName << ": PASSED" << endl;
        ++passed;
    }
    else {
        cout << testName << ": NOT PASSED" << endl;
        ++notPassed;
    }
}

int main() {
    // tests of compile errors
    uniqueTypeError();
    dimTypesError();
    priceTypesError();
    areaSpaceErrors();

    test(profitsAndSell(), "Profits and sell");
    test(stockAndSell(), "Stock and sell");
    test(productArea(), "Product area");
    test(productSell(), "Product sell");
    test(productRestock(), "Product restock");

    std::cout << "Passed: " << passed << "\nNot passed: " << notPassed << endl;
}