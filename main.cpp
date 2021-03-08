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

//struct AudioEffect {
//    AudioEffect* next;
//};


//std::unordered_map<AudioEffect*, bool> visited;

//bool detect_feedback(AudioEffect* root) {
////    std::cout << "Pointer = " << root << std::endl;
////    std::cout << "Step 1" << std::endl;
//    if(root == nullptr) return false;
//
////    std::cout << "Step 2" << std::endl;
//    if(visited.find(root) == visited.end()) {
//        visited[root] = true;
//        return detect_feedback(root->next);
//    }
//
////    std::cout << "Step 3" << std::endl;
//
//    return true;
//}

struct AudioEffect {
    virtual ~AudioEffect() = default;
//    virtual void process(float* buf, size_t num) = 0;
    std::shared_ptr<AudioEffect> next;
};

/*
 * Notes
    * Function will not compile for the case root = nullptr, because there is no null reference you must create a node
 * Questions
    * How exactly make shared is working in this context
 * */

bool detect_feedback(const AudioEffect& root) {
    bool feedback_loop = false;
    const AudioEffect* slow_ptr = &root;
    const AudioEffect* fast_ptr = &root;
    bool list_end = false;

    while(true) {
        // Progress fast pointer 2 steps
        for(int i = 0; i < 2; ++i) {
            fast_ptr = fast_ptr->next.get();
            if(fast_ptr == nullptr) {
                list_end = true;
                break;
            }
        }
        if(list_end) break;

        // Progress slow pointer
        slow_ptr = slow_ptr->next.get();

        if(fast_ptr == slow_ptr) {
            feedback_loop = true;
            break;
        }
    }

    return feedback_loop;
}

int main() {
//    AudioEffect root;
//    AudioEffect first_node;
//    root.next = &first_node;
//    first_node.next = &root;
//    first_node.next = nullptr;

//    std::cout << "First node next = " << first_node.next.get() << std::endl;
//    std::cout<< detect_feedback(&root) << std::endl;

    AudioEffect* root = new AudioEffect;
    AudioEffect* first = new AudioEffect;
    AudioEffect* second = new AudioEffect;
    AudioEffect* third = new AudioEffect;

//    root.next = std::make_shared<AudioEffect>(first);
//    first.next = std::make_shared<AudioEffect>(second);
//    second.next = std::make_shared<AudioEffect>(third);
//    third.next = std::make_shared<AudioEffect>(first);
    root->next.reset(first);
    first->next.reset(second);
    second->next.reset(third);
    third->next.reset(second);
//    root->next.reset(root);


    std::cout << detect_feedback(*root) << std::endl;
//    if(root.next == nullptr) std::cout << "root = nullptr" << std::endl;

    std::cout << "Hello world" << std::endl;
    return 0;
}

