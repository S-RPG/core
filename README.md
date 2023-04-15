# core

Este é o repositório principal do RPG

# Regras de desenvolvimento

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
