
void bubble_sort(int array[], int num){
	int i = 0;
	int j = 0;
	for (i = 0; i < num; i++) {
		for (j = 0; j < num-1; j++) {
			if (array[j] > array[j+1]) {
				int temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
}
