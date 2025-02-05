# Embarcatech_U4C5O12-2 
## Unidade 4 - Capítulo 5
### TAREFA 2 PARTE 2 PISCA-LEDs ONE-SHOT - U4C5O12
#### Autor:
* Roberto Vítor Lima Gomes Rodrigues

#### Vídeo de funcionamento
###### No simulador wokwi:
* https://youtu.be/dGH9-NuCWf4
###### Na placa BitDogLag:
* https://youtu.be/JUw4qK8Fp4Y

#### Instruções de compilação
Certifique-se de que você tem o ambiente configurado conforme abaixo:
* Pico SDK instalado e configurado.
* VSCode com todas as extensões configuradas, CMake e Make instalados.
* Clone o repositório e abra a pasta do projeto, a extensão Pi Pico criará a pasta build
* Clique em Compile na barra inferior, do lado direito (ao lado esquerdo de RUN | PICO SDK)
* Clique em diagram.json
* Dê play

#### Manual do programa
Ao executar o programa, dever-se-á apertar o botão, que iniciará uma interrupção com a seguinte lógica:
* Primeiro serão acesos todos os LEDs, por 3 segundos
* Depois serão acesos 2 LEDs, por 3 segundos
* Em seguida, será aceso 1 LED, por mais 3 segundos
* Por fim, todos os LEDs serão apagados
* Ao final, será necessário apertar novamente o botão para reiniciar a rotina.
Obs.: apertar o botão durante a execução da rotina não causará efeito, apenas uma mensagem no monitor serial indicando que apertar o botão durante a sequência não causa efeito.

* Obs.: documentei todo o código com doxygen, então ao passar o cursos do mouse em cima de qualquer uma das funções, será mostrada uma pequena descrição da implementação
* Obs. II: criei um servidor node para pegar as saídas em série da placa, como mostrado no vídeo.
