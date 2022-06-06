class Solution {
public:
	string gcdOfStrings(string s1, string s2) {
		int len1 = s1.length();
		int len2 = s2.length();
        
		if(len1 > len2) {
			swap(s1,s2);
			swap(len1, len2);
		}

		while(len1 <= len2 and len1) {
			string sub = s2.substr(0, len1);
			if(s1 == sub) {
				s2 = s2.substr(len1, len2-len1);
				len2 = s2.length();
			} else {
				return "";
			}
			if(len1 > len2) {
				swap(s1, s2);
				swap(len1, len2);
			}            
		}
		return s2;
	}
};