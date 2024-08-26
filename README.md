# Para criar o hot-reload para o c usei nodemon

execute:
``` bash 
#!/bin/bash

# Verifica se o nodemon está instalado globalmente
if ! command -v nodemon &> /dev/null
then
    echo "nodemon não está instalado. Instalando..."
    npm install -g nodemon

    if [ $? -ne 0 ]; then
        echo "Falha ao instalar o nodemon."
        exit 1
    fi
else
    echo "nodemon já está instalado."
fi

# Inicia o nodemon
nodemon
``` 