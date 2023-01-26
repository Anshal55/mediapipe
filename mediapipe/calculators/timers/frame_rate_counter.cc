/**
 * @file frame_rate_counter.cc
 * @author Anshal Singh
 * @brief A calculator that takes in the final output as an input and detects
 * the fps of the module
 * @version 0.1
 * @date 2023-01-26
 * @copyright Copyright (c) 2023
 */

// NOTE: Usage of the calculator
// node {
//   calculator: "FrameRateCounter"
//   input_stream: "INPUT:landmarks"
//   output_stream: "FPS:frame_rate"
// }

#include "mediapipe/calculators/timers/frame_rate_counter.h"

namespace mediapipe {
namespace {
constexpr char kInputTag[] = "INPUT";
constexpr char kFpsTag[] = "FPS";

} // namespace

absl::Status FrameRateCounter::GetContract(CalculatorContract *cc) {
  cc->SetProcessTimestampBounds(true);

  RET_CHECK(cc->Inputs().HasTag(kInputTag)) << "Input stream not provided.";
  if (cc->Inputs().HasTag(kInputTag)) {
    cc->Inputs().Tag(kInputTag).SetAny();
  }

  if (cc->Outputs().HasTag(kFpsTag)) {
    cc->Outputs().Tag(kFpsTag).Set<int>();
  }

  return absl::OkStatus();
}

absl::Status FrameRateCounter::Open(CalculatorContext *cc) {
  cc->SetOffset(TimestampDiff(0));

  return absl::OkStatus();
}

absl::Status FrameRateCounter::Process(CalculatorContext *cc) {

  // final output
  auto frame_rate = absl::make_unique<int>(NULL);

  // ! code to calculate fps
  auto curr_time = TIME_NOW();
  fps++;

  auto time_diff = TIME_DIFF(start_time, curr_time);

  if (time_diff >= 1) {
    LOG(INFO) << "FPS = " << (int)(fps / time_diff);
    std::cout << "FPS = " << (int)(fps / time_diff) << "\n";
    start_time = curr_time;
    *frame_rate = fps;
    fps = 0;
  }

  // NOTE: get the face ids and corresponding locations of the faces
  // template typename<type>
  const Packet &input_packet = cc->Inputs().Tag(kInputTag).Value();

  //? send the final outputs
  cc->Outputs().Tag(kFpsTag).Add(frame_rate.release(), cc->InputTimestamp());

  return absl::OkStatus();
}

absl::Status FrameRateCounter::Close(CalculatorContext *cc) {
  return absl::OkStatus();
}
REGISTER_CALCULATOR(FrameRateCounter);

} // namespace mediapipe