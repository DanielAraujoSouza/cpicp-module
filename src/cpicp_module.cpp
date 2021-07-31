#include <napi.h>
#include "../include/wrappers.h"

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
  exports.Set(Napi::String::New(env, "CloudPartitioning"),
              Napi::Function::New(env, CloudPartitioningPromise));
  exports.Set(Napi::String::New(env, "CloudPartitioningSync"),
              Napi::Function::New(env, CloudPartitioningSync));
  return exports;
}

NODE_API_MODULE(addon, Init)