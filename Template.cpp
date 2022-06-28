ios_base::sync_with_stdio(false);
cin.tie(NULL);

(a+b)%m = ((a%m) + (b%m)) % m;
(a*b)%m = ((a%m) * (b%m)) % m;
/* <><><><><><><><> Number Theory <><><><><><><><> */
/* ********  Prime numbers  ********* */
#define M 1000000
bool marked[M];
void sieve(int n)
{   for (int i = 2; i * i <= n; i++)
    {
        if (marked[i] == false)   // i is a prime
        {
            for (int j = i * i; j <= n; j += i)
            {
                marked[j] = true;
            }
        }
    }
}
/* ***** Segmented Sieve ****** */
// for segment size we need to find out 32000 first time number
#define Max 32000
#define ll long long int
vector<int>  primes = sieve(Max); // primes contain up 32000 to times numbers
// start segment times using those time s?
void segSieve(ll l, ll r)
{   bool isPrime[r-l+1];
    for(int i = 0; i < r-l+1, i++) isPrime[i] = true;
    if(l == 1) isPrime[0] = false; // 1 not prime
    for(int i = 0; isPrime[i] * isPrime[i] <= r; i++)
    {
        int currentPrime = prime[i];
        ll base = (l / currentPrime) * currentPrime;
        if(base < l) base += currentPrime;
        for(ll j = base; j <= r; j += currentPrime)
        {
            isPrime[j-l] = false;  // cut
        }
        if(base == currentPrime) isPrime[base - l] = true;
    }
    // get all prime Range l to r
    for(int i = 0; i < r - l + 1; i++)
    {
        if(isPrime[i] == true)
            cout << i + l <<  endl;
    }
}
/* *********** Prime Factorization ************* */
int list[128];
int listSize = 0;
vector<int> prime = sieve(sqrt(n) + 1); // contain prime numbers
// sieve() call to generate prime number the go for prime factorization
void primeFactorize(int n)
{   listSize = 0;
    for(int i = 0; prime[i] * prime[i] <= n; i++)
    {
        if(n % prime[i] == 0)
        {
            while(n % prime[i] == 0)
            {
                n /= prime[i];
                list[listSize] = prime[i];
                listSize++;
            }
        }
    }
    if(n > 1)
    {
        list[listSize] = n;
        listSize++;
    }
}
/* ************ SOD => Sum of divisor ************ */
// formula => ( r^(n+1) - 1 ) / (r-1)  => From Prime factoriazation

/*  ************ NOD => Count Number of Divisor ************/
// formula => a^x , b^y => (x+1) * (y+1)
vector<int> primes; // serive(sqrt(n) + 1)we'll preload primes once at the beginning
int cntDivisor(int n)
{   int total = 1; // for SOD
    int divisor = 1; // for NOD
    for(int i = 0; i < primes.size(); i++)
    {
        if(n % primes[i] == 0)
        {
            int cnt = 1;
            while(n % primes[i] == 0)
            {
                n /= primes[i];
                cnt++;
            }
            total *= (pow(prime[i], cnt) - 1) / (primes[i] - 1); // For SOD
            divisor *= cnt; // FOR NOD
        }
    }
    return total; // For SOD
    return divisor; // For NOD
}
/* ****** GCD ************ */
int gcd = __gcd(a,b);

