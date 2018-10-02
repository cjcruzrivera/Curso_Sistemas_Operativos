# 1428907-SO-19-Abril-2017 Camilo José Cruz Rivera

-Este es el ejercicio número 1
-Comando que cuenta el numero de procesos corriendo en el sistema operativo

ps -A | wc -l

ps -A | tail -n +2 | wc -l

-Este es el ejercicio número 2
-Comando que imprime el valor de 2 a la potencia 4

echo $((2**4))

-Comandos que guarda este resultado en una variable e imprima esta variable por pantalla

export cuadrado=$((2**4))
echo${cuadrado}


