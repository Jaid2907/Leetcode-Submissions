class Solution {
public:
    int getMax(int array[], int n) {
  int max = array[0];
  for (int i = 1; i < n; i++)
    if (array[i] > max)
      max = array[i];
  return max;
}
    void countingSort(int array[], int size, int place) {
  const int max = 10;
  int output[size];
  int count[max];

  for (int i = 0; i < max; ++i)
    count[i] = 0;

  // Calculate count of elements
  for (int i = 0; i < size; i++)
    count[(array[i] / place) % 10]++;

  // Calculate cumulative count
  for (int i = 1; i < max; i++)
    count[i] += count[i - 1];

  // Place the elements in sorted order
  for (int i = size - 1; i >= 0; i--) {
    output[count[(array[i] / place) % 10] - 1] = array[i];
    count[(array[i] / place) % 10]--;
  }

  for (int i = 0; i < size; i++)
    array[i] = output[i];
}
    
    void radixsort(int array[], int size) {
  // Get maximum element
  int max = getMax(array, size);

  // Apply counting sort to sort elements based on place value.
  for (int place = 1; max / place > 0; place *= 10)
    countingSort(array, size, place);
}
    int maximumGap(vector<int>& nums) {
        
        if(nums.size()<2)
            return 0;
        int arr[nums.size()];
        int j = 0;
        for(auto it: nums)
        {
            arr[j++] = it;
        }
        radixsort(arr,nums.size());
        int max_diff = INT_MIN;
        
        for(int i=0; i<nums.size()-1; i++)
        {
            max_diff = max(max_diff, arr[i+1] - arr[i]);
            
        }
        
        return max_diff;
    }
};