class MedianFinder {
public:
    priority_queue<int> left; // Max Heap
    priority_queue<int, vector<int>, greater<int>> right; // Min Heap

    MedianFinder() {
    }

    void addNum(int num) {
        left.push(num);

        // Ensure every element in left <= every element in right
        if (!right.empty() && left.top() > right.top()) {
            right.push(left.top());
            left.pop();
        }

        // Balance the heaps
        if (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        }
        else if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian() {
        if (left.size() == right.size()) {
            return ((double)left.top() + (double)right.top()) / 2.0;
        }

        return left.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */