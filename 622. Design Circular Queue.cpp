
class MyCircularQueue {
public:

    vector<int> v;
    int cap;
    int size;

    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        cap = 0;
        size = k;
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (cap >= size) return false;
        v.push_back(value);
        ++cap;
        return true;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (cap == 0) return false;
        v.erase(v.begin());
        --cap;
        return true;
    }

    /** Get the front item from the queue. */
    int Front() {
        if (cap == 0) return -1;
        return v[0];
    }

    /** Get the last item from the queue. */
    int Rear() {
        if (cap == 0) return -1;
        return v.back();
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return cap == 0;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return cap == size;
    }
};
