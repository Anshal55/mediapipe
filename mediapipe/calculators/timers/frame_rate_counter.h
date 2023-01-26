#ifndef FRAME_RATE_COUNTER
#define FRAME_RATE_COUNTER

#include "absl/memory/memory.h"
#include "absl/strings/str_cat.h"
#include "absl/strings/str_join.h"
#include "mediapipe/framework/calculator_framework.h"
#include "mediapipe/framework/port/ret_check.h"
#include "mediapipe/framework/port/status.h"

#include <chrono>
#define TIME_NOW() std::chrono::system_clock::now()
#define time_Point std::chrono::time_point<std::chrono::system_clock>
#define TIME_DURATION std::chrono::duration<double>
#define TIME_DIFF(start, end) TIME_DURATION(end - start).count()

namespace mediapipe {
class FrameRateCounter : public CalculatorBase {
public:
  static absl::Status GetContract(CalculatorContract *cc);

  absl::Status Open(CalculatorContext *cc) override;
  absl::Status Process(CalculatorContext *cc) override;
  absl::Status Close(CalculatorContext *cc) override;

private:
  std::chrono::_V2::system_clock::time_point start_time = TIME_NOW();
  int fps = 0;
};

} // namespace mediapipe

#endif // !FRAME_RATE_COUNTER