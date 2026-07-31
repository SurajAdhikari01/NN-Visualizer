#pragma once

class Application {
public:
  Application();
  virtual ~Application();
  virtual void on_create() = 0;
  virtual void on_destroy() = 0;

  void run();
  virtual void update() = 0;
  virtual void draw() = 0;
  bool m_running = true;

private:
};
Application *create_application();
