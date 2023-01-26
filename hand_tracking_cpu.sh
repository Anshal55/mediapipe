# -c opt, -c dbg, -c fastbuild

# (minloglevel) Log messages at or above this level. Again, 
# the numbers of severity levels INFO, WARNING, ERROR, and FATAL are 0, 1, 2, and 3, respectively.

# v (int, default=0)
# Show all VLOG(m) messages for m less or equal the value of this flag. Overridable by --vmodule

echo "$(tput setaf 1)$(tput bold)***Building the model!***"
bazel build -c opt --define MEDIAPIPE_DISABLE_GPU=1 mediapipe/examples/desktop/hand_tracking:hand_tracking_cpu
echo "$(tput setaf 2)$(tput bold)***BUILT!***"
echo "$(tput setaf 2)$(tput bold)***Starting Predictions.***"
GLOG_v=$2 GLOG_logtostderr=$1 bazel-bin/mediapipe/examples/desktop/hand_tracking/hand_tracking_cpu \
--calculator_graph_config_file=mediapipe/graphs/hand_tracking/hand_tracking_desktop_live.pbtxt
echo "$(tput setaf 1)$(tput bold)**STOPPED!**$(tput sgr0)"