int gcd(int a, int b)
{
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}
/* ******* LCM ***********/
int lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}
/* *********** Find x^n in log n ******** */
int power(int x, unsigned int y)
{   int temp;
    if( y == 0)
        return 1;
    temp = power(x, y / 2);
    if (y % 2 == 0)
        return temp * temp;
    else
        return x * temp * temp;
}
/* *********** Modular Arithmetic *********** */
//(ab) mod p = ( (a mod p) * (b mod p) ) mod p
// To compute x^y under modulo m
int power(int x, unsigned int y, unsigned int m)
{
    if (y == 0)
        return 1;
    int p = power(x, y / 2, m) % m;
    p = (p * p) % m;

    return (y % 2 == 0) ? p : (x * p) % m;
}
/* *********** Modular Inverse of a Number ********* */
// a^-1 how we find out => gcd(a, m) = 1 // power(a, m-2) // call
// Function to find modular inverse of a under modulo m // Assumption: m is prime
void modInverse(int a, int m)
{   int g = __gcd(a, m);
    if (g != 1)
        cout << "Inverse doesn't exist";
    else
    {
        // If a and m are relatively prime, then modulo
        // inverse is a^(m-2) mode m
        cout << "Modular multiplicative inverse is "
             << power(a, m - 2, m);
    }
}
/* ************* Factorial Modulo Mod ********** */
// Returns value of n! % p
int modFact(int n, int p)
{
    if (n >= p)
        return 0;

    int result = 1;
    for (int i = 1; i <= n; i++)
        result = (result * i) % p;

    return result;
}
/* ***************** nCr  and nPr for Queries *********** */
// (n!/(r!*(n-r)!) )
//  (n!*inverse(r!)*inverse((n-r)!) ) mod p
ll p = 1000000007;
ll factorialNumInverse[N + 1]; // array to store inverse of 1 to N
ll naturalNumInverse[N + 1]; // array to precompute inverse of 1! to N!
ll fact[N + 1]; // array to store factorial of first N numbers
// Function to precompute inverse of numbers
void InverseofNumber(ll p)
{
    naturalNumInverse[0] = naturalNumInverse[1] = 1;
    for (int i = 2; i <= N; i++)
        naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
}
// Function to precompute inverse of factorials
void InverseofFactorial(ll p)
{
    factorialNumInverse[0] = factorialNumInverse[1] = 1;
    // precompute inverse of natural numbers
    for (int i = 2; i <= N; i++)
        factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
}
// Function to calculate factorial of 1 to N
void factorial(ll p)
{
    fact[0] = 1;
    // precompute factorials
    for (int i = 1; i <= N; i++)
    {
        fact[i] = (fact[i - 1] * i) % p;
    }
}
// Function to return nCr % p in O(1) time
ll Binomial(ll N, ll R, ll p)
{
    // n C r = n!*inverse(r!)*inverse((n-r)!)
    ll ans = ((fact[N] * factorialNumInverse[R])
              % p * factorialNumInverse[N - R])
             % p;
    return ans;
}
/* <><><><><><><><><><><> Array <><><><><><><><><><><> */
// hash, map, set, stack, priority queue
/* ********* kadane's algorithm => largest sum contiguous subarray ******** */
// [-2, -3, 4, -1, -2, 1, 5, -3]  => [4, -1, -2, 1, 5] => max sum => 7
int maxSubArray(vector<int> &nums)
{   int sum = 0;
    int maxi = INT_MIN;
    for(auto it : nums)
    {
        sum += it;
        maxi = max(sum, maxi);
        if(sum < 0) sum = 0;
    }
    return maxi;
}
/* ***************** Rotated array elements by k ********* */
vector< int > rotated(vector< int > v, int k)
{   vector< int > temp(v.size());
    for(int i = 0; i < v.size(); i++)
    {
        temp[(i+k)%v.size()] = v[i];
    }
    return temp;
}
/* ********** SubArry all print ********* */
void subArray(int arr[], int n)
{   for (int i=0; i <n; i++) // Pick starting point
    {
        for (int j=i; j<n; j++) // Pick ending point
        {
            // Print subarray between current starting and ending points
            for (int k=i; k<=j; k++)
                cout << arr[k] << " ";
            cout << endl;
        }
    }
}
/* *********** Subsequence All print **************** */
void printSubsequences(int arr[], int n)
{
    unsigned int opsize = pow(2, n);/* Number of subsequences is (2**n -1)*/

    /* Run from counter 000..1 to 111..1*/
    for (int counter = 1; counter < opsize; counter++)
    {
        for (int j = 0; j < n; j++)
        {
            /* Check if jth bit in the counter is set
                If set then print jth element from arr[] */
            if (counter & (1<<j))
                cout << arr[j] << " ";
        }
        cout << endl;
    }
}
/* *************** Maximum subarray with sum zero ******** */
int maxLen(int A[], int n)
{
    unordered_map<int,int> mpp;
    int maxi = 0;
    int sum = 0;
    for(int i = 0; i<n; i++)
    {
        sum += A[i];
        if(sum == 0)
            maxi = i + 1;
        else
        {
            if(mpp.find(sum) != mpp.end())
                maxi = max(maxi, i - mpp[sum]);
            else
                mpp[sum] = i;
        }
    }
    return maxi;
}
/* ************** Segment Tree ************ */
// given range query to find out Maximum and Minimum => RMQ  update and query O(log n)
// in return time modification come => not take => return 0, in case max return INT_MIN, in case min return INT_MAX
#define mx 100001
int arr[mx];
int tree[mx*3];
void init(int node, int b, int e)
{
    if(b == e)
    {   tree[node] = arr[b];
        return ;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b+e) / 2;
    init(left, b, mid);
    init(right, mid+1, e);
    tree[node] = tree[left] + tree[right];
}
int query(int node, int b, int e, int i, int j)
{
    if(i > 0 || j < b)
        return 0; // if outside
    if(b >= i && e <= j)
        return tree[node]; // relavent segment
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = query(left, b, mid, i, j);
    int p2 = query(right, mid+1, e, i, j);
    return p1 + p2;
}
void update(int node, int b, int e, int i, int newValue)
{
    if(i > e || i < b)
        return ; // out side range
    if(b >= i && e <= i)
    {
        tree[node] = newValue;
        return;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e)/2;
    update(left, b, mid, i, newValue);
    update(right, mid+1, e, i, mewValue );
    tree[node] = tree[left] + right[right];
}
int main()
{   int n;
    cin >> n;
    for(int i = 0; i< n; i++)
        cin >> arr[i];
    // node and range 1 to n here
    init(1, 1, n);
    // range 3, 5
    cout << query(1, 1, n, 3, 5);
}
/* ************ Fenew Tree BIT ************** */
int arr[10000]; // initially all tree index are zero
int tree[10000]; // one by one element come and affected index updated
int query(int idx)
{   int sum = 0;
    while(idx > 0)
    {
        sum += tree[idx];
        idx -= (idx & -idx); // back side go
    }
    return sum;
}
void update(int idx, int val, int n)
{
    while(idx <= n)
    {
        tree[idx] += val;
        idx += (idx & -idx);  // forward go
    }
}
int main()
{
    for(int i = 1; i<=n; i++)
    {
        cin >> arr[i];
        update(i, arr[i], n);  // this way we generate the BIT tree
    }
    query(r); // l r this way
}
/* <><><><><><><><><><><> String <><><><><><><><><><> */
/*  ********* simple parttern mathcing ********** */
text = ababcdf;
pattern = abc;
function naive_matching(text, pattern)
{
    n = text.size()
        m = pattern.size()
            for(i = 0; i < n; i++)
    {
        for(j = 0; j < m && i + j < n; j++)
        {
            if(text[i + j] != pattern[j])
                break; // mismatch found, break the inner loop
        }
        if(j == m)
        {
            // match found
        }
    }
}
/* ********** Remove all occurences of substring ******** */
string s = "daabcbaabcbc";
string part = "abc";
while(s.length() != 0 && s.find(part) < s.length())
{
    s.erase(s.find(part), part.length());
}
cout << s << endl;
/* **************** KMP algorithm pattern matching *********** */
#define MAX 100000
int failure[MAX];
void build_failure_function(string pattern, int m)
{   failure[0] = 0
    failure[1] = 0; //base case
    for(int i = 2; i <= m; i++)
    {
        int j = failure[i - 1];
        while(true)
        {
            if(pattern[j] == pattern[i - 1])
            {
                failure[i] = j + 1;
                break;
            }
            if(j == 0)
            {
                failure[i] = 0;
                break;
            }
            j = failure[j];
        }
    }
}
bool kmp(string text, string pattern)
{   int n = text.size();
    int m = pattern.size();
    build_failure_function(pattern, m);
    int i = 0;
    int j = 0;
    while(true)
    {
        if(j == n)
            return false;
        if(text[j] == pattern[i])
        {
            i++;
            j++;
            if(i == m)
                return true;
        }
        else
        {
            if (i == 0)
                j++;
            else
                i = failure[i];
        }
    }
    return false;
}
/* <><><><><><><><> Greedy Algorithm <><><><><><><><><> */
/* ************ Fractional Knapsack Problem ****************** */
struct Item
{
    int value;
    int weight;
};
class Solution
{
public:
    bool static comp(Item a, Item b)
    {
        double r1 = (double) a.value / (double) a.weight;
        double r2 = (double) b.value / (double) b.weight;
        return r1 > r2;
    }
    // function to return fractionalweights
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr + n, comp);
        int curWeight = 0;
        double finalvalue = 0.0;
        for (int i = 0; i < n; i++)
        {
            if (curWeight + arr[i].weight <= W)
            {
                curWeight += arr[i].weight;
                finalvalue += arr[i].value;
            }
            else
            {
                int remain = W - curWeight;
                finalvalue += (arr[i].value / (double) arr[i].weight) * (double) remain;
                break;
            }
        }
        return finalvalue;
    }
};
int main()
{
    int n = 3, weight = 50;
    Item arr[n] = { {100,20},{60,10},{120,30} };
    Solution obj;
    double ans = obj.fractionalKnapsack(weight, arr, n);
    cout << "The maximum value is " << setprecision(2) << fixed << ans;
    return 0;
}
/* *************** Find minimum number of coins ******************* */
// in coin prev two sum => 2+5 => 10 not exit the next one  then greed work
// if 5 6 coin there then DP [1, 5, 6, 9] => case 11 => 5+6, (9+1+1) two solve for 11 => DP
int main()
{
    int V = 49;
    vector < int > ans;
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int n = 9;
    for (int i = n - 1; i >= 0; i--)
    {
        while (V >= coins[i])
        {
            V -= coins[i];
            ans.push_back(coins[i]);
        }
    }
    cout<<"The minimum number of coins is "<<ans.size()<<endl;
    cout<<"The coins are "<<endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
/* <><><><><><><><><> Recursion <><><><><><><><><> */
/* ************** Subsequence **************** */
void subsequence(int index, int n, int arr[], vector<int> &sub)
{
    if(index >= n)
    {
        for(auto x : sub)  // print the subsequence
        {
            cout << x << " ";
        }
        cout << endl;
        return ;
    }
    // take of the index
    sub.push_back(arr[index]);
    subsequence(index + 1, n, arr, sub);

    // not take the index
    sub.pop_back();
    subsequence(index + 1, n, arr, sub);
}
int main()
{   int arr[5] = {3, 1, 2};
    vector<int> v;
    subsequence(0, 3, arr, v);
}
/* **************** CombinationSum1 ************ */
void findCombination(int index, int n, int target, int arr[], vector< vector<int> > &ans, vector<int> &sub)
{
    if(index >= n)
    {
        if(target == 0)
        {
            ans.push_back(sub);
        }
        return ;
    }
    // pick up the element
    if(arr[index] <= target)
    {
        sub.push_back(arr[index]);
        // one index take many number of time
        findCombination(index, n, target-arr[index], arr, ans, sub);
        sub.pop_back();
    }
    findCombination(index+1, n, target, arr, ans, sub);
}
int main()
{
    int arr[] = {2, 3, 6, 7};
    vector< vector<int> > ans;
    vector<int> sub;
    int target = 7;
    findCombination(0, 4, target, arr, ans, sub);
}
/* ************* Subset Sums ****************** */
// Given a list of N integers print sums of all subsets in it. output should be printed in increasing order of sums
void findSumSubset(int index, int n, int arr[], vector<int> &sumSubset, int sum)
{
    if(index >= n)
    {
        sumSubset.push_back(sum);
        return;
    }
    // pick the element
    findSumSubset(index+1, n, arr, sumSubset, sum+arr[index]);
    // do not pick the element
    findSumSubset(index+1, n, arr, sumSubset, sum);
}
int main()
{
    int arr[] = {2, 3};
    vector<int> sumSubset;
    findSumSubset(0, 2, arr, sumSubset, 0);
    sort(sumSubset.begin(), sumSubset.end());
}
/* ************* PrintAllPermutationsOfStringOrArray **************** */
int N = 3;
void recurPermute(vector<int> &ds, int arr[], vector< vector<int> > &ans, vector<int> &mark)
{
    if(ds.size() == N)
    {
        ans.push_back(ds);
        return ;
    }
    for(int i = 0; i < N; i++)
    {
        if(mark[i] == 0)
        {
            // pick and mark
            ds.push_back(arr[i]);
            mark[i] = 1;
            recurPermute(ds, arr, ans, mark);
            // not pick and unmark
            mark[i] = 0;
            ds.pop_back();
        }
    }
}
int main()
{
    int arr[] = {1, 2, 3};

    vector< vector<int> > ans;
    vector<int> ds;

    // mark vector
    vector<int> mark(3, 0);

    recurPermute(ds, arr, ans, mark);
}
/* <><><><><><><><><> Stack <><><><><><><><><><><><> */
/* <><><><><><><><><><> Heap <><><><><><><><><><> */
/* <><><><><><><><><> Tree <><><><><><><><><><><><> */
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int d)
        {
            this -> data = d;
            this -> left = NULL;
            this -> right = NULL;
        }
};
Node* buildTree(Node* root)
{
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new Node(data);
    if(data == -1)
    {
        return NULL;
    }
    cout << "Enter data for inserting in left: " << endl;
    root -> left = buildTree(root->left);
    cout << "Enter data for inserting in righ: " << endl;
    root -> right = buildTree(root -> right);

    return root;
}

