#ifndef CAMERA_PLUS_HPP
#define CAMERA_PLUS_HPP

#include <string>
#include "camera_app.hpp"

// extend sharing within the class
struct ShareWithEncryptedSources : public ShareBehavior
{
    std::string share()
    {
        return "Sharing Securely";
    }
};

struct ShareWithNFC : public ShareBehavior
{
    std::string share()
    {
        return "Sharing with NFC";
    }
};

enum EXT_SHARE_BEHAVIOR
{
    ENCRYPTED = 1001, // set int to diffirentiate enum
    NFC,
};

struct CameraPlus
{
    std::string share(const int &shareBehavior)
    {
        ShareBehavior *behavior = nullptr;
        switch (shareBehavior)
        {
        case SHARE_BEHAVIOR::BLUETOOTH:
            behavior = new ShareWithBluetooth();
            break;
        case SHARE_BEHAVIOR::WIFI:
            behavior = new ShareWithWifi();
            break;
        case SHARE_BEHAVIOR::EMAIL:
            behavior = new ShareWithEmail();
            break;
        case SHARE_BEHAVIOR::SOCIAL_MEDIA:
            behavior = new ShareWithSocialMedia();
            break;
        case EXT_SHARE_BEHAVIOR::ENCRYPTED:
            behavior = new ShareWithEncryptedSources();
            break;
        case EXT_SHARE_BEHAVIOR::NFC:
            behavior = new ShareWithNFC();
            break;
        default:
            return "Not Available";
        }
        return behavior->share();
    }
};

#endif