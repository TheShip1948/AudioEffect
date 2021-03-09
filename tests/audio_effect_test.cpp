#include "../third_party/catch2/catch_amalgamated.hpp"
#include "../src/audio_effect.h"

TEST_CASE("Feedback loop") {
    std::shared_ptr<AudioEffect> root = std::make_shared<AudioEffectChild>();

    SECTION("Multi nodes, no loop") {
        std::shared_ptr<AudioEffect> first_node = std::make_shared<AudioEffectChild>();
        std::shared_ptr<AudioEffect> second_node = std::make_shared<AudioEffectChild>();
        std::shared_ptr<AudioEffect> third_node = std::make_shared<AudioEffectChild>();

        root->next = first_node;
        first_node->next = second_node;
        second_node->next = third_node;

        REQUIRE(detect_feedback(root) == false);
    }
}

