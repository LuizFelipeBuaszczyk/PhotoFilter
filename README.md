# PhotoFilter

O **PhotoFilter** é uma aplicação web para processamento digital de imagens que executa algoritmos diretamente no navegador utilizando **C** compilado para **WebAssembly (WASM)**.

> O projeto está em desenvolvimento inicial ainda, necessitando adaptações da antiga engine escrita em C++ para C.

---

## Tecnologias

- C
- WebAssembly
- JavaScript
- HTML
- CSS

---

## Sobre o projeto

Este projeto surgiu a partir da refatoração de um trabalho desenvolvido para a disciplina de **Processamento Digital de Imagens** do curso de Ciência da Computação.

A versão original utilizava um backend em **C++** responsável por disponibilizar uma API REST para o frontend. Entretanto, motivado pela curiosidade em compreender melhor o funcionamento do **WebAssembly**, decidi reescrever toda a camada de processamento em **C**, executando-a diretamente no navegador.

Durante esse processo, o projeto passou a explorar conceitos como:

- manipulação de memória com ponteiros;
- compartilhamento de memória entre **JavaScript** e **WebAssembly**;
- processamento direto de buffers de imagem (RGBA);
- implementação de algoritmos clássicos de processamento digital de imagens.

O resultado foi uma arquitetura onde o frontend atua apenas como interface, enquanto toda a lógica de processamento é executada pelo módulo em WebAssembly.

---

## Contribuições

Contribuições são sempre bem-vindas!

Se você deseja:

- melhorar a interface do frontend;
- implementar novos algoritmos de processamento de imagens;
- otimizar algoritmos existentes;
- refatorar ou melhorar a arquitetura do projeto;

Se sinta livre para abrir um **Pull Request**. Será um prazer revisar suas contribuições.
