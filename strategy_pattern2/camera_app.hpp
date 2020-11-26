#ifndef CAMERA_APP_HPP
#define CAMERA_APP_HPP

#include <string>
#include <vector>
#include "share_behavior.hpp"

using std::string;
using std::vector;

struct CameraApp
{
    CameraApp() {}
    virtual string take();
    virtual string edit();
    virtual string save();
    virtual string share(const SHARE_BEHAVIOR) = 0;
};

string CameraApp::take()
{
    return "Taking Photo";
}

string CameraApp::edit()
{
    return "Editing Photo";
}

string CameraApp::save()
{
    return "Saving Photo";
}

#endif