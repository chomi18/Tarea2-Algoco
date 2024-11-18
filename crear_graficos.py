import re
import matplotlib.pyplot as plt

# Abrir y leer el archivo de texto
archivo = "resultados.txt"  # Cambia esto por la ruta de tu archivo
with open(archivo, 'r') as file:
    data = file.read()

# Expresiones regulares para extraer los tiempos de BF y DP
patron_tiempo_bf = re.compile(r"Tiempo BF: (\d+) microseconds")
patron_tiempo_dp = re.compile(r"Tiempo DP: (\d+) microseconds")

# Extraer datos
tiempos_bf = [int(match) for match in patron_tiempo_bf.findall(data)]
tiempos_dp = [int(match) for match in patron_tiempo_dp.findall(data)]

# Generar gráfico para BF
plt.figure(figsize=(10, 5))
plt.plot(range(1, len(tiempos_bf) + 1), tiempos_bf, marker='o', label="Tiempo BF", color="blue")
plt.xlabel("Índice de Prueba")
plt.ylabel("Tiempo de Ejecución (microsegundos)")
plt.title("Tiempos de Ejecución - Fuerza Bruta (BF)")
plt.legend()
plt.grid(True)
plt.show()

# Generar gráfico para DP
plt.figure(figsize=(10, 5))
plt.plot(range(1, len(tiempos_dp) + 1), tiempos_dp, marker='x', label="Tiempo DP", color="green")
plt.xlabel("Índice de Prueba")
plt.ylabel("Tiempo de Ejecución (microsegundos)")
plt.title("Tiempos de Ejecución - Programación Dinámica (DP)")
plt.legend()
plt.grid(True)
plt.show()
