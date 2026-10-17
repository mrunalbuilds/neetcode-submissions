class LRUCache {
private:
    struct Node {
        int key;
        int value;

        Node *prev;
        Node *next;

        Node(int k, int v){
            key = k;
            value = v;
            prev = nullptr;
            next = nullptr;
        }
    };
    unordered_map<int, Node*> cache;
    int capacity;
    Node *head;
    Node *tail;

    

    void removeNode(Node* node){
        Node *curr = node->next;
        Node *before = node->prev;

        curr->prev = before;
        node->next = nullptr;
        before->next = curr;
        node->prev = nullptr;
    }

    void insertAfterHead(Node *node){
        Node *curr = head->next;
        head->next = node;
        node->next = curr;
        curr->prev = node;
        node->prev = head;

    }
public:

    //we will be storing node value and node itself in hashmap to get in O(1)
    LRUCache(int capacity) {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        //check if key is available in hashmap
        //if you get key, remove and add it to he head
        //by getting the stored node in hashmap

        if(cache.find(key) == cache.end()){
            return -1;
        }
        Node *node = cache[key];
        removeNode(node);
        insertAfterHead(node);

        return node->value;
    }
    
    void put(int key, int value) {
        //check the capacity
        //if it full, then remove node from head
        //and insert new node
        if (cache.find(key) != cache.end()) {
            Node *node = cache[key];
            node->value = value;
            removeNode(node);
            insertAfterHead(node);
            return;
        }

        if(capacity == 0)
            return;
        
        if(cache.size() == capacity){
            Node *prev = tail->prev;
            cache.erase(prev->key);
            removeNode(prev);
            delete prev;
        }

        Node *curr = new Node(key,value);
        cache[key] = curr;
        insertAfterHead(curr);
    }
};
