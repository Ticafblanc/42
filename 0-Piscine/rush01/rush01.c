#ifndef TST_SKYSCRAPERETEST_H
#define TST_SKYSCRAPERETEST_H

#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include "../Skyscrapers/skyscrapers.h"

#include <array>

using namespace testing;

TEST(Skyscrapers, easy)
{
    int clues[16] = {2, 2, 1, 3, 2, 2, 3, 1, 1, 2, 2, 3, 3, 2, 1, 3};

    int expectedResult[4][4] = {
        {1, 3, 4, 2}, {4, 2, 1, 3}, {3, 4, 2, 1}, {2, 1, 3, 4}};

    auto result = SolvePuzzle(clues);

    for (int y = 0; y < 4; ++y) {
        for (int x = 0; x < 4; ++x) {
            EXPECT_EQ(result[y][x], expectedResult[y][x]);
        }
    }
}

TEST(Skyscrapers, easy_2)
{
    int clues[16] = {4, 2, 3, 1, 1, 3, 2, 2, 2, 2, 2, 1, 1, 2, 2, 3};

    int expectedResult[4][4] = {
        {1, 3, 2, 4}, {2, 4, 3, 1}, {3, 1, 4, 2}, {4, 2, 1, 3}};

    auto result = SolvePuzzle(clues);

    for (int y = 0; y < 4; ++y) {
        for (int x = 0; x < 4; ++x) {
            EXPECT_EQ(result[y][x], expectedResult[y][x]);
        }
    }
}

TEST(Skyscrapers, hard)
{
    int clues[16] = {0, 0, 1, 2, 0, 2, 0, 0, 0, 3, 0, 0, 0, 1, 0, 0};

    int expectedResult[4][4] = {
        {2, 1, 4, 3}, {3, 4, 1, 2}, {4, 2, 3, 1}, {1, 3, 2, 4}};

    auto result = SolvePuzzle(clues);

    for (int y = 0; y < 4; ++y) {
        for (int x = 0; x < 4; ++x) {
            EXPECT_EQ(result[y][x], expectedResult[y][x]);
        }
    }
}

TEST(Skyscrapers, hard_2)
{
    int clues[16] = {0, 3, 0, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0};

    int expectedResult[4][4] = {
        {1, 2, 3, 4}, {3, 1, 4, 2}, {4, 3, 2, 1}, {2, 4, 1, 3}};

    auto result = SolvePuzzle(clues);

    for (int y = 0; y < 4; ++y) {
        for (int x = 0; x < 4; ++x) {
            EXPECT_EQ(result[y][x], expectedResult[y][x]);
        }
    }
}
