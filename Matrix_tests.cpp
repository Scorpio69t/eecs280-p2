// Project UID af1f95f547e44c8ea88730dfb185559d

#include "Matrix.h"
#include "Matrix_test_helpers.h"
#include "unit_test_framework.h"
#include "iostream"
#include "fstream"
#include "sstream"
#include "string"

using namespace std;

// Here's a free test for you! Model yours after this one.
// Test functions have no interface and thus no RMEs, but
// add a comment like the one here to say what it is testing.
// -----
// Fills a 3x5 Matrix with a value and checks
// that Matrix_at returns that value for each element.
TEST(test_print_basic)
{
  cout << "testing init basic" << endl;
  std::string correct = "2 2\n2 2 \n2 2 \n";
  Matrix *mat = new Matrix;
  Matrix_init(mat, 2, 2);
  Matrix_fill(mat, 2);
  ostringstream out;
  Matrix_print(mat, out);
  ASSERT_EQUAL(correct, out.str());
  delete mat;
}
TEST(test_print_edge)
{
  cout << "testing print edge" << endl;
  std::string correct = "1 1\n1 \n";
  Matrix *mat = new Matrix;
  Matrix_init(mat, 1, 1);
  Matrix_fill(mat, 1);
  ostringstream out;
  Matrix_print(mat, out);
  ASSERT_EQUAL(correct, out.str());
  delete mat;
}

TEST(test_init_basic)
{
  cout << "testing init basic" << endl;
  Matrix *mat = new Matrix;
  const int width = 3;
  const int height = 5;
  Matrix_init(mat, 3, 5);
  ASSERT_EQUAL(width, Matrix_width(mat));
  ASSERT_EQUAL(height, Matrix_height(mat));
  delete mat;
}

TEST(test_init_edge)
{
  cout << "testing init edge" << endl;
  Matrix *mat = new Matrix;
  const int width = 1;
  const int height = 1;
  Matrix_init(mat, 1, 1);
  ASSERT_EQUAL(width, Matrix_width(mat));
  ASSERT_EQUAL(height, Matrix_height(mat));
  delete mat;
}

TEST(test_fill_basic)
{
  cout << "testing fill basic" << endl;
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
  cout << "testing fill edge1" << endl;
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 5;
  const int height = 5;
  const int value = -42;
  Matrix_init(mat, 5, 5);
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
  cout << "testing fill edge2" << endl;
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
  cout << "testing width height basic" << endl;
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
  cout << "testing width height edge" << endl;
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
  cout << "testing at basic" << endl;
  Matrix *mat = new Matrix;
  Matrix_init(mat, 2, 3);
  Matrix_fill(mat, -21);
  ASSERT_EQUAL(*Matrix_at(mat, 0, 0), -21);
  Matrix_fill(mat, 40);
  ASSERT_EQUAL(*Matrix_at(mat, 1, 1), 40);

  const Matrix *m = mat;
  ASSERT_EQUAL(*Matrix_at(m, 0, 0), 40);
  ASSERT_EQUAL(*Matrix_at(mat, 1, 1), 40);
  delete mat;
}
TEST(test_at_edge)
{
  cout << "testing at edge" << endl;
  Matrix *mat = new Matrix;
  Matrix_init(mat, 1, 1);
  Matrix_fill(mat, -21);
  ASSERT_EQUAL(*Matrix_at(mat, 0, 0), -21);
  Matrix_fill(mat, 40);
  ASSERT_EQUAL(*Matrix_at(mat, 0, 0), 40);

  const Matrix *m = mat;
  ASSERT_EQUAL(*Matrix_at(m, 0, 0), 40);
  ASSERT_EQUAL(*Matrix_at(mat, 0, 0), 40);
  delete mat;
}
TEST(test_row_column_basic)
{
  cout << "testing row column basic" << endl;
  Matrix *mat = new Matrix;
  const int value = 21;
  Matrix_init(mat, 2, 3);
  Matrix_fill(mat, value);
  int *location = Matrix_at(mat, 2, 1);
  ASSERT_EQUAL(Matrix_row(mat, location), 2);
  ASSERT_EQUAL(Matrix_column(mat, location), 1);
  location = Matrix_at(mat, 0, 0);
  ASSERT_EQUAL(Matrix_row(mat, location), 0);
  ASSERT_EQUAL(Matrix_column(mat, location), 0);
  delete mat;
}
TEST(test_row_column_edge)
{
  cout << "testing row column edge" << endl;
  Matrix *mat = new Matrix;
  const int value = 21;
  Matrix_init(mat, 1, 1);
  Matrix_fill(mat, value);
  int *location = Matrix_at(mat, 0, 0);
  ASSERT_EQUAL(Matrix_row(mat, location), 0);
  ASSERT_EQUAL(Matrix_column(mat, location), 0);
  delete mat;
}

