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

    SECTION("Single node with loop") {
        root->next = root;

        REQUIRE(detect_feedback(root) == true);
    }

    SECTION("Single node with no loop") {
        REQUIRE(detect_feedback(root) == false);
    }

    SECTION("Multi node with loop on the tail node") {
        std::shared_ptr<AudioEffect> first_node = std::make_shared<AudioEffectChild>();
        std::shared_ptr<AudioEffect> second_node = std::make_shared<AudioEffectChild>();
        std::shared_ptr<AudioEffect> third_node = std::make_shared<AudioEffectChild>();

        root->next = first_node;
        first_node->next = second_node;
        second_node->next = third_node;
        third_node->next = third_node;

        REQUIRE(detect_feedback(root) == true);
    }

    SECTION("Multi node with loop, tail is connected to root") {
        std::shared_ptr<AudioEffect> first_node = std::make_shared<AudioEffectChild>();
        std::shared_ptr<AudioEffect> second_node = std::make_shared<AudioEffectChild>();
        std::shared_ptr<AudioEffect> third_node = std::make_shared<AudioEffectChild>();

        root->next = first_node;
        first_node->next = second_node;
        second_node->next = third_node;
        third_node->next = root;

        REQUIRE(detect_feedback(root) == true);
    }

    SECTION("Multi node with loop, tail is connected to middle node") {
        std::shared_ptr<AudioEffect> first_node = std::make_shared<AudioEffectChild>();
        std::shared_ptr<AudioEffect> second_node = std::make_shared<AudioEffectChild>();
        std::shared_ptr<AudioEffect> third_node = std::make_shared<AudioEffectChild>();

        root->next = first_node;
        first_node->next = second_node;
        second_node->next = third_node;
        third_node->next = first_node;

        REQUIRE(detect_feedback(root) == true);
    }
}

