#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;
 
#define ll long long
 
void exgcd(int a, int b, int& x, int& y) {
	if (!b) {
		x = 1, y = 0;
	} else {
		exgcd(b, a % b, y, x);
		y -= (a / b) * x;
	}
}
 
int inv(int a, int n) {
	int x, y;
	exgcd(a, n, x, y);
	return (x < 0) ? (x + n) : (x);
}
 
const int Mod = 1e9 + 7;
 
template <const int Mod = :: Mod>
class Z {
	public:
		int v;
 
		Z() : v(0) {	}
		Z(int x) : v(x){	}
		Z(ll x) : v(x % Mod) {	}
 
		friend Z operator + (const Z& a, const Z& b) {
			int x;
			return Z(((x = a.v + b.v) >= Mod) ? (x - Mod) : (x));
		}
		friend Z operator - (const Z& a, const Z& b) {
			int x;
			return Z(((x = a.v - b.v) < 0) ? (x + Mod) : (x));
		}
		friend Z operator * (const Z& a, const Z& b) {
			return Z(a.v * 1ll * b.v);
		}
		friend Z operator ~(const Z& a) {
			return inv(a.v, Mod);
		}
		friend Z operator - (const Z& a) {
			return Z(0) - a;
		}
		Z& operator += (Z b) {
			return *this = *this + b;
		}
		Z& operator -= (Z b) {
			return *this = *this - b;
		}
		Z& operator *= (Z b) {
			return *this = *this * b;
		}
		friend boolean operator == (const Z& a, const Z& b) {
			return a.v == b.v;
		} 
};
 
Z<> qpow(Z<> a, int p) {
	Z<> rt = Z<>(1), pa = a;
	for ( ; p; p >>= 1, pa = pa * pa) {
		if (p & 1) {
			rt = rt * pa;
		}
	}
	return rt;
}
 
typedef Z<> Zi;
 
const int N = 2e5 + 5;
 
typedef class SegTreeNode {
	public:
		ll v, cv;
		Zi f, cf, df;
		SegTreeNode *l, *r;
 
		void cover(ll _v, Zi _f) {
			v = _v, f = _f;
			cv = _v, cf = _f;
			df = 0;
		}
		void add(Zi _df) {
			df += _df;
			f += _df;
		}
		void push_down() {
			if (cv != -1) {
				l->cover(cv, cf);
				r->cover(cv, cf);
				cv = -1;
			}
			if (df.v) {
				l->add(df);
				r->add(df);
				df = 0;
			}
		}
		void push_up() {
			v = max(l->v, r->v);
		}
} SegTreeNode;
 
