class RandomizedSet {
public:
    std::vector<int> vec;
    RandomizedSet() {
        
    }

    std::vector<int>::iterator find_val(int val) {
        return std::find(vec.begin(), vec.end(), val);
    }

    bool contain(int val){
        if (find_val(val) == vec.end())
            return false;
        return true;
    }
    
    bool insert(int val) {
        if (contain(val))
            return false;
        vec.emplace_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (contain(val)){
            vec.erase(find_val(val));
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int rand_val = std::rand()%vec.size();
        return vec[rand_val];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */