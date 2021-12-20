package com.myturbo2;
import androidx.annotation.NonNull;

import com.example.samplelibrary.NativeSampleLibrarySpec;
import com.facebook.react.bridge.Promise;
import com.facebook.react.bridge.ReactApplicationContext;
public class NativeSampleLibrary extends NativeSampleLibrarySpec{
    public static final String NAME = "NativeSampleLibrary";

    public NativeSampleLibrary(ReactApplicationContext reactContext) {
        super(reactContext);
    }

    @Override
    public void getString(String id, Promise promise) {
        promise.resolve("test " + id + NAME);
    }

    @NonNull
    public String getName() {
        return NAME;
    }
}
