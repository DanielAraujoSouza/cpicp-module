#include <napi.h>
#include "CpicpWorkers.h"

#ifndef CPICP_WRAPPERS_H
#define CPICP_WRAPPERS_H

Napi::Promise CloudPartitioningPromise(const Napi::CallbackInfo& info);

#endif // CPICP_WRAPPERS_H