void levelOrderTraversal(Node* root)
{
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node* temp = q.front();
        cout << temp -> data << " ";
        q.pop();

        if(temp -> left)
        {
            q.push(temp -> left);
        }
        if(temp -> right)
        {
            q.push(temp->right);
        }
    }
}
void Inorder(Node* root)
{
    if(root == NULL)
        return;
    Inorder(root -> left);
    cout << root -> data << " ";
    Inorder(root -> right);
}
void preOrder(Node* root)
{
    if(root == NULL)
        return;
    cout << root -> data << " ";
    preOrder(root -> left);
    preOrder(root -> right);
}
void postOrder(Node* root)
{
    if(root == NULL)
        return;
    postOrder(root -> left);
    postOrder(root -> right);
    cout << root -> data << " ";
}
// build tree by level order traversal
Node* buildFromLevelOrder(Node* root)
{
    queue< Node* > q;
    cout << "Enter data for root: " << endl;
    int data;
    cin>> data;
    root = new Node(data);
    q.push(root);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        cout << "Enter left Node for: " << temp-data << endl;
        int leftData;
        cin >> leftData;
        if(leftData != -1)
        {
            temp -> left = new Node(leftData);
            q.push(temp -> left);
        }
        cout << "Enter right node for: " << root->data << endl;
        int rightData;
        cin >> rightData;
        if(rightData != -1)
        {
            temp -> right = new Node(rightData);
            q.push(temp -> right);
        }

    }
    return root;
}
// ******** inorder count number of leaf node ********* */
void leafNode(Node* root, int &cnt){
    if(root == NULL)
        return ;

    leafNode(root -> left, cnt);

    if(root -> left == NULL && root -> right == NULL)
        cnt++;
    leafNode(root -> right, cnt);
}
int countNumberOfLeafNode(Node* root)
{   int cnt = 0;
    leafNode(root, cnt);
    return cnt;
}
// ******************** hight of binary tree *********
// longest path between root node to leaf node
int height(Node* root)
{
    if(root == NULL)
        return 0;
    int left = height(root -> left);
    int right = height(root -> right);
    int ans = max(left, right) + 1; // lastly root add +1
    return ans;
}
// ********************** Width or  Diameter of Binary Tree ************
// Longest path between to Node basically one two leaf node
 pair<int, int> diameterFast(Node* root)
 { // pair< diameter, height>
     if(root == NULL)
     {
         pair<int, int> p = make_pair(0, 0);
         return p;
     }
     pair<int, int> left = diameterFast(root -> left);
     pair<int, int> right = diameterFast(root -> right);

     int op1 = left.first;
     int op2 = right.first;
     int op3 = left.second + right.second + 1;

     pair<int, int> ans;
     ans.first = max(op1, max(op2, op3));
     ans.second = max(left.second, right.second) + 1;
     return ans;
 }
 int diameter(Node* root)
 {
    return diameterFast(root).first;
 }
 // ************* Check for Balanced Tree **********
