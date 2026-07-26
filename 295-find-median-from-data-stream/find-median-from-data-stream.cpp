class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> left;
    priority_queue<int> right;
    MedianFinder() {}

    void addNum(int num) {
        left.push(num);
        right.push(left.top());
        left.pop();
        if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian() {
        int n = left.size() + right.size();
        if (n % 2 == 0) {
            return (left.top() + right.top()) / 2.0;
        } else {
            return left.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */