#include <napi.h>
#include "../include/cpicpWrapper.h"

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "CloudPartitioning"),
              Napi::Function::New(env, CloudPartitioningPromise));
  return exports;
}

NODE_API_MODULE(addon, Init)