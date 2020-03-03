TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

CONFIG -= debug_and_release build_all

AMSTER_SDK_PATH = $$(AMSTERFWK)

AMSTER_LIB_DEPENDS += notification gbbinfra
include($$AMSTER_SDK_PATH/amster.pri)

DEFINES += DATA_PATH=\\\"$$PWD\\\"

#message(include_paths: $$INCLUDEPATH)
#message(libs: $$LIBS)
#message(amster path: $$AMSTER_SDK_PATH)

DISTFILES += \
    gbb.json \
    notification.json
