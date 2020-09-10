#include "xsens_streamer.h"


xsens_streamer::xsens_streamer(int num_channels) : info("XSens", "MoCap", num_channels), outlet(info) {}

xsens_streamer::stream_data()