#include <napi.h>

#include "opencv.hpp"

using namespace Napi;

// N-API Wrapper for FillSudokuWithZeros function
Value FillSudokuWithZerosWrapper(const CallbackInfo& info)
{
    Env env = info.Env();

    // Check the number of arguments
    if (info.Length() < 2)
    {
        TypeError::New(env, "Two paths required").ThrowAsJavaScriptException();
        return env.Null();
    }

    // Check the argument types
    if (!info[0].IsString() || !info[1].IsString())
    {
        TypeError::New(env, "String arguments expected").ThrowAsJavaScriptException();
        return env.Null();
    }

    // Convert Value to C++ type
    std::string srcPath = info[0].As<String>().Utf8Value();
    std::string dstPath = info[1].As<String>().Utf8Value();

    // Call the C++ function
    FillSudokuWithZeros(srcPath, dstPath);

    // for now, return null(undefined)
    return env.Null();
}

Object Init(Env env, Object exports)
{
    // Set the exported function in the exports object
    exports.Set("fillSudokuWithZeros", Function::New(env, FillSudokuWithZerosWrapper));
    return exports;
}

NODE_API_MODULE(mySudokuModule, Init)