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

### Topicos de estudo ponteiro e funcoes

funcoes tem 4 logicas basicas:
``` c
//1:tipo 2:nome da funcao         3:parametros
    char terminalLinuxSoUsarTexto(char apenasTexto) {
        // 4:pode ter um retorno ou nao... tudo depende de como
        // voce tipou o dado
        return apenasTexto;
    }
```

Ponteiro é uma variavel que contém um endereco de memória

https://embarcados.com.br/wp-content/uploads/2015/12/Mem%C3%B3ria.png