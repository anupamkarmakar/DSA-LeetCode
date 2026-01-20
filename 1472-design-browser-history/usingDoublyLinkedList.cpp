class BrowserHistory {
public:
    struct ListNode{
        string val;
        ListNode* next;
        ListNode* prev;
        ListNode(string x) : val(x), next(nullptr), prev(nullptr) {}
    };

    ListNode *head;
    ListNode *p;

    BrowserHistory(string homepage) {
        head = new ListNode(homepage);
        p=head;
    }
    
    void visit(string url) {
        // clear forward visits
        p->next=nullptr;

        ListNode *temp = new ListNode(url);
        p->next=temp;
        temp->prev=p;
        p=temp;
    }
    
    string back(int steps) {
        while(p->prev!=nullptr && steps>0){
            p=p->prev;
            steps--;
        }
        return p->val;
    }
    
    string forward(int steps) {
        while(p->next!=nullptr && steps>0){
            p=p->next;
            steps--;
        }
        return p->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */