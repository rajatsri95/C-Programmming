// Implementation of Selection Sort in Descending order
void select_sort(int a[], int N) {
		
	int i = 0;
	int j = 0;
	int max_ind = 0;
	for (i = 0; i < N-1; i++){
		max_ind = i;
		for (j = i+1; j < N; j++) {
			if (a[j] > a[max_ind]) {
				int temp = a[j];
				a[j] = a[max_ind];
				a[max_ind] = temp;
			}
		}
	}

}

