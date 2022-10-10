#include "src/track_manager.h"

#include <gtest/gtest.h>

using namespace ad;

TEST(TrackManagerTest, TrackCreation) {
    struct RadarData {size_t val;};
    using Radar = Trackable<RadarData>;

    TrackManager<RadarData> radar_manager;

}