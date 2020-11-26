#ifndef BASIC_CAMERA_HPP
#define BASIC_CAMERA_HPP

#include <string>

#include "camera_app.hpp"

using std::string;

struct BasicCamera : public CameraApp
{
    string share(const SHARE_BEHAVIOR shareBehavior)
    {
        ShareBehavior *behavior = nullptr;
        switch (shareBehavior)
        {
        case SHARE_BEHAVIOR::EMAIL:
            behavior = new ShareWithEmail();
        case SHARE_BEHAVIOR::SOCIAL_MEDIA:
            behavior = new ShareWithSocialMedia();
        default:
            return "Not Available";
        }
        return behavior->share();
    }
};

#endif