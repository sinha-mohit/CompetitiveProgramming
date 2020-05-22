/*
note: without lazy solve hoga hi nahi
Segment trees are extremely useful. In particular "Lazy Propagation" (i.e. see here, for example) allows one to compute sums over a range in O(lg(n)), and update ranges in O(lg(n)) as well. In this problem you will compute something much harder:
The sum of squares over a range with range updates of 2 types:
1) increment in a range
2) set all numbers the same in a range.
Input
There will be T (T <= 25) test cases in the input file. First line of the input contains two positive integers, N (N <= 100,000) and Q (Q <= 100,000). 
The next line contains N integers, each at most 1000. Each of the next Q lines starts with a number, which indicates the type of operation:

2 st nd -- return the sum of the squares of the numbers with indices in [st, nd] {i.e., from st to nd inclusive} (1 <= st <= nd <= N).

1 st nd x -- add "x" to all numbers with indices in [st, nd] (1 <= st <= nd <= N, and -1,000 <= x <= 1,000).

0 st nd x -- set all numbers with indices in [st, nd] to "x" (1 <= st <= nd <= N, and -1,000 <= x <= 1,000).
Output
For each test case output the “Case <caseno>:” in the first line and from the second line output the sum of squares for each operation of type 2. Intermediate overflow will not occur with proper use of 64-bit signed integer.
Input:
2
4 5
1 2 3 4
2 1 4
0 3 4 1
2 1 4
1 3 4 1
2 1 4
1 1
1
2 1 1
Output:
Case 1:
30
7
13
Case 2:
1
*/

/*
note: without lazy solve hoga hi nahi
Segment trees are extremely useful. In particular "Lazy Propagation" (i.e. see here, for example) allows one to compute sums over a range in O(lg(n)), and update ranges in O(lg(n)) as well. In this problem you will compute something much harder:
The sum of squares over a range with range updates of 2 types:
1) increment in a range
2) set all numbers the same in a range.
Input
There will be T (T <= 25) test cases in the input file. First line of the input contains two positive integers, N (N <= 100,000) and Q (Q <= 100,000). 
The next line contains N integers, each at most 1000. Each of the next Q lines starts with a number, which indicates the type of operation:

2 st nd -- return the sum of the squares of the numbers with indices in [st, nd] {i.e., from st to nd inclusive} (1 <= st <= nd <= N).

1 st nd x -- add "x" to all numbers with indices in [st, nd] (1 <= st <= nd <= N, and -1,000 <= x <= 1,000).

0 st nd x -- set all numbers with indices in [st, nd] to "x" (1 <= st <= nd <= N, and -1,000 <= x <= 1,000).
Output
For each test case output the “Case <caseno>:” in the first line and from the second line output the sum of squares for each operation of type 2. Intermediate overflow will not occur with proper use of 64-bit signed integer.
Input:
2
4 5
1 2 3 4
2 1 4
0 3 4 1
2 1 4
1 3 4 1
2 1 4
1 1
1
2 1 1
Output:
Case 1:
30
7
13
Case 2:
1
*/

