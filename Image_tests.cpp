// Project UID af1f95f547e44c8ea88730dfb185559d

#include "Matrix.h"
#include "Image_test_helpers.h"
#include "unit_test_framework.h"
#include <cassert>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Here's a free test for you! Model yours after this one.
// Test functions have no interface and thus no RMEs, but
// add a comment like the one here to say what it is testing.
// -----
// Sets various pixels in a 2x2 Image and checks
// that Image_print produces the correct output.
TEST(test_print_basic)
{
  Image *img = new Image; // create an Image in dynamic memory

  const Pixel red = {255, 0, 0};
  const Pixel green = {0, 255, 0};
  const Pixel blue = {0, 0, 255};
  const Pixel white = {255, 255, 255};

  Image_init(img, 2, 2);
  Image_set_pixel(img, 0, 0, red);
  Image_set_pixel(img, 0, 1, green);
  Image_set_pixel(img, 1, 0, blue);
  Image_set_pixel(img, 1, 1, white);

  // Capture our output
  ostringstream s;
  Image_print(img, s);

  // Correct output
  ostringstream correct;
  correct << "P3\n2 2\n255\n";
  correct << "255 0 0 0 255 0 \n";
  correct << "0 0 255 255 255 255 \n";
  ASSERT_EQUAL(s.str(), correct.str());

  delete img; // delete the Image
}
TEST(test_width_height_basic)
{
  Image *img = new Image;

  Image_init(img, 2, 3);
  ASSERT_EQUAL(Image_width(img), 2);
  ASSERT_EQUAL(Image_height(img), 3);
  delete img;
}
TEST(test_get_pixel_basic)
{
  Image *img = new Image; // create an Image in dynamic memory

  const Pixel red = {255, 0, 0};
  const Pixel green = {0, 255, 0};
  const Pixel blue = {0, 0, 255};
  const Pixel white = {255, 255, 255};

  Image_init(img, 2, 2);
  Image_set_pixel(img, 0, 0, red);
  Image_set_pixel(img, 0, 1, green);
  Image_set_pixel(img, 1, 0, blue);
  Image_set_pixel(img, 1, 1, white);

  ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 0, 1), green));
  ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 1, 1), white));
  delete img;
}
TEST(test_fill_basic)
{
  Image *img = new Image; // create an Image in dynamic memory

  // const Pixel red = {255, 0, 0};
  // const Pixel green = {0, 255, 0};
  const Pixel blue = {0, 0, 255};
  const Pixel white = {255, 255, 255};

  Image_init(img, 2, 2);
  Image_fill(img, white);
  ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 0, 1), white));
  Image_fill(img, blue);
  ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 1, 1), blue));
  delete img;
}

TEST(test_init_from_ppm_basic)
{
  Image *img = new Image;
  ifstream fin;
  fin.open("dog.ppm");
  if (!fin.is_open())
  {
    cout << "Unable to open" << endl;
    exit(EXIT_FAILURE);
  }

  Image_init(img, fin);
  ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 0, 2), {255, 255, 250}));
  delete img;
}
// IMPLEMENT YOUR TEST FUNCTIONS HERE
// You are encouraged to use any functions from Image_test_helpers.h as needed.

// NOTE: The unit test framework tutorial in Lab 2 originally
// had a semicolon after TEST_MAIN(). Although including and
// excluding the semicolon are both correct according to the c++
// standard, the version of g++ we are using reports a warning
// when there is a semicolon. Therefore do NOT add a semicolon
// after TEST_MAIN()
TEST_MAIN() // Do NOT put a semicolon here
