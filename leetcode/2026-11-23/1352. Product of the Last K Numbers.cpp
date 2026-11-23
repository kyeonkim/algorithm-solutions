class ProductOfNumbers {
private:
    vector<int> products;
public:
    ProductOfNumbers() {
    }
    
    void add(int num) {
        products.push_back(num);
    }
    
    int getProduct(int k) {
        int sum = 1;

        for (int i = 0; i < k; i++) {
            sum *= products[products.size() - 1 - i];
        }

        return sum;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */