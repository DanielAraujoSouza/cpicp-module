#include "../include/wrappers.h"

Napi::Promise CloudPartitioningPromise(const Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();
  Napi::Promise::Deferred deferred = Napi::Promise::Deferred::New(env);

  if (info.Length() != 3)
  {
    deferred.Reject(
        Napi::TypeError::New(env, "Wrong number of arguments").Value());
  }
  else if (!info[0].IsObject() || !info[1].IsNumber() || !info[2].IsString())
  {
    deferred.Reject(
        Napi::TypeError::New(env, "Invalid argument types").Value());
  }
  else
  {
    Cloud *cloud = NapiObjectToCloud(info[0].As<Napi::Object>());
    int numPartitions = info[1].As<Napi::Number>().Int32Value();
    char axis = info[2].As<Napi::String>().Utf8Value()[0];

    CloudPartitioningWorker *wk = new CloudPartitioningWorker(env, deferred, cloud, numPartitions, axis);
    wk->Queue();
  }

  return deferred.Promise();
}

Napi::Value CloudPartitioningSync(const Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();
  Napi::Value rtn;

  if (info.Length() != 3)
  {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  else if (!info[0].IsObject() || !info[1].IsNumber() || !info[2].IsString())
  {
    Napi::TypeError::New(env, "Invalid argument types")
        .ThrowAsJavaScriptException();
  }
  else
  {
    Cloud *cloud = NapiObjectToCloud(info[0].As<Napi::Object>());
    int numPartitions = info[1].As<Napi::Number>().Int32Value();
    char axis = info[2].As<Napi::String>().Utf8Value()[0];

    std::vector<Cloud *> *partitions = cloudPartitioning(cloud, numPartitions, axis);

    Napi::Array partitionsArr = Napi::Array::New(env, partitions->size());
    std::vector<Cloud *>::iterator it;
    uint i = 0;
    for (it = partitions->begin(); it != partitions->end(); ++it)
    {
      partitionsArr[i++] = CloudToNapiObject(env, *it);
    }
    rtn = partitionsArr;
  }

  return rtn;
}