#include <iostream>
#include <gtest/gtest.h>

#include "modules/ForcePlatform.h"

static double requiredPrecision(1e-10);

TEST(ForcePlatForm, NoPlatForm){
    ezc3d::c3d c3d("c3dTestFiles/Vicon.c3d");
    ezc3d::Modules::ForcePlatforms pf(c3d);
    EXPECT_EQ(pf.forcePlatforms().size(), 0);
}

TEST(ForcePlatForm, AMTI){
    ezc3d::c3d c3d("c3dTestFiles/Qualisys.c3d");
    ezc3d::Modules::ForcePlatforms pf(c3d);
    const std::vector<ezc3d::Vector3d>& forces(pf.forcePlatform(0).forces());
    const std::vector<ezc3d::Vector3d>& moments(pf.forcePlatform(0).moments());
    const std::vector<ezc3d::Vector3d>& cop(pf.forcePlatform(0).CoP());
    const std::vector<ezc3d::Vector3d>& Tz(pf.forcePlatform(0).Tz());

    EXPECT_NEAR(forces[0](0), 0.13992118835449219, requiredPrecision);
    EXPECT_NEAR(forces[0](1), 0.046148300170898438, requiredPrecision);
    EXPECT_NEAR(forces[0](2), -0.18352508544921872, requiredPrecision);

    EXPECT_NEAR(moments[0](0), 20.867615272954936, requiredPrecision);
    EXPECT_NEAR(moments[0](1), -4.622511359985765, requiredPrecision);
    EXPECT_NEAR(moments[0](2), -29.393223381101276, requiredPrecision);

    EXPECT_NEAR(cop[0](0), 228.81266090518048, requiredPrecision);
    EXPECT_NEAR(cop[0](1), 118.29556977523387, requiredPrecision);
    EXPECT_NEAR(cop[0](2), 0.0, requiredPrecision);

    EXPECT_NEAR(Tz[0](0), 0.0, requiredPrecision);
    EXPECT_NEAR(Tz[0](1), 0.0, requiredPrecision);
    EXPECT_NEAR(Tz[0](2), -44.140528790099872, requiredPrecision);
}
