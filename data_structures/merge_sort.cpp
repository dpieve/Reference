const int INF = 1e9;

// sort array v, O(N * log(N))

void merge_sort(vector<int> &v) {
	
	if (v.size() == 1) 
		return;

	vector<int> u1, u2;

	for(int i = 0; i < (int)v.size() / 2; ++i)
		u1.push_back(v[i]);
	
	for(int i = (int)v.size() / 2; i < (int)v.size(); ++i)
		u2.push_back(v[i]);

	merge_sort(u1);
	merge_sort(u2);

	u1.push_back(INF);
	u2.push_back(INF);

	for(int i = 0, p1 = 0, p2 = 0; i < v.size(); ++i) {
		if (u1[p1] <= u2[p2])
			v[i] = u1[p1++];
		else v[i] = u2[p2++];
	}

}
