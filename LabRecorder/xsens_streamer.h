#include "lsl_cpp.h"
#include <stdlib.h>
#include <thread>

/*
Generic class for streaming any xsens datagram
*/

using namespace lsl;

struct xsens_streamer {
    stream_info info;
    stream_outlet outlet;
    void virtual stream_data(const char &buffer){};
    xsens_streamer(int num_channels);
};
