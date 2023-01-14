class UF {
public:   
    UF(int n): ds(n, -1) {}
    
    int ds_find(int p) {
      return ds[p] == -1 ? p : ds[p] = ds_find(ds[p]);
    }
    
    void ds_merge(int p1, int p2) {
      p1 = ds_find(p1), p2 = ds_find(p2);
      if (p1 != p2) ds[max(p1, p2)] = min(p1, p2);
    }
private:
    vector<int> ds;
};

class Solution {
public:
    string smallestEquivalentString(string A, string B, string S) {
      auto uf = UF(26);
      for (auto i = 0; i < A.size(); ++i) 
          uf.ds_merge(A[i] - 'a', B[i] - 'a');
      for (auto i = 0; i < S.size(); ++i) 
          S[i] = uf.ds_find(S[i] - 'a') + 'a';
      return S;
    }
};