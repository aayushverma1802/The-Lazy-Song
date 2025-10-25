class Solution
{
public:
  int numIdenticalPairs (vector < int >&nums)
  {
    int count = 0;
    int i = 0;
    int n = nums.size ();
    int j = nums.size () - 1;
    for (int i = 0; i < nums.size (); i++)
      {
	for (int j = i + 1; j < nums.size (); j++)
	  {
	    if (nums[i] == nums[j])
	      {
		count++;
	      }
	  }

      }


    return count;
  }
};
