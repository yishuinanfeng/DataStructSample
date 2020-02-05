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

//        val hashMap = KHashMap<String,String>()
//        hashMap.put("1","a")
//        hashMap.put("2","b")
//        hashMap.put("3","c")
//        hashMap.put("4","d")
//        hashMap.put("5","v")
//        hashMap.put("6","a")
//        hashMap.put("7","b")
//        hashMap.put("8","c")
//        hashMap.put("9","d")
//        hashMap.put("10","v")
//        hashMap.put("11","a")
//        hashMap.put("12","b")
//        hashMap.put("13","c")
//        hashMap.put("14","d")
//        hashMap.put("15","v")
//        hashMap.put("16","a")
//        hashMap.put("17","b")
//        hashMap.put("18","c")
//        hashMap.put("19","d")
//        hashMap.put("20","v")
//        hashMap.put("20","sdfd")
//
//        Log.d(HASHMAP_TAG,hashMap.get("1"))
//        Log.d(HASHMAP_TAG,hashMap.get("2"))
//        Log.d(HASHMAP_TAG,hashMap.get("3"))
//        Log.d(HASHMAP_TAG,hashMap.get("4"))
//        Log.d(HASHMAP_TAG,hashMap.get("5"))
//        Log.d(HASHMAP_TAG,hashMap.get("6"))
//        Log.d(HASHMAP_TAG,hashMap.get("7"))
//        Log.d(HASHMAP_TAG,hashMap.get("8"))
//        Log.d(HASHMAP_TAG,hashMap.get("9"))
//        Log.d(HASHMAP_TAG,hashMap.get("10"))
//        Log.d(HASHMAP_TAG,hashMap.get("11"))
//        Log.d(HASHMAP_TAG,hashMap.get("12"))
//        Log.d(HASHMAP_TAG,hashMap.get("13"))
//        Log.d(HASHMAP_TAG,hashMap.get("14"))
//        Log.d(HASHMAP_TAG,hashMap.get("15"))
//        Log.d(HASHMAP_TAG,hashMap.get("16"))
//        Log.d(HASHMAP_TAG,hashMap.get("17"))
//        Log.d(HASHMAP_TAG,hashMap.get("18"))
//        Log.d(HASHMAP_TAG,hashMap.get("19"))
//        Log.d(HASHMAP_TAG,hashMap.get("20"))
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
