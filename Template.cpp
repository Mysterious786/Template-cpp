#include<bits/stdc++.h>
 
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
//using namespace boost::multiprecision;
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
 
//--------------------------------* TYPES----------------------------------------------------*/
 
#define ll long long
#define ld long  double
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define vii vector<pair<ll,ll>>
#define F first
#define S second
//------------------------------* FUNCTIONS *-----------------------------------------------/
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define pb push_back
#define eb emplace_back
#define sza(x) ((ll)x.size())
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(),(a).rend()
 
 
 
const int MAX_N = 1e5 + 5;
const ll MOD2 = 998244353;
const ll MOD = 1e9+7;
const ll INF = 1e9;
const ld EPS = 1e-9;
#define PI 3.1415926535897932384626433832795
 
 
//-----------------------------Code----------------------------------------------------------
 
ll min(ll a,int b) { if (a<b) return a; return b; }
ll min(int a,ll b) { if (a<b) return a; return b; }
ll max(ll a,int b) { if (a>b) return a; return b; }
ll max(int a,ll b) { if (a>b) return a; return b; }
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
 
 
//----------------------------Print-----------------------------------------------------------
 
 
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }
 
 
//----------------------------Loops-----------------------------------------------------------
 
#define printv(a) {for(auto u:a) cout<<u<<" "; cout<<endl;}
#define printm(a) {for(auto u:a) cout<<u.f sp u.s<<endl;}
#define forn(i,n) for(auto i=0; i<n; i++)
#define fort(i,n) for(auto i=0; i<=n; i++)
#define forbn(i,n) for(auto i=n-1; i>=0; i--)
#define test int tc; cin>>tc; while(tc--)
 
 
 
//----------------------------Speed-----------------------------------------------------------
 
 
 
#define op() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
//---------------------------Prime Sieve------------------------------------------------------
 
vector<bool> is_prime;
void sieve(ll n){
 
is_prime.resize(n+1, true);
is_prime[0] = is_prime[1] = false;
for (int i = 2; i <= n; i++) {
    if (is_prime[i] && (long long)i * i <= n) {
        for (int j = i * i; j <= n; j += i)
            is_prime[j] = false;
    }
}
 
}
 
//----------------------------Count Factors---------------------------------------------------
 
int countFactors(int n) {
    int count = 0;
    
    for (int i = 1; i * i <= n; i++) {
 
        if(count>3) return 0;
        if (n % i == 0) {
           
            count++;
 
          
            if (i != n / i) {
                count++;
            }
        }
    }
 
    return count;
}
//----------------------------Modular Exponential----------------------------------------------------------
 
