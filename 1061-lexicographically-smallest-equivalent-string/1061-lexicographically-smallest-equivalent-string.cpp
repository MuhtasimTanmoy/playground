class Solution {
    int ds_find(vector<int>& ds, int p) {
      return ds[p] == -1 ? p : ds[p] = ds_find(ds, ds[p]);
    }
    
    void ds_merge(vector<int>& ds, int p1, int p2) {
      p1 = ds_find(ds, p1), p2 = ds_find(ds, p2);
      if (p1 != p2) ds[max(p1, p2)] = min(p1, p2);
    }
public:
    string smallestEquivalentString(string A, string B, string S) {
      vector<int> ds(26, -1);
      for (auto i = 0; i < A.size(); ++i) ds_merge(ds, A[i] - 'a', B[i] - 'a');
      for (auto i = 0; i < S.size(); ++i) S[i] = ds_find(ds, S[i] - 'a') + 'a';
      return S;
    }
};