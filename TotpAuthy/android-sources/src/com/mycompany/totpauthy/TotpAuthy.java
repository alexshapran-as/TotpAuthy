package com.mycompany.totpauthy;

import org.qtproject.qt5.android.bindings.QtApplication;
import org.qtproject.qt5.android.bindings.QtActivity;

import android.content.Context;
import android.content.Intent;
import android.database.Cursor;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.net.Uri;
import android.os.Bundle;
import android.os.Environment;
import android.provider.MediaStore;
import android.util.Log;
import android.widget.Toast;

import java.io.File;
import java.io.IOException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public class TotpAuthy extends QtActivity
{

    public static native void fileSelected(String fileName);

    static final int REQUEST_OPEN_IMAGE = 1;
    static final int REQUEST_CAPTURE_IMAGE = 1;

    public String lastCameraFileUri;

    private static TotpAuthy m_instance;

    public TotpAuthy()
    {
        m_instance = this;
    }

    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
    }

    @Override
    protected void onDestroy()
    {
        super.onDestroy();
    }

    static void openAnImage()
    {
        m_instance.dispatchOpenGallery();
    }

    static void captureAnImage()
    {
        m_instance.dispatchTakePictureIntent();
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data)
    {
        if (resultCode == RESULT_OK)
        {
                if (requestCode == REQUEST_CAPTURE_IMAGE)
                {
                        String filePath = lastCameraFileUri;
                        fileSelected(filePath);
                }
        }
        else
        {
                fileSelected("-");
        }

        super.onActivityResult(requestCode, resultCode, data);
    }

    private void dispatchOpenGallery()
    {
        Intent intent = new Intent(Intent.ACTION_GET_CONTENT);
        intent.setType("image/*");
        startActivityForResult(intent, REQUEST_OPEN_IMAGE);
    }

    private File createImageFile() throws IOException
    {
        // Create an image file name
        String timeStamp = new SimpleDateFormat("yyyyMMdd_HHmmss").format(new Date());
        String imageFileName = "MYAPPTEMP_" + timeStamp + "_";
        File storageDir = Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_PICTURES);
        File image = File.createTempFile(imageFileName, /* prefix */
                ".jpg", /* suffix */
                storageDir /* directory */
        );

        return image;
    }

    private void dispatchTakePictureIntent()
    {
        Intent takePictureIntent = new Intent(MediaStore.ACTION_IMAGE_CAPTURE);

        // Ensure that there's a camera activity to handle the intent
        if (takePictureIntent.resolveActivity(getPackageManager()) != null)
        {
                // Create the File where the photo should go
                File photoFile = null;
                try
                {
                        photoFile = m_instance.createImageFile();
                }
                catch (IOException ex)
                {
                        // Error occurred while creating the File
                        Toast.makeText(TotpAuthy.this, ex.getLocalizedMessage(), Toast.LENGTH_LONG).show();
                        Toast.makeText(TotpAuthy.this, ex.getMessage(), Toast.LENGTH_LONG).show();
                }
                // Continue only if the File was successfully created
                if (photoFile != null)
                {
                        takePictureIntent.putExtra(MediaStore.EXTRA_OUTPUT, Uri.fromFile(photoFile));

                        lastCameraFileUri = photoFile.toString();

                        startActivityForResult(takePictureIntent, REQUEST_CAPTURE_IMAGE);
                }
        }
        else
        {
                Toast.makeText(TotpAuthy.this, "Problems with your camera?!", Toast.LENGTH_SHORT).show();
        }
    }

    public String getRealPathFromURI(Context context, Uri contentUri)
    {
        Cursor cursor = null;
        try
        {
            String[] proj = { MediaStore.Images.Media.DATA };
            cursor = context.getContentResolver().query(contentUri,  proj, null, null, null);
            int column_index = cursor.getColumnIndexOrThrow(MediaStore.Images.Media.DATA);
            cursor.moveToFirst();
            return cursor.getString(column_index);
        }
        finally
        {
            if (cursor != null)
            {
                cursor.close();
            }
        }
    }
}

