# -c opt, -c dbg, -c fastbuild

# (minloglevel) Log messages at or above this level. Again, 
# the numbers of severity levels INFO, WARNING, ERROR, and FATAL are 0, 1, 2, and 3, respectively.

# v (int, default=0)
# Show all VLOG(m) messages for m less or equal the value of this flag. Overridable by --vmodule

echo "***Building the model!***"
bazel build -c opt --copt -DMESA_EGL_NO_X11_HEADERS --copt \
-DEGL_NO_X11 mediapipe/examples/desktop/hand_tracking:hand_tracking_gpu
echo "***BUILT!***"
echo "***Starting Predictions.***"
GLOG_v=$2 GLOG_logtostderr=$1 bazel-bin/mediapipe/examples/desktop/hand_tracking/hand_tracking_gpu \
--calculator_graph_config_file=mediapipe/graphs/hand_tracking/hand_tracking_desktop_live_gpu.pbtxt





# The --compilation_mode option (often shortened to -c, especially -c opt)
# takes an argument of fastbuild, dbg or opt, and affects various C/C++ code-generation options, 
# such as the level of optimization and the completeness of debug tables.
# Bazel uses a different output directory for each different compilation mode, 
# so you can switch between modes without needing to do a full rebuild every time.


#! fastbuild means build as fast as possible: generate minimal debugging information (-gmlt -Wl,-S), and don't optimize. 
#! This is the default. Note: -DNDEBUG will not be set.

#! dbg means build with debugging enabled (-g), so that you can use gdb (or another debugger).

#! opt means build with optimization enabled and with assert() calls disabled (-O2 -DNDEBUG). 
#! Debugging information will not be generated in opt mode unless you also pass --copt -g.