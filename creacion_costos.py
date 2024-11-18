import numpy as np

def crear_arreglo_costos_unicos(tamaño=26, min_valor=1, max_valor=5):
    # Genera un arreglo donde cada posición tiene un costo único aleatorio
    return np.random.randint(min_valor, max_valor + 1, size=tamaño)

def crear_matriz_costos_unicos(tamaño=26, min_valor=1, max_valor=5):
    # Genera una matriz donde cada posición tiene un costo único aleatorio
    matriz = np.random.randint(min_valor, max_valor + 1, size=(tamaño, tamaño))
    np.fill_diagonal(matriz, 0)  # La diagonal se mantiene con ceros
    return matriz

def guardar_arreglo_en_archivo(arreglo, nombre_archivo):
    with open(nombre_archivo, 'w') as file:
        file.write(" ".join(map(str, arreglo)))

def guardar_matriz_en_archivo(matriz, nombre_archivo):
    with open(nombre_archivo, 'w') as file:
        for i, row in enumerate(matriz):
            file.write(" ".join(map(str, row)))
            if i < len(matriz) - 1:  # Evitar el salto de línea en la última fila
                file.write("\n")

# Crear y guardar el arreglo para delete e insert con costos únicos
arreglo_delete = crear_arreglo_costos_unicos()
arreglo_insert = crear_arreglo_costos_unicos()
guardar_arreglo_en_archivo(arreglo_delete, "cost_delete.txt")
guardar_arreglo_en_archivo(arreglo_insert, "cost_insert.txt")

# Crear y guardar las matrices para replace y transpose con costos únicos
matriz_replace = crear_matriz_costos_unicos()
matriz_transpose = crear_matriz_costos_unicos()
guardar_matriz_en_archivo(matriz_replace, "cost_replace.txt")
guardar_matriz_en_archivo(matriz_transpose, "cost_transpose.txt")

print("Archivos de costos únicos (arreglos y matrices) generados exitosamente.")



