/**
 * @file Cloud.h
 * @author Daniel Araújo Chaves Souza (daniel_araujo@alu.ufc.br)
 * @brief Classe que representa uma coleção de pontos 3D (nuvem de pontos)
 * @version 1.0
 * @date 2021-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef CLOUD_H
#define CLOUD_H

#include <vector>
#include <algorithm>
#include <string>
#include "Point3.h"

class Cloud
{
private:
  int numpts;
  std::vector<Point3 *> *points;

public:
  /**
     * @brief Contrói um objeto Cloud
     * 
     */
  Cloud();

  /**
     * @brief Contrói um objeto Cloud recebendo um vetor de pontos
     * 
     * @param newPoints Vetor de pontos da nuvem
     */
  Cloud(std::vector<Point3 *> *newPoints);

  /**
     * @brief Destroi o objeto Cloud
     * 
     */
  ~Cloud();

  /**
     * @brief Adiciona um ponto a nuvem
     * 
     * @param newPoint Objeto contendo as coordenadas do ponto
     */
  void AddPoint(Point3 *newPoint);

  /**
     * @brief Seta os pontos da nuvem
     * 
     * @param newPoints Vetor de pontos da nuvem
     */
  void SetPoints(std::vector<Point3 *> *newPoints);

  /**
     * @brief Informa a quantidade de pontos que a nuvem possui
     * 
     * @return int Tamanho da nuvem
     */
  int Width();

  /**
     * @brief Retorna o vetor de pontos da nuvem
     * 
     * @return std::vector<Point3*>* vetor de pontos da nuvem
     */
  std::vector<Point3 *> *Points();

  /**
     * @brief Ordena a nuvem a partir de um de seus eixos, por padrão a ordem é feita no eixo z
     * 
     * @param axis Eixo de ordenação ('x', 'y' ou 'z')
     */
  void SortByAxis(char axis);
};

#endif /* CLOUD_H */