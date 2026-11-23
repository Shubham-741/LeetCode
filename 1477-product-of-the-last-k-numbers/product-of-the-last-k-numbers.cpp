class ProductOfNumbers {
public:
    ProductOfNumbers() {
        
    }

    vector<int>arr;
    
    void add(int num) {

        arr.push_back(num);
        
    }
    
    int getProduct(int k) {

        int n = static_cast<int>(arr.size());

        if(k>n || k<=0){
            return 0;
        }

        int p =1;

        for(int i = n-1; i>=n-k; i--){
            p *= arr[i];
        }

        return p;
        
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */