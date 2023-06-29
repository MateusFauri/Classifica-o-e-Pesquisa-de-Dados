# Quick-Sort

Nesta pasta estão os seguintes arquivos:

- main.cpp: código fonte que faz o gerenciamento da entrada, saída e chamada das funções.
- func.cpp: código fonte das funções de ordenamento desenvolvidas.
- func.h: cabeçalho das funções

Para resolver o lab, é necessário criar um executável para cada parte, pois as diretivas 
'<' e '>' foram utilizadas para leitura e escrita de arquivos.

Para compilar e executar: 
g++ main.cpp func.cpp -o quick
quick.exe "escolha_pivo" "escolha_particionamento" < entrada.txt > saida.txt


escolha_pivo = aleatorio, mediana
escolha_particionamento = lomuto, hoare