#include <iostream>
#include <thread>
#include <chrono>

#include <notification/notificationcenter.h>
#include <gbbinfra/gbbstoragemanager.h>

#include <google/protobuf/message.h>
#include <amster/bb/Messages.pb.h>

using namespace amster::notification;
using namespace amster::gbbinfra;
using namespace amster::bb;
using namespace std::chrono_literals;
namespace pb = google::protobuf;

int main()
{
    GBBStorageManager _gbbMgr;
    _gbbMgr.initFromConfigFile(DATA_PATH "/gbb.json");

    NotificationCenter _center;
    _center.initFromConfigFile(DATA_PATH "/notification.json");

    std::this_thread::sleep_for(10ms);

    auto _listener = _center.registerMessageMonitor("amster.bb.message.*");
    for(;;){
        auto _msg = _center.waitForMonitoredMessage(_listener);
        // BBTick
        auto _tick = std::dynamic_pointer_cast<const message::BBTick>(_msg);
        if(_tick){
            std::cout << "bb time : " << _tick->bb_time_msec()<< std::endl;
        }else{
            std::cout << "recv msg : " << _msg->GetTypeName() << " \r\n"
                      << _msg->DebugString() << std::endl;
        }
    }
    return 0;
}
