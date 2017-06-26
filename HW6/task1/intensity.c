#include "../lib/imageio.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc,char * argv[]){
	IMAGE img = image_open(argv[1]);
	if (img == NULL) {
		return -1;
		}

	float m;
	m = atof(argv[2]); 
	IMAGE img2 = image_clone(img);
	int width = image_width(img2);
	int height = image_height(img2);
	int num_pixels = width*height;
	int* pixels = image_pixels(img2);

	int i = 0;
	for (i = 0; i < num_pixels; i++) {
		unsigned char * rgba = (unsigned char*)&(pixels[i]);
		float red = rgba[0];
		float green = rgba[1];
		float blue = rgba[2];
		red = red * (m);
		green = green * (m);
		blue = blue * (m);
		if (red > 255) red = 255;
		if (green > 255) green = 255;
		if (blue > 255) blue = 255;
		rgba[0] = (int) red;
		rgba[1] = (int) green;
		rgba[2] = (int) blue;
	}

	// Step 3: Save to file
	int len = strlen(argv[1]);
	int j;
	char name[len];
	int k = 0;
	int l = 0;
	for (j = len-1; j >= 0; j--) {
		if (argv[1][j] == '/') {
			break;
		}
		if (k) {
			name[l] = argv[1][j];
			l++;
		}
		if (argv[1][j] == '.') {
			k++;				
		}
	}
	int x = 0;
	for (x = 0; x < l/2 ; x++){  
		char temp = name[x];
		name[x] = name[l - x -1];
		name[l - x- 1] = temp;
	}
	
	if (image_save(img2,strcat(name,"_int.jpg"))) 
		return -1;

	image_close(img);
	image_close(img2);

	return 0;
}
