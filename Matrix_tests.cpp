// Project UID af1f95f547e44c8ea88730dfb185559d

#include "Matrix.h"
#include "Matrix_test_helpers.h"
#include "unit_test_framework.h"

using namespace std;

// Here's a free test for you! Model yours after this one.
// Test functions have no interface and thus no RMEs, but
// add a comment like the one here to say what it is testing.
// -----
// Fills a 3x5 Matrix with a value and checks
// that Matrix_at returns that value for each element.
TEST(test_fill_basic)
{
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 3;
  const int height = 5;
  const int value = 42;
  Matrix_init(mat, 3, 5);
  Matrix_fill(mat, value);

  for (int r = 0; r < height; ++r)
  {
    for (int c = 0; c < width; ++c)
    {
      ASSERT_EQUAL(*Matrix_at(mat, r, c), value);
    }
  }

  delete mat; // delete the Matrix
}
TEST(test_fill_edge1)
{
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 500;
  const int height = 500;
  const int value = 42;
  Matrix_init(mat, 500, 500);
  Matrix_fill(mat, value);

  for (int r = 0; r < height; ++r)
  {
    for (int c = 0; c < width; ++c)
    {
      ASSERT_EQUAL(*Matrix_at(mat, r, c), value);
    }
  }

  delete mat; // delete the Matrix
}
TEST(test_fill_edge2)
{
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 1;
  const int height = 1;
  const int value = 42;
  Matrix_init(mat, 1, 1);
  Matrix_fill(mat, value);

  for (int r = 0; r < height; ++r)
  {
    for (int c = 0; c < width; ++c)
    {
      ASSERT_EQUAL(*Matrix_at(mat, r, c), value);
    }
  }

  delete mat; // delete the Matrix
}
TEST(test_width_height_print_basic)
{
  Matrix *mat = new Matrix;
  const int width = 5;
  const int height = 7;
  const int value = 2;
  Matrix_init(mat, 5, 7);
  Matrix_fill(mat, value);
  Matrix_print(mat, cout);
  ASSERT_EQUAL(width, Matrix_width(mat));
  ASSERT_EQUAL(height, Matrix_height(mat));
  delete mat;
}
TEST(test_width_height_print_edge)
{
  Matrix *mat = new Matrix;
  const int width = 1;
  const int height = 1;
  const int value = 2;
  Matrix_init(mat, 1, 1);
  Matrix_fill(mat, value);
  Matrix_print(mat, cout);
  ASSERT_EQUAL(width, Matrix_width(mat));
  ASSERT_EQUAL(height, Matrix_height(mat));
  delete mat;
}
TEST(test_at_basic)
{
  Matrix *mat = new Matrix;
  const int value = 21;
  Matrix_init(mat, 2, 3);
  Matrix_fill(mat, value);
  ASSERT_EQUAL(*Matrix_at(mat, 0, 0), 21);
  Matrix_fill(mat, 40);
  ASSERT_EQUAL(*Matrix_at(mat, 1, 1), 40);
  delete mat;

  // const Matrix *mat1 = new Matrix;
  // Matrix_init(mat1, 3, 4);
  // Matrix_fill(mat1, value);
  // ASSERT_EQUAL(*Matrix_at(mat1, 0, 1), 7);
  // ASSERT_EQUAL(*Matrix_at(mat1, 1, 2), 7);
  // Matrix_fill(mat1, 98);
  // const int value = *Matrix_at(mat,1 0, 2);
  // ASSERT_EQUAL(value, 98);
  // delete mat;
}
TEST(test_row_column_basic)
{
  Matrix *mat = new Matrix;
  const int value = 21;
  Matrix_init(mat, 2, 3);
  Matrix_fill(mat, value);
  int *location = Matrix_at(mat, 2, 1);
  ASSERT_EQUAL(Matrix_row(mat, location), 2);
  ASSERT_EQUAL(Matrix_column(mat, location), 1);
  delete mat;
}
TEST(test_fill_border_basic)
{
  Matrix *mat = new Matrix;
  const int value = 21;
  Matrix_init(mat, 3, 3);
  Matrix_fill(mat, value);
  Matrix_fill_border(mat, 10);
  ASSERT_EQUAL(*Matrix_at(mat, 0, 0), 10);
  ASSERT_EQUAL(*Matrix_at(mat, 1, 1), 21);
  delete mat;
}
TEST(test_fill_border_edge)
{
  Matrix *mat = new Matrix;
  const int value = 21;
  Matrix_init(mat, 1, 1);
  Matrix_fill(mat, value);
  Matrix_fill_border(mat, 10);
  ASSERT_EQUAL(*Matrix_at(mat, 0, 0), 10);
  delete mat;
}
TEST(test_max_basic)
{
  Matrix *mat = new Matrix;
  const int value = 21;
  Matrix_init(mat, 3, 3);
  Matrix_fill(mat, value);
  Matrix_fill_border(mat, 10);
  ASSERT_EQUAL(Matrix_max(mat), 21);
  delete mat;
}
TEST(test_max_edge1)
{
  Matrix *mat = new Matrix;
  const int value = 21;
  Matrix_init(mat, 500, 500);
  Matrix_fill(mat, value);
  Matrix_fill_border(mat, 10);
  ASSERT_EQUAL(Matrix_max(mat), 21);
  delete mat;
}
TEST(test_max_edge2)
{
  Matrix *mat = new Matrix;
  const int value = 21;
  Matrix_init(mat, 1, 1);
  Matrix_fill(mat, value);
  ASSERT_EQUAL(Matrix_max(mat), 21);
  delete mat;
}
TEST(test_min_basic)
{
  Matrix *mat = new Matrix;
  const int value = 7;
  Matrix_init(mat, 3, 3);
  Matrix_fill(mat, value);
  Matrix_fill_border(mat, 10);
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 0, 0, 2), 0);
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 1, 0, 2), 1);
  ASSERT_EQUAL(Matrix_min_value_in_row(mat, 0, 0, 2), 10);
  ASSERT_EQUAL(Matrix_min_value_in_row(mat, 1, 0, 2), 7);
  delete mat;
}
TEST(test_min_edge)
{
  Matrix *mat = new Matrix;
  const int value = 7;
  Matrix_init(mat, 1, 1);
  Matrix_fill(mat, value);
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 0, 0, 1), 0);
  ASSERT_EQUAL(Matrix_min_value_in_row(mat, 0, 0, 1), 7);

  delete mat;
}
// ADD YOUR TESTS HERE
// You are encouraged to use any functions from Matrix_test_helpers.h as needed.

// NOTE: The unit test framework tutorial in Lab 2 originally
// had a semicolon after TEST_MAIN(). Although including and
// excluding the semicolon are both correct according to the c++
// standard, the version of g++ we are using reports a warning
// when there is a semicolon. Therefore do NOT add a semicolon
// after TEST_MAIN()
TEST_MAIN() // Do NOT put a semicolon here
