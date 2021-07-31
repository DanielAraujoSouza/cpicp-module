/**
 * @file converters.h
 * @author Daniel Araújo Chaves Souza (daniel_araujo@alu.ufc.br)
 * @brief Métodos para converter os tipo Napi nos tipos utilizados pelas rotinas do CP-IPC
 * @version 1.0
 * @date 2021-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef CONVERTERS_H
#define CONVERTERS_H

#include <napi.h>
#include <vector>
#include <string>
#include "../types/Point3.h"
#include "../types/Cloud.h"

/**
 * @brief Converte Napi::String ou Napi::Number em double
 * 
 * @param val Napi::String ou Napi::Number
 * @return double 
 */
double NapiValueToDouble(Napi::Value val);

/**
 * @brief Converte um Napi::Object em um objeto Point3
 * 
 * @param pointObj Objeto que será convertido
 * @return Point3*
 */
Point3 *NapiObjectToPoint3(Napi::Object pointObj);

/**
 * @brief Converte um objeto Point3 em Napi::Object
 * 
 * @param env Variavel que representa o contexto em que o objeto será criado
 * @param point Ponteiro aponta para o objeto Point3 que será convertido
 * @return Napi::Object 
 */
Napi::Object Point3ToNapiObject(const Napi::Env env, Point3 *point);

/**
 * @brief Converte um Napi::Object em um objeto Cloud
 * 
 * @param cloudObj Objeto que será convertido
 * @return Cloud* 
 */
Cloud *NapiObjectToCloud(Napi::Object cloudObj);

/**
 * @brief Converte um objeto Cloud em Napi::Object
 * 
 * @param env Variavel que representa o contexto em que o objeto será criado
 * @param cloud Ponteiro aponta para o objeto Cloud que será convertido
 * @return Napi::Object 
 */
Napi::Object CloudToNapiObject(const Napi::Env env, Cloud *cloud);

#endif /* CONVERTERS_H */