#!	/bin/bash

export FREEMEM=$(free | grep Memoria | tr -s ' ' |cut -d ' ' -f 3)
echo $FREEMEM

