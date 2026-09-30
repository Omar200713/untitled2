#include"Image_Class.h"
#include "string"
#include "iostream"
void invert(Image& image){
for (int i=0; i<image.width; i++) {
    for (int j=0; j<image.height; j++) {
        for (int k=0; k<3; k++) {
            if (k==0) {image.setPixel(i,j,k,255-image.getPixel(i,j,k));}
            if (k==2) {image.setPixel(i,j,k,255-image.getPixel(i,j,k));}
        }
    }
}


}
void brightness(Image& img, const int x) {


    Image image("luffy.jpg") ;
    for (int i=0; i<image.width; i++) {
        for (int j=0; j<image.height; j++) {
            for (int k=0; k<3; k++) {
                int p = static_cast<int>(image.getPixel(i, j, k)) + x;
                if (p>255) p=255;
                else if (p<0) p=0;
                image.setPixel(i,j,k,p);
            }
        }
    }
}

int main() {
    std::string filename;
    std::cout << "Enter image filename: ";
    std::cin >> filename;

    Image image(filename);
    int choice;
    std::cout << "Choose filter (1-Invert, 2-Brightness): ";
    std::cin >> choice;
    if (choice == 1) {
        invert(image);
    }
    else if (choice == 2) {
        int i;
        std::cout << "Enter brightness value: ";
        std::cin >> i;
        brightness(image, i);
    }
    else {
        std::cout << "Invalid choice." << std::endl;
        return 1;
    }


    int newname;
    std::cout << "Save as (1-Same name, 2-New name): ";
    std::cin >> newname;

    std::string outputFilename;

    if (newname == 1) {
        outputFilename = filename; // نفس اسم الصورة الأصلية
    }
    else if (newname == 2) {
        std::cout << "Enter new filename: ";
        std::cin >> outputFilename; // it must be (.jpg, .bmp, etc. , .png)
    }
    else {
        std::cout << "Invalid choice." << std::endl;
        return 1;
    }

    image.saveImage(outputFilename);
    return 0;
}
