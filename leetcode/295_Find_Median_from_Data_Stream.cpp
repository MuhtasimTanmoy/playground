#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/find-median-from-data-stream
#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

class MedianFinder {
    
typedef struct Node {
    int val;
    Node* next;
} Node; 
    
int count;  
Node* head;
Node* median;    
    
public:
    /** initialize your data structure here. */
    MedianFinder() {
        // Initialize
        count = 0;
        head  = NULL;
        median = NULL;
    }
    
    void addNum(int num) {
        // Make Node, 
		count++;
        Node* n = new Node();
        n->val = num;
        n->next = NULL;
        
        // head check
        if(head == NULL){
            head = n;
        }
		else if(n->val < head->val){
			n->next = head;
			head = n;
		}
        else{
            // iterate through
            Node* itr = head;
            while(itr->next != NULL && num > itr->next->val){
                itr = itr->next;
            }
             // and position where needed.
            n->next = itr->next;
            itr->next = n;
        }
    }
    
    double findMedian() {

        Node* itr = head;
        while(itr->next!=NULL){
            cout<<itr->val<<endl;
            itr=itr->next;
        }
        cout<<itr->val<<endl;

        // even check
		bool isEven = count%2;
		int go = (count - 1)/2;
        double res = 0;
		median = head;
		for(int i = 0; i< go;i++){
			median = median->next;
		}

        if(!isEven){
            res = median->val + median->next->val;
            res = res/2;
        }
        else{
            res = median->val;
        }
        return res;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main()
{
	MedianFinder m;

	cout<<m.findMedian()<<endl;


	return 0;
}
