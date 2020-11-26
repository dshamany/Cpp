#include <iostream>

#include "camera_app.hpp"
#include "basic_camera.hpp"
#include "camera_plus.hpp"

int main(int argc, char const *argv[])
{
    BasicCamera camera;
    CameraPlus pCamera;

    std::cout << camera.share(SHARE_BEHAVIOR::SOCIAL_MEDIA) << '\n';
    std::cout << pCamera.share(EXT_SHARE_BEHAVIOR::NFC) << '\n';
    return 0;
}
