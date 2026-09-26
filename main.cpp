#include"Image_Class.h"
int main() {
Image image("luffy.jpg") ;
for (int i=0; i<image.width; i++) {
    for (int j=0; j<image.height; j++) {
        for (int k=0; k<3; k++) {
            if (k==0) {image.setPixel(i,j,k,255-image.getPixel(i,j,k));}
            if (k==2) {image.setPixel(i,j,k,255-image.getPixel(i,j,k));}
            }
        }
    }

image.saveImage("luffy2.png");
return 0;
}





