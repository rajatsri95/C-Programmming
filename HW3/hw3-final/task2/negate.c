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
	// int* pixels_array = image_pixels(img);
	int width = image_width(img);
   	int height = image_height(img);
	int num_pixels = width*height;

	// Step 2: Negate it
	IMAGE img2 = image_clone(img);
	int* pixels2 = image_pixels(img2);
	int i;
	for (i = 0; i < num_pixels; i++) {
		pixels2[i] = ((pixels2[i] >> 24) << 24) + ((pixels2[i] ^ 0xFFFFFFFF)& 0xFFFFFF ); 

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
	
	if (image_save(img2,strcat(name,"_negation.bmp"))) return -1;
	// Step 4: Finalization
	image_close(img);
	image_close(img2);
	return 0;
}
