/**
 * @file Point3.h
 * @author Daniel Araújo Chaves Souza (daniel_araujo@alu.ufc.br)
 * @brief Classe que representa as coordenadas euclidianas de um ponto (x, y e z)
 * @version 0.1
 * @date 2021-05-07
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef POINT3_H 
#define POINT3_H

class Point3 {
  private:
    double x;
    double y;
    double z;

  public:
    /**
     * @brief Construtor par um novo objeto Point3
     * 
     * @param x Coordenada no eixo x
     * @param y Coordenada no eixo y
     * @param z Coordenada no eixo z
     */
    Point3(double x, double y, double z);

    /**
     * @brief Destroi o objeto Point3
     * 
     */
    ~Point3();

    /**
     * @brief Atualiza os valores das coordenadas de um ponto
     * 
     * @param newX Novo valor da coordenada x
     * @param newY Novo valor da coordenada y
     * @param newZ Novo valor da coordenada z
     */
    void Set(double newX, double newY, double newZ);

    /**
     * @brief Retorna o valor de uma coordenada
     * 
     * @param axis Simbolo da coordenada ('x', 'y' ou 'z')
     * @return double 
     */
    double Get(char axis);
};

#endif /* POINT3_H */