pair<bool, int> isBalacedFast(Node* root)
{
    if(root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    pair<bool, int> left = isBalacedFast(root -> left);
    pair<bool, int> right = isBalacedFast(root -> right);

    bool leftAns = left.first;
    bool rightAns = right.first;

    bool dif = abs(left.second - right.second) <= 1;

    pair<bool, int> ans;
    ans.second = max(left.second, right.second) + 1;

    if(leftAns && rightAns && dif)
    {
        ans.first = true;
    }
    else{
        ans.first = false;
    }
    return ans;
}
 int isBalaced(Node* root)
 {
     return isBalacedFast(root).first;
 }
// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 // by recursion we build tree
// 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1 // by build tree using levelOrder
int main()
{
    Node* root = NULL;
    //root = buildTree(root);
    root = buildFromLevelOrder(root);
    levelOrderTraversal(root);
    cout << endl << countNumberOfLeafNode(root) << endl;
    cout << height(root) << endl;
    cout << diameter(root) << endl;
    cout << isBalaced(root) << endl;
}
/* <><><><><><><><><><> Graph <><><><><><><><><><><> */
/* ***************** Graph Representation ********************* */
int main()
{   int n, m;
    cin >> n >> m;
    vector< int > adj[n+1]; // adj list
    int adj[n+1][n+1]; // adj matrix
    for(int i = 0; i < m; i++)
    {   int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
/* ****************** BFS ***************** */
vector< int > bfsOfGraph(int n, vector< int > adj[])
{   vector< int > bfs;
    vector< int > vis(n+1, 0); // visited array initialize with zero

    for(int i = 1; i <= n; i++)
    {   if(vis[i] == 0){
            queue< int > q;
            q.push(i);
            vis[i] = 1;

            while(!q.empty()){
              int node = q.front();
              q.pop();
              bfs.push_back(node); // visited node
              for(auto it : adj[node])
              {
                  if(vis[it] == 0){
                     q.push(it);
                     vis[it] = 1;
                 }
              }
            }
        }
    }
    return bfs;
}
vector< int > bfs = bfsOfGraph(n, adj); // call BFS from main() function

/* ******************** DFS ************************ */
void dfs(int node, vector< int > &vis, vector< int > adj[], vector< int > &dfsStore)
{
    dfsStore.push_back(node);
    vis[node] = 1;
    for(auto it : adj[node])
    {
        if(vis[it] == 0)
        {
            dfs(it, vis, adj, dfsStore);
        }
    }
}
vector< int > dfsOfGraph(int n, vector< int > adj[])
{
    vector< int > dfsStore;
    vector< int > vis(n+1, 0);
    for(int i = 1; i <= n; i++)
    {
        if(vis[i] == 0)
        {
            dfs(i, vis, adj, dfsStore);
        }
    }
    return dfsStore;
}
vector< int > dfs = dfsOfGraph(n, adj);  // call DFS from here

/* ********************* Undirected Graph Cycle Detection BFS **************** */
bool checkForCycle(int s, int n, vector< int > adj[], vector< int > &visited)
{
    queue< pair< int, int >> q;
    visited[s] = 1;
    q.push({s, -1});

    while(!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for(auto it : adj[node])
        {
            if(visited[it] == 0)
            {
                q.push({it, node});
                visited[it] = 1;
            }
            else if(parent != it)
            {
                return true; // cycle in this component
            }
        }
    }
    return false; // no cycle in this component
}
bool isCycle(int n, vector< int > adj[])
{
    vector< int > vis(n+1, 0);
    for(int i = 1; i <= n; i++)
    {
        if(vis[i] == 0)
        {
            if(checkForCycle(i, n, adj, vis) == 1){
                return true; // if any cycle found the then its says total graph has cycle
            }
        }
    }
    return false; // no cycle it this graph
}
cout << "isCycle : " << isCycle(n, adj); // call here from main() function // true or false

/* ******************* Two color or Bipartite Graph BFS *************** */
// even cycle Bipartite Graph  or Odd cycle No Bipartite Graph
bool bipartiteBfs(int s, vector< int > adj[], vector< int > &color)
{
    queue< int > q;
    q.push(s);
    color[s] = 1;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto it : adj[node])
        {
            if(color[it] == -1)
            {
                color[it] = 1 - color[node];
                q.push(it);
            }
            else if(color[it] == color[node]){
                return false;  // adj two nodes have some color not Bipartite graph
            }
        }
    }
    return true; // the components is Bipartite
}
bool checkBipartite(vector< int > adj[], int n)
{
    vector< int > color(n+1);
    for(int i=1;  i<=n; i++) color[i] = -1;

    for(int i = 1; i <= n; i++)
    {
        if(color[i] == -1)
        {
            if(!bipartiteBfs(i, adj, color))
            {// if any node is not bipartite then entire graph is not Bipartite
                return false;
            }
        }
    }
    return true;  // Bipartite Graph return true
}

if(checkBipartite(adj, n)) cout << "YES Bipartite" << endl; // call from main() function

/* ************  Topological sort Directed Graph DAG( directed acyclic graph) ************ */
void findTopoSort(int node, vector<int> &vis, stack<int> &st, vector<int> adj[])
{
    vis[node] = 1;
    for(auto it : adj[node])
    {
        if(vis[it] == 0)
        {
            findTopoSort(it, vis, st, adj);
        }
    }
    st.push(node);
}
vector<int> topoSort(vector<int> adj[], int n)
{
    stack<int> st;
    vector<int> vis(n, 0);
    for(int i = 0; i < n; i++)
    {
        if(vis[i] == 0)
        {
            findTopoSort(i, vis, st, adj);
        }
    }
    // pop out the stack value one by one and push into a vector
    vector<int> topo;
    while( !st.empty() )
    {
        topo.push_back(st.top());
        st.pop();
    }
    return topo; // return the topological sorted value
}

vector<int> v = topoSort(adj, n); // call from main() function

/* **************** (In-Degree)  Cycle Detection Directed BFS ************* */
bool isCyclic(vector<int> adj[], int n)
{
   queue<int> q;
   vector<int> indegree(n, 0);
   for(int i = 0; i < n; i++)
   {
       for(auto it : adj[i])
       {
           indegree[it]++; // In-Degree count
       }
   }
   for(int i = 0; i < n; i++)
   {
       if(indegree[i] == 0)
       {
           q.push(i);
       }
   }
   int cnt = 0;
   while(!q.empty())
   {
       int node = q.front();
       q.pop();
       cnt++;
       for(auto it : adj[node])
       {
           indegree[it]--;
           if(indegree[it] == 0)
           {
               q.push(it);
           }
       }
   }
   if(cnt == n) return false;
   return true;
}

 if(isCyclic(adj, n)) cout << "is it has cycle " << endl; // call from main() function

/* ************** Shortest Path Undirected Graph ************ */
  /*  src => target ... store min distance inside the distance array
    1) take distance array 2) put in infinity 3) initial take zero go
    4) go adj nodes add weight (1) if the added distance smaller then previous then take it in distance array  */
void shortestPathBFS(vector<int> adj[], int n, int src)
{
    int dist[n+1];
    for(int i = 0; i <= n; i++) dist[i] = INT_MAX;
    queue<int> q;
    dist[src] = 0;
    q.push(src);

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto it : adj[node])
        {
            if(dist[node]+1 < dist[it])
            {
                dist[it] = dist[node]+1;
                q.push(it);
            }
        }
    } // dis return or print
    for(int i = 0; i <= n; i++){ // print the distance array dist array contain src to all other node distance....
        cout << dist[i] << " ";
    }
}
shortestPathBFS(adj,  n, 0); // call from main() function

