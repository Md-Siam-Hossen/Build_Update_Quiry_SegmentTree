#include<bits/stdc++.h>
using namespace std;

#define lt long int
#define ll long long int
#define cn cin
#define co cout
#define nl endl
#define vec vector
#define pb push_back
#define all(v) v.begin(), v.end()
#define loop(i,n) for(int i=0; i<(n); i++)

vec<int>A, ST;

void build(int node, int L, int R){
	if(L==R){
		ST[node] = A[L];
	}
	else{

		int mid = (L+R)/2;

		build(2*node, L, mid);
		build(2*node+1, mid+1, R);

		ST[node] = ST[2*node] + ST[2*node+1];

	}
}

int update(int node, int L, int R, int idx, int val){
	if(L == R){
		A[idx] += val;
		ST[node] += val;
	}
	else{
		int mid = (L+R) / 2;

		if(L <= idx and idx <= mid){
			update(2*node, L, mid, idx, val);
		}
		else{
			update(2*mid+1, mid+1, R, idx, val);
		}

		ST[node] = ST[2*node] + ST[2*node+1];
	}
}

int query(int node, int tl, int tr, int l, int r){
	if(r < tl or l > tr){
		return 0;
	}

	if(l<=tl and tr<=r){
		return ST[node];
	}

	int tm = (tl+tr)/2;

	return query(2*node, tl, tm, l, r) + query(2*node+1, tm+1, tr, l, r);
}

void solve(){
	int n = 6;
    A = { 0, 1, 3, 5, -2, 3 };
    ST.resize(4*n);

    build(1, 0, n-1);

    update(1, 0, n-1, 1, 100);

    query(1, 0, n-1, 0, 4);
}

int main(){
    ios::sync_with_stdio(false);
    cn.tie(nullptr);
    co.tie(nullptr);

    solve();
    
}
