// #include "Core/Application.hpp"
//
// int main() {
//   auto* app = create_application();
//   app->run();
//   delete app;
//   return 0;
// }

#include <iostream>
#include <mlpack.hpp>

using namespace mlpack;
using namespace arma;

int main() {
  std::cout << "=== mlpack starter: Linear Regression ===\n";

  // --- 1. Generate synthetic data instead of loading a file ---
  // mlpack convention: rows = features, cols = samples
  const size_t nSamples  = 100;
  const size_t nFeatures = 1;

  mat X(nFeatures, nSamples, fill::randu);  // random values in [0,1)
  X *= 10.0;                                // scale to [0,10)

  // True relationship: y = 3x + 2 + noise
  rowvec noise(nSamples, fill::randn);  // gaussian noise
  rowvec y = 3.0 * X.row(0) + 2.0 + 0.5 * noise;

  std::cout << "Data shape -> X: " << X.n_rows << "x" << X.n_cols << ", y: " << y.n_elem << "\n";

  // --- 2. Train/test split (simple manual split) ---
  size_t trainCount = static_cast<size_t>(nSamples * 0.8);

  mat    XTrain = X.cols(0, trainCount - 1);
  mat    XTest  = X.cols(trainCount, nSamples - 1);
  rowvec yTrain = y.cols(0, trainCount - 1);
  rowvec yTest  = y.cols(trainCount, nSamples - 1);

  // --- 3. Train the model ---
  regression::LinearRegression lr(XTrain, yTrain);

  std::cout << "Learned parameters:\n";
  lr.Parameters().print("beta (intercept, slope):");

  // --- 4. Predict on test set ---
  rowvec predictions;
  lr.Predict(XTest, predictions);

  std::cout << "\nPredictions vs Actual (test set):\n";
  for (size_t i = 0; i < predictions.n_elem; ++i) {
    std::cout << "  Predicted: " << predictions(i) << "   Actual: " << yTest(i) << "\n";
  }

  // --- 5. Compute simple error metric (MSE) ---
  double mse = accu(square(predictions - yTest)) / predictions.n_elem;
  std::cout << "\nTest MSE: " << mse << "\n";

  return 0;
}
