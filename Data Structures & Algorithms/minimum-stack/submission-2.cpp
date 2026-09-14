class MinStack {
public:
    stack<long long> st;
    long long min;
    MinStack() {
        min = 0;
    }
    
    void push(int val) {
        if(st.empty()){
            min = val;
            st.push(val);
        }else if(val > min){
            st.push(val);
        }else{
            st.push(2LL*val-min);
            min = val;
        }
    }
    
    void pop() {
        long long n = st.top();
        st.pop();
        if(n < min) //modified and next min should be stored
            min = 2*min-n;
    }
    
    int top() {
        long long n = st.top();
        if(min < n)
            return n; //not modified
        else 
            return min; //its a modified value but eventually min
    }
    
    int getMin() {
        return min;
    }
};
