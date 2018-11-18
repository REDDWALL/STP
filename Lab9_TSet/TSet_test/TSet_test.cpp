#include <cassert>
#include <iostream>
#include "TSet_test.h"
#include "../TFrac/TFrac.h"
#include "../TSet/TSetFirst.h"
#include "../TSet/TSetSecond.h"

void TSet_test::constructorTest() {
    TSetFirst<int> tSetFirst_1;
    assert(tSetFirst_1.empty());

    TSetFirst<TFrac> tSetFirst_2;
    assert(tSetFirst_2.empty());

    TSetSecond<int> tSetSecond_1;
    assert(tSetSecond_1.empty());

    TSetSecond<TFrac> tSetSecond_2;
    assert(tSetSecond_2.empty());
}

void TSet_test::clearAndEmptyTest() {
    TSetFirst<int> tSetFirst_1;
    tSetFirst_1.insert(1);
    tSetFirst_1.insert(2);
    tSetFirst_1.insert(3);
    tSetFirst_1.clear();
    assert(tSetFirst_1.empty());

    TSetFirst<TFrac> tSetFirst_2;
    tSetFirst_2.insert(TFrac(1, 2));
    tSetFirst_2.insert(TFrac(10, 5));
    tSetFirst_2.insert(TFrac(-1, 8));
    tSetFirst_2.clear();
    assert(tSetFirst_2.empty());

    TSetSecond<int> tSetSecond_1;
    tSetSecond_1.insert(1);
    tSetSecond_1.insert(2);
    tSetSecond_1.insert(3);
    tSetSecond_1.clear();
    assert(tSetSecond_1.empty());

    TSetSecond<TFrac> tSetSecond_2;
    tSetSecond_2.insert(TFrac(1, 2));
    tSetSecond_2.insert(TFrac(10, 5));
    tSetSecond_2.insert(TFrac(-1, 8));
    tSetSecond_2.clear();
    assert(tSetSecond_2.empty());
}

void TSet_test::insertTest() {
    TSetFirst<int> tSetFirst_1;
    tSetFirst_1.insert(3);
    tSetFirst_1.insert(2);
    tSetFirst_1.insert(1);
    assert(tSetFirst_1.size() == 3);
    assert(tSetFirst_1.getElement(0) == 1);
    assert(tSetFirst_1.getElement(1) == 2);
    assert(tSetFirst_1.getElement(2) == 3);

    TSetFirst<TFrac> tSetFirst_2;
    tSetFirst_2.insert(TFrac(1, 2));
    tSetFirst_2.insert(TFrac(10, 5));
    tSetFirst_2.insert(TFrac(-1, 8));
    assert(tSetFirst_2.size() == 3);
    assert(tSetFirst_2.getElement(0) == TFrac(-1, 8));
    assert(tSetFirst_2.getElement(1) == TFrac(1, 2));
    assert(tSetFirst_2.getElement(2) == TFrac(10, 5));

    TSetSecond<int> tSetSecond_1;
    tSetSecond_1.insert(1);
    tSetSecond_1.insert(2);
    tSetSecond_1.insert(3);
    assert(tSetSecond_1.size() == 3);
    assert(tSetSecond_1.getElement(0) == 1);
    assert(tSetSecond_1.getElement(1) == 2);
    assert(tSetSecond_1.getElement(2) == 3);

    TSetSecond<TFrac> tSetSecond_2;
    tSetSecond_2.insert(TFrac(1, 2));
    tSetSecond_2.insert(TFrac(10, 5));
    tSetSecond_2.insert(TFrac(-1, 8));
    assert(tSetSecond_2.size() == 3);
    assert(tSetSecond_2.getElement(0) == TFrac(-1, 8));
    assert(tSetSecond_2.getElement(1) == TFrac(1, 2));
    assert(tSetSecond_2.getElement(2) == TFrac(10, 5));
}

void TSet_test::eraseTest() {
    TSetFirst<int> tSetFirst_1;
    tSetFirst_1.insert(3);
    tSetFirst_1.insert(2);
    tSetFirst_1.insert(1);
    tSetFirst_1.erase(4);
    tSetFirst_1.erase(2);
    assert(tSetFirst_1.size() == 2);
    assert(tSetFirst_1.getElement(0) == 1);
    assert(tSetFirst_1.getElement(1) == 3);

    TSetFirst<TFrac> tSetFirst_2;
    tSetFirst_2.insert(TFrac(1, 2));
    tSetFirst_2.insert(TFrac(10, 5));
    tSetFirst_2.insert(TFrac(-1, 8));
    tSetFirst_2.erase(TFrac(3, 7));
    tSetFirst_2.erase(TFrac(10, 5));
    assert(tSetFirst_2.size() == 2);
    assert(tSetFirst_2.getElement(0) == TFrac(-1, 8));
    assert(tSetFirst_2.getElement(1) == TFrac(1, 2));

    TSetSecond<int> tSetSecond_1;
    tSetSecond_1.insert(1);
    tSetSecond_1.insert(2);
    tSetSecond_1.insert(3);
    tSetSecond_1.erase(4);
    tSetSecond_1.erase(2);
    assert(tSetSecond_1.size() == 2);
    assert(tSetSecond_1.getElement(0) == 1);
    assert(tSetSecond_1.getElement(1) == 3);

    TSetSecond<TFrac> tSetSecond_2;
    tSetSecond_2.insert(TFrac(1, 2));
    tSetSecond_2.insert(TFrac(10, 5));
    tSetSecond_2.insert(TFrac(-1, 8));
    tSetSecond_2.erase(TFrac(3, 7));
    tSetSecond_2.erase(TFrac(10, 5));
    assert(tSetSecond_2.size() == 2);
    assert(tSetSecond_2.getElement(0) == TFrac(-1, 8));
    assert(tSetSecond_2.getElement(1) == TFrac(1, 2));
}

