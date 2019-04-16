#include <stdio.h> 
#include <netdb.h> 

main(int argc, char *argv[])
{
    int meusocket; 
    int conecta; // variavel que recebe o retorno se a porta esta aberta ou não 
    int port; // recebe o numero da porta 
    int inicio = 0 ;   // inicio das portas a ser varrida 
    int final = 65535 ; //até aonde vamos varer as portas 
    char * destino; //variavel que vai receber o endereço de IP

    destino = argv[1];
        
    struct sockaddr_in alvo; 

    
    
    for (port = inicio ; port <final ; port++)
    {
            meusocket = socket(AF_INET, SOCK_STREAM,0);
            alvo.sin_family = AF_INET ; 
            alvo.sin_port = htons(port);
            alvo.sin_addr.s_addr = inet_addr(destino);
     

            conecta = connect(meusocket , (struct sockaddr *)&alvo, sizeof alvo);

    
            
            if (conecta == 0 ) //se o retorno da variavel conecta for 0 significa que a porta esta aberta 
            {
                printf("Porta  %d status [ABERTA] \n",port);
                close(meusocket);
                close(conecta);
            
            } else 
            {
                close(meusocket);
                close(conecta);         
            }
    
     
    }




                printf("Fim de varredura !");  

    
}
