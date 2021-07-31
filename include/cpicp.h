/**
 * @file cpicp.h
 * @author Daniel Araújo Chaves Souza (daniel_araujo@alu.ufc.br)
 * @brief Rotinas para a execução do CP-ICP
 * @version 1.0
 * @date 2021-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef CPICP_H
#define CPICP_H

#include <cmath>
#include <vector>
#include <stdexcept>
#include "types/Cloud.h"

/**
 * @brief Calcula o tamanho de partição em quantidade de pontos
 * 
 * @param cloudWidth Quantidade de pontos da nuvem
 * @param numPartitions Número de partições
 * @param partitionIdx  Índice da  partição (1, 2, 3, ...)
 * @return int Tamanho da i-ésima partição
 */
int partitionWidth(int cloudWidth, int numPartitions, int partitionIdx);

/**
 * @brief Particiona a nuvem de ponto em n subnuvens em um determinado eixo
 * 
 * @param cloud Nuvem de pontos que vai ser particionada
 * @param numPartitions  Quantidade de partições que serão criadas
 * @param axis Eixo onde será feito o particionamento
 * @return std::vector<Cloud*>* Vetor contendo as subnuvens
 */
std::vector<Cloud *> *cloudPartitioning(Cloud *cloud, int numPartitions, char axis);

#endif /* CPICP_H */