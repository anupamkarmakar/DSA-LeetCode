class BrowserHistory {
public:
    stack <string> bst; //bst -> backward stack
    stack <string> fst; //fst -> forward stack

    BrowserHistory(string homepage) {
        bst.push(homepage);
    }
    
    void visit(string url) {
        bst.push(url);

        while(!fst.empty()) fst.pop();
    }
    
    string back(int steps) {
        while(bst.size()>1 && steps>0){
            fst.push(bst.top());
            bst.pop();
            steps--;
        }

        if(bst.empty()) return fst.top();
        else return bst.top();
    }
    
    string forward(int steps) {
        while(!fst.empty() && steps>0){
            bst.push(fst.top());
            fst.pop();
            steps--;
        }
        return bst.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */