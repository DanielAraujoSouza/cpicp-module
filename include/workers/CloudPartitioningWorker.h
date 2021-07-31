/**
 * @file CloudPartitioningWorker.h
 * @author Daniel Araújo Chaves Souza (daniel_araujo@alu.ufc.br)
 * @brief Classe que realiza o processamento de uma promise
 * @version 1.0
 * @date 2021-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef CPICP_WORKERS_H
#define CPICP_WORKERS_H

#include <napi.h>
#include "../cpicp.h"
#include "../common/converters.h"

class CloudPartitioningWorker : public Napi::AsyncWorker
{
public:
  /**
   * @brief Contrói um objeto CloudPartitioningWorker
   * 
   * @param env O ambiente napi_env no qual criar o objeto.
   * @param deferred Objeto que resolve a promessa
   * @param cloud Nuvens de pontos que será particionada
   * @param numPartitions Número de partições em que a nuvem será dividida
   * @param axis Eixo no qual será realizado o particionamento
   */
  CloudPartitioningWorker(Napi::Env &env,
                          Napi::Promise::Deferred &deferred,
                          Cloud *cloud,
                          int numPartitions,
                          char axis) : Napi::AsyncWorker(env),
                                       deferred(deferred),
                                       cloud(cloud),
                                       numPartitions(numPartitions),
                                       axis(axis) {}

  /**
   * @brief Destrói um objeto CloudPartitioningWorker
   * 
   */
  ~CloudPartitioningWorker();

  /**
   * @brief Executa o processamento assíncrono
   * 
   */
  void Execute();

  /**
   * @brief Executa a rotina de sucesso
   * 
   */
  void OnOK();

  /**
   * @brief Executa a rotina de erro
   * 
   * @param error 
   */
  void OnError(Napi::Error const &error);

private:
  Napi::Promise::Deferred deferred;
  Cloud *cloud;
  int numPartitions;
  char axis;
  std::vector<Cloud *> *partitions;
};

#endif // CPICP_WORKERS_H