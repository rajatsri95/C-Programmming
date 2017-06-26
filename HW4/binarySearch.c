
/* nums is the anomaly sorted array
 * target is the number you want to search in nums
 * len is the length of the array
 * return the index of target if it exists
 * otherwise return -1
 */

int binarySearch(int nums[], int target, int len)
{
    // Breaking into two arrays

    int min1 = 0;
    int min2 = 0;
    int max1 = 0;
    int max2 = 0;
    int mid1 = 0;
    int mid2 = 0;
	int min = 0;
	int max = len-1;
	int mid = 0;
	while(1)
	{
		mid = (min + max)/2;
		if (nums[mid] > nums[mid+1]) {
			min1 = 0;
			max1 = mid;
			min2 = mid+1;
			max2 = len-1;
			break;
		}
		else {
			if (nums[mid] > nums[min]) {
				max = mid;
			}
			else {
				min = mid;
			}
		}	
	}
	
    int index = 0;
    int num_found = 0;
    
    // Look for the number in 1st array
    while (1)
    {
		mid1 = (min1 + max1) / 2;
		if ((target < nums[min1]) || (target > nums[max1]))
		{
			break;
		}
		if (nums[mid1] == target)
		{
			index = mid1;
			num_found = 1;
			break;
		}
		if (nums[mid1] > target)
		{
			max1 = mid1;
		}
		if (nums[mid1] < target)
		{
			min1 = mid1+1;
		}
	}

	// Look for the number in 2nd array
    if (num_found == 0)
    {
		
		while (1)
		{
			if ((target < nums[min2]) || (target > nums[max2]))
			{
				return -1;
			}
			mid2 = (min2 + max2)/2;
			if (nums[mid2] == target)
			{
				index = mid2;
				break;
			}
			if (nums[mid2] > target)
			{
				max2 = mid2;
			}
			if (nums[mid2] < target)
			{
				min2 = mid2+1;
			}
		}
	}

    return index;
}