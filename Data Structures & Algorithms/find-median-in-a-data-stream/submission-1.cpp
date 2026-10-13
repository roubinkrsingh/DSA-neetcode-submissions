class MedianFinder {
public:
    priority_queue<int>pq1;
    priority_queue<int,vector<int>,greater<int>>pq2;
    int len=0;
    MedianFinder() {
        pq1= priority_queue<int>();
        pq2=priority_queue<int, vector<int>, greater<int>>();
    }
    void addNum(int num) {
        if(pq1.empty()){
            pq1.push(num);
        }
        else if(pq2.empty()){
            if(num>=pq1.top()) pq2.push(num);
            else{
                pq2.push(pq1.top());
                pq1.pop();
                pq1.push(num);
            }
        }
        else{
            int first=pq1.top();
            int second=pq2.top();
            if(num>=first && num<=second){
                if(len%2==0) pq1.push(num);
                else pq2.push(num);
            }
            else if(num>second){
                if(len%2==0){
                    pq1.push(second);
                    pq2.pop();
                    pq2.push(num);
                }
                else pq2.push(num);
            }
            else{
                if(len%2==0) pq1.push(num);
                else {
                    pq2.push(first);
                    pq1.pop();
                    pq1.push(num);
                }
            }
        }
        len++;
    }
    double findMedian() {
        if(len & 1) return pq1.top();
        else return (pq1.top()+pq2.top())/2.0;
    }
};
