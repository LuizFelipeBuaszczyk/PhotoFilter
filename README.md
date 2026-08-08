<div align="center">
    <img src="docs/logo.png" width="200" height="200" alt="PhotoFilter logo" style="border-radius: 45px;">
</div>

# PhotoFilter

O **PhotoFilter** é uma aplicação web para processamento digital de imagens que executa algoritmos diretamente no navegador utilizando **C** compilado para **WebAssembly (WASM)**.

---

## Tecnologias

- C
- WebAssembly
- JavaScript
- HTML
- CSS

---

## Como Rodar localmente

Para rodar localmente é necessário ter um compilador como o **Emscripten** para executar a compilação.

1. Clone o projeto
```sh
git clone http://github.com/luizfelipebuaszczyk/PhotoFilter
```

2. Dentro do repositório compile com **Emscripten**

```sh
emcc backend/main.c backend/src/* -I backend/include -o frontend/engine.js -sSTACK_SIZE=5000000
```

3. Inicie um servidor HTTP de sua preferência para o frontend.

```sh
cd frontend/ && python -m http.server 80
```

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
