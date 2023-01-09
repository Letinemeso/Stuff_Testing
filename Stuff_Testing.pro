TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

INCLUDEPATH += "../MDL_Parser/include"
LIBS += "../../MDL_Parser/Build/libMDL_Parser.a"

INCLUDEPATH += "../Utility/include"
INCLUDEPATH += "../Utility/include/Data_Structures"
INCLUDEPATH += "../Utility/include/Debug"
LIBS += "../../Utility/Build/libUtility.a"
