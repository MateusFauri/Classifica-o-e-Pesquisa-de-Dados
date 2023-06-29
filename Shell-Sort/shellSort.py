import time

class sort(object):
    """
        Classe para ordenação de uma lista usando metodos diferentes de ordenação (podendo conter varios metodos diferentes)

        Construtor:
            Lista para ser ordenada
            Tamanho da lista a ser ordenada
    """

    def __init__(self, lista, tamanho):
        self.lista = lista
        self.tamanho = tamanho


    def shell_sort(self, arquivo, tipo = 'SHELL', saida = 1):
        """
            arquivo     (*FILE)     -       Ponteiro para o arquivo de saida
            tipo        (string)    -       "SHELL", "KNUTH", "CIURA" deifine a lista de segmentos (gaps) para o shell sort  
            saida       (int)       -       1 - saida do tipo exemplo saida1.txt ou 2 -  saida do tipo exemplo saida2.txt

            Ordena a lista da instancia com o metodo shell_sort com segmentos seguindo a sequencia explicitada no tipo e imprime a saida em um arquivo
        """
        lista_gap = []

        if tipo == 'SHELL':
            lista_potencia_2 = []
            self._potencia_2(lista_potencia_2)
            lista_gap = lista_potencia_2.copy()
        elif tipo == 'KNUTH':
            lista_knuth = []
            self._knuth(lista_knuth)
            lista_gap = lista_knuth.copy()
        elif tipo == 'CIURA':
            lista_ciura = []
            self._ciura(lista_ciura)
            lista_gap = lista_ciura.copy()
        else:
            print("Escrever mensagem de erro!")
            pass
        
        lista_gap.reverse()
        
        if saida == 1:
            for element in self.lista:
                arquivo.write(f"{element} ")
            arquivo.write(f" SEQ={tipo} \n")

            for gap in lista_gap:
                for inicio in range(gap): 
                    self.insertion_sort(inicio, gap)

                for element in self.lista:
                    arquivo.write(f"{element} ")
                arquivo.write(f" INC={gap} \n")

        elif saida == 2:
            _inicio = time.time()

            for gap in lista_gap:
                for inicio in range(gap): 
                    self.insertion_sort(inicio, gap)

            _fim = time.time()
            _tempo = (_fim - _inicio) * 1000
            #_processador = ' '.join((subprocess.check_output("lscpu", shell=True).strip()).decode().split('\n')[7].split()[2:])

            arquivo.write(f"{tipo}, {self.tamanho}, {_tempo:.6f}, AMD Ryzen 5 3500U with Radeon Vega Mobile Gfx\n")

        else:
            print("Tipo invalido!")

    def insertion_sort(self, inicio, gap):
        """
            Ordena a lista com o metodo insertion_sort, com o numero "gap" de segmentos e um inicio em "inicio"
        """

        for elemento in range(inicio + gap, self.tamanho, gap):
            chave = int(self.lista[elemento])
            number = int(elemento)
            while number >= gap and int(self.lista[number-gap]) > chave:
                self.lista[number] = self.lista[number - gap]
                number -= gap
            self.lista[number] = chave

    def _potencia_2(self, gaps):
        """
            Cria uma sequencia de numeros de potencia de dois ate o maior numero menor que o tamnanho da lista e adiciona eles a lista gaps
        """

        number = i = 1
        while number < self.tamanho:
            gaps.append(number)
            number = 2 ** i
            i += 1

    def _knuth(self, gaps):
        """
            Cria uma sequencia de numeros de knuth ate um terço da lista e adiciona eles a lista gaps
        """

        h=1
        gaps.append(h)
        while h < self.tamanho / 3:
            h = 3*h + 1
            gaps.append(h)

    def _ciura(self, gaps):
        """
            Cria uma sequencia de numeros de ciura ate o maior numero menor que o tamnanho da lista e adiciona eles a lista gaps
        """

        ciura = [1,4,10,23,57,132,301,701,1577,3548,7983,17961,40412,90927,204585,460316,1035711]
        for element in ciura:
            if element < self.tamanho:
                gaps.append(element)
            else:
                break
   

