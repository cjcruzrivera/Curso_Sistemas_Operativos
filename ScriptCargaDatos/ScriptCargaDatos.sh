#!/usr/bin/env bash

#Porcentaje de Uso de la Cpu

#top -bn1 | grep Cpu | head -n1 | tr -s ' ' | cut -d ' ' -f 8

cpuInactiva=`top -bn1 | grep Cpu | head -n1 | tr -s ' ' | cut -d ' ' -f 8`
totalUso=`echo 100 - $cpuInactiva | bc` 

echo "Porcentaje de Cpu en uso: $totalUso %"

#Carga del sistema
cargaTotal=`uptime | tr -s ' ' | cut -d ' ' -f 10 | cut -d , -f 1` 

echo "Carga del sistema: $cargaTotal"

#Porcentaje de uso de memoria RAM

totalMemoria=`free -m | grep Mem | tr -s ' ' | cut -d ' ' -f 2`
#totalMemoria=`free -m | grep Mem | cut -d ' ' -f 9`
#totalMemoriaUsada=`free -m | grep Mem | cut -d ' ' -f 17`
totalMemoriaUsada=`free -m | grep Mem | tr -s ' ' | cut -d ' ' -f 3`
Porcentaje=$((totalMemoriaUsada*100/$totalMemoria))
#echo "memoria: $totalMemoria"
echo "Porcentaje de memoria Ram en uso: $Porcentaje%"

#Almacenamiento disponible

memoriaEnUso=`df | grep /dev/mmcblk0 | tr -s ' ' | cut -d ' ' -f 5 | cut -d '%' -f 1`
PorcentajeMemoriaDisponible=$((100 - memoriaEnUso))
echo "Porcentaje de Memoria disponible: $PorcentajeMemoriaDisponible %"

#Ancho de Banda de subida

anchoSubida=`speedtest-cli --simple | grep Upl | cut -d ' ' -f 2`


#Ancho de Banda de bajada

anchoBajada=`speedtest-cli --simple | grep Down | cut -d ' ' -f 2`

echo "La velocidad de subida es: $anchoSubida Mbits/s"
echo "La Velocidad de bajada es: $anchoBajada Mbits/s"

curl --silent "http://api.thingspeak.com/update?key=7SFI1NR3R5W63SUA&field1=$totalUso&field2=$cargaTotal&field3=$Porcentaje&field4=$PorcentajeMemoriaDisponible&field5=$anchoSubida&field6=$anchoBajada"

#curl --silent "http://api.thingspeak.com/update?key=7SFI1NR3R5W63SUA&field5=$anchoSubida&field6=$anchoBajada"


