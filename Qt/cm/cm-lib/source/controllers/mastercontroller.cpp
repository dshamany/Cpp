#include "mastercontroller.h"

namespace cm {
namespace controller {
MasterController::MasterController(QObject *parent) : QObject(parent)
{
    welcomeMessage = "This is MasterController to Major Tom.";
}

}}
