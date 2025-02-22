#include <bits/stdc++.h>
using namespace std;

// Recursive function to print all subsequences
void printSubsequences(int index, int k, vector<int> &nums, vector<int> &current, vector<vector<int>> &store)
{
  if (index == nums.size())
  {
    if (!current.empty())
    {
      store.push_back(current);
      int sum = 0;
      for (int num : current)
        sum += num;
      if (sum == k)
      {
        for (int i : current)
        {
          cout << i << " ";
        }
        cout << endl;
      }
    }
    else
      store.push_back(INT_MIN);
    return;
  }

  // Include the current element
  current.push_back(nums[index]);
  printSubsequences(index + 1, k, nums, current, store);

  // Exclude the current element
  current.pop_back();
  printSubsequences(index + 1, k, nums, current, store);
}

// Iterative approach using Bit Manipulation
void printSubsequencesIterative(vector<int> &nums)
{
  int n = nums.size();
  int totalSubsequences = (1 << n); // 2^n

  for (int i = 0; i < totalSubsequences; i++)
  {
    vector<int> subsequence;
    for (int j = 0; j < n; j++)
    {
      if (i & (1 << j)) // If the j-th bit is set, include nums[j]
        subsequence.push_back(nums[j]);
    }
    // Print the subsequence
    for (int num : subsequence)
      cout << num << " ";
    cout << endl;
  }
}

int main()
{
  vector<int> nums;
  int n;
  cout << "Enter number of elements: ";
  cin >> n;
  cout << "Enter elements: ";
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    nums.push_back(x);
  }

  cout << "\nSubsequences using Recursion:\n";
  vector<int> current;
  vector<vector<int>> store;
  int k;
  cout << "Enter k: ";
  cin >> k;
  printSubsequences(0, k, nums, current, store);
  cout << "___________________________________" << endl;

  for (auto row : store)
  {
    for (int i : row)
    {
      cout << i << " ";
    }
    cout << endl;
  }
  cout << "___________________________________" << endl;
  // cout << "\nSubsequences using Bit Manipulation:\n";
  // printSubsequencesIterative(nums);

  return 0;
}
