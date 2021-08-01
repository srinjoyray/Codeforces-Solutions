#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int INF = 1e9;

vector<int> t, ps;

void push(int v){
	if (v * 2 + 1 < int(ps.size())){
		ps[v * 2] += ps[v];
		ps[v * 2 + 1] += ps[v];
	}
	t[v] += ps[v];
	ps[v] = 0;
}

void upd(int v, int l, int r, int L, int R, int val){
	push(v);
	if (L >= R)
		return;
	if (l == L && r == R){
		ps[v] += val;
		push(v);
		return;
	}
	int m = (l + r) / 2;
	upd(v * 2, l, m, L, min(m, R), val);
	upd(v * 2 + 1, m, r, max(m, L), R, val);
	t[v] = min(t[v * 2], t[v * 2 + 1]);
}

int get(){
	return t[1] + ps[1];
}

struct seg{
	int l, r, w;
};

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector<seg> a(n);
	forn(i, n){
		scanf("%d%d%d", &a[i].l, &a[i].r, &a[i].w);
		--a[i].l, --a[i].r;
	}
	--m;
	sort(a.begin(), a.end(), [](const seg &a, const seg &b){
		return a.w < b.w;
	});
	t.resize(4 * m);
	ps.resize(4 * m);
	int ans = INF;
	int j = 0;
	forn(i, n){
		while (j < n && get() == 0){
			upd(1, 0, m, a[j].l, a[j].r, 1);
			++j;
		}
		if (get() == 0){
			break;
		}
		ans = min(ans, a[j - 1].w - a[i].w);
		upd(1, 0, m, a[i].l, a[i].r, -1);
	}
	printf("%d\n", ans);
	return 0;
}