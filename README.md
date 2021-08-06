Esse módulo nativo adapta as rotinas de particionamento de nuvens de pontos 3D, presentes no algoritmo de registro _Cloud Partitioning for Iterative Closest Point_ (CP-ICP), desenvolvida em **C++**, ao ambiente javascript **Node.JS**. Esse módulo é desenvolvido utilizando o módulo [_node-addon-api_](https://github.com/nodejs/node-addon-api) que fornece um modelo de objeto **C++** para a API de desenvolvimento de complementos nativos do projeto Node.JS, [Node-API](https://nodejs.org/api/n-api.html). Com o módulo CP-ICP, é possivel realiza o particionamento de nuvens de pontos 3D de forma fácil sem abrir mão do desempenho proporcionado por uma linguagem de programação de mais baixo nível.

## Índice

- [Dependências](#dependências)
- [Instalação](#instalação)
- [Testes](#testes)
- [Uso](#uso)
- [API](#api)
  - [CloudPartitioning](#cloudpartitioning)
  - [CloudPartitioningSync](#cloudpartitioningsync)
- [Exemplos](#exemplos)
  - [Assíncrono](#assíncrono)
  - [Síncrono](#síncrono)
- [Debug](#debug)
- [Tipos de Dados](#tipos-de-dados)
  - [Cloud OBJ](#cloud-obj)

## Dependências

- Uma versão do [Node.js](https://nodejs.org/) instalada;
- Módulo global [node-gyp](https://www.npmjs.com/package/node-gyp);
- Módulo [node-addon-api](https://github.com/nodejs/node-addon-api) (instalado automaticamente no passo seguinte);

## Instalação

> **OBS:** Se ainda não possuir nenhuma versão do Node.JS [faça o download e instale](https://nodejs.org/en/download/).

Em seguida faça o download desse projeto, acesse o diretório do projeto, a partir do terminal, e execute o comando abaixo para instalar, de forma global, o módulo **node-gyp**, responsável por compilar o módulo nativo.

> **OBS:** Para o que **node-gyp** consiga compilar seu código corretamente, o sistema operacional precisa ter as ferramentas de compilação adequadas instaladas. Verifique as dependências, para o seu sistema operacional, no [repositório do projeto node-gyp](https://github.com/nodejs/node-gyp#installation).

```bash
npm install -g node-gyp
```

Em seguida, ainda dentro do diretório do projeto, execute o comando abaixo, para instalar as demais dependências e compilar o módulo:

```bash
npm install
```

## Testes

Para executar o conjunto de testes, após ter realizado a instalação, execute `npm test`:

```bash
npm test
```

## Uso

Como atualmente o módulo ainda não está disponivel no [NPM](https://www.npmjs.com/), a maneira mais facil de instanciá-lo, em seu projeto, é por meio de uma instalação NPM usando diretório local. Para isso, execute o `npm install <folder>`, onde `<folder>` é o caminho para o diretório onde econtra-se o módulo Pontu. Por exemplo, se o módulo estiver no mesmo nível de diretório que seu projeto, bastaria executar, dentro do diretório do seu projeto:

```bash
npm install ../cpicp-module
```

Após incluir o módulo CP-ICP às dependências de seu projeto, basta utilizar a função `require`.

```js
// Carrega o módulo CP-ICP
const cpicp = require('cpicp-module')

// Executa uma função do módulo
const clouds = cpicp.CloudPartitioningSync( ... )
```

## API

As funções assíncronas do módulo **CP-ICP** são baseadas em [Javascript Promises](https://developer.mozilla.org/pt-BR/docs/Web/JavaScript/Reference/Global_Objects/Promise), podendo ser facilmente encadeadas ou executadas em paralelo. As funções assíncronas são o padrão de excução recomendado, entretanto, esse módulo também possui funções síncronas para todos os métodos.

### CloudPartitioning

Método para particionar uma nuvem de pontos 3D de forma assíncrona.

```js
cpicp.CloudPartitioning(cloud, numPartitions, axis)
  .then(clouds => {
    ...
  })
```

- **[IN] cloud** - Objeto correspondente a nuvem que será particionada ([Cloud OBJ](#cloud-obj)).
- **[IN] numPartitions** - Número de partições em que a nuvem será dividida ([Number](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Number)).
- **[IN] axis** - Eixo (**X**, **Y** ou **Z**) referência pelo qual o particionamento será realizado ([String](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String)).
- **[OUT] clouds** - Vetor contendo as sub-nuvens resultantes ([Cloud OBJ](#cloud-obj)).

### CloudPartitioningSync

Método para particionar uma nuvem de pontos 3D de forma síncrona.

```js
const clouds = cpicp.CloudPartitioningSync(cloud, numPartitions, axis)
```

- **[IN] cloud** - Objeto correspondente a nuvem que será particionada ([Cloud OBJ](#cloud-obj)).
- **[IN] numPartitions** - Número de partições em que a nuvem será dividida ([Number](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Number)).
- **[IN] axis** - Eixo (**X**, **Y** ou **Z**) referência pelo qual o particionamento será realizado ([String](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String)).
- **[OUT] clouds** - Vetor contendo as sub-nuvens resultantes ([Cloud OBJ](#cloud-obj)).

## Exemplos

### Assíncrono

```js
const cpicp = require('cpicp-module')

// Argumentos de entrada
const cloud = {
  numpts: 5,
  points: [
    { x: 1, y: 1, z: 1 },
    { x: 2, y: 2, z: 2 },
    { x: 3, y: 3, z: 3 },
    { x: 4, y: 4, z: 4 },
    { x: 5, y: 5, z: 5 },
    { x: 6, y: 6, z: 6 },
    { x: 7, y: 7, z: 7 },
    { x: 8, y: 8, z: 8 },
    { x: 9, y: 9, z: 9 },
  ],
}
const numPartitions = 5
const axis = 'y'

// Executa o particionamento
cpicp.CloudPartitioning(cloud, numPartitions, axis).then((clouds) => {
  console.log(clouds)
})
```

### Síncrono

```js
const cpicp = require('cpicp-module')

// Argumentos de entrada
const cloud = {
  numpts: 5,
  points: [
    { x: 1, y: 1, z: 1 },
    { x: 2, y: 2, z: 2 },
    { x: 3, y: 3, z: 3 },
    { x: 4, y: 4, z: 4 },
    { x: 5, y: 5, z: 5 },
    { x: 6, y: 6, z: 6 },
    { x: 7, y: 7, z: 7 },
    { x: 8, y: 8, z: 8 },
    { x: 9, y: 9, z: 9 },
  ],
}
const numPartitions = 5
const axis = 'y'

// Executa o particionamento
const clouds = cpicp.CloudPartitioningSync(cloud, numPartitions, axis)
console.log(clouds)
```

## Debug

Por padrão, o módulo será compilado com a produção de informações de depuração **desabilitada**. Entretanto isso pode ser bastante útil em cenários de desenvolvimento. Para compilar o módulo, com produção de informações de depuração, execute:

```bash
npm run rebuild-debug
# OU
node-gyp --debug rebuild
```

Em seguida modifique o arquivo `./lib/binding.js` para que seja carregado a vesão **Debug** do módulo, no lugar da versão **Release**. O arquivo `binding.js`, por padrão, carrega a versão **Release** (`const addon = require('../build/Release/cpicp-module-native')`). Para carregar a versão **Debug**, compilada no passo anterior, comente a primeira declaração e adicione ou descomente a seguinte linha:

```js
// Carrega a versão Release
//const addon = require('../build/Release/cpicp-module-native')

// Carrega a versão Debug
const addon = require('../build/Debug/cpicp-module-native')
```

## Tipos de Dados

Formatos de dados utilizados pela API.

### Cloud OBJ

- **numpts** - Contém o total de pontos da nuvem;
- **points** - Vetor de objetos que representam os pontos, as propriedades desse objeto respresentam as cordenadas **x**, **y** e **z** do ponto.

Exemplo:

```js
const cloudObj = {
  numpts: 3,
  points: [
    {
      x: 0.044211581349372864,
      y: -0.02174988202750683,
      z: 0.05041627958416939,
    },
    {
      x: 0.05305223912000656,
      y: -0.02392994426190853,
      z: 0.05167124792933464,
    },
    {
      x: 0.05364399775862694,
      y: -0.023770984262228012,
      z: 0.05163086578249931,
    },
  ],
}
```
