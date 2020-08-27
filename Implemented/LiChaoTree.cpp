ll f(vector<ll> line, int x){
	return line[0] * x + line[1];
}
 
void insert(vector<ll> line, int lo = 1, int hi = N, int i = 1){
	int m = (lo + hi) / 2;
	bool left = f(line, lo) < f(tree[i], lo);
	bool mid = f(line, m) < f(tree[i], m);
 
	if(mid) swap(tree[i], line);
 
	if(hi - lo == 1) return;
	else if(left != mid) insert(line, lo, m, 2*i);
	else insert(line, m, hi, 2*i+1);
}
 
ll query(int x, int lo = 1, int hi = N, int i = 1){
	int m = (lo+hi)/2;
	ll curr = f(tree[i], x);
	if(hi-lo==1) return curr;
	if(x<m) return min(curr, query(x, lo, m, 2*i));
	else return min(curr, query(x, m, hi, 2*i+1));
}