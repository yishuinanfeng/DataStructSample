package com.haha.datastructuresample

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import com.haha.datastructuresample.hashMap.KHashMap
import kotlinx.android.synthetic.main.activity_main.*

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        // Example of a call to a native method
        sample_text.text = stringFromJNI()

        val hashMap = KHashMap<String,String>()
        hashMap.put("1","a")
        hashMap.put("2","b")
        hashMap.put("3","c")
        hashMap.put("4","d")

        Log.d(HASHMAP_TAG,hashMap.get("1"))
        Log.d(HASHMAP_TAG,hashMap.get("2"))
        Log.d(HASHMAP_TAG,hashMap.get("3"))
        Log.d(HASHMAP_TAG,hashMap.get("4"))
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    external fun stringFromJNI(): String

    companion object {

        // Used to load the 'native-lib' library on application startup.
        init {
            System.loadLibrary("native-lib")
        }
    }
}
