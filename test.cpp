#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "Rectangle.h"


// TEST_CASE ( "Factorials are computed", "[factorial]") {
//   REQUIRE( Factorial(2) == 2 );
//   REQUIRE( Factorial(3) == 6 );
// }

TEST_CASE ( "Constructor is OK", "[Rectangle]") {
  Point p1, p2;
  p1.x = 0;
  p1.y = 0;
  p2.x = 1;
  p2.y = 1;
  Rectangle myRectangle(p1, p2);
  //reversed space rectangle
  Rectangle myRectangle2(p2, p1);

  REQUIRE(myRectangle.get_p1().x == p1.x);
  REQUIRE(myRectangle.get_p1().y == p1.y);
  REQUIRE(myRectangle.get_p2().x == p2.x);
  REQUIRE(myRectangle.get_p2().y == p2.y);

  //test reversing to negative space
  REQUIRE(myRectangle2.get_p1().x == p1.x);
  REQUIRE(myRectangle2.get_p1().y == p1.y);
  REQUIRE(myRectangle2.get_p2().x == p2.x);
  REQUIRE(myRectangle2.get_p2().y == p2.y);
  
}

TEST_CASE ( "GetWidth is OK", "[GetWidth]") {
  Point p1, p2;
  p1.x = 0;
  p1.y = 0;
  p2.x = 1;
  p2.y = 1;
  Rectangle myRectangle(p1, p2);
  int width = p2.x - p1.x;

  REQUIRE(myRectangle.GetWidth() == width);
  
}

TEST_CASE ( "GetHeight is OK", "[GetHeight]") {
  Point p1, p2;
  p1.x = 0;
  p1.y = 0;
  p2.x = 1;
  p2.y = 1;
  Rectangle myRectangle(p1, p2);
  int height = p2.y - p1.y;

  REQUIRE(myRectangle.GetHeight() == height);
  
}

//Wondering how  much we need to test for this function - 
//do we need to look at only corners overlapping, and different
//sides overlapping?
TEST_CASE ( "Overlaps is OK", "[Overlaps]") {
  Point p1, p2, p3, p4, p5; 
  Point p6, p7, p8, p9 ;

  p1.x = 0;
  p1.y = 0;

  p2.x = 2;
  p2.y = 2;

  p3.x = 3;
  p3.y = 3;

  p4.x = 4;
  p4.y = 4;

  p5.x = 1;
  p5.y = 1;

  p6.x = 1;
  p6.y = 0;

  p7.x = 2;
  p7.y = 1;

  p8.x = 0;
  p8.y = 3;

  p9.x = 1;
  p9.y = 4;

  

  Rectangle r1(p1, p2);
  Rectangle r2(p3, p4);
  Rectangle r3(p1, p5);
  Rectangle r4(p6, p7);
  Rectangle r5(p5,p3);
  Rectangle r6(p8,p9);


  //Complete overlap (same rectangle)
  REQUIRE(r1.Overlaps(r1) == true);
  //Completely separate- no overlap
  REQUIRE(r1.Overlaps(r2) == false);
  //Share the line x = 1, share an edge
  REQUIRE(r3.Overlaps(r4) == true);
  //Partial overlap, no corners shared
  REQUIRE(r1.Overlaps(r5) == true);
  //share corners that aren't p1 or p2
  REQUIRE(r5.Overlaps(r6) == true);
  
}

TEST_CASE ( "CalculateArea is OK", "[CalculateArea]") {
  Point p1, p2, p3;
  p1.x = 0;
  p1.y = 0;
  p2.x = 1;
  p2.y = 1;
  p3.x = 3;
  p3.y = 5;
  Rectangle myRectangle(p1, p2);
  Rectangle r1(p2, p3);
  int height = p2.y - p1.y;
  int width = p2.x - p1.x;
  int area = width * height;

  int height1 = p3.y - p2.y;
  int width1 = p3.x - p2.x;
  int area1 = width1 * height1;

  REQUIRE(myRectangle.CalculateArea() == area);
  REQUIRE(r1.CalculateArea() == area1);
  
}

TEST_CASE ( "Expand is OK", "[Expand]") {
  Point p0, p1, p2, p3;
  p0.x = 0;
  p0.y = 0;
  p1.x = 1;
  p1.y = 1;
  p2.x = 2;
  p2.y = 2;
  p3.x = 3;
  p3.y = 3;
  Rectangle myRectangle(p1, p2);
  Rectangle r1(p0, p3);
  myRectangle.Expand();
  REQUIRE(myRectangle.get_p1().x == p0.x);
  REQUIRE(myRectangle.get_p1().y == p0.y);
  REQUIRE(myRectangle.get_p2().x == p3.x);
  REQUIRE(myRectangle.get_p2().y == p3.y);
}

TEST_CASE ( "Shrink is OK", "[Shrink]") {
  Point p0, p1, p2, p3;
  p0.x = 0;
  p0.y = 0;
  p1.x = 1;
  p1.y = 1;
  p2.x = 2;
  p2.y = 2;
  p3.x = 3;
  p3.y = 3;
  Rectangle r1(p0, p3);
  Rectangle r2(p0,p0);
  r1.Shrink();
  REQUIRE(r1.get_p1().x == p1.x);
  REQUIRE(r1.get_p1().y == p1.y);
  REQUIRE(r1.get_p2().x == p2.x);
  REQUIRE(r1.get_p2().y == p2.y);
  r2.Shrink();
  REQUIRE(r2.get_p1().x == p0.x);
  REQUIRE(r2.get_p1().y == p0.y);
  REQUIRE(r2.get_p2().x == p0.x);
  REQUIRE(r2.get_p2().y == p0.y);

}
