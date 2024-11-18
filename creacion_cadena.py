import random
import string

def generar_cadenas_para_casos(cantidad_ejemplos=20, longitud_min=2, longitud_max=10):
    casos_prueba = []

    # Caso 1: Una cadena es nula (vacía), y la otra tiene caracteres
    for i in range(cantidad_ejemplos):
        longitud_actual = longitud_min + (i * (longitud_max - longitud_min) // cantidad_ejemplos)
        if random.choice([True, False]):  # Aleatoriamente selecciona cuál será nula
            cadena1 = ""
            cadena2 = "".join(random.choices(string.ascii_lowercase, k=longitud_actual))
        else:
            cadena1 = "".join(random.choices(string.ascii_lowercase, k=longitud_actual))
            cadena2 = ""
        casos_prueba.append((cadena1, cadena2))

    # Caso 2: Cadenas con caracteres repetidos
    for i in range(cantidad_ejemplos):
        longitud_actual = longitud_min + (i * (longitud_max - longitud_min) // cantidad_ejemplos)
        base = "".join(random.choices(string.ascii_lowercase, k=longitud_actual))
        repetido = random.choice(string.ascii_lowercase)
        max_repeticiones = max(2, min(4, longitud_max - len(base) + 1))
        if max_repeticiones > 0:
            repeticion = repetido * random.randint(2, max_repeticiones)
            cadena_modificada = base[:len(base)//2] + repeticion + base[len(base)//2:]
            cadena_modificada = cadena_modificada[:longitud_max]  # Cortar si excede la longitud máxima
            casos_prueba.append((base, cadena_modificada))

    # Caso 3: Cadenas con transposiciones
    for i in range(cantidad_ejemplos):
        longitud_actual = longitud_min + (i * (longitud_max - longitud_min) // cantidad_ejemplos)
        cadena_base = "".join(random.choices(string.ascii_lowercase, k=longitud_actual))
        if len(cadena_base) > 1:
            pos1, pos2 = random.sample(range(len(cadena_base)), 2)
            cadena_transpuesta = list(cadena_base)
            cadena_transpuesta[pos1], cadena_transpuesta[pos2] = cadena_transpuesta[pos2], cadena_transpuesta[pos1]
            casos_prueba.append((cadena_base, "".join(cadena_transpuesta)))

    # Caso 4: Cadenas completamente aleatorias
    for i in range(cantidad_ejemplos):
        longitud_actual = longitud_min + (i * (longitud_max - longitud_min) // cantidad_ejemplos)
        cadena_aleatoria1 = "".join(random.choices(string.ascii_lowercase, k=longitud_actual))
        cadena_aleatoria2 = "".join(random.choices(string.ascii_lowercase, k=longitud_actual))
        cadena_aleatoria1 = cadena_aleatoria1[:longitud_max]  # Cortar si excede la longitud máxima
        cadena_aleatoria2 = cadena_aleatoria2[:longitud_max]  # Cortar si excede la longitud máxima
        casos_prueba.append((cadena_aleatoria1, cadena_aleatoria2))

    # Caso 5: Cadenas con prefijos comunes
    for i in range(cantidad_ejemplos):
        longitud_actual = longitud_min + (i * (longitud_max - longitud_min) // cantidad_ejemplos)
        prefijo_longitud = random.randint(1, min(longitud_actual // 2, longitud_max // 2))
        prefijo_comun = "".join(random.choices(string.ascii_lowercase, k=prefijo_longitud))
        sufijo1 = "".join(random.choices(string.ascii_lowercase, k=(longitud_actual - len(prefijo_comun))))
        sufijo2 = "".join(random.choices(string.ascii_lowercase, k=(longitud_actual - len(prefijo_comun))))
        cadena_prefijo1 = (prefijo_comun + sufijo1)[:longitud_max]  # Cortar si excede la longitud máxima
        cadena_prefijo2 = (prefijo_comun + sufijo2)[:longitud_max]  # Cortar si excede la longitud máxima
        casos_prueba.append((cadena_prefijo1, cadena_prefijo2))

    return casos_prueba


def guardar_casos_en_archivo(casos_prueba, nombre_archivo):
    with open(nombre_archivo, 'w') as file:
        caso_actual = 1
        ejemplos_por_caso = len(casos_prueba) // 5  # Asegurar distribución uniforme
        for idx, (cadena1, cadena2) in enumerate(casos_prueba, 1):
            if (idx - 1) % ejemplos_por_caso == 0:
                file.write(f"--- Caso {caso_actual} ---\n")
                caso_actual += 1
            file.write(f"{cadena1},{cadena2}\n")

# Generar casos de prueba
casos_prueba = generar_cadenas_para_casos()

# Guardar en archivo
guardar_casos_en_archivo(casos_prueba, "casos_prueba.txt")

print("Casos de prueba generados y guardados exitosamente.")

