#include "core/Application.hpp"
#include <raylib.h>
Application::Application() {}
Application::~Application() {}
void Application::run() {
  SetTraceLogLevel(LOG_NONE);
  on_create();
  while (!WindowShouldClose() && m_running) {
    update();
    draw();
  }
  on_destroy();
};
