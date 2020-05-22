/*
Search Engine

Let us see how search engines work. Consider the following simple auto complete feature. When you type some characters in the text bar, the engine automatically gives best matching options among it's database. Your job is simple. Given an incomplete search text, output the best search result.
Each entry in engine's database has a priority factor attached to it. We consider a result / search suggestion best if it has maximum weight and completes the given incomplete search query. For each query in the input, print the maximum weight of the string in the database, that completes the given incomplete search string. In case no such string exists, print -1.
INPUT
First line contains two integers n and q, which represent number of database entries and number of search queries need to be completed. Next n lines contain a string s and an integer weight, which are the database entry and it's corresponding priority.

Next q lines follow, each line having a string t, which needs to be completed.
OUTPUT
Output q lines, each line containing the maximum possible weight of the match for given query, else -1, in case no valid result is obtained.
CONSTRAINTS
1 ≤ n, weight, len(s), len(t) ≤ 10^6
1 ≤ q ≤ 10^5
total length of all strings in database entries ≤ 10^6
total length of all query strings ≤ 10^6
SAMPLE INPUT
2 1
hackerearth 10
hackerrank 9
hacker
SAMPLE OUTPUT
10
*/

#include <iostream>
#include <climits>
#include <cmath>
#include <algorithm>
using namespace std;

struct node{
    node* children[26];
    int weight;
};

node* newNode(){
    node *temp = new node; // ye heap me create hoga so is function ka scope khatam hone ke baad bhi available rahega (you cannot do node temp;)
    for(int i = 0; i < 26; i++){
        temp->children[i] = NULL;
    }
    temp->weight = 0;
    return temp;
}

void insert(node *root, string s, int weight){
    if(s.length() == 0){
        return;
    }
    node *current = root;
    int index = s[0] - 'a';
    if(current->children[index] == NULL){
        current->children[index] = newNode();
    }
        current->weight = max(current->weight, weight);
        insert(current->children[index], s.substr(1), weight);

}

int query(node *root, string s){
    if(s.length() == 0){
        return root->weight;
    }
    node *current = root;
    int index = s[0] - 'a';
    if(current->children[index]){
        return query(current->children[index], s.substr(1));
    }
    else{
        return -1;
    }
}

int main(){
    int m, n;
    cin >> m >> n;
    node *root = newNode();
    while(m--){
        string s;
        int weight;
        cin >> s >> weight;
        insert(root, s, weight);
    }
    while(n--){
        string s;
        cin >> s;
        cout << query(root, s) << endl;
    }
    return 0;
}