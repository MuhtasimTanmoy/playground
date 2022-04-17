class Solution {
public:
	int numUniqueEmails(vector<string>& emails) {
        
		unordered_set<string> uniqueEmails;

		for(auto email: emails) {
			string localName = "";
			int i = 0;
            
			while (1) {
                if(email[i]=='+' || email[i]=='@')break;
                else if (email[i] == '.') i++;
				else {
                    localName+=email[i];
                    i++;
                }
			}
			if (email[i]=='+') while(email[i] != '@')i++;
            
			string domain=email.substr(i);
			uniqueEmails.insert(localName+domain);
		}
		return uniqueEmails.size();
	}
};