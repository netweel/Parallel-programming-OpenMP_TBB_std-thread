// Copyright 2021 Kiseleva Anastasia
#include <gtest/gtest.h>
#include <omp.h>
#include <time.h>
#include <vector>
#include <complex>
#include "./umnrazr.h"

TEST(CCR_UMN, razm1030x100_100_10000) {
    int na = 1030;
    int ma = 100;
    int nb = 100;
    int mb = 100;
    int nza = 4;
    int nzb = 8;
    ComplexMatr a = rand(na, ma, nza);
    ComplexMatr b = rand(nb, mb, nzb);
    a = transp(a, na, ma);
    int tmp;
    tmp = na;
    na = ma;
    ma = tmp;
    ComplexMatr valA = value(a, na, ma);
    ComplexMatr valB = value(b, nb, mb);
    std::vector<int> rowsA = rows(a, na, ma);
    std::vector<int> rowsB = rows(b, nb, mb);
    std::vector<int> indexA = index(a, na, ma);
    std::vector<int> indexB = index(b, nb, mb);
    tmp = na;
    na = ma;
    ma = tmp;
    clock_t t1 = clock();
    ComplexMatr CCR = umn_posled(valA, valB, rowsA,
        rowsB, indexA, indexB, na, ma, nb, mb);
    clock_t t2 = clock();
    double posled = static_cast<double>(t2 - t1) / CLOCKS_PER_SEC;
    clock_t t11 = clock();
    ComplexMatr umn = umn_parallel_std(valA, valB, rowsA,
       rowsB, indexA, indexB, na, ma, nb, mb);
    clock_t t22 = clock();
    double parallel = static_cast<double>(t22 - t11) / CLOCKS_PER_SEC;
    for (int i = 0; i < na * mb; i++) {
        ASSERT_EQ(CCR[i], umn[i]);
    }
    std::cout << "posled: " << posled << std::endl;
    std::cout << "parallel: " << parallel << std::endl;
}

TEST(CCR_UMN, razm100x100_100x100_4_8) {
    int na = 100;
    int ma = 100;
    int nb = 100;
    int mb = 100;
    int nza = 4;
    int nzb = 8;
    ComplexMatr a = rand(na, ma, nza);
    ComplexMatr b = rand(nb, mb, nzb);
    a = transp(a, na, ma);
    int tmp;
    tmp = na;
    na = ma;
    ma = tmp;
    ComplexMatr valA = value(a, na, ma);
    ComplexMatr valB = value(b, nb, mb);
    std::vector<int> rowsA = rows(a, na, ma);
    std::vector<int> rowsB = rows(b, nb, mb);
    std::vector<int> indexA = index(a, na, ma);
    std::vector<int> indexB = index(b, nb, mb);
    tmp = na;
    na = ma;
    ma = tmp;
    clock_t t1 = clock();
    ComplexMatr CCR = umn_posled(valA, valB, rowsA,
        rowsB, indexA, indexB, na, ma, nb, mb);
    clock_t t2 = clock();
    double posled = static_cast<double>(t2 - t1) / CLOCKS_PER_SEC;
    clock_t t11 = clock();
    ComplexMatr umn = umn_parallel_std(valA, valB, rowsA,
        rowsB, indexA, indexB, na, ma, nb, mb);
    clock_t t22 = clock();
    double parallel = static_cast<double>(t22 - t11) / CLOCKS_PER_SEC;
    for (int i = 0; i < na * mb; i++) {
        ASSERT_EQ(CCR[i], umn[i]);
    }
    std::cout << "posled: " << posled << std::endl;
    std::cout << "parallel: " << parallel << std::endl;
}

TEST(CCR_UMN, razm113x85_85x21_7_1) {
    int na = 113;
    int ma = 85;
    int nb = 85;
    int mb = 21;
    int nza = 7;
    int nzb = 1;
    ComplexMatr a = rand(na, ma, nza);
    ComplexMatr b = rand(nb, mb, nzb);
    a = transp(a, na, ma);
    int tmp;
    tmp = na;
    na = ma;
    ma = tmp;
    ComplexMatr valA = value(a, na, ma);
    ComplexMatr valB = value(b, nb, mb);
    std::vector<int> rowsA = rows(a, na, ma);
    std::vector<int> rowsB = rows(b, nb, mb);
    std::vector<int> indexA = index(a, na, ma);
    std::vector<int> indexB = index(b, nb, mb);
    tmp = na;
    na = ma;
    ma = tmp;
    clock_t t1 = clock();
    ComplexMatr CCR = umn_posled(valA, valB, rowsA,
        rowsB, indexA, indexB, na, ma, nb, mb);
    clock_t t2 = clock();
    double posled = static_cast<double>(t2 - t1) / CLOCKS_PER_SEC;
    clock_t t11 = clock();
    ComplexMatr umn = umn_parallel_std(valA, valB, rowsA,
        rowsB, indexA, indexB, na, ma, nb, mb);
    clock_t t22 = clock();
    double parallel = static_cast<double>(t22 - t11) / CLOCKS_PER_SEC;
    for (int i = 0; i < na * mb; i++) {
        ASSERT_EQ(CCR[i], umn[i]);
    }
    std::cout << "posled: " << posled << std::endl;
    std::cout << "parallel: " << parallel << std::endl;
}

