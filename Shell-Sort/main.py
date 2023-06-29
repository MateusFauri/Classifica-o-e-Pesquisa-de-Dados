import shellSort as sort

linha = 0
nome_arquivo = str(input("Nome do arquivo entrada: ").strip().lower())
nome_saida = str(input("Nome arquivo saida: ").strip().lower())
tipo_saida = int(input("Tipo do arquivo saida: ").strip())

saida = open(nome_saida,'w')

with open(nome_arquivo) as file:

    lista_arquivo = file.readlines()

    for line in lista_arquivo:
        lista_aula = lista_arquivo[linha].split(' ')
        elementos = int(lista_aula[0])
        lista_aula = lista_aula[1:]

        if(lista_aula[-1] == '\n'):
            lista_aula.pop()

        lista_potencia_2 = lista_aula[:]
        potencia_2 = sort.sort(lista_potencia_2, elementos)

        lista_knuth = lista_aula[:]
        knuth = sort.sort(lista_knuth, elementos)

        lista_ciura = lista_aula[:]
        ciura = sort.sort(lista_ciura, elementos)

        potencia_2.shell_sort(tipo = 'SHELL', saida = tipo_saida, arquivo = saida)
        knuth.shell_sort(tipo = 'KNUTH', saida = tipo_saida, arquivo = saida)
        ciura.shell_sort(tipo = 'CIURA', saida = tipo_saida, arquivo = saida)

        linha += 1


saida.close()