typedef class SegmentTree {
	public:
		static SegTreeNode pool[N << 1];
		static SegTreeNode* top;
 
		static SegTreeNode* newnode() {
			top->v = 0;
			top->cv = -1, top->cf = -1;
			top->df = 0;
			top->f = 1;
			top->l = top->r = NULL;
			return top++;
		}
		
		int n;
		SegTreeNode* rt;
 
		SegmentTree() : rt(NULL) {	}
		
		void build(SegTreeNode*& p, int l, int r) {
			p = newnode();
			if (l ^ r) {
				int mid = (l + r) >> 1;
				build(p->l, l, mid);
				build(p->r, mid + 1, r);
			}
		}
 
		void build(int n) {
			this->n = n;
			build(rt, 1, n);
		}
 
		void cover(SegTreeNode* p, int l, int r, int ql, int qr, ll v, Zi f) {
			if (l == ql && r == qr) {
				p->cover(v, f);
				return;
			}
			int mid = (l + r) >> 1;
			p->push_down();
			if (qr <= mid) {
				cover(p->l, l, mid, ql, qr, v, f);
			} else if (ql > mid) {
				cover(p->r, mid + 1, r, ql, qr, v, f);
			} else {
				cover(p->l, l, mid, ql, mid, v, f);
				cover(p->r, mid + 1, r, mid + 1, qr, v, f);
			}
			p->push_up();
		}
		void cover(int l, int r, ll v, Zi f) {
			cover(rt, 1, n, l, r, v, f);
		}
 
		void add(SegTreeNode* p, int l, int r, int ql, int qr, Zi df) {
			if (l == ql && r == qr) {
				p->add(df);
				return;
			}
			int mid = (l + r) >> 1;
			p->push_down();
			if (qr <= mid) {
				add(p->l, l, mid, ql, qr, df);
			} else if (ql > mid) {
				add(p->r, mid + 1, r, ql, qr, df);
			} else {
				add(p->l, l, mid, ql, mid, df);
				add(p->r, mid + 1, r, mid + 1, qr, df);
			}
			p->push_up();
		}
		void add(int l, int r, Zi df) {
			add(rt, 1, n, l, r, df);
		}
 
		int query(SegTreeNode *p, int l, int r, ll x) {
			if (l == r) {
				return (p->v <= x) ? l : (l - 1);
			}
			int mid = (l + r) >> 1;
			p->push_down();
			if (p->l->v > x) {
				return query(p->l, l, mid, x);
			}
			return query(p->r, mid + 1, r, x);
		}
		int query(ll x) {
			return query(rt, 1, n, x);
		}
 
		ll get_v(SegTreeNode* p, int l, int r, int idx) {
			if (l == r) {
				return p->v;
			}
			p->push_down();
			int mid = (l + r) >> 1;
			if (idx <= mid) {
				return get_v(p->l, l, mid, idx);
			} 
			return get_v(p->r, mid + 1, r, idx);
		}
		ll get_v(int idx) {
			return get_v(rt, 1, n, idx);
		}
 
		Zi get_f(SegTreeNode* p, int l, int r, int idx) {
			if (l == r) {
				return p->f;
			}
			p->push_down();
			int mid = (l + r) >> 1;
			if (idx <= mid) {
				return get_f(p->l, l, mid, idx);
			} 
			return get_f(p->r, mid + 1, r, idx);
		}
		Zi get_f(int idx) {
			return get_f(rt, 1, n, idx);
		} 
} SegmentTree;
 
SegTreeNode SegmentTree :: pool[N << 1];
SegTreeNode* SegmentTree :: top = SegmentTree :: pool;
 
typedef class Pair {
	public:
		int in, out;
 
		void read() {
			scanf("%d%d", &out, &in);
		}
		boolean operator < (Pair b) const {
			return in < b.in;
		}
} Pair;
 
int n;
int ps[N];
Pair a[N];
ll v[N];
Zi f[N];
SegmentTree st;
 
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		a[i].read();
	}
	sort(a + 1, a + n + 1);
	st.build(n);
	for (int i = 1; i <= n; i++) {
		int l = i + 1, r = n, mid;
		while (l <= r) {
			mid = (l + r) >> 1;
			if (a[mid].in >= a[i].out) {
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		ps[i] = r + 1;
		v[i] = st.get_v(i);
		f[i] = st.get_f(i);
//		cerr << i << " " << v[i] << " " << f[i].v << '\n';
		if (ps[i] <= n) {
			int p1 = st.query(v[i] + a[i].out - a[i].in - 1);
			int p2 = st.query(v[i] + a[i].out - a[i].in);
			// [ps_i, p1] [max(p1 + 1, ps_i), p2]
			if (ps[i] <= p1) {
				st.cover(ps[i], p1, v[i] + a[i].out - a[i].in, f[i]);
			}
			p1 = max(p1 + 1, ps[i]);
			if (p1 <= p2) {
				st.add(p1, p2, f[i]);
			}
		}
	}
	ll dist = 1ll << 60;
	Zi ans = 0;
	for (int i = 1; i <= n; i++) {
		if (ps[i] <= n)
			continue;
		if (a[i].in - v[i] < dist) {
			dist = a[i].in - v[i];
			ans = f[i];
		} else if (a[i].in - v[i] == dist) {
			ans += f[i];
		}
	}
	printf("%d\n", ans.v);
	return 0;
}