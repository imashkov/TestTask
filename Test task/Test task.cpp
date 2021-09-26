
#define cimg_use_jpeg
#include "CImg.h"
#include <jpeglib.h>
#include <iostream>

void ChangeBrightness(cimg_library::CImg<float> &image, int modifier) {
    for (int i = 0; i < image.width(); i++) {
        for (int j = 0; j < image.height(); j++) {
            // checks for RGB limits
            if (image(i, j, 0) + modifier >= 255)
                image(i, j, 0) = 255;
            else if (image(i, j, 0) + modifier <= 0)
                image(i, j, 0) = 0;
            else
                image(i, j, 0) = image(i, j, 0) + modifier;
            
            if (image(i, j, 1) + modifier >= 255)
                image(i, j, 1) = 255;
            else if (image(i, j, 1) + modifier <= 0)
                image(i, j, 1) = 0;
            else
                image(i, j, 1) = image(i, j, 1) + modifier;
          
            if (image(i, j, 2) + modifier >= 255)
                image(i, j, 2) = 255;
            else if (image(i, j, 2) + modifier <= 0)
                image(i, j, 2) = 0;
            else
                image(i, j, 2) = image(i, j, 2) + modifier;
        }
    }
}

int main() {
    cimg_library::CImg<float> image("images/image.bmp");
    ChangeBrightness(image, -50);
    image.save("images/result2.bmp");
	return 0;
}



