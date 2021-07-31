/**
 * @file wrappers.h
 * @author Daniel Araújo Chaves Souza (daniel_araujo@alu.ufc.br)
 * @brief Métodos para particionamento de nuvens de pontos
 * @version 1.0
 * @date 2021-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef WRAPPERS_H
#define WRAPPERS_H

#include <napi.h>
#include "workers/CloudPartitioningWorker.h"

/**
 * @brief Executa o particionamento de forma assíncrona
 * 
 * @param info Contêm informações sobre o contexto no qual o objeto foi chamado
 * @return Napi::Promise 
 */
Napi::Promise CloudPartitioningPromise(const Napi::CallbackInfo &info);

/**
 * @brief Executa o particionamento de forma síncrona
 * 
 * @param info Contêm informações sobre o contexto no qual o objeto foi chamado
 * @return Napi::Value 
 */
Napi::Value CloudPartitioningSync(const Napi::CallbackInfo &info);

#endif // WRAPPERS_H