ll modularExponentiation(ll base, ll exponent, ll modulus) {
    ll result = 1;
    base = base % modulus;
    while (exponent > 0) {
        if (exponent & 1) {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent >>= 1;
    }
    return result;
}
//-----------------------------------------DSU Pairs----------------------------------------
ll find_set(ll x,vii& parent){
    if(parent[x].F==x){
        return x;
    }
    return parent[x].F = find_set(parent[x].F,parent);
}
 
void union_set(ll x,ll y,vii& parent){
    ll xroot = find_set(x,parent);
    ll yroot = find_set(y,parent);
    if(xroot==yroot){
        return;
    }
    if(parent[xroot].S>parent[yroot].S){
        parent[yroot].F = xroot;
    }
    else if(parent[yroot].S>parent[xroot].S){
        parent[xroot].F = yroot;
    }
    else{
        parent[xroot].S++;
        parent[yroot].F = xroot;
    }
}
//------------------------------------------------------Solve-----------------------------------
vector<vll> adj;
vll vis;
vll ans;
void dfs(ll node){
    vis[node] =1;
    ans.push_back(node);
    for(auto it : adj[node]){
 
        if(!vis[it])
        dfs(it);
 
    }
}
vll v;
void cal (){
ll MAXI = 200002;
 v.resize(MAXI,0);
for(int i=1;i<MAXI;i++){
    ll num =i;
    ll sum =0;
    while(num>0){
        sum+=num%10;
        num/=10;
    }
    v[i] = v[i-1] + sum;
 
 
}
 
}
 
//----------------------------Count_Prime_Divisors----------------------------------------------------------
int countPrimeDivisors(int n) {
    int count = 0;
    // Iterate from 2 to sqrt(n)
    for (int i = 2; i * i <= n; i++) {
        // Check if i is a divisor of n
        if (n % i == 0) {
            // Increment count if i is prime
            while (n % i == 0) {
                n /= i;
            }
            count++;
        }
    }
    // If n is greater than 1, it is also a prime divisor
    if (n > 1) {
        count++;
    }
    return count;
}

//------------------------------------Kadane_Algo------------------------------
  ll kadanesAlgo(vector<ll>& a){
        ll g_maxi=-1e9+7;
        ll l_maxi=-1e9+7;
        for(int i=0;i<a.size();i++){
            l_maxi=max((ll)a[i],l_maxi+(ll)a[i]);
            g_maxi=max(g_maxi,l_maxi);
        }
        return g_maxi;
    }
//------------------------------------Sieve_of_Eras----------------------------
vector<bool> isprime;
 void sieve(){
    ll n = 1e6+1;
    isprime[0] = isprime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (isprime[i] && (long long)i * i <= n) {
            for (int j = i * i; j <= n; j += i)
                isprime[j] = false;
        }
    }
}
//------------------------------------Useful STL-------------------------------
/*
---------Array Movement-----

vll dx={0,0,-1,1};
vll dy={1,-1,0,0};

---------Tuple--------------

tuple<ll,ll,ll> t;
make_tuple(x1,x2,x3);
get<0>(t);

---------Dequeue------------

dequeue<int> dq;
dq.push_back();
dq.push_front();
.size(), .max_size();
.front(), .at(pos), .back();
.pop_front(), .pop_back();
dequeue<int>::iterator it;
for (it = g.begin(); it != g.end(); ++it)
        cout << '\t' << *it;
 
----------Set---------------

syntax: set<object_type> variable_name;
.insert(val)
.begin() ----> iterator to the first element
.end() -----> iterator to the theoratical element after last element
.count(x) --> return true if x count>0
.clear() --> deletes all element
.erase() ---> deletes a single element
.size(), .empty()

--------Multiset------------

T.C ===> O(log(n))

multiset<int, greater<int> > gquiz1;
multiset<int> gquiz1;
begin() – Returns an iterator to the first element in the multiset –>  O(1)
end() – Returns an iterator to the theoretical element that follows the last element in the multiset –> O(1)
size() – Returns the number of elements in the multiset –> O(1)
max_size() – Returns the maximum number of elements that the multiset can hold –> O(1)
empty() – Returns whether the multiset is empty –> O(1)
insert (x) – Inserts the element x in the multiset –> O(log n)
clear () – Removes all the elements from the multiset –> O(n)
erase(x) – Removes all the occurrences of x –> O(log n)
.lower_bound(val), .upper_bound(val);

--------------Bitset----------

bitset<size> variable_name(initialization);

// C++ program to demonstrate the bitset 
#include <bitset>
#include <iostream>

using namespace std;

int main()
{
    // declaring an uninitialized bitset object
    bitset<8> uninitializedBitset;

    // initialization with decimal number
    bitset<8> decimalBitset(15);

    // initialization with binary string
    bitset<8> stringBitset(string("1111"));

    cout << "Uninitialized bitset: " << uninitializedBitset
         << endl;
    cout << "Initialized with decimal: " << decimalBitset
         << endl;
    cout << "Initialized with string: " << stringBitset
         << endl;

    return 0;
}


-----------------Custom_Sort--------------

// to be included....


----------------------The End of STL------

*/




//-----------------------------------------------------------------------------
/*
Always think What matters for you before Leaving
You have a dream this is the last chance you have 
put every effort that you can Inorder to make yourself feel yeah I did it
Let Allah decide what your effort present you as a reward
 
Dont Loose Hope
Stay Hungry....
Stay Calm...
Be patience...
 
 
*/
 
//-------------------------------------------Solve---------------------------- 
 
void solve() 
 
{


}
 
 
 
 
int main() {
    ll t;
    t=1;
    cin >> t;
    while (t--) solve();
    return 0;
}
