# PROJETO-SENHA-PRIORIDADE


Você foi contratato para desenvolver um sistema de emissão de senhas para uma agência bancária. O sistema deve atender as solicitações abaixo:

- emissão de senha para atendimento comum

- emissão de senha para atendimento preferencial

- opção para atendimento do cliente pelo caixa

- opção para apresentação da fila de senhas da fila, informando o número da senha e o tipo, ao final mostrar a quantidade de clientes na fila



Para a implementação, considere as seguintes informações:

- um cliente comum chega na agência e pode solicitar a senha para atendimento

- um cliente preferencial chega a agência e pode solicitar a senha para atendimento: nesse momento, o sistema deve priorizar esse atendimento colocando esse cliente na primeira posição da fila caso essa esteja ocupada por um cliente comum, caso o(s) primeiro(s) cliente(s) da fila seja(m) preferencial(is), deverá encontrar a posição para enfileiramento. Essa posição será a primeira na fila (na sequência) que estiver ocupada por um cliente comum. 
