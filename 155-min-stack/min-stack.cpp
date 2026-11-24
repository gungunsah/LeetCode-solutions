class MinStack {
    stack<long long> s;
    long long minval;
public:
    MinStack() {}

    void push(int val) {
        if (s.empty()) {
            s.push(val);
            minval = val;
        } else if (val < minval) {
            s.push(2LL * val - minval);  // encoded value
            minval = val;
        } else {
            s.push(val);
        }
    }

    void pop() {
        if (s.top() < minval) {
            minval = 2 * minval - s.top();  // purana min restore
        }
        s.pop();
    }

    int top() {
        if (s.top() < minval) {
            return (int)minval;  // asli top minval hi hai
        }
        return (int)s.top();
    }

    int getMin() {
        return (int)minval;
    }
};