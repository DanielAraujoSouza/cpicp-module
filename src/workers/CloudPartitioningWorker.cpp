#include "../../include/workers/CloudPartitioningWorker.h"

void CloudPartitioningWorker::Execute()
{
  partitions = cloudPartitioning(cloud, numPartitions, axis);
}

void CloudPartitioningWorker::OnOK()
{
  Napi::Array partitionsArr = Napi::Array::New(Env(), partitions->size());
  std::vector<Cloud *>::iterator it;
  uint i = 0;
  for (it = partitions->begin(); it != partitions->end(); ++it)
  {
    partitionsArr[i++] = CloudToNapiObject(Env(), *it);
  }
  deferred.Resolve(partitionsArr);
}

void CloudPartitioningWorker::OnError(Napi::Error const &error)
{
  deferred.Reject(error.Value());
}

CloudPartitioningWorker::~CloudPartitioningWorker()
{
  std::vector<Cloud *>::iterator it;
  for (it = partitions->begin(); it != partitions->end(); ++it)
  {
    delete *it;
  }
  delete partitions;
}