#include "game/Game.h"

#include <GL/gl.h>
#include <GLFW/glfw3.h>

#include <algorithm>
#include <cmath>
#include <cstdlib>

namespace game {

namespace {
constexpr int kRoundTimeSeconds = 60;
constexpr float kMoveSpeed = 2.5f;
constexpr float kAttackCooldownSeconds = 0.4f;
constexpr float kAiAttackCooldownSeconds = 0.8f;
constexpr float kWorldMinX = -5.5f;
constexpr float kWorldMaxX = 5.5f;

void DrawRect(float x, float y, float w, float h, float r, float g, float b) {
  glColor3f(r, g, b);
  glBegin(GL_QUADS);
  glVertex2f(x, y);
  glVertex2f(x + w, y);
  glVertex2f(x + w, y + h);
  glVertex2f(x, y + h);
  glEnd();
}

void DrawHealthBar(float x, float y, float width, float height, float ratio,
                   float r, float g, float b) {
  glColor3f(0.15f, 0.15f, 0.15f);
  glBegin(GL_QUADS);
  glVertex2f(x, y);
  glVertex2f(x + width, y);
  glVertex2f(x + width, y + height);
  glVertex2f(x, y + height);
  glEnd();

  glColor3f(r, g, b);
  glBegin(GL_QUADS);
  glVertex2f(x, y);
  glVertex2f(x + width * ratio, y);
  glVertex2f(x + width * ratio, y + height);
  glVertex2f(x, y + height);
  glEnd();
}
}  // namespace

Game::Game(bool headless)
    : headless_(headless),
      initialized_(false),
      window_(nullptr),
      player_(100, -2.0f),
      ai_(100, 2.0f),
      remaining_time_seconds_(kRoundTimeSeconds),
      last_frame_time_(0.0),
      time_accumulator_(0.0),
      attack_cooldown_(0.0f),
      ai_attack_cooldown_(0.0f),
      ai_move_direction_(1.0f) {}

Game::~Game() { Shutdown(); }

bool Game::initialize() {
  if (initialized_) {
    return true;
  }

  if (headless_) {
    initialized_ = true;
    return true;
  }

  if (!glfwInit()) {
    return false;
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

  window_ = glfwCreateWindow(960, 540, "2D Fighting Prototype", nullptr, nullptr);
  if (!window_) {
    glfwTerminate();
    return false;
  }

  glfwMakeContextCurrent(window_);

  glViewport(0, 0, 960, 540);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-6.0, 6.0, -3.0, 3.0, -1.0, 1.0);
  glMatrixMode(GL_MODELVIEW);

  last_frame_time_ = glfwGetTime();
  time_accumulator_ = 0.0;
  attack_cooldown_ = 0.0f;
  ai_attack_cooldown_ = 0.0f;

  initialized_ = true;
  return true;
}

void Game::run() {
  if (!initialized_ || headless_) {
    return;
  }

  while (!glfwWindowShouldClose(window_) &&
         GetRoundResult() == RoundResult::kInProgress) {
    const double now = glfwGetTime();
    const float dt = static_cast<float>(now - last_frame_time_);
    last_frame_time_ = now;

    time_accumulator_ += dt;
    while (time_accumulator_ >= 1.0) {
      TickSecond();
      time_accumulator_ -= 1.0;
    }

    ProcessInput(dt);
    Update(dt);
    Render();

    glfwSwapBuffers(window_);
    glfwPollEvents();
  }
}

void Game::ProcessInput(float dt) {
  if (!window_) {
    return;
  }

  float move = 0.0f;
  if (glfwGetKey(window_, GLFW_KEY_A) == GLFW_PRESS ||
      glfwGetKey(window_, GLFW_KEY_LEFT) == GLFW_PRESS) {
    move -= kMoveSpeed * dt;
  }
  if (glfwGetKey(window_, GLFW_KEY_D) == GLFW_PRESS ||
      glfwGetKey(window_, GLFW_KEY_RIGHT) == GLFW_PRESS) {
    move += kMoveSpeed * dt;
  }
  if (move != 0.0f) {
    player_.Move(move);
  }

  const bool attack_pressed =
      glfwGetKey(window_, GLFW_KEY_SPACE) == GLFW_PRESS ||
      glfwGetKey(window_, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS;
  if (attack_pressed && attack_cooldown_ <= 0.0f) {
    player_.TryAttack(&ai_, AttackType::kHeavy);
    attack_cooldown_ = kAttackCooldownSeconds;
  }
}

void Game::Update(float dt) {
  attack_cooldown_ = std::max(0.0f, attack_cooldown_ - dt);
  ai_attack_cooldown_ = std::max(0.0f, ai_attack_cooldown_ - dt);

  if (player_.position_x() < kWorldMinX) {
    player_.Move(kWorldMinX - player_.position_x());
  } else if (player_.position_x() > kWorldMaxX) {
    player_.Move(kWorldMaxX - player_.position_x());
  }

  if (ai_.position_x() < kWorldMinX) {
    ai_.Move(kWorldMinX - ai_.position_x());
  } else if (ai_.position_x() > kWorldMaxX) {
    ai_.Move(kWorldMaxX - ai_.position_x());
  }

  UpdateAI(dt);
}

void Game::UpdateAI(float dt) {
  if (ai_.is_ko() || player_.is_ko()) {
    return;
  }

  const float distance = player_.position_x() - ai_.position_x();
  const float abs_distance = std::fabs(distance);

  // Move towards player if too far, retreat slightly if overlapping.
  if (abs_distance > 1.5f) {
    const float direction = distance > 0 ? 1.0f : -1.0f;
    ai_.Move(direction * kMoveSpeed * 0.6f * dt);
    ai_move_direction_ = direction;
  } else if (abs_distance < 0.8f) {
    ai_.Move(-ai_move_direction_ * kMoveSpeed * 0.4f * dt);
  }

  if (abs_distance <= MakeAttack(AttackType::kLight).range &&
      ai_attack_cooldown_ <= 0.0f) {
    const AttackType type =
        (std::rand() % 2 == 0) ? AttackType::kLight : AttackType::kHeavy;
    ai_.TryAttack(&player_, type);
    ai_attack_cooldown_ = kAiAttackCooldownSeconds;
  }
}

void Game::Render() {
  if (headless_ || !window_) {
    return;
  }

  glClearColor(0.05f, 0.07f, 0.1f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);

  glLoadIdentity();

  // Ground
  glColor3f(0.2f, 0.25f, 0.3f);
  glBegin(GL_QUADS);
  glVertex2f(-6.0f, -2.0f);
  glVertex2f(6.0f, -2.0f);
  glVertex2f(6.0f, -3.0f);
  glVertex2f(-6.0f, -3.0f);
  glEnd();

  // Fighters
  DrawRect(player_.position_x() - 0.4f, -2.0f, 0.8f, 1.6f, 0.2f, 0.6f, 0.9f);
  DrawRect(ai_.position_x() - 0.4f, -2.0f, 0.8f, 1.6f, 0.9f, 0.35f, 0.35f);

  // Health bars
  const float player_ratio =
      static_cast<float>(player_.health()) / static_cast<float>(player_.max_health());
  const float ai_ratio =
      static_cast<float>(ai_.health()) / static_cast<float>(ai_.max_health());

  DrawHealthBar(-5.5f, 2.1f, 4.5f, 0.35f, player_ratio, 0.2f, 0.8f, 0.4f);
  DrawHealthBar(1.0f, 2.1f, 4.5f, 0.35f, ai_ratio, 0.9f, 0.4f, 0.2f);
}

void Game::Shutdown() {
  if (window_) {
    glfwDestroyWindow(window_);
    window_ = nullptr;
  }
  if (!headless_) {
    glfwTerminate();
  }
  initialized_ = false;
}

void Game::TickSecond() {
  if (remaining_time_seconds_ > 0) {
    --remaining_time_seconds_;
  }
}

RoundResult Game::GetRoundResult() const {
  if (player_.is_ko() && ai_.is_ko()) {
    return RoundResult::kDraw;
  }
  if (ai_.is_ko()) {
    return RoundResult::kPlayerWins;
  }
  if (player_.is_ko()) {
    return RoundResult::kAiWins;
  }
  if (remaining_time_seconds_ > 0) {
    return RoundResult::kInProgress;
  }
  if (player_.health() > ai_.health()) {
    return RoundResult::kPlayerWins;
  }
  if (ai_.health() > player_.health()) {
    return RoundResult::kAiWins;
  }
  return RoundResult::kDraw;
}

}  // namespace game
