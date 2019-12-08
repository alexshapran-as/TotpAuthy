#ifndef QRDECODER_H
#define QRDECODER_H

#include <QImage>
#include <QtAndroidExtras>
#include <opencv2/objdetect/objdetect.hpp>
//#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;

class QrDecoder
{
public:
    QrDecoder();
    QString takePictureAndDecode();
};

#endif // QRDECODER_H
