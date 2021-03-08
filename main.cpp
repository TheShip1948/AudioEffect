#include <iostream>
#include <memory>
#include <unordered_map>

//struct AudioEffect {
//    virtual ~AudioEffect() = default;
////    virtual void process(float* buf, size_t num) = 0;
//    virtual void process(float* buf, size_t num) {};
//    std::shared_ptr<AudioEffect> next;
//};
//
//std::unordered_map<AudioEffect*, bool> visited;
//
//bool detect_feedback(struct AudioEffect* root) {
//    std::cout << "Pointer = " << root << std::endl;
//    std::cout << "Step 1" << std::endl;
//    if(root == nullptr) return false;
//
//    std::cout << "Step 2" << std::endl;
//    if(visited.find(root) == visited.end()) {
//        visited[root] = true;
//        return detect_feedback(root->next.get());
//    }
//
//    std::cout << "Step 3" << std::endl;
//
//    return true;
//}

struct AudioEffect {
    AudioEffect* next;
};

std::unordered_map<AudioEffect*, bool> visited;

bool detect_feedback(AudioEffect* root) {
//    std::cout << "Pointer = " << root << std::endl;
//    std::cout << "Step 1" << std::endl;
    if(root == nullptr) return false;

//    std::cout << "Step 2" << std::endl;
    if(visited.find(root) == visited.end()) {
        visited[root] = true;
        return detect_feedback(root->next);
    }

//    std::cout << "Step 3" << std::endl;

    return true;
}

int main() {
    AudioEffect root;
    AudioEffect first_node;
    root.next = &first_node;
//    first_node.next = &root;
    first_node.next = nullptr;

//    std::cout << "First node next = " << first_node.next.get() << std::endl;
    std::cout<< detect_feedback(&root) << std::endl;

    std::cout << "Hello world" << std::endl;
    return 0;
}

