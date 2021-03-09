#ifndef AUDIO_EFFECT_H
#define AUDIO_EFFECT_H

#include <iostream>
#include <memory>
#include <unordered_map>

struct AudioEffect {
    virtual ~AudioEffect() = default;
    virtual void process(float* buf, size_t num) = 0;
    std::shared_ptr<AudioEffect> next;
};

struct AudioEffectChild : public AudioEffect {
    virtual void process(float* buf, size_t num) override final {
        std::cout << "Do processing" << std::endl;
    }
};

bool detect_feedback(const std::shared_ptr<AudioEffect> root) {
    bool feedback_loop = false;
    std::shared_ptr<AudioEffect> slow_ptr = root;
    std::shared_ptr<AudioEffect> fast_ptr = root;
    bool list_end = false;

    while(true) {
        // Progress fast pointer 2 steps
        for(int i = 0; i < 2; ++i) {
            fast_ptr = fast_ptr->next;
            if(fast_ptr == nullptr) {
                list_end = true;
                break;
            }
        }
        if(list_end) break;

        // Progress slow pointer
        slow_ptr = slow_ptr->next;

        if(fast_ptr == slow_ptr) {
            feedback_loop = true;
            break;
        }
    }

    return feedback_loop;
}

#endif
