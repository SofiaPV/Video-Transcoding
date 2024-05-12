TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        interpolator.cpp \
        main.cpp

QT += widgets
INCLUDEPATH +="/usr/local/include/opencv4"
LIBS += -L"/usr/local/lib/"
LIBS += \
   -lopencv_core \
   -lopencv_features2d \
   -lopencv_highgui \
   -lopencv_imgcodecs \
   -lopencv_imgproc \
   -lopencv_video \
   -lopencv_videoio

HEADERS += \
    interpolator.h
