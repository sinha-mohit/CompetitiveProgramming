// program in c++ to use priority_queue with structure 
//Max heap based on height.
#include <iostream> 
#include <queue> 
using namespace std; 

#define ROW 5 
#define COL 2 

struct Person { 

	int age; 

	float height; 

	// this will used to initialize the variables 
	// of the structure 
	Person(int _age, float _height) { 
        age = _age;      //constructor me you never initialize the variables...uppar waale hi variavle use hote hai
        height = _height;
    }
}; 

// this is an strucure which implements the 
// operator overlading 
struct CompareHeight { 
	bool operator()(Person const& p1, Person const& p2) 
	{ 
	// this will return true when second person  
    // has greater height. Suppose we have p1.height=5  
    // and p2.height=5.5 then the object which 
    // have max height will be at the top(or  
    // max priority) 
		return p1.height < p2.height; //maxHeap (baade height ko heap ke top pe rakhoge)
		//return p1.height > p2.height; //minHeap (choote heoght ko heap ke top pe rakhoge)
	} 
}; 


//***********CANNOT DO LIKE THIS HERE****************//

// bool CompareHeight(Person const& p1, Person const& p2) 
// 	{ 
//         // this will return true when second person  
//         // has greater height. Suppose we have p1.height=5  
//         // and p2.height=5.5 then the object which 
//         // have max height will be at the top(or  
//         // max priority) 
// 		return p1.height < p2.height; //maxHeap (baade height ko heap ke top pe rakhoge)
// 		//return p1.height > p2.height; //minHeap (choote heoght ko heap ke top pe rakhoge)
// 	} 



int main() 
{ 
	priority_queue<Person, vector<Person>, CompareHeight> Q; 

	// When we use priority_queue with structure 
	// then we need this kind of syntax where 
	// CompareAge is the functor or comparision function 
	float arr[ROW][COL] = { { 30, 5.5 }, { 25, 5 }, { 20, 6 }, { 33, 6.1 }, { 23, 5.6 } }; 

	for (int i = 0; i < ROW; ++i) { 

		Q.push(Person(arr[i][0], arr[i][1])); 

		// insert an object in priority_queue by using 
		// the Person strucure constructor 
	} 

	while (!Q.empty()) { 
		Person p = Q.top(); 
		Q.pop(); 
		cout << p.age << " " << p.height << "\n"; 
	} 
	return 0; 
} 



/*
Output :
33 6.1
20 6
23 5.6
30 5.5
25 5
*/