TEST(test_fill_border_basic)
{
  cout << "testing fill border basic" << endl;
  Matrix *mat = new Matrix;
  const int value = 21;
  Matrix_init(mat, 3, 3);
  Matrix_fill(mat, value);
  Matrix_fill_border(mat, 10);
  ASSERT_EQUAL(*Matrix_at(mat, 0, 0), 10);
  ASSERT_EQUAL(*Matrix_at(mat, 1, 1), 21);
  delete mat;
}
TEST(test_fill_border_edge1)
{
  cout << "testing fill border edge1" << endl;
  Matrix *mat = new Matrix;
  const int value = 21;
  Matrix_init(mat, 1, 1);
  Matrix_fill(mat, value);
  Matrix_fill_border(mat, 10);
  ASSERT_EQUAL(*Matrix_at(mat, 0, 0), 10);

  delete mat;
}
TEST(test_fill_border_edge2)
{
  cout << "testing fill border edge2" << endl;
  Matrix *mat = new Matrix;
  const int value = 21;
  Matrix_init(mat, 500, 500);
  Matrix_fill(mat, value);
  Matrix_fill_border(mat, -10);
  ASSERT_EQUAL(*Matrix_at(mat, 0, 0), -10);
  ASSERT_EQUAL(*Matrix_at(mat, 1, 1), 21);

  delete mat;
}
TEST(test_max_basic)
{
  cout << "testing max basic" << endl;
  Matrix *mat = new Matrix;
  const int value = 21;
  Matrix_init(mat, 3, 3);
  Matrix_fill(mat, value);
  ASSERT_EQUAL(Matrix_max(mat), 21);
  Matrix_fill_border(mat, 10);
  ASSERT_EQUAL(Matrix_max(mat), 21);
  delete mat;
}
TEST(test_max_edge1)
{
  cout << "testing max edge1" << endl;
  Matrix *mat = new Matrix;
  const int value = -21;
  Matrix_init(mat, 500, 500);
  Matrix_fill(mat, value);
  Matrix_fill_border(mat, 10);
  ASSERT_EQUAL(Matrix_max(mat), 10);
  delete mat;
}
TEST(test_max_edge2)
{
  cout << "testing max edge2" << endl;
  Matrix *mat = new Matrix;
  const int value = 21;
  Matrix_init(mat, 1, 1);
  Matrix_fill(mat, value);
  ASSERT_EQUAL(Matrix_max(mat), 21);
  delete mat;
}
TEST(test_min_basic)
{
  cout << "testing min basic" << endl;
  Matrix *mat = new Matrix;
  const int value = 7;
  Matrix_init(mat, 500, 500);
  Matrix_fill(mat, value);
  Matrix_fill_border(mat, 10);
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 0, 0, 2), 0);
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 1, 0, 2), 1);
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 0, 0, 1), 0);
  ASSERT_EQUAL(Matrix_min_value_in_row(mat, 0, 0, 2), 10);
  ASSERT_EQUAL(Matrix_min_value_in_row(mat, 1, 0, 2), 7);
  ASSERT_EQUAL(Matrix_min_value_in_row(mat, 0, 0, 1), 10);
  Matrix_fill_border(mat, -10);
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 0, 0, 2), 0);
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 1, 0, 2), 0);
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 0, 0, 1), 0);
  ASSERT_EQUAL(Matrix_min_value_in_row(mat, 0, 0, 2), -10);
  ASSERT_EQUAL(Matrix_min_value_in_row(mat, 1, 0, 2), -10);
  ASSERT_EQUAL(Matrix_min_value_in_row(mat, 0, 0, 1), -10);
  delete mat;
}
TEST(test_min_edge)
{
  cout << "testing min edge" << endl;
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
