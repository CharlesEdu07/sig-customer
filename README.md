# SIG-Customer
Projeto desenvolvido na linguagem C na disciplina de Programação


Aluno: Charles Eduardo Araújo de Faria

Orientador: Flavius Gorgonio



SIG-Custumer: Um sistema de controle de cliente


As empresas da atualidade utilizam complexos sistemas gerenciais para,
entre varias outras coisas, controlar seus clientes, alem de ajudar a
a conseguir novos clientes. O presente projeto tem como objetivo propor
um software que implementa funcionalidades basicas relacionadas ao con-
trole de clientes de uma empresa, facilitando a gestao.



Como executar este projeto? Seguem os comandos:


gcc -c -Wall main.c customer.c product.c request.c report.c about.c readers.c util.c

gcc -o teste main.o customer.o product.o request.o report.o about.o readers.o util.o

./teste