class AnimalShelf {
private:
    queue<int> cats;
    queue<int> dogs;
public:
    AnimalShelf() {
        
    }
    
    void enqueue(vector<int> animal) {
        int id = animal[0];
        int type = animal[1];
        if(type) {
            dogs.push(id);
        }
        else {
            cats.push(id);
        } 
    }
    
    vector<int> dequeueAny() {
        int csize = cats.size();
        int dsize = dogs.size();
        vector<int> ans(2);
        int id  = -1;
        int type = -1;
        if(csize==0 && dsize==0) {
            
        }
        else if(csize==0) {
            id = dogs.front();
            dogs.pop();
            type = 1;
        }
        else if(dsize==0) {
            id = cats.front();
            cats.pop();
            type = 0;
        }
        else {
            int idc = cats.front();
            int idd = dogs.front();
            if(idc < idd) {
                id =  idc;
                type = 0;
                cats.pop();
            }
            else {
                id = idd;
                type = 1;
                dogs.pop();
            }
        }
        ans[0] = id;
        ans[1] = type;
        return ans;
    }
    
    vector<int> dequeueDog() {
        vector<int> ans(2);
        if(dogs.empty()) {
            ans[0] = ans[1] = -1;
        }
        else {
            ans[1] = 1;
            ans[0] = dogs.front();
            dogs.pop();
        }
        return ans;
    }
    
    vector<int> dequeueCat() {
        vector<int> ans(2);
        if(cats.empty()) {
            ans[0] = ans[1] = -1;
        }
        else {
            ans[1] = 0;
            ans[0] = cats.front();
            cats.pop();
        }
        return ans;
    }
};

/**
 * Your AnimalShelf object will be instantiated and called as such:
 * AnimalShelf* obj = new AnimalShelf();
 * obj->enqueue(animal);
 * vector<int> param_2 = obj->dequeueAny();
 * vector<int> param_3 = obj->dequeueDog();
 * vector<int> param_4 = obj->dequeueCat();
 */