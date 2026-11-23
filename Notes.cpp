// Toggle a binary value (0 or 1):
int num = 0;
int toggledNum = 1 - num;

// ASCII codes: 'A'–'Z' = 65–90; 'a'–'z' = 97–122.
int upperCode = 'A';
int lowerCode = 'a';

// Convert between matching uppercase and lowercase letters.
char upperLetter = 'C'; //upperLetter++ will be 'D'
char lowerLetter = upperLetter + ('a' - 'A');

// For such pattern, cell value can be derived from minimum distance from any edge.
int examplePattern[7][7] = {
    {4, 4, 4, 4, 4, 4, 4},
    {4, 3, 3, 3, 3, 3, 4},
    {4, 3, 2, 2, 2, 3, 4},
    {4, 3, 2, 1, 2, 3, 4},
    {4, 3, 2, 2, 2, 3, 4},
    {4, 3, 3, 3, 3, 3, 4},
    {4, 4, 4, 4, 4, 4, 4}
};


// Total space complexity = input space (space for input data) + auxiliary space (extra space used by the algorithm).
// sum(a, b) uses O(1) input space for two integers and O(1) auxiliary space.
int sum(int a, int b) {
    int c = a + b; // O(1) auxiliary space for variable c
    return a + b;
}

// modulo M
(a + b) % M == ((a % M) + (b % M)) % M
(a - b) % M == ((a % M) - (b % M) + M) % M
(a * b) % M == ((a % M) * (b % M)) % M

// In Time complexity we usually keep the constant multiplied to the highest power of N. 
// Example: O(2N) , O(3N^2) , O(5N^3)


//manual recursive pow function:
//O(log y) Time and O(log y) Space
long long Power(long long x, long long y) {
    if (y == 0)
        return 1;

    long long half = Power(x, y / 2);
    if (y % 2 == 0)
        return half * half;
    return x * half * half;
}

// Including Modular 
long long modPower(long long x, long long y, long long M) {
    if (y == 0)
        return 1 % M;

    x %= M;
    if (x < 0)
        x += M;

    long long half = modPower(x, y / 2, M);
    long long result = (half * half) % M;
    if (y % 2 != 0)
        result = (result * x) % M;
    return result;
}

//inbuilt pow function returns x raised to the power y (Part of STL):
pow(x, y) //O(log y) Time and O(1) Space


//-----------Standard Template Library (STL)--------------
//using namespace std; //std:: is the namespace for STL, it has to be written in the beginning of the code, else we will have to use std:: before every STL function or container. Example: std::vector<int> v; std::cout << "Hello World!";

//-------Containers--------

//----Pair----
pair<int, char> p = make_pair(1, 'h'); 
//or
pair<int, char> p = {1, 'h'};
//accessing pair elements
p.first; 
p.second; 
//p.first and p.second can be any data type, including user-defined types and STL containers. Ex:
pair<int, pair<int, int>> p = {1, {1, 2}};


//----Vector----
vector<int> v; //declaring an empty vector of integers, similarly it can contain any data type, including user-defined types and STL containers. Ex: vector<pair<int, int>> v;
vector<int> v(5); // size 5, all elements initialized to 0
vector<int> v(5, 8); // size 5, all elements initialized to 8
vector<int> v = {1, 2, 3, 4, 5}; // size 5, elements initialized to 1, 2, 3, 4, 5
vector<int> v2 = v; vector<int> v2(v); //copying vector v to vector v2
vector<int> v2(v.begin() + 1, v.end() - 2); //copying elements from vector v to vector v2, starting from the 2nd element of v to the 2nd last element of v
v.size(); //returns the number of elements in the vector
v.push_back(1); //adding an element to the end of the vector
v.insert(v.begin() + 1, 6); //inserting an element 6 at the 2nd position of the vector
v.pop_back(); //removing the last element of the vector
v.erase(v.begin() + 1); //removing the 2nd element of the vector
v.erase(v.begin() + 1, v.end() - 2); //removing elements from the 2nd element to the 2nd last element of the vector
v.clear(); //removing all elements of the vector
v[i]; //accessing the ith element of the vector, 0-based indexing
swap(v, v2); //swapping the elements of vectors of same size and data type

