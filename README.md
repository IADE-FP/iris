# IADE - Faculdade de Design, Tecnologia e Comunicação da Universidade Europeia
# Fundamentos da Programação

Este projeto pretende ilustrar a leitura e gravação com ficheiros. A evolução do código do projeto deve ser observada através do histórico de commits.

Os dados utilizados neste projeto foram obtidos em [UCI Machine Learning Repository](https://archive.ics.uci.edu/ml/datasets/Iris). O dataset é composto por 150 registos de 3 espécies de flores (Iris setosa, Iris virginica e Iris versicolor). Cada registo é composto por 5 atributos: comprimento da sépala, largura da sépala, comprimento da pétala, largura da pétala e espécie.

Além da leitura dos registos, o programa calcula a média do comprimento da sépala para cada espécie, e grava em ficheiro.

## Compilação e execução

```bash
gcc -Wall -o main main.c iris_records.c
./main
```

O resultado é gravado em `iris_means.csv`.
