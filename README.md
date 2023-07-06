# NOME DO PROJETO

## core

Este é o repositório principal do RPG

## Apresentação do problema

Este é um programa que simula um jogo baseado no jogo "60 Seconds". O jogo consiste em tomar decisões rápidas em situações de sobrevivência, onde o jogador tem que gerenciar recursos, lidar com eventos aleatórios e garantir a sobrevivência do personagem principal.

## Visão geral da solução (foco na estrutura e desenvolvimento)

O programa é dividido em diferentes arquivos e estruturas para gerenciar diferentes aspectos do jogo. Abaixo está uma visão geral dos principais _headers_ implementados no programa:

**Arquivo "item.hpp"**

Este arquivo contém a definição da estrutura Item, que representa um item no jogo. Cada item possui um nome, tipo, se é consumível, preço, valores de vitalidade e sanidade, quantidade disponível e um ID único.

**Arquivo "loja.hpp"**

Neste arquivo, está a classe Loja, responsável pela gestão das compras e vendas de itens. A classe possui funcionalidades para adicionar itens ao carrinho, removê-los, visualizar o carrinho e efetuar a compra.

**Arquivo "situacao.hpp"**

A classe Situacao, definida neste arquivo, é responsável por gerenciar as diferentes situações do jogo. Cada situação possui um contexto, um conjunto de decisões e um título. A classe permite definir e obter o contexto, as decisões e o título da situação.

**Arquivo "decisao.hpp"**

A estrutura Decisao representa uma decisão no jogo. Cada decisão possui uma alternativa, impacto na sanidade, impacto na vitalidade e um texto.


Para desenvolvimento do programa foram adotadas as seugintes regras de desenvolvimento:

## Regras de desenvolvimento

Vamos utilizar um protocolo a ser seguido pelos desenvolvedores com o objetivo de proteger o código principal de códigos não revisados e facilitar manutenções futuras.

1. **Não realizar "push" direto para a _branch_ principal (`main`) do projeto.**

   - _Sempre criar uma branch nova a cada push, afim de ter o código revisado e aprovado por pelo menos 2 outros desenvolvedores. Dessa forma, protegemos o código principal de códigos falhos, typos e etc..._
   - _Apesar de uma tentativa de subir um código direto para o `main` retornar um erro, devido as regras de permissões estipuladas para essa branch, é importante sempre estar atento em qual branch você está realizando alterações._

2. **Nome da branch com prefixo descritivo da operação.**

   - _Basicamente vamos ter 2 situações para a submissão de novos códigos no projeto:_
     - [`feat`] Incrementar;
     - [`fix`] Alterar;
   - _Utilizar então o prefixo relativo ao papel a ser realizado pelo PR (pull request) seguido por `/` e o no nome da branch, ex.: `feat/nome-da-branch`_ ou `fix/nome-da-branch`.

3. **Commits descritivos e pontuais.**

   - _Evitar "commitar" a cada grande quantidade de código, ou seja, realizar um commit a cada lote de código que pertença a um mesmo contexto._
   - _Ser descritivo no commit, assim como o nome da branch em um mesmo PR (pull request) podemos ter horas em que vamos alterar/remover um código já presente (fix) ou incluir nova lógica/função no código (feat), dessa forma utilizar o prefixo relativo (fix ou feat) seguido de `:` e a descrição daquele commit. Ex.: `git commit -m "feat: inclui função getOdd() na classe Math"` ou `git commit -m "fix: altera nome da função getOdd() -> getUnique()"`._
   - _Essa boa prática facilita a manutenção futura do código, em que se outro desenvolvedor precisar dar manutenção em seu código futuramente ele irá conseguir se guiar pelos commits, evitando assim uma sobrecarga de comentários no código._
   - _Existe a possibilidade de utilizar `wip` (work in progress) em um commit, porém é sempre bom evitar, esse tipo de commit é interessante quando se precisa, por algum motivo, parar o desenvolvimento naquela branch e salvar o progresso feito até ali._

4. **Estar atento as notificações do github para revisões de códigos.**

   - _Para que o projeto não fique parado, é importante sempre estar atento a requisições de revisão de código, dessa forma quanto mais rápido um PR (pull request) é revisado, mais rápido o código principal é incrementado e mais rápido se dá o desenvolvimento do projeto._`

## Comandos úteis

Segue alguns comandos úteis que serão frequentemente utilizados ao longo de todo o desenvolvimento do projeto.

- Atualizar a branch local com o código da branch no github:

  ```bash
  git pull origin <nome/da-branch>
  ```

- Atualizar a branch local com o código da branch `main` no github:

  ```bash
  git pull origin main
  ```

- Criar uma branch nova local:

  ```bash
  git checkout -b <nome/da-branch>
  ```

- Alterar a branch local:
  ```bash
  git checkout <nome/da-branch>
  ```
- Deletar uma branch local:
  ```bash
  git branch -D <nome/da-branch>
  ```
- Adicionar arquivos para commit:

  ```bash
  git add <path/do/arquivo> <path/do/arquivo>
  ```

- Adicionar todos os arquivos modificados para commit:
  ```bash
  git add .
  ```
- Commitar modificações:
  ```bash
  git commit -m "<feat/fix>: <descrição>"
  ```
- Shorthand, adicionar e commitar modificações:
  ```bash
  git add . && git commit -m "<feat/fix>: <descrição>"
  ```
- Subir modificações para o github:
  ```bash
  git push origin <nome/da-branch>
 
- Shorthand, sempre dar push para branch atual:
  ```bash
  git config --global --add --bool push.autoSetupRemote true
  ```


## Funcionamento do Programa

O programa permite que o jogador interaja com o jogo, tomando decisões em diferentes situações e gerenciando os recursos disponíveis. O jogador pode escolher diferentes alternativas e lidar com as consequências das decisões.

## PRINCIPAIS DIFICULDADES ENCONTRADAS

Durante o desenvolvimento do programa, algumas das principais dificuldades encontradas foram:

  - Gerenciar as interações entre as diferentes estruturas e classes do programa, garantindo a consistência e o correto funcionamento do jogo.
  - Implementar a lógica para o processamento das decisões do jogador e as consequências das mesmas.
  - Lidar com eventos aleatórios e suas influências no jogo.

# Conclusão

O programa "60 Seconds" é um jogo emocionante que desafia os jogadores a tomarem decisões rápidas em situações de sobrevivência. Com a implementação das estruturas e classes adequadas, o programa oferece uma experiência imersiva e desafiadora.

Para mais informações sobre o funcionamento detalhado do programa, consulte a documentação completa disponível no diretório "docs".

## Autores

  - Alan Mota Calegari
  - Davi de Carvalho Clark
  - Gustavo Santiago de Magalhães
  - Ricardo Augusto Costa Brito Moraes
  - Washington Aparecido de Jesus Morais