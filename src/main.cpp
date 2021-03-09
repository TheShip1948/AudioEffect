#include "audio_effect.h"

int main() {
    std::shared_ptr<AudioEffect> root = std::make_shared<AudioEffectChild>();
    std::shared_ptr<AudioEffect> first_node = std::make_shared<AudioEffectChild>();

    root->next = first_node;
    first_node->next = root;

    std::cout << "Feedback loop = " << detect_feedback(root) << std::endl;
    return 0;
}

