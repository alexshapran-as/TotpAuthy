QT       += core gui
QT       += network
QT       += androidextras

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
#DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += QGOOGLEAUTH_LIBRARY

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    accountitem.cpp \
    base32.cpp \
    hmac.cpp \
    main.cpp \
    qgoogleauth.cpp \
    qrdecoder.cpp \
    secretkeyform.cpp \
    totpauthy.cpp

HEADERS += \
    accountitem.h \
    base32.h \
    hmac.h \
    qgoogleauth.h \
    qgoogleauth_global.h \
    qrdecoder.h \
    secretkeyform.h \
    totpauthy.h

FORMS += \
    accountitem.ui \
    secretkeyform.ui \
    totpauthy.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icons.qrc

DISTFILES += \
    android-sources/AndroidManifest.xml \
    android-sources/libopencv_java.so \
    android-sources/src/com/mycompany/myappname/totpauthy.java \
    android-sources/src/com/mycompany/totpauthy/TotpAuthy.java \
    android-sourceslibsarmeabi-v7a/libopencv_java.so

INCLUDEPATH += "$$_PRO_FILE_PWD_/OpenCV-2.4.10-android-sdk/sdk/native/jni/include"
android {
    LIBS += \
        -L"$$_PRO_FILE_PWD_/OpenCV-2.4.10-android-sdk/sdk/native/3rdparty/libs/armeabi-v7a"\
        -L"$$_PRO_FILE_PWD_/OpenCV-2.4.10-android-sdk/sdk/native/libs/armeabi-v7a"\
        -llibtiff\
        -llibjpeg\
        -llibjasper\
        -llibpng\
        -lIlmImf\
        -ltbb\
        -lopencv_core\
        -lopencv_androidcamera\
        -lopencv_flann\
        -lopencv_imgproc\
        -lopencv_highgui\
        -lopencv_features2d\
        -lopencv_calib3d\
        -lopencv_ml\
        -lopencv_objdetect\
        -lopencv_video\
        -lopencv_contrib\
        -lopencv_photo\
        -lopencv_java\
        -lopencv_legacy\
        -lopencv_ocl\
        -lopencv_stitching\
        -lopencv_superres\
        -lopencv_ts\
        -lopencv_videostab

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android-sources
}

