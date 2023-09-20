
def MultiplicaMatrizes(MatrizEsquerda, MatrizDireita, MatrizResultado):
    ColEsquerda = len(MatrizEsquerda[0])
    LinhaDireita = len(MatrizDireita)
    if ColEsquerda != LinhaDireita:
        print("Ta errado man kk")
    else:
        #Produto Matricial
        for i in range(len(MatrizEsquerda)):
            for j in range(len(MatrizDireita[0])):
                #Cálculo da entrada
                for p in range(len(MatrizEsquerda[0])):
                    c_ij = MatrizEsquerda[i][p] * MatrizDireita[p][j]
                    MatrizResultado[i][j] = c_ij

A = [[1,2,4]]
B = [[4], [2], [1]]
c_linha = [0]*len(B)
c_colunas = [c_linha]*len(A[0])
C = c_colunas
print(C)

MultiplicaMatrizes(A,B,C)
print(C)