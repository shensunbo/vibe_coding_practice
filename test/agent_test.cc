#include <gtest/gtest.h>

#include "game/Game.h"

TEST(CharacterTest, AttackAppliesDamageWhenInRange) {
    game::Character player(100, 0.0f);
    game::Character ai(100, 1.0f);

    const bool hit = player.TryAttack(&ai, game::AttackType::kLight);

    EXPECT_TRUE(hit);
    EXPECT_EQ(ai.health(), 92);
}

TEST(CharacterTest, AttackMissesWhenOutOfRange) {
    game::Character player(100, 0.0f);
    game::Character ai(100, 10.0f);

    const bool hit = player.TryAttack(&ai, game::AttackType::kHeavy);

    EXPECT_FALSE(hit);
    EXPECT_EQ(ai.health(), 100);
}

TEST(GameTest, KOWinConditionWorks) {
    game::Game game(true);
    ASSERT_TRUE(game.initialize());

    game::Character& player = game.player();
    game::Character& ai = game.ai();

    ai.TakeDamage(100);

    EXPECT_EQ(game.GetRoundResult(), game::RoundResult::kPlayerWins);
    EXPECT_FALSE(player.is_ko());
}

TEST(GameTest, TimeOverWinConditionUsesRemainingHealth) {
    game::Game game(true);
    ASSERT_TRUE(game.initialize());

    game.player().TakeDamage(10);
    game.ai().TakeDamage(20);

    for (int i = 0; i < 60; ++i) {
        game.TickSecond();
    }

    EXPECT_EQ(game.GetRoundResult(), game::RoundResult::kPlayerWins);
}
