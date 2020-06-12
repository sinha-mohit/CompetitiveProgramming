/*
https://leetcode.com/problems/search-a-2d-matrix/

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
Example 1:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true
Example 2:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
Output: false
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int x) {
        int r = matrix.size();
        if(r == 0){
            return false;
        }
        int c = matrix[0].size();
        int i, j;
        
        
        //Approach 1:
        //start at top right corner: O(n + m) Solution
        i = 0;
        j = c - 1;
        while(i >= 0 && i < r && j >= 0 && j < c){
            if(matrix[i][j] == x){
                return true;
            }
            else if(x < matrix[i][j]){
                j--;
            }
            else{
                i++;
            }
        }
        return false;
    }
};
        
//Appproach 2:
//start at bottom left corner: O(n + m) Solution
/*
i = r - 1;
j = 0;
while(i >= 0 && i < r && j >= 0 && j < c){
    if(matrix[i][j] == x){
        return true;
    }
    else if(x < matrix[i][j]){
        i--;
    }
    else{
        j++;
    }
}
return false;*/


//Approach 3: O(log(mn))
//Don't treat it as a 2D matrix, just treat it as a sorted list
/*Use binary search.

n * m matrix convert to an array => matrix[x][y] => a[x * m + y]

an array convert to n * m matrix => a[x] =>matrix[x / m][x % m];*/

/*
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int l = 0, r = m * n - 1;
        while (l != r){
            int mid = (l + r - 1) >> 1;
            if (matrix[mid / m][mid % m] < target)
                l = mid + 1;
            else 
                r = mid;
        }
        return matrix[r / m][r % m] == target;
    }
};
    */


//Approach 4:
/*m * n may overflow for large m and n. I think it is better to binary search by row first, then binary            
search by column. The time complexity is the same but this avoids multiplication overflow.
O(log n) + O(log m) = O(log m * n)*/

/*
bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    if (matrix.size() == 0 || matrix[0].size() == 0)
    {
        return false;
    }

    int low;
    int high;

    // first search in first column, use binary search
    for (low = 0, high = matrix.size() - 1; low <= high;)
    {
        int middle = (low + high) / 2;
        if (matrix[middle][0] < target)
        {
            low = middle + 1;
        }
        else if (matrix[middle][0] > target)
        {
            high = middle - 1;
        }
        else
        {
            return true;
        }
    }

    // when above loop ends, search in row[high]
    int row = high;
    if (row >= 0)
    {
        for (low = 0, high = matrix[row].size() - 1; low <= high;)
        {
            int middle = (low + high) / 2;
            if (matrix[row][middle] < target)
            {
                low = middle + 1;
            }
            else if (matrix[row][middle] > target)
            {
                high = middle - 1;
            }
            else
            {
                return true;
            }
        }
    }

    return false;
}
*/
   