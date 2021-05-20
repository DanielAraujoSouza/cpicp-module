#include <napi.h>
#include "cpicp.h"
#include "types.h"

#ifndef CPICP_WORKERS_H
#define CPICP_WORKERS_H

class CloudPartitioningWorker : public Napi::AsyncWorker {
  public:
    CloudPartitioningWorker(Napi::Env &env,
      Napi::Promise::Deferred &deferred,
      Cloud* cloud,
      int numPartitions,
      char axis) : Napi::AsyncWorker(env),
        deferred(deferred),
        cloud(cloud),
        numPartitions(numPartitions),
        axis(axis) {}
    
    ~CloudPartitioningWorker();

    void Execute();

    void OnOK();

    void OnError(Napi::Error const &error);

  private:
    Napi::Promise::Deferred deferred;
    Cloud* cloud;
    int numPartitions;
    char axis;
    std::vector<Cloud*>* partitions;
};

#endif // CPICP_WORKERS_H