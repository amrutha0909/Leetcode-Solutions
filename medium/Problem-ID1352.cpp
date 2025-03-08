class ProductOfNumbers {
    public:
        vector<int>arr;
        ProductOfNumbers() {
            this->arr=arr;
        }
        
        void add(int num) {
            arr.push_back(num);
        }
        
        int getProduct(int k) {
            int product=1;
            for(int i=arr.size()-k;i<arr.size();i++){
                product*=arr[i];
            }
            return product;
        }
    };
    
    /**
     * Your ProductOfNumbers object will be instantiated and called as such:
     * ProductOfNumbers* obj = new ProductOfNumbers();
     * obj->add(num);
     * int param_2 = obj->getProduct(k);
     */