#include "../include/cpicpWrapper.h"

Napi::Promise CloudPartitioningPromise(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::Promise::Deferred deferred = Napi::Promise::Deferred::New(env);
  
  if (info.Length() != 3) {
    deferred.Reject(
      Napi::TypeError::New(env, "Wrong number of arguments").Value()
    );
  }
  else if (!info[0].IsObject() || !info[1].IsNumber() || !info[2].IsString()) {
    deferred.Reject(
      Napi::TypeError::New(env, "Invalid argument types").Value()
    );
  }
  else {
    Cloud* cloud = NapiObjectToCloud(info[0].As<Napi::Object>());
    int numPartitions = info[1].As<Napi::Number>().Int32Value();
    char axis = info[2].As<Napi::String>().Utf8Value()[0];

    CloudPartitioningWorker* wk = new CloudPartitioningWorker(env, deferred, cloud, numPartitions, axis);
    wk->Queue();
  }

  return deferred.Promise();
}