void TSet_test::containsTest() {
    TSetFirst<int> tSetFirst_1;
    tSetFirst_1.insert(3);
    tSetFirst_1.insert(2);
    tSetFirst_1.insert(1);
    assert(tSetFirst_1.contains(3));
    assert(tSetFirst_1.contains(2));
    assert(tSetFirst_1.contains(1));
    assert(!tSetFirst_1.contains(5));

    TSetFirst<TFrac> tSetFirst_2;
    tSetFirst_2.insert(TFrac(1, 2));
    tSetFirst_2.insert(TFrac(10, 5));
    tSetFirst_2.insert(TFrac(-1, 8));
    assert(tSetFirst_2.contains(TFrac(1, 2)));
    assert(tSetFirst_2.contains(TFrac(10, 5)));
    assert(tSetFirst_2.contains(TFrac(-1, 8)));
    assert(!tSetFirst_2.contains(TFrac(3, 7)));

    TSetSecond<int> tSetSecond_1;
    tSetSecond_1.insert(1);
    tSetSecond_1.insert(2);
    tSetSecond_1.insert(3);
    assert(tSetSecond_1.contains(3));
    assert(tSetSecond_1.contains(2));
    assert(tSetSecond_1.contains(1));
    assert(!tSetSecond_1.contains(5));

    TSetSecond<TFrac> tSetSecond_2;
    tSetSecond_2.insert(TFrac(1, 2));
    tSetSecond_2.insert(TFrac(10, 5));
    tSetSecond_2.insert(TFrac(-1, 8));
    assert(tSetSecond_2.contains(TFrac(1, 2)));
    assert(tSetSecond_2.contains(TFrac(10, 5)));
    assert(tSetSecond_2.contains(TFrac(-1, 8)));
    assert(!tSetSecond_2.contains(TFrac(3, 7)));
}

void TSet_test::concatenationTest() {
    TSetFirst<int> tSetFirst_1;
    tSetFirst_1.insert(1);
    tSetFirst_1.insert(2);

    TSetFirst<int> tSetFirst_2;
    tSetFirst_2.insert(3);
    tSetFirst_2.insert(4);

    TSetFirst<int> tSetFirst_3 = tSetFirst_1.concatenate(tSetFirst_2);
    assert(tSetFirst_3.size() == 4);
    assert(tSetFirst_3.getElement(0) == 1);
    assert(tSetFirst_3.getElement(1) == 2);
    assert(tSetFirst_3.getElement(2) == 3);
    assert(tSetFirst_3.getElement(3) == 4);

    TSetSecond<int> tSetSecond_1;
    tSetSecond_1.insert(1);
    tSetSecond_1.insert(2);

    TSetSecond<int> tSetSecond_2;
    tSetSecond_2.insert(3);
    tSetSecond_2.insert(4);

    TSetSecond<int> tSetSecond_3 = tSetSecond_1.concatenate(tSetSecond_2);
    assert(tSetSecond_3.size() == 4);
    assert(tSetSecond_3.getElement(0) == 1);
    assert(tSetSecond_3.getElement(1) == 2);
    assert(tSetSecond_3.getElement(2) == 3);
    assert(tSetSecond_3.getElement(3) == 4);

    TSetFirst<TFrac> tSetFirst_4;
    tSetFirst_4.insert(TFrac(-1, 2));
    tSetFirst_4.insert(TFrac(-2, 2));

    TSetFirst<TFrac> tSetFirst_5;
    tSetFirst_4.insert(TFrac(1, 2));
    tSetFirst_4.insert(TFrac(2, 2));

    TSetFirst<TFrac> tSetFirst_6 = tSetFirst_4.concatenate(tSetFirst_5);
    assert(tSetFirst_6.size() == 4);
    assert(tSetFirst_6.getElement(0) == TFrac(-2, 2));
    assert(tSetFirst_6.getElement(1) == TFrac(-1, 2));
    assert(tSetFirst_6.getElement(2) == TFrac(1, 2));
    assert(tSetFirst_6.getElement(3) == TFrac(2, 2));

    TSetSecond<TFrac> tSetSecond_4;
    tSetSecond_4.insert(TFrac(-1, 2));
    tSetSecond_4.insert(TFrac(-2, 2));

    TSetSecond<TFrac> tSetSecond_5;
    tSetSecond_5.insert(TFrac(1, 2));
    tSetSecond_5.insert(TFrac(2, 2));

    TSetSecond<TFrac> tSetSecond_6 = tSetSecond_4.concatenate(tSetSecond_5);
    assert(tSetSecond_6.size() == 4);
    assert(tSetSecond_6.getElement(0) == TFrac(-2, 2));
    assert(tSetSecond_6.getElement(1) == TFrac(-1, 2));
    assert(tSetSecond_6.getElement(2) == TFrac(1, 2));
    assert(tSetSecond_6.getElement(3) == TFrac(2, 2));
}

