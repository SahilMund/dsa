
/******************************************
* AUTHOR : Abhishek Naidu *
* NICK : abhisheknaiidu *
******************************************/

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define all(n)          n.begin(),n.end()
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define f               first
#define s               second
#define int             long long int
#define pb              push_back
#define mp              make_pair
#define inf             1e18
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;


void abhisheknaiidu()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

// If it returns true, then we can say that any no. ppl can
// read this num of pages => max of min pages,
// but we need to find min of max pages, so will do binary search again!
bool check( vector <int> &a, int n, int ppl, int min_num) {
	// First distributing books to 1st person
	int student = 1, min = 0 ;


	for (int i = 0; i < n; ++i)
	{
		if ( a[i] + min >= min_num) {

			student++;

			min = a[i];

			//Allocate books among exact ppl
			if ( student > ppl ) return false;
		}

		else {
			min += a[i];
		}
	}

	return true;

}



int32_t main()
{
	abhisheknaiidu();

	int n;
	cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	int len = a.size();
	int ppl;
	cin >> ppl;

	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += a[i];
	}

	int s = 0, e = sum, mid, res;

	//Binary Search
	while (s <= e) {
		mid = s + (e - s) / 2;

		// Checking whether exact no of ppl are able to read with the min
		// num of pages( i.e mid)
		if (check(a, n, ppl, mid)) {

			res = mid;
			e = mid - 1;
		}

		else {
			s = mid + 1;
		}
	}

	cout << res - 1;
	return 0;
}