//iterator
vector<int>::iterator it = v.begin(); //declaring an iterator pointing to the beginning(1st element) of the vector
it //is the memory address of the element of the vector.
*it //is the value of the element of the vector
it++; //incrementing the iterator by 1, moving to the next element in the vector
it--; //decrementing the iterator by 1, moving to the previous element in the vector
it += 2; //incrementing the iterator by 2, moving to the element after next in the vector
it = v.end(); //declaring an iterator pointing to the end of the vector (1 past the last element)
//traversing a vector using iterators
for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
{ cout << *it << " "; }

//auto keyword can be used to avoid writing the data type of the iterator, it will automatically deduce the data type of the iterator from the container.
auto it = v.begin();
for (auto it = v.begin(); it != v.end(); it++)

//similarly, we can use iterators for other STL containers like list, set, map, etc.


//----List----
//everything is exactly same as vector, except that list can also insert in front using push_front() and remove from front using pop_front(), 
list <int> l = {6 , 7};
l.push_front(5); // l = {5, 6, 7}
l.pop_front(); // l = {6, 7}
//list is a doubly linked list, so it has O(1) time complexity for insertion and deletion at any position, while vector has O(n) time complexity for insertion and deletion at any position (except at the end). But, list has O(n) time complexity for accessing an element at any position, while vector has O(1) time complexity for accessing an element at any position. So, we should use list when we have to do a lot of insertion and deletion at any position, and we should use vector when we have to do a lot of accessing an element at any position.


//----Stack----
stack<int> s; 
// It is Last In First Out (LIFO) data structure.
// It has O(1) time complexity for push, pop and top operations.
s.push(6); //pushing an element on top of the stack
s.pop(); //removing the top element of the stack
s.top(); //returning the top element of the stack
s.empty(); //returning true if the stack is empty, false otherwise
s.size(); //returning the number of elements in the stack
//traversing a stack using while loop
while (!s.empty()) {
    cout << s.top() << " ";
    s.pop();
}


//----Queue----
queue<int> q;
// It is First In First Out (FIFO) data structure.
// It has O(1) time complexity for push, pop and top operations.
q.push(6); //pushing an element into the queue
q.pop(); //removing the front element of the queue
q.front(); //returning the front element of the queue
q.back(); //returning the back element of the queue
q.empty(); //returning true if the queue is empty, false otherwise
q.size(); //returning the number of elements in the queue
//traversing a queue using while loop
while (!q.empty()) {
    cout << q.front() << " ";
    q.pop();
}


//----Priority Queue----
priority_queue<int> pq;
//Stores the highest element at the top
// It is a Max Heap data structure.
// It has O(log n) time complexity for push and pop operations, and O(1) time complexity for top operation.
pq.push(6); 
pq.push(2);
pq.push(10);
pq.push(8);
//pq.top() will return 10
pq.pop(); //removing the top element of the priority queue
pq.top(); //returning the top element of the priority queue
pq.empty(); //returning true if the priority queue is empty, false otherwise
pq.size(); //returning the number of elements in the priority queue
//traversing a priority queue using while loop
while (!pq.empty()) {
    cout << pq.top() << " ";
    pq.pop();
}

//min Heap priority queue (Store the lowest element at the top)
priority_queue<int, vector<int>, greater<int>> minPq; //here all ints can be replaced with any other datatype.
//here greater<int> is a comparator function that tells the priority queue to store the lowest element at the top. It can be replaced with any other comparator function to change the order of elements in the priority queue. For example:
priority_queue<int, vector<int>, customComparator> customPq; //here customComparator is a user-defined comparator function that tells the priority queue to store the elements in a custom order. It can be used to store the elements in any order we want. For example, we can store the elements in descending order, or we can store the elements in such a way that the element with the highest frequency is at the top, etc.
// customComparator is a function that takes two arguments and returns true if the first argument should be placed before the second argument in the priority queue, and false otherwise. For example, if we want to store the elements in descending order, we can define the customComparator function as follows:
bool customComparator(int a, int b) {   
    return a > b; 
}


