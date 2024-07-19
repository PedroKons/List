# Implementação de Listas em C++

Este projeto contém implementação de três tipos de listas em c++: lista estática, listas encadeadas e listas duplamente encadeadas.

## Conteúdo

- [Introdução]()
- [Listas Estáticas]()
- [Listas Encadeadas]()
- [Listas Duplamente Encadeadas]()
- [Exemplos de Uso]()
- [Contribuições]()

## Introdução

Este repositório contém exemplos de implementação de três tipos diferentes de listas, muito usadas em estruturas de dados. Cada tipo de lista tem suas vantagens e desvantagens, dependendo do caso de uso específico.

## Listas Estáticas

Listas estáticas são implementadas usando arrays. Elas têm um tamanho fixo que é determinado na criação e nao pode ser alterado durante a execcução do programa.

### Características:

- Tamanho fixo
- Acesso rápido aos elementos
- Inserção e remoção de elementos podem ser custosas

### Arquivo:

- `listaestaticaGEN.h`

### Funções Principais

- 'bool insereFim();'
- 'bool insereInicio();'
- 'bool inserePosicao();'
- 'bool removeFim();'
- 'bool removeInicio();'
- 'bool removePosicao);'

## Listas Encadeadas

Listas encadeadas são compostas por nós, onde cada nó contém um valor e um ponteiro para o próximo nó na lista. Elas permitem um uso eficiente da memória, pois o tamanho da lista pode crescer ou diminuir dinamicamente.

### Características:

- Tamanho dinâmico
- Inserção e remoção de elementos são mais eficientes do que em listas estáticas
- Acesso sequencial aos elementos

### Arquivo:

- `listaencadeadaGEN.h`

### Funções Principais

- 'bool insereFim();'
- 'bool insereInicio();'
- 'bool inserePosicao();'
- 'bool removeFim();'
- 'bool removeInicio();'
- 'bool removePosicao);'

## Listas Duplamente Encadeadas 

Listas duplamente encadeadas são uma extensão das listas encadeadas, onde cada nó possui um ponteiro para o próximo nó e um ponteiro para o nó anterior. Isso permite a navegação em ambas as direções na lista.

### Características:

- Tamanho dinâmico
- Navegação bidirecional
- Inserção e remoção de elementos são eficientes

### Arquivo:

- `listaduplamenteencadeadaGEN.h`

## Exemplos de Uso

### Lista Estática

```cpp

#include "listaestaticaGEN.h"

// Código de exemplo usando a lista estática
TLista<int, 10> lista;
inicializaLista(lista);
insereFim(lista, 5);
insereInicio(lista, 10);

```

## Lista Encadeada

```cpp

#include "listaencadeadaGEN.h"

// Código de exemplo usando a lista encadeada
Tlista<int> lista;
inicializaLista(lista);
insereFim(lista, 5);
insereInicio(lista, 10);
quicksortLista(lista);

```
## Lista Duplamente Encadeada

```cpp

#include "listaduplamenteencadeadaGEN.h"

// Código de exemplo usando a lista duplamente encadeada
TLista<int> lista;
inicializaLista(lista);
insereFim(lista, 5);
insereInicio(lista, 10);
quickSort(lista.inicio, lista.fim);

```

## Contribuições 

Contribuições são bem-vindas! Por favor, abra uma issue ou faça um pull request para contribuir com melhorias.



