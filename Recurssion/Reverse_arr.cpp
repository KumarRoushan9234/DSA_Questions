#include <bits/stdc++.h>
using namespace std;
void reverse_recr(int i, vector<int> &nums)
{
  if (i >= nums.size() / 2)
    return;
  swap(nums[i], nums[nums.size() - i - 1]);
  reverse_recr(i + 1, nums);
}
int main()
{
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }
  cout << endl;
  reverse_recr(0, nums);

  for (int i = 0; i < n; i++)
  {
    cout << nums[i] << " ";
  }
  return 0;
}