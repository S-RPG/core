// const readline = require("readline");
// let resp = "";

// var leitor = readline.createInterface({
//   input: process.stdin,
//   output: process.stdout,
// });

// const decisao_1 = {
//   alternativa: "a",
//   texto: "Sim!",
//   impactoSanidade: 0.1,
//   impactoVitalidade: -0.2,
// };

// const decisao_2 = {
//   alternativa: "b",
//   texto: "Não",
//   impactoSanidade: 0.1,
//   impactoVitalidade: -0.2,
// };

// const decisoes_1 = new Map();
// decisoes_1.set("a", decisao_1);
// decisoes_1.set("b", decisao_2);

// const decisoes = new Map();
// decisoes.set(1, decisoes_1);

// const decisoesMap = new Map();
// decisoesMap.set(1, decisoes_1);
// decisoesMap.set(2, decisoes_1);
// decisoesMap.set(3, decisoes_1);

// const situacao_1 = {
//   id: 1,
//   titulo: "Ola, um novo dia começou",
//   contexto: "Bla bla bla bla bla\n",
//   decisoesId: 1,
//   dia: 1,
// };

// const situacao_2 = {
//   id: 2,
//   titulo: "Situação 2, omg!",
//   contexto: "Bla bla bla bla bla...",
//   decisoesId: 2,
//   dia: 2,
// };
// const situacao_3 = {
//   id: 3,
//   titulo: "Situação 3, ufa!",
//   contexto: "Bla bla bla bla bla...",
//   decisoesId: 3,
//   dia: 2,
// };

// const situacoes_dia_1 = [situacao_1];
// const situacoes_dia_2 = [situacao_2, situacao_3];

// const situacoes_dias = [situacoes_dia_1, situacoes_dia_2];

// let vida = true;
// while (vida) {
//   for (const situacoes_dia of situacoes_dias) {
//     let proximoDia = false;
//     let situacoesCompletadas = false;

//     while (!proximoDia) {
//       if (!situacoesCompletadas) {
//         for (const situacao of situacoes_dia) {
//           console.log(
//             `[Dia: ${situacao.dia}]\n🚩 ${situacao.titulo} 🚩\n${situacao.contexto}\n`
//           ); // std::cout
//           const decisoesDisponiveis = decisoes.get(situacao.id);
//           for (const [alternativa, decisao] of decisoesDisponiveis) {
//             console.log(`${alternativa}) ${decisao.texto}`);
//           }

//           leitor.question("R.: ", (answer) => {
//             resp = answer;

//             leitor.close();
//           });
//           const alternativaSelecionada = decisoesDisponiveis.get(resp);
//           console.log("Alteracao na vitalidade do personagem... ");
//           console.log("Alteracao na vitalidade do personagem... ");
//         }
//       }
//       situacoesCompletadas = true;
//       console.log("Exibindo status do personagem...");
//       console.log("Exibindo outras informações importantes...\n\n");
//       leitor.question(
//         "(L) Loja - (I) - Inventário - (S) Status - (0) Próximo dia\nR.:",
//         (answer) => {
//           resp = answer;

//           leitor.close();
//         }
//       );

//       switch (resp) {
//         case "L":
//           console.log("Exibindo loja...");
//           // lojaFn();
//           break;

//         case "I":
//           console.log("Exibindo Inventário...");
//           // inventarioFn();
//           break;

//         case "S":
//           console.log("Exibindo status do personagem...");
//           // personagemFn();
//           break;

//         case "0":
//           console.log("Proximo dia...");
//           proximoDia = true;
//           break;
//       }
//     }
//   }
//   vida = false;
// }
// console.log("vc morreu doidao");
const campoTipo = "       TIPO       ";
const campoVitalidade = " VITALIDADE ";
const campoSanidade = " SANIDADE ";

let output = `Item(QNT?)          |${campoTipo} | ${campoVitalidade} | ${campoSanidade}|`;
output =
  `\n${"".padEnd(output.length, "-")}\n` +
  output +
  `\n${"".padEnd(output.length, "-")}\n`;
const items = new Map();
items.set(0, {
  id: 0,
  nome: "Leite",
  vitalidade: 0.1,
  quantidade: 3,
  tipo: "ALIMENTO",
  consumivel: true,
});

items.set(1, {
  id: 1,
  nome: "Faca",
  tipo: "ARMA",
});

items.set(2, {
  id: 2,
  nome: "Cigarro",
  tipo: "ENTRETENIMENTO",
  vitalidade: -0.1,
  sanidade: 0.2,
  quantidade: 10,
  consumivel: true,
});
for (let itemId = 0; itemId < items.size; itemId++) {
  const item = items.get(itemId);
  const itemName = `${item.nome}${
    item.quantidade ? "(" + item.quantidade + ")" : ""
  }`;
  const itemVitalidade = item.vitalidade ? `${item.vitalidade}` : " - ";
  const itemSanidade = item.sanidade ? `${item.sanidade}` : " - ";
  output =
    output +
    itemName.padEnd(20, " ") +
    `|${item.tipo
      .padStart(
        item.tipo.length + (campoTipo.length / 2 - item.tipo.length / 2),
        " "
      )
      .padEnd(
        item.tipo.length + (campoTipo.length - item.tipo.length),
        " "
      )} | ${itemVitalidade
      .padStart(
        itemVitalidade.length +
          (campoVitalidade.length / 2 - itemVitalidade.length / 2),
        " "
      )
      .padEnd(
        itemVitalidade.length +
          (campoVitalidade.length - itemVitalidade.length),
        " "
      )} | ${itemSanidade
      .padStart(
        itemSanidade.length +
          (campoSanidade.length / 2 - itemSanidade.length / 2),
        " "
      )
      .padEnd(
        itemSanidade.length + (campoSanidade.length - itemSanidade.length),
        " "
      )}|\n`;
}

console.log(output);
