# PSI-Microcontroladores2-Aula01

Atividade prática inicial da aula 1 da disciplina Microcontroladores 2 (PSI).

Registre sua evolução utilizando os checklists abaixo por meio de commits com mensagens descritivas:

### Setup (individual)
- [x] Possuo VSCode instalado
- [x] Possuo MCUXpresso instalado
- [x] Possuo PlatformIO instalado
- [x] Possuo cabo USB compatível com Placa Freedom
- [x] Possuo Placa Freedom operacional
- [x] Possuo Zephyr atualizado para versão 4.2

Materiais para consulta: https://frdm-kl25z-com-zephyr-rtos.super.site/instalao, https://frdm-kl25z-com-zephyr-rtos.super.site/tutoriais/1-exemplo-pisca-led-rtos/atualizao-para-o-zephyr-42

### Atividade Baremetal (implementação individual, validação em dupla)
- [x] Crie uma branch chamada baremetal
- [x] Compile e execute o exemplo de piscar led baremetal na placa Freedom com o Zephyr versão 4.2 (vide [https://frdm-kl25z-com-zephyr-rtos.super.site/tutoriais/2-pisca-led-simples](https://frdm-kl25z-com-zephyr-rtos.super.site/tutoriais/1-exemplo-pisca-led-rtos/atualizao-para-o-zephyr-42)). Dica: Utilize por enquanto somente o led da placa
- [x] Faça alterações no código para controlar dois leds: um led deve piscar a cada segundo, e o segundo led deve piscar a cada meio segundo
- [x] Desafio: tente fazer com que o primeiro led pisque a cada segundo, e o segundo led pisque a cada 350 ms
- [x] Crie um planejamento de testes para verificação do correto funcionamento, detalhando quais são os resultados esperados
- [ ] Abra uma Pull Request
- [ ] Seu par irá avaliar a Pull Request: adicionar sugestões em issues ou na discussão do PR (ATENÇÃO: o par deve tentar executar os testes propostos, e mesmo em caso de tudo funcionar, registrar em comentários como a validação foi realizada)
- [ ] Após as pendências serem resolvidas, seu par irá validar as melhorias e aceitar a PR

### Atividade Threads (implementação individual, validação em dupla)
- [ ] Crie uma branch chamada threads
- [ ] Compile e execute o exemplo de piscar led com threads na placa Freedom (vide [https://github.com/platformio/platform-freescalekinetis/blob/develop/examples/zephyr-blink/src/main.c e https://frdm-kl25z-com-zephyr-rtos.super.site/tutoriais/1-exemplo-pisca-led-rtos](https://frdm-kl25z-com-zephyr-rtos.super.site/tutoriais/threads-zephyr-42))
- [ ] Faça alterações no código para controlar dois leds: um led deve piscar a cada segundo, e o segundo led deve piscar a cada meio segundo
- [ ] Desafio: tente fazer com que o primeiro led pisque a cada segundo, e o segundo led pisque a cada 350 ms
- [ ] Crie um planejamento de testes para verificação do correto funcionamento, detalhando quais são os resultados esperados
- [ ] Abra uma Pull Request
- [ ] Seu par irá avaliar a Pull Request: adicionar sugestões em issues ou na discussão do PR (ATENÇÃO: o par deve tentar executar os testes propostos, e mesmo em caso de tudo funcionar, registrar em comentários como a validação foi realizada)
- [ ] Após as pendências serem resolvidas, seu par irá validar as melhorias e aceitar a PR

### Desafio (individual)
- [ ] Explore recursos de debug e faça um arquivo markdown mostrando como estes recursos podem ser úteis na identificação e correção de problemas
- [ ] Reflita e responda em seu arquivo markdown: qual a diferença entre os recursos de debug e testes? São abordagens complementares?



### Planejamento de testes para a verificação do código:

segundo o projeto desenvolvido, um led deve ligar à cada 350 ms e o outro à cada 1000 ms. Isso significa que eles piscam juntos à cada 7s. Existem duas formas de fazer o teste:

#### Forma 1: verificação visual
Você pode observar o led piscando e ver que ele pisca de forma composta. Com isso, dá pra observar que à cada 7 segundos, led pisca em ciano, que é a composição de ambos os sinais

#### Forma 2: Verificação por serial

no código estará comentada uma opção de teste para verificar a funcionalidade de ambos os leds. pode usá-la conectando o microcontrolador, compilando o código e vendo a porta serial.
