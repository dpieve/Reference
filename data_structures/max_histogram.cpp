const int MAXN = 200000 + 5;

using LL = long long;

LL N, a[MAXN];
stack < LL > s;

LL mxHistogram () {
	int i = 0;
		LL area = 0, mxArea = 0;

		while (i < N) {
			
			if (s.empty () || (a[(s.top())] <= a[i])) {
				s.push (i++);
			}
			else {
				LL top = s.top(); s.pop();

				if (s.empty())
					area = i * a[top];
				else area = (i - 1 - s.top()) * a[top];
			}

			mxArea = max (mxArea, area);
		}


		while (!s.empty ()) {
			LL top = s.top(); s.pop();
			if (s.empty())
				area = N * a[top];
			else area = (N - 1 - s.top()) * a[top];
		
			mxArea = max (mxArea, area);
		}

		return mxArea;
}



