// Leetcoce 643. Maximum Average Subarray I

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;

        // Calculate the sum of the first 'k' elements
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }

        // Set the initial maximum average
        double maxAverage = sum;

        // Slide the window across the array
        for (int i = k; i < nums.size(); i++) {
            sum += nums[i] - nums[i - k];  // Update the sum by adding new element and removing the old one
            maxAverage = max(maxAverage, sum);  // Update the max sum if needed
        }

        // Return the maximum average
        return maxAverage / k;
    }
};

int main() {
    Solution obj1;

    // Input array and window size k
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;  // Example k value

    // Call the function and print the result
    double result = obj1.findMaxAverage(nums, k);
    cout << "Maximum average of subarray of size " << k << " is: " << result << endl;

    return 0;
}
