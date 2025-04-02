#include<stdio.h>
#include<string.h>

struct registro
{
    char nome[50];
    int idade;
    float salario;
    char sexo[20];
};

struct registro criarRegistro()
{
    struct registro r;
    printf("Digite seu nome: \n");
    scanf("%s", r.nome);//não se utiliza "&" para strings (char)

    printf("Informe sua idade: \n");
    scanf("%d", &r.idade);
    if (r.idade < 18)
    {
        printf("Idade invalida\n");
        r.idade = -1;//marcador de idade invalida
    }
    
    printf("Informe seu salario: \n");
    scanf("%f", &r.salario);

    int opcao;

    do
    {
        printf("selecione seu genero: \n\n");
        printf("1. Masculino\n");
        printf("2. Feminino\n");
        printf("3. Indefinido\n");
        printf("4. Outro\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            strcpy(r.sexo, "Masculino.\n");
            break;

            case 2:
            strcpy(r.sexo, "Feminino.\n");
            break;

            case 3:
            strcpy(r.sexo, "Eh complicado.\n");
            break;
        
            case 4:
            printf("Informe seu genero: \n");
            scanf("%s", r.sexo);
            break;

        default:
        printf("Erro.\n");
        opcao = -1;//força o loop a continuar.
        }
    } while (opcao == -1);//maneira mais fácil de fechar o loop.
    return r;

};

//função para chegagem do registro
void checarRegistro(struct registro r){
    printf("\n---REGISTRO---\n");
    printf("Nome: %s\n", r.nome);
    printf("Idade: %d\n", r.idade);
    printf("Genero: %s\n", r.sexo);
    printf("Salario: %.2f\n", r.salario);
}

int main(){
    int opcao;
    struct registro registroCriado;
    int meuRegistro = 0;

    do
    {
        printf("1. Criar registro\n");
        printf("2. Checar registro\n");
        printf("0. Sair");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            registroCriado = criarRegistro();
            meuRegistro = 1;
            printf("Sucesso.\n");
            break;

        case 2:
            if (meuRegistro)
            {
                checarRegistro(registroCriado);
            }else {
                printf("Crie um registro.\n");
            }
            break;

        case 0:
        break;

        default:
        printf("Erro\n");
            break;
        }
    } while (opcao != 0);
    
    return 0;
    
}
