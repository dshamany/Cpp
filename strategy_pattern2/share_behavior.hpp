#ifndef SHARE_BEHAVIOR_HPP
#define SHARE_BEHAVIOR_HPP

#include <string>

using std::string;

enum SHARE_BEHAVIOR
{
    EMAIL,
    BLUETOOTH,
    WIFI,
    SOCIAL_MEDIA,
};

struct ShareBehavior
{
    virtual string share() = 0;
};

struct ShareWithEmail : public ShareBehavior
{
    string share()
    {
        return "Sharing with Email";
    }
};

struct ShareWithBluetooth : public ShareBehavior
{
    string share()
    {
        return "Sharing over Bluetooth";
    }
};

struct ShareWithWifi : public ShareBehavior
{
    string share()
    {
        return "Sharing over Wi-Fi";
    }
};

struct ShareWithSocialMedia : public ShareBehavior
{
    string share()
    {
        return "Sharing with Social Media";
    }
};

#endif