#include <iostream>
using namespace std;
struct node{
    int sum;
    int sqSum;
};
struct lazyNode{
    int addValue;
    int setValue;
};
void buildTree(int *arr, node *tree, int start, int end, int treeNode){
    if(start == end){
        tree[treeNode].sqSum = arr[start] * arr[start];
        tree[treeNode].sum = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    buildTree(arr, tree, start, mid, 2 * treeNode);
    buildTree(arr, tree, mid + 1, end, 2 * treeNode + 1);
    tree[treeNode].sqSum = tree[2 * treeNode].sqSum + tree[2 * treeNode + 1].sqSum;
    tree[treeNode].sum = tree[2 * treeNode].sum + tree[2 * treeNode + 1].sum;
    return;
}

void addValue(int *arr, node *tree, int left, int right, int start, int end, int x, int treeNode, lazyNode *lazyArr){
    if(lazyArr[treeNode].addValue != 0){
        int oldSum = tree[treeNode].sum;
        int oldValue = lazyArr[treeNode].addValue;
        tree[treeNode].sum += oldValue * (end - start + 1);
        tree[treeNode].sqSum += (2 * oldSum * oldValue) + (oldValue * oldValue * (end - start +1));
        //if present node has children then
        if(start != end){
            lazyArr[2 * treeNode].addValue += oldValue;
            lazyArr[2 * treeNode + 1].addValue += oldValue;
        }
        lazyArr[treeNode].addValue = 0;
    }
    
    if(lazyArr[treeNode].setValue != 0){
        int oldValue = lazyArr[treeNode].setValue;
        tree[treeNode].sum = oldValue * (end - start + 1);
        tree[treeNode].sqSum = (oldValue * oldValue * (end - start + 1));
        //if present node has children then
        if(start != end){
            lazyArr[2 * treeNode].setValue = oldValue; // if you are setting the value then addvalue should be zero most important step as it gets reset due to setValue
            lazyArr[2 * treeNode].addValue = 0;
            lazyArr[2 * treeNode + 1].setValue = oldValue;
            lazyArr[2 * treeNode + 1].addValue = 0;
        }
        lazyArr[treeNode].setValue = 0;
    }
    
	//completely outside of range
    if (end < left || start > right) {
        return;
    }

    //completely inside the range
    if (start >= left && right >= end) {//////////important step
        int oldSum = tree[treeNode].sum;
        tree[treeNode].sum += x * (end - start + 1);
        tree[treeNode].sqSum += (2 * oldSum * x) + (x * x * (end - start +1));
        if(start != end){
            lazyArr[2 * treeNode].addValue += x;
            lazyArr[2 * treeNode + 1].addValue += x;
        }
        lazyArr[treeNode].addValue = 0;
        return;
    }
    //partially left and right present 
        int mid = (start + end) / 2;
        addValue(arr, tree, left, right, start, mid, x, 2*treeNode, lazyArr);
        addValue(arr, tree, left, right, mid + 1, end, x, 2*treeNode + 1, lazyArr);

        tree[treeNode].sum = tree[2 * treeNode].sum + tree[2 * treeNode + 1].sum;
        tree[treeNode].sqSum = tree[2 * treeNode].sqSum + tree[2 * treeNode + 1].sqSum;
        return;
}

void setValue(int *arr, node *tree, int left, int right, int start, int end, int x, int treeNode, lazyNode *lazyArr){
    if(lazyArr[treeNode].addValue != 0){
        int oldSum = tree[treeNode].sum;
        int oldValue = lazyArr[treeNode].addValue;
        tree[treeNode].sum += oldValue * (end - start + 1);
        tree[treeNode].sqSum += (2 * oldSum * oldValue) + (oldValue * oldValue * (end - start +1));
        //if present node has children then
        if(start != end){
            lazyArr[2 * treeNode].addValue += oldValue;
            lazyArr[2 * treeNode + 1].addValue += oldValue;
        }
        lazyArr[treeNode].addValue = 0;
    }
  
    if(lazyArr[treeNode].setValue != 0){
        int oldValue = lazyArr[treeNode].setValue;
        tree[treeNode].sum = oldValue * (end - start + 1);
        tree[treeNode].sqSum = (oldValue * oldValue * (end - start + 1));
        //if present node has children then
        if(start != end){
            lazyArr[2 * treeNode].setValue = oldValue;
            lazyArr[2 * treeNode].addValue = 0;
            lazyArr[2 * treeNode + 1].setValue = oldValue;
            lazyArr[2 * treeNode + 1].addValue = 0;
        }
        lazyArr[treeNode].setValue = 0;
    }
  	
    //completely outside of range
    if (end < left || start > right) {
        return;
    }
    //completely inside the range
    if (start >= left && right >= end) {//////////important step
        tree[treeNode].sum = x * (end - start + 1);
        tree[treeNode].sqSum = (x * x * (end - start +1));

        if(start != end){
            lazyArr[2 * treeNode].setValue = x;
            lazyArr[2 * treeNode].addValue = 0;
            lazyArr[2 * treeNode + 1].setValue = x;
            lazyArr[2 * treeNode + 1].addValue = 0;
        }
        //lazyArr[treeNode].setValue = 0;
        return;
    }
    //partially left and right present
        int mid = (start + end) / 2;
        setValue(arr, tree, left, right, start, mid, x, 2*treeNode, lazyArr);
        setValue(arr, tree, left, right, mid + 1, end, x, 2*treeNode + 1, lazyArr);
        
        tree[treeNode].sum = tree[2 * treeNode].sum + tree[2 * treeNode + 1].sum;
        tree[treeNode].sqSum = tree[2 * treeNode].sqSum + tree[2 * treeNode + 1].sqSum;
        return;
    
}

node query(int *arr, node *tree, int left, int right, int start, int end, int treeNode, lazyNode *lazyArr){
    if(lazyArr[treeNode].setValue != 0){
        int oldValue = lazyArr[treeNode].setValue;
        tree[treeNode].sum = oldValue * (end - start + 1);
        tree[treeNode].sqSum = (oldValue * oldValue * (end - start +1));
        //if present node has children then
        if(start != end){
            lazyArr[2 * treeNode].setValue = oldValue;
            lazyArr[2 * treeNode].addValue = 0;
            lazyArr[2 * treeNode + 1].setValue = oldValue;
            lazyArr[2 * treeNode + 1].addValue = 0;
        }
        lazyArr[treeNode].setValue = 0;
    }

    if(lazyArr[treeNode].addValue != 0){
        int oldSum = tree[treeNode].sum;
        int oldValue = lazyArr[treeNode].addValue;
        tree[treeNode].sum += oldValue * (end - start + 1);
        tree[treeNode].sqSum += (2 * oldSum * oldValue) + (oldValue * oldValue * (end - start +1));
        //if present node has children then
        if(start != end){
            lazyArr[2 * treeNode].addValue += oldValue;
            lazyArr[2 * treeNode + 1].addValue += oldValue;
        }
        lazyArr[treeNode].addValue = 0;
    }

    int mid = (start + end) / 2;
    //completely outside of range
    if (end < left || start > right) {
        node z;
        z.sqSum = 0;
        z.sum = 0;
        return z;
    }
    //completely inside the range
    else if (start >= left && right >= end) {//////////important step
        return tree[treeNode];
    }
    //partially left and right present 
        node ans1 = query(arr, tree, left, right, start, mid, 2*treeNode, lazyArr);
        node ans2 = query(arr, tree, left, right, mid + 1, end, 2*treeNode + 1, lazyArr);
        node z;
        z.sqSum = ans1.sqSum + ans2.sqSum;
        z.sum = ans1.sum + ans2.sum;
        return z;
    
}
int main(){
    int test;
    cin >> test;
    int c = 1;
    while(test--){
        int n, q;
        cin >> n >> q;
        int *arr = new int[n + 1];
        for(int i = 1; i <= n; i++){
            cin >> arr[i];
        }
        node *tree = new node[4 * n]();
        lazyNode *lazyArr = new lazyNode[4 * n]();
        for(int i = 0; i <4 * n; i++){
            lazyArr[i].addValue = 0;
            lazyArr[i].setValue = 0;
        }
        cout << "Case " << c++ << ":"<< endl;
        buildTree(arr, tree, 1, n, 1);
        while(q--){
            int flag;
            cin >> flag;
            if(flag == 2){
                int left, right;
                cin >> left >> right;
                node z;
                z = query(arr, tree, left, right, 1, n, 1, lazyArr);
                cout << z.sqSum << endl;
            }
            else{
                if(flag == 1){
                    int left, right, value;
                    cin >> left >> right >> value;
                    addValue(arr, tree, left, right, 1, n, value, 1, lazyArr);
                }
                else if(flag == 0){
                    int left, right, value;
                    cin >> left >> right >> value;
                    setValue(arr, tree, left, right, 1, n, value, 1, lazyArr);
                }
            }
        }
        delete[] arr;
        delete[] tree;
        delete[] lazyArr;
    }
    return 0;
}