//----Set----
set<int> s; //stores unique elements in sorted order
s.insert(6); //inserting an element into the set, log(n) time complexity
s.find(6); //returns an iterator to the element if it is present in the set, otherwise returns s.end(), log(n) time complexity
s.erase(6); //removing an element from the set, log(n) time complexity
auto it = s.find(6); //getting an iterator to the element
if (it != s.end()) {
    cout << *it << " "; //printing the value of the element
}
//erasing a range of elements from the set
s.erase(s.begin(), s.find(6)); //removing all elements from the beginning of the set to the element 6 (not including 6)
s.empty(); //returning true if the set is empty

//lower_bound() and upper_bound() functions in set
auto it1 = s.lower_bound(6); //getting an iterator to the first element that is not less than 6, log(n) time complexity
auto it2 = s.upper_bound(6); //getting an iterator to the first element that is greater than 6, log(n) time complexity


//----Multiset----
multiset<int> ms; //stores all elements in sorted order (duplicates also)
//Example: ms = {1, 2, 2, 4, 4, 4, 5}
ms.find(4); //returns an iterator to the first occurrence of 4 (just after 2) if it is present, otherwise returns ms.end(), time complexity O(log n)
ms.erase(4); //removes all occurrences of 4, time complexity O(log n + count) where count is the number of occurrences of 4
ms.erase(ms.find(4)); //removes only the first occurrence of 4 (just after 2)
ms.count(4); //returns the number of occurrences of 4 in the multiset, time complexity is O(log n + count) 
ms.lower_bound(4); //returns an iterator to the first occurrence of 4 (just after 2), O(log n) TC
ms.upper_bound(4); //returns an iterator to the first element that is greater than 4 (just after the last occurrence of 4), O(log n) TC


//----Unordered Set----
unordered_set<int> us; //stores unique elements in arbitrary order (not sorted)
// all the below operations have average time complexity O(1), worst case O(n)
us.insert(6);  
us.find(6); 
us.erase(6); 


//----Map----
map<int, string> m; //stores key-value pairs in sorted order of keys
m[6] = "six"; 
m.insert({7, "seven"}); 
auto it = m.find(6); //O(log n) TC
(*it).first; //returns the key
(*it).second; //returns the value 
m.lower_bound(6); //returns an iterator to the first element whose key is not less than 6, O(log n) TC
m.upper_bound(6); //returns an iterator to the first element whose key is greater than 6, O(log n) TC
m.erase(6); //removes the key-value pair with key 6


//----Unordered Map----
unordered_map<int, string> um; //stores key-value pairs in arbitrary order (not sorted)
// all the below operations have average time complexity O(1), worst case O(n)
um[6] = "six";  
auto it = um.find(6);
um.erase(6);


//----Multimap----
multimap<int, string> mm; //stores key-value pairs in sorted order of keys (duplicates allowed)
mm.insert({6, "six"});
mm.insert({6, "six again"}); 
mm.insert({6, "six aa"});
//These will be stored in the sorted order of keys, and for the same key, they will be stored in the order of insertion (not sorted by value)
mm = {{6, "six"}, {6, "six again"}, {6, "six aa"}};
//Hence Time Complexity of operations will be similar to Multiset
auto it = mm.equal_range(6); //returns a pair of iterators, the first iterator points to the first occurrence of key 6, and the second iterator points to the element just after the last occurrence of key 6. O(log n) TC


//-------Functions--------


//----Sort----
//sorts the elements in ascending order by default, O(n log n) time complexity
sort(arr, arr + n); //sorting an array in ascending order, n is the size of the array
sort(arr+1, arr+n-2); //sorting a subarray from index 1 to n-3 in ascending order
sort(v.begin(), v.end()); //sorting a vector in ascending order
sort(v.begin(), v.end(), greater<int>()); //sorting a vector in descending order
sort(v.begin(), v.end(), customComparator); //sorting a vector using a custom comparator function   


//----Next Permutation----
//generates the next lexicographically greater permutation of the elements, O(n) time complexity
next_permutation(arr, arr + n); //generates the next permutation of an array
next_permutation(v.begin(), v.end()); //generates the next permutation of a vector
string str = "abc";
do {
    cout << str << endl;
} while (next_permutation(str.begin(), str.end())); //generates all permutations of a string in lexicographical order
//Output: abc, acb, bac, bca, cab, cba


//----Previous Permutation----
string str = "bac";
do {
    cout << str << endl;
} while (prev_permutation(str.begin(), str.end())); //generates all permutations of a string in lexicographical order
//Output: bac, acb, abc