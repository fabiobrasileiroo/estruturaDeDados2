#include <microhttpd.h>
#include <stdio.h>
#include <string.h>

#define PORT 8888

// Função callback para responder a requisições
int handle_request(void *cls, struct MHD_Connection *connection, 
                   const char *url, const char *method, 
                   const char *version, const char *upload_data, 
                   size_t *upload_data_size, void **con_cls)
{
    const char *response_text = "Hello, World!";
    struct MHD_Response *response;
    int ret;

    // Cria a resposta HTTP
    response = MHD_create_response_from_buffer(strlen(response_text), (void*)response_text, MHD_RESPMEM_PERSISTENT);

    // Envia a resposta
    ret = MHD_queue_response(connection, MHD_HTTP_OK, response);

    // Libera a memória da resposta
    MHD_destroy_response(response);
    return ret;
}

int main()
{
    struct MHD_Daemon *daemon;

    // Inicializa o servidor HTTP
    daemon = MHD_start_daemon(MHD_USE_SELECT_INTERNALLY, PORT, NULL, NULL, 
                              &handle_request, NULL, MHD_OPTION_END);
    if (NULL == daemon) return 1;

    printf("Server rodando na porta %d\n", PORT);

    // Mantenha o servidor rodando
    getchar();

    // Para o servidor quando for necessário
    MHD_stop_daemon(daemon);
    return 0;
}
