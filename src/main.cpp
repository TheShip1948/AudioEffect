#include "audio_effect.h"

int main() {
    std::shared_ptr<AudioEffect> root = std::make_shared<AudioEffectChild>();
    std::shared_ptr<AudioEffect> first = std::make_shared<AudioEffectChild>();
    root->next = first;
    first->next = root;

    std::cout << "Feedback loop = " << detect_feedback(root) << std::endl;
    return 0;
}