/* ********** Shortest Path in wighted DAG => Directed acyclic Graph *********** */
void findTopoSort(int node, int vis[], stack<int> &st, vector< pair<int,int> > adj[]){
    vis[node] = 1;
    for(auto it : adj[node])
    {
        if(vis[it.first] == 0)
        {
            findTopoSort(it.first, vis, st, adj);
        }
    }
    st.push(node);
}
 void shortestPath(int src, int n, vector< pair<int, int> > adj[])
 {
     int vis[n+1] = {0};  // first step is generate topological sort
     stack<int> st;
     for(int i = 0; i < n; i++)
     {
         if(vis[i] == 0)
         {
             findTopoSort(i, vis, st, adj);
         }
     }
    // second task is call BFS to topological sorted nodes one by one till the stack is not empty
    int dist[n+1];
    for(int i= 0; i < n; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[src] = 0; // start
    while( !st.empty() )
    {
        int node = st.top();
        st.pop();
        //  if the dist [node] == Infinity  then the node not visited yet ..
        // if the node has been reach previously
        if(dist[node] != INT_MAX){
            for(auto it : adj[node])
            {
                if(dist[node] + it.second < dist[it.first])
                {
                    dist[it.first] = dist[node] + it.second;
                }
            }
        }
    }
    for(int i = 0; i < n; i++) // print the distance src to Target node;
    {
        if(dist[i] == INT_MAX)
            cout << "INT" << " ";
        else
            cout << dist[i] << endl;
    }
 }
 int main(){
     int n, m;
     cin >> n >> m;
     vector< pair<int, int> > adj[n+1];
     for(int i = 0; i < m; i++){
         int u, v, wt;
         cin >> u >> v >> wt;
         adj[u].push_back({v, wt});
     }
     shortestPath(0, n, adj); // src 0 start we can given node to as src
 }

/* **************  Dijkstra's Algorithm Find the shortest Path **************** */
int main()
{   int n, m, source;
    cin >> n >> m;
    vector< pair<int, int> > adj[n+1];
    int u, v, wt;

    for(int i = 0; i < m; i++)
    {
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
     cin >> source;
     // Dijkstra's Algorithm begins from here
     priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;  // min-heap; in pair  => (dis, node)

     vector<int> distTo(n+1, INT_MAX);

     distTo[source] = 0;  // First or source;
     pq.push(make_pair(0, source));

    while( !pq.empty())
    {
        int dist = pq.top().first; //int queue =>  pair< dis, node>
        int parentNode = pq.top().second;
        pq.pop();
        for(auto it : adj[parentNode])
        {
            int next = it.first; // adj[] pair( node, weight)
            int nextWeight = it.second;

            if(distTo[next] > distTo[parentNode] + nextWeight)
            {
                distTo[next] = distTo[parentNode] + nextWeight;
                pq.push(make_pair(distTo[next], next));
            }
        }
    }
    cout << "The distances from source" << source << " are: " << endl;
    for(int i = 1; i <= n; i++)
        cout << distTo[i] << " ";
}
/* ****************  MST => Minimum Spanning Tree ************* */
// Take a node and pick minimum weight/distance to go
int main()
{   int n, m;
    cin >> n >> m;
    vector< pair<int, int> > adj[n];
    int u, v, wt;
    for(int i = 0; i < m; i++)
    {
        cin >> u >> v >> wt;  // 0 1
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    int parent[n]; // Prim's algorithm start here
    int key[n];
    bool mstSet[n];

    for(int i=0; i<n; i++)  // array initialize
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
        parent[i] = -1;
    }
    // start node
    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;

    key[0] = 0;
    parent[0] = -1;
    // pq.push( dis, node);
    pq.push({0, 0});
    // spanning tree N - 1 edges
    for(int cnt=0; cnt < n-1; cnt++)
    {
       int node = pq.top().second; // find the minimum distance node to pick
        pq.pop();
        mstSet[node] = true; // the node taken for MST

        for(auto it : adj[node])
        {
            int x = it.first;
            int weight = it.second;
            if(mstSet[x] == false && weight < key[x])
            {
                parent[x] = node;
                key[x] = weight;
                pq.push({key[x], x});
            }
        }
    }
    for(int i = 0; i < n; i++) // printing distance
    {
        cout << parent[i] << " " << i << endl;
    }
}
/* ************** M Coloring problem in graph ************** */
bool isSafe(int node, int color[], bool graph[101][101], int n, int col)
{   for(int k = 0; k < n; k++)
    {
        // none of the adj node has same == col then .. if it is same color then return false
        if(k != node && graph[k][node] == 1 && color[k] == col)
            return false;
    }
    return true;
}
bool solve(int node, int color[], int m, int n, bool graph[101][101])
{
    if(node == n)
    {
        return true;
    }
    //check using M color is possible to color or not
    for(int i = 1; i <= m; i++)
    {
        if( isSafe(node, color, graph, n, i) == 1)
        {
            color[node] = i; // coloring

            if(solve(node+1, color, m, n, graph) == 1) // call with next node
            {
                return true;
            }
            // if not possible to color backtrack and remove previous putting color
            color[node] = 0;
        }
    }
    // after all try it is not possible to color then return false;
    return false;
}
// call form main function
int color[n] = {0};

    if(solve(0, color, m, n, graph) == 1)
    {
        cout << "coloring is possible" << endl;
    }

/* <><><><><><><><><><> DP <><><><><><><><><><><> */
/* ************* 0 / 1 Knapsack problem ************* */
int knapsack(vector<int> wt, vector<int> val, int n, int maxWeight)
{
    vector<int> prev(maxWeight+1, 0), curr(maxWeight+1, 0);
    for(int W = wt[0]; W <= maxWeight; W++)
        prev[W] = val[0];

    for(int ind = 1; ind < n; ind++)
    {
        for(int W = 0; W <= maxWeight; W++)
        {
            int notTake = 0 + prev[W];
            int take = INT_MIN;
            if(wt[ind] <= W)
            {
                take = val[ind] + prev[W - wt[ind]];
            }

            curr[W] = max(take, notTake);
        }
        prev = curr;
    }
    return prev[maxWeight];
}
/* ************* Minimum Coins changes ************************** */
int minimumElements(vector<int> &nums, int target)
{
    int n = nums.size();
    vector < int> prev(target+1, 0), curr(target+1, 0);
    for(int T = 0; T <= target; T++)
    {
        if(T % nums[0] == 0) prev[T] = T / nums[0];
        else prev[T] = 1e9;
    }
    for(int ind = 1; ind < n; ind++)
    {
        for(int T = 0; T <= target; T++)
        {
            int notTake = 0 + prev[T];
            int take = INT_MAX;
            if(nums[ind] <= T)
            {
                take = 1 + curr[T - nums[ind]];
            }
            curr[T] = min(take, notTake);
        }
        prev = curr;
    }

    int ans = prev[target];
    if(ans >= 1e9) return -1;
    return ans;

}

/* ************* Longest common subsequence (LCS) ************* */
/* ***************** Longest increasing common sequence (LICS) ************** */

/* ***************** Longest Increasing Subsequence (LIS) *********** */
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> dp(n, 1), hash(n);
    int maxi = 1;
    int lastIndex = 0;
    for(int i = 0; i < n; i++)
    {
        hash[i] = i;
        for(int prev = 0; prev < i; prev++)
        {
            if(arr[prev] < arr[i] && 1 + dp[prev] > dp[i])
            {
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
        if(dp[i] > maxi)
        {
            maxi = dp[i];
            lastIndex = i;
        }
    } // store the subsequence
    vector<int> temp;
    temp.push_back(arr[lastIndex]);
    while(hash[lastIndex] != lastIndex)
    {
        lastIndex = hash[lastIndex];
        temp.push_back(arr[lastIndex]);
    }
    reverse(temp.begin(), temp.end());
    // print
    for(auto it : temp) cout << it << " ";
    cout << endl;

    return maxi;
}
/* ********* For code print ********* */
#include <stdio.h>
#include<stdlib.h>
int main()
{
    //file pointer
    FILE *fp = NULL;
    int ch = 0;
    //open the file
    fp = fopen(__FILE__, "r");
    if(fp == NULL)
    {
        printf("Error in opening the file\n");
        exit(1);
    }
    do  //read till EOF
    {
        ch = fgetc(fp);
        printf("%c",ch);
    }
    while (ch != EOF);
    //close open file
    fclose (fp);
    return 0;
}