void TSet_test::subtractionTest() {
    TSetFirst<int> tSetFirst_1;
    tSetFirst_1.insert(3);
    tSetFirst_1.insert(2);
    tSetFirst_1.insert(1);

    TSetFirst<int> tSetFirst_2;
    tSetFirst_2.insert(3);
    tSetFirst_2.insert(4);
    tSetFirst_2.insert(5);

    TSetFirst<int> tSetFirst_3 = tSetFirst_1.subtract(tSetFirst_2);
    assert(tSetFirst_3.size() == 2);
    assert(tSetFirst_3.getElement(0) == 1);
    assert(tSetFirst_3.getElement(1) == 2);

    TSetSecond<int> tSetSecond_1;
    tSetSecond_1.insert(3);
    tSetSecond_1.insert(2);
    tSetSecond_1.insert(1);

    TSetSecond<int> tSetSecond_2;
    tSetSecond_2.insert(3);
    tSetSecond_2.insert(4);
    tSetSecond_2.insert(5);

    TSetSecond<int> tSetSecond_3 = tSetSecond_1.subtract(tSetSecond_2);
    assert(tSetSecond_3.size() == 2);
    assert(tSetSecond_3.getElement(0) == 1);
    assert(tSetSecond_3.getElement(1) == 2);

    TSetSecond<TFrac> tSetSecond_4;
    tSetSecond_4.insert(TFrac(3, 1));
    tSetSecond_4.insert(TFrac(2, 1));
    tSetSecond_4.insert(TFrac(1, 1));

    TSetSecond<TFrac> tSetSecond_5;
    tSetSecond_5.insert(TFrac(3, 1));
    tSetSecond_5.insert(TFrac(4, 1));
    tSetSecond_5.insert(TFrac(5, 1));

    TSetSecond<TFrac> tSetSecond_6 = tSetSecond_4.subtract(tSetSecond_5);
    assert(tSetSecond_6.size() == 2);
    assert(tSetSecond_6.getElement(0) == TFrac(1, 1));
    assert(tSetSecond_6.getElement(1) == TFrac(2, 1));
}

void TSet_test::multiplicationTest() {
    TSetFirst<int> tSetFirst_1;
    tSetFirst_1.insert(1);
    tSetFirst_1.insert(2);
    tSetFirst_1.insert(3);

    TSetFirst<int> tSetFirst_2;
    tSetFirst_2.insert(2);
    tSetFirst_2.insert(3);
    tSetFirst_2.insert(4);

    TSetFirst<int> tSetFirst_3 = tSetFirst_1.intersect(tSetFirst_2);
    assert(tSetFirst_3.size() == 2);
    assert(tSetFirst_3.getElement(0) == 2);
    assert(tSetFirst_3.getElement(1) == 3);

    TSetSecond<int> tSetSecond_1;
    tSetSecond_1.insert(1);
    tSetSecond_1.insert(2);
    tSetSecond_1.insert(3);

    TSetSecond<int> tSetSecond_2;
    tSetSecond_2.insert(2);
    tSetSecond_2.insert(3);
    tSetSecond_2.insert(4);

    TSetSecond<int> tSetSecond_3 = tSetSecond_1.intersect(tSetSecond_2);
    assert(tSetSecond_3.size() == 2);
    assert(tSetSecond_3.getElement(0) == 2);
    assert(tSetSecond_3.getElement(1) == 3);

    TSetSecond<TFrac> tSetSecond_4;
    tSetSecond_4.insert(TFrac(1, 1));
    tSetSecond_4.insert(TFrac(2, 1));
    tSetSecond_4.insert(TFrac(3, 1));

    TSetSecond<TFrac> tSetSecond_5;
    tSetSecond_5.insert(TFrac(2, 1));
    tSetSecond_5.insert(TFrac(3, 1));
    tSetSecond_5.insert(TFrac(4, 1));

    TSetSecond<TFrac> tSetSecond_6 = tSetSecond_4.intersect(tSetSecond_5);
    assert(tSetSecond_6.size() == 2);
    assert(tSetSecond_6.getElement(0) == TFrac(2, 1));
    assert(tSetSecond_6.getElement(1) == TFrac(3, 1));
}
