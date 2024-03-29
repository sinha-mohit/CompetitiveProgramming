/*
Help Me Pradyumana!

Pradyumn is tired of using auto - correct feature in his smartphone. He needs to correct his auto - correct more times than the auto - correct corrects him. Pradyumn is thinking to make his own app for mobile which will restrict auto - correct feature, instead it will provide auto - completion. Whenever Pradyumn types factorial, auto - correct changes it to fact. Pradyumn's App will show options such as fact, factorial, factory. Now, he can chose from any of these options. As Pradyumn is busy with his front - end work of his App. He asks you to help him. He said "You will be given set of words(words may repeat too but counted as one only). Now, as user starts the app, he will make queries(in lowercase letters only). So, you have to print all the words of dictionary which have the prefix same as given by user as input. And if no such words are available, add this word to your dictionary." As you know, Pradyumn want this app to be as smart as him :P So, implement a program for him such that he can release it on Fun Store.
INPUT CONSTRAINTS
1≤N≤30000
sum(len(string[i]))≤2∗10^5
1≤Q≤10^3
INPUT FORMAT
Single integer N which denotes the size of words which are input as dictionary
N lines of input, where each line is a string of consisting lowercase letter
Single integer Q which denotes the number of queries.
Q number of lines describing the query string on each line given by user
OUTPUT FORMAT
If auto - completions exists, output all of them in lexicographical order else output "No suggestions" without quotes

NOTE: All strings are lowercase
SAMPLE INPUT
3
fact
factorial
factory
2
fact
pradyumn
SAMPLE OUTPUT
fact
factorial
factory
No suggestions


Second: Strong Test case
input:
3
fact
factorial
factory
7
fac
sinha
mohit
sinhaasd
sinha
s
mohitsinha


Expected Output:
fact
factorial
factory
No suggestions
No suggestions
No suggestions
sinha
sinhaasd
sinha
sinhaasd
No suggestions
*/

#include <iostream>
#include <climits>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

struct node{
    node* children[26];
    int flag;
};

node* newNode(){
    node *temp = new node; // ye heap me create hoga so is function ka scope khatam hone ke baad bhi available rahega (you cannot do node temp;)
    for(int i = 0; i < 26; i++){
        temp->children[i] = NULL;
    }
    temp->flag = 0;
    return temp;
}

void insert(node *root, string s){
    node *current = root;
    if(s.length() == 0){
        current->flag = 1;
        return;
    }
    int index = s[0] - 'a';
    if(current->children[index]){
        insert(current->children[index], s.substr(1));
    }
    else{
        current->children[index] = newNode();
        insert(current->children[index], s.substr(1));
    }

}

void query(node *root, string s, string output, node *head, string original){
    node *current = root;
    if(current->flag == 1 && s.length() == 0){
        cout << output << endl;
        for(int i = 0; i < 26; i++){
            if(current->children[i]){
                query(current->children[i], s, output + (char)(i + 'a'), head, original);
            }
        }
        return;
    }
    
    if(s.length() == 0){
        for(int i = 0; i < 26; i++){
            if(current->children[i]){
                query(current->children[i], s, output + (char)(i + 'a'), head, original);
            }
        }
    }
    else{
        int index = s[0] - 'a';
        if(current->children[index]){
            query(current->children[index], s.substr(1), output + s[0], head, original);
        }
        else{
            cout << "No suggestions" << endl;
            insert(head, original);
            return;
        }
    }
    
}

int main(){
    int n;
    cin >> n;
    node *root = newNode();
    while(n--){
        string s;
        cin >> s;
        insert(root, s);
    }
    int m;
    cin >> m;
    while(m--){
        string s;
        cin >> s;
        query(root, s, "", root, s);
    }
    return 0;
}