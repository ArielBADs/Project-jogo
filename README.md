# Projeto-jogo
Projeto ministrado pelo grupo: Ariel Sharon, João Nascimento, Heitor Higino, Joyce de Oliveira e Criso Albuquerque

# Objetivo
* __Criar um jogo usando a linguagem C com auxílio da biblioteca [Raylib](https://www.raylib.com/index.html), e desenvolver a arte e mecânica do jogo__

# Desenvolvimento
Ao entrarmos em contato com a biblioteca pela primeira vez, sentimos um pouco de deficuldade em entender como ela funcionava, mas com o passar das práticas, conseguimos
usar-la para criar o que precisávamos e desenvolver um jogo em 2D que consiste na movimentação da câmera e na agilidade do personagem para chegar até o final do mapa e terminar-lo. Entretanto, existe também algumas dificuldades para impedir o jogador de terminar tão rápido, como não saber onde o crachá é posicionado e lutar contra a velocidade da onda, que é bem mais rápida que o personagem, porém isso pode ser remediado com itens de velocidade dentro do jogo.

# Desafios
Enfretamos dois grandes desafios, sendo eles, conseguir mapear e desenvolver a colisão do chão e da parede com o personagem em relação ao mapa, já que cada parte do dele
possui uma posição X e Y que é diferente das outras, então uma verificação dessas dimensões deve ser feita a todo momento para condizer com a posição do personagem. O 
segundo maior desafio foi relacionar a colisão do personagem com a animação dele, já que não há um plano fixo para o boneco, pois a posição na dimensão esta sempre alterando, e isso impedia que pudessemos fazer que identificasse quando realizar a animação ou não.

# Resultado
Por fim, este foi o resultado da simulação do projeto:

https://user-images.githubusercontent.com/100333063/234721513-d12274b7-f95d-433c-8f53-dba193cf0244.mp4