TEST(CCR_UMN, razm25000x10000_10000x25000_110_80) {
    int na = 25000;
    int ma = 10000;
    int nb = 10000;
    int mb = 25000;
    int nza = 1100;
    int nzb = 800;
    ComplexMatr a = rand(na, ma, nza);
    ComplexMatr b = rand(nb, mb, nzb);
    a = transp(a, na, ma);
    int tmp;
    tmp = na;
    na = ma;
    ma = tmp;
    ComplexMatr valA = value(a, na, ma);
    ComplexMatr valB = value(b, nb, mb);
    std::vector<int> rowsA = rows(a, na, ma);
    std::vector<int> rowsB = rows(b, nb, mb);
    std::vector<int> indexA = index(a, na, ma);
    std::vector<int> indexB = index(b, nb, mb);
    tmp = na;
    na = ma;
    ma = tmp;
    clock_t t1 = clock();
    ComplexMatr CCR = umn_posled(valA, valB, rowsA,
        rowsB, indexA, indexB, na, ma, nb, mb);
    clock_t t2 = clock();
    double posled = static_cast<double>(t2 - t1) / CLOCKS_PER_SEC;
    clock_t t11 = clock();
    ComplexMatr umn = umn_parallel_std(valA, valB, rowsA,
        rowsB, indexA, indexB, na, ma, nb, mb);
    clock_t t22 = clock();
    double parallel = static_cast<double>(t22 - t11) / CLOCKS_PER_SEC;
    for (int i = 0; i < na * mb; i++) {
        ASSERT_EQ(CCR[i], umn[i]);
    }
    std::cout << "posled: " << posled << std::endl;
    std::cout << "parallel: " << parallel << std::endl;
}

TEST(CCR_UMN, razm10000x10000_10000x10000_10_8) {
    int na = 10000;
    int ma = 10000;
    int nb = 10000;
    int mb = 10000;
    int nza = 100;
    int nzb = 8;
    ComplexMatr a = rand(na, ma, nza);
    ComplexMatr b = rand(nb, mb, nzb);
    a = transp(a, na, ma);
    int tmp;
    tmp = na;
    na = ma;
    ma = tmp;
    ComplexMatr valA = value(a, na, ma);
    ComplexMatr valB = value(b, nb, mb);
    std::vector<int> rowsA = rows(a, na, ma);
    std::vector<int> rowsB = rows(b, nb, mb);
    std::vector<int> indexA = index(a, na, ma);
    std::vector<int> indexB = index(b, nb, mb);
    tmp = na;
    na = ma;
    ma = tmp;
    clock_t t1 = clock();
    ComplexMatr CCR = umn_posled(valA, valB, rowsA,
        rowsB, indexA, indexB, na, ma, nb, mb);
    clock_t t2 = clock();
    double posled = static_cast<double>(t2 - t1) / CLOCKS_PER_SEC;
    clock_t t11 = clock();
    ComplexMatr umn = umn_parallel_std(valA, valB, rowsA,
        rowsB, indexA, indexB, na, ma, nb, mb);
    clock_t t22 = clock();
    double parallel = static_cast<double>(t22 - t11) / CLOCKS_PER_SEC;
    for (int i = 0; i < na * mb; i++) {
        ASSERT_EQ(CCR[i], umn[i]);
    }
    std::cout << "posled: " << posled << std::endl;
    std::cout << "parallel: " << parallel << std::endl;
}

TEST(CCR_UMN, razm1000x500_500x200_10_0) {
    int na = 1000;
    int ma = 500;
    int nb = 500;
    int mb = 200;
    int nza = 10;
    int nzb = 0;
    ComplexMatr a = rand(na, ma, nza);
    ComplexMatr b = rand(nb, mb, nzb);
    a = transp(a, na, ma);
    int tmp;
    tmp = na;
    na = ma;
    ma = tmp;
    ComplexMatr valA = value(a, na, ma);
    ComplexMatr valB = value(b, nb, mb);
    std::vector<int> rowsA = rows(a, na, ma);
    std::vector<int> rowsB = rows(b, nb, mb);
    std::vector<int> indexA = index(a, na, ma);
    std::vector<int> indexB = index(b, nb, mb);
    tmp = na;
    na = ma;
    ma = tmp;
    clock_t t1 = clock();
    ComplexMatr CCR = umn_posled(valA, valB, rowsA,
        rowsB, indexA, indexB, na, ma, nb, mb);
    clock_t t2 = clock();
    double posled = static_cast<double>(t2 - t1) / CLOCKS_PER_SEC;
    clock_t t11 = clock();
    ComplexMatr umn = umn_parallel_std(valA, valB, rowsA,
        rowsB, indexA, indexB, na, ma, nb, mb);
    clock_t t22 = clock();
    double parallel = static_cast<double>(t22 - t11) / CLOCKS_PER_SEC;
    for (int i = 0; i < na * mb; i++) {
        ASSERT_EQ(CCR[i], umn[i]);
    }
    std::cout << "posled: " << posled << std::endl;
    std::cout << "parallel: " << parallel << std::endl;
}
