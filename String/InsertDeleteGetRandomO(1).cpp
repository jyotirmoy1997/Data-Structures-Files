#include<bits/stdc++.h>
using namespace std;
class RandomizedSet {
public:
    unordered_map<int,int> indices;
    vector<int> values;
    RandomizedSet() {}
    
    bool insert(int val) {
        if(indices.find(val)==indices.end()){
            values.push_back(val);
            indices[val] = values.size() -1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {

       if(indices.find(val)==indices.end())
           return false;

        int idx = indices[val];
        indices[values[values.size()-1]] = idx;
        values[idx] = values[values.size()-1];
        values.pop_back();
        indices.erase(val);
        return true;
    }
    
    int getRandom() {
        return values[rand()%values.size()];
    }
};
int main(){

}