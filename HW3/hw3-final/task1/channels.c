// do not modify the line after the line after next
// do not modify the line after next
// do not modify the next line
#include "../lib/imageio.h"
#include <string.h>
int main(int argc, char* argv[])
{
	// TODO
	// Step 1: Load original image
	IMAGE img = image_open(argv[1]);
	if (img == NULL) {
		return -1;
	}
	// Step 2: Separate channels
	// int* pixels_array = image_pixels(img);
	int width = image_width(img);
        int height = image_height(img);
	int num_pixels = width*height;

	IMAGE img_red = image_clone(img);
	int* pixels_red = image_pixels(img_red);
	IMAGE img_green = image_clone(img);
	int* pixels_green = image_pixels(img_green);
	IMAGE img_blue = image_clone(img);
	int* pixels_blue = image_pixels(img_blue);
	
	int i;
	for (i = 0; i < num_pixels; i++)
	{
		pixels_blue[i] = (pixels_blue[i] >> 16) << 16;

		pixels_red[i] = pixels_red[i] - (((pixels_red[i] >> 16) & 0xFF) << 16);
		pixels_red[i] = pixels_red[i] - (((pixels_red[i] >> 8) & 0xFF) << 8);
		
		pixels_green[i] = ((pixels_green[i] >> 24) << 24) + (((pixels_green[i] >> 8) & 0xFF) << 8);
		
		
	}

	// Step 3: Save each channels to three files
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
	char name2[l];
	char name3[l];
	strcpy(name2,name);
	strcpy(name3,name);
	if (image_save(img_red,strcat(name, "_red.jpg")))
		return -1;
	if (image_save(img_green,strcat(name2, "_green.tif")))
		return -1;
	if (image_save(img_blue,strcat(name3,"_blue.bmp")))
		return -1;
	// Step 4: Finalization
	image_close(img);
	image_close(img_red);
	image_close(img_green);
	image_close(img_blue);
	return 0;
}

