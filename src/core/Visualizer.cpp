

#include "Core/Application.hpp"
#include "Core/Layer.hpp"

class NNVisualizer : public Application {
public:
  NNVisualizer()::m_nn_visualizer(Layer{}) {}
  virtual ~NNVisualizer() {}

  virtual void on_create() override { m_nn_visualizer.on_attach(); }
  virtual void on_destroy() override { m_nn_visualizer.on_detach(); }

  virtual void update() override { m_nn_visualizer.on_update(); }
  virtual void draw() override { m_nn_visualizer.on_draw(); }

private:
  Layer m_nn_visualizer;
};

Application *create_application() { return new NNVisualizer(); }
