#include <gtest/gtest.h>
#include "../src/plane.hpp"

using namespace plane;

TEST(VectorSuite, ZeroTest) {
    Vector v = Vector::zero();
    EXPECT_EQ(v.x, 0.0);
    EXPECT_EQ(v.y, 0.0);
}

TEST(VectorSuite, EqualityTest) {
    Vector u{1.0, 2.0};
    Vector v{1.0, 2.0 + 1e-10};
    EXPECT_TRUE(u == v);
}

TEST(VectorSuite, AdditionTest) {
    Vector u{1.0, 2.0};
    Vector v{3.0, 4.0};
    Vector res = u + v;
    EXPECT_EQ(res.x, 4.0);
    EXPECT_EQ(res.y, 6.0);
}

TEST(VectorSuite, SubtractionTest) {
    Vector u{5.0, 7.0};
    Vector v{2.0, 3.0};
    Vector res = u - v;
    EXPECT_EQ(res.x, 3.0);
    EXPECT_EQ(res.y, 4.0);
}

TEST(VectorSuite, DotProductTest) {
    Vector u{1.0, 2.0};
    Vector v{3.0, 4.0};
    EXPECT_EQ(u * v, 11.0);
}

TEST(VectorSuite, OrtogonalTest) {
    Vector v{2.0, 3.0};
    Vector ort = v.ortogonal();
    EXPECT_EQ(ort.x, 3.0);
    EXPECT_EQ(ort.y, -2.0);
}

TEST(VectorSuite, IsOrtogonalTest) {
    Vector u{1.0, 0.0};
    Vector v{0.0, 1.0};
    EXPECT_TRUE(u.isOrtogonal(v));
}

TEST(VectorSuite, IsCollinearTest) {
    Vector u{2.0, 4.0};
    Vector v{1.0, 2.0};
    EXPECT_TRUE(u.isCollinear(v));
}

TEST(LineSuite, Construction) {
    Point A{0.0, 0.0};
    Point B{1.0, 1.0};
    Line l(A, B);
    EXPECT_EQ(l.direction.x, 1.0);
    EXPECT_EQ(l.direction.y, 1.0);
}

TEST(LineSuite, IntersectionTest) {
    Line l1(Point{0,0}, Point{1,1});
    Line l2(Point{0,1}, Point{1,0});
    auto result = l1.intersection(l2);
    ASSERT_TRUE(result.has_value());
    EXPECT_TRUE(partial_eq(result->x, 0.5));
    EXPECT_TRUE(partial_eq(result->y, 0.5));
}

TEST(LineSuite, TryIntersectParallelTest) {
    Line l1(Point{0,0}, Point{1,1});
    Line l2(Point{1,0}, Point{2,1});
    EXPECT_FALSE(l1.intersection(l2).has_value());
}

TEST(LineTest, PerpendicularTest) {
    Line l(Point{0,0}, Point{1,0});
    Point p{2,3};
    Line per = l.perpendicular(p);
    EXPECT_TRUE(l.direction.isOrtogonal(per.direction));
}
