#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cassert>
#include <cstring>
#include "Image.h"
#include "processing.h"

using namespace std;

const string OUT_PPM_EXT = ".ppm";

int main(int argc, char *argv[])
{
    if (argc < 4 || argc > 5)
    {
        cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
             << "WIDTH and HEIGHT must be less than or equal to original" << endl;
        return 1;
    }
    Image *img = new Image;
    ifstream fin;
    ofstream fout;
    fin.open(argv[1]);
    if (!fin.is_open())
    {
        cout << "Error opneing file: " << argv[1] << endl;
        return 1;
    }
    Image_init(img, fin);
    fin.close();

    int new_width = Image_width(img), new_height = Image_width(img);
    if (argc == 4)
    {
        new_width = stoi(argv[3]);
    }
    else
    {
        new_width = stoi(argv[3]);
        new_height = stoi(argv[4]);
    }

    if (new_width <= 0 || new_width > Image_width(img))
    {
        cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
             << "WIDTH and HEIGHT must be less than or equal to original" << endl;
        return 1;
    }
    if (new_height <= 0 || new_height > Image_height(img))
    {
        cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
             << "WIDTH and HEIGHT must be less than or equal to original" << endl;
        return 1;
    }

    seam_carve(img, new_width, new_height);

    fout.open(argv[2]);
    if (!fout.is_open())
    {
        cout << "Error opneing file: " << argv[1] << endl;
        return 1;
    }

    Image_print(img, fout);
    fout.close();

    delete img;

    return 0;
}