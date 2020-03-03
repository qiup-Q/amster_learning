#include <iostream>
#include <thread>
#include <chrono>

#include <notification/notificationcenter.h>
#include <gbbinfra/gbbstoragemanager.h>

#include <amster/bb/Message.pb.h>

using namespace amster::notification;
using namespace amster::gbbinfra;
using namespace std::chrono_literals;

int main()
{
    GBBStorageManager _gbbMgr;
    _gbbMgr.initFromConfigFile(DATA_PATH "/gbb.json");

    NotificationCenter _center;
    _center.initFromConfigFile(DATA_PATH "/notification.json");

    std::this_thread::sleep_for(10ms);

    auto _listener = _center.registerMessageMonitor("amster.bb.message.*");
    auto _msg = _center.waitForMonitoredMessage(_listener);
    BBTick _tick = _msg;
    _tick.DebugString();
    std::cout << "listener : " << _listener << std::endl;
    return 0;
}
