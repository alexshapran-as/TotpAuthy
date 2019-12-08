#include "qrdecoder.h"

QString selectedFileName;

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT void JNICALL
Java_com_mycompany_totpauthy_TotpAuthy_fileSelected(JNIEnv */*env*/,
                                                             jobject /*obj*/,
                                                             jstring results)
{
    selectedFileName = QAndroidJniObject(results).toString();
}

#ifdef __cplusplus
}
#endif

QrDecoder::QrDecoder()
{

}

QString QrDecoder::takePictureAndDecode()
{
    selectedFileName = "#";
    QAndroidJniObject::callStaticMethod<void>("com/mycompany/totpauthy/TotpAuthy",
                                              "captureAnImage",
                                              "()V");
    while(selectedFileName == "#")
        qApp->processEvents();

    if(QFile(selectedFileName).exists())
    {
        QImage img(selectedFileName);
//        Mat inputImage = imread(selectedFileName.toStdString());
//        QRCodeDetector qrDecoder;
        return selectedFileName;
    }
    else {
        return "#";
    }

}
