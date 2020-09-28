#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cassert>
#include <cstring>
#include "Image.h"
#include "processing.h"
#include "Matrix_test_helpers.h"
#include "Image_test_helpers.h"

using namespace std;

const string OUT_PPM_EXT = ".ppm";

int main(int argc, char *argv[])
{
    if (argc < 4 || argc > 5)
    {
        cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
             << "WIDTH and HEIGHT must be less than or equal to original" << endl;
    }
    Image *img = new Image;
    string ifilename = argv[1];
    string ofilename = argv[2];
    ifstream fin;
    fin.open(ifilename);
    if (!fin.is_open())
    {
        cout << "Unable to open " << ifilename << endl;
        exit(EXIT_FAILURE);
    }
    Image_init(img, fin);

    int new_width = 0, new_height = 0;
    if (argc == 4)
    {
        new_width = (int32_t)argv[3];
        new_height = Image_height(img);
    }
    else
    {
        new_width = (int32_t)argv[3];
        new_height = (int32_t)argv[4];
    }
}