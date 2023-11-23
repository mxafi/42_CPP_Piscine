/*
* This test is for CPP Module 02 exercise 02.
* (A fully functional Fixed number class)
*/

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Fixed.hpp"

TEST_CASE("getting/setting raw bits works") {
  Fixed a;
  Fixed b(a);
  Fixed c;
  c = a;

  REQUIRE(a.getRawBits() == 0);
  REQUIRE(b.getRawBits() == 0);
  REQUIRE(c.getRawBits() == 0);

  SECTION("setting and getting a positive number works") {
    a.setRawBits(3);
    b.setRawBits(4);
    c.setRawBits(5);

    REQUIRE(a.getRawBits() == 3);
    REQUIRE(b.getRawBits() == 4);
    REQUIRE(c.getRawBits() == 5);
  }

  SECTION("setting and getting a negative number works") {
    a.setRawBits(-3);
    b.setRawBits(-4);
    c.setRawBits(-5);

    REQUIRE(a.getRawBits() == -3);
    REQUIRE(b.getRawBits() == -4);
    REQUIRE(c.getRawBits() == -5);
  }
}

TEST_CASE("converting int, float, and insertion overload works") {
  Fixed a;
  Fixed b(int(10));
  Fixed c(42.42f);
  Fixed d(b);
  a = Fixed(1234.4321f);
  Fixed e(2.25f);
  Fixed f(2.75f);
  Fixed g(-3.25f);
  Fixed h(-3.75f);

  SECTION("constructing with ints and floats") {
    REQUIRE(a.getRawBits() == 316015);
    REQUIRE(b.getRawBits() == 2560);
    REQUIRE(c.getRawBits() == 10860);
    REQUIRE(d.getRawBits() == 2560);
  }

  SECTION("converting to float works") {
    REQUIRE(e.toFloat() == 2.25f);
    REQUIRE(f.toFloat() == 2.75f);
    REQUIRE(g.toFloat() == -3.25f);
    REQUIRE(h.toFloat() == -3.75f);
  }

  SECTION("converting to int works") {
    REQUIRE(e.toInt() == 2);
    REQUIRE(f.toInt() == 3);
    REQUIRE(g.toInt() == -3);
    REQUIRE(h.toInt() == -4);
  }

  SECTION("insertion overload works") {
    std::stringstream test_stream;
    test_stream << e;
    test_stream << g;

    REQUIRE(test_stream.str() == "2.25-3.25");
  }
}
