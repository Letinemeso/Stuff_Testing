TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

INCLUDEPATH += \
	"../Utility/include"

LIBS += \
	"../../Utility/Build/libUtility.a";
