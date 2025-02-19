#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 50
#define MAX_UPDATE_LEN 100

// Função para criptografar a senha usando Cifra de César com deslocamento 3
void criptografarSenha(char *senha) {
    while (*senha) {
        *senha = *senha + 3;
        senha++;
    }
}

// Função para descriptografar a senha
void descriptografarSenha(char *senha) {
    while (*senha) {
        *senha = *senha - 3;
        senha++;
    }
}

// Função para registrar um novo usuário
void registrarUsuario() {
    char usuario[MAX_LEN], senha[MAX_LEN];
    FILE *file = fopen("usuarios.txt", "a");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo de usuários!\n");
        return;
    }

    printf("Digite um nome de usuário: ");
    scanf("%49s", usuario);
    printf("Digite uma senha: ");
    scanf("%49s", senha);

    criptografarSenha(senha);
    fprintf(file, "%s %s\n", usuario, senha);
    fclose(file);

    printf("Usuário cadastrado com sucesso!\n");
}

// Função para verificar login
int verificarLogin() {
    char usuario[MAX_LEN], senha[MAX_LEN];
    char userFile[MAX_LEN], passFile[MAX_LEN];
    FILE *file = fopen("usuarios.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo de usuários!\n");
        return 0;
    }

    printf("Digite seu usuário: ");
    scanf("%49s", usuario);
    printf("Digite sua senha: ");
    scanf("%49s", senha);
    criptografarSenha(senha);

    while (fscanf(file, "%s %s", userFile, passFile) != EOF) {
        if (strcmp(usuario, userFile) == 0 && strcmp(senha, passFile) == 0) {
            fclose(file);
            printf("Login bem-sucedido!\n");
            return 1;
        }
    }
    
    fclose(file);
    printf("Usuário ou senha incorretos.\n");
    return 0;
}

// Função para registrar atualização da indústria
void registrarAtualizacao() {
    char industria[MAX_LEN], descricao[MAX_UPDATE_LEN];
    FILE *file = fopen("atualizacoes.txt", "a");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo de atualizações!\n");
        return;
    }

    printf("Nome da indústria: ");
    scanf("%49s", industria);
    getchar(); // Limpa buffer
    printf("Descrição da atualização: ");
    fgets(descricao, MAX_UPDATE_LEN, stdin);
    descricao[strcspn(descricao, "\n")] = 0;

    fprintf(file, "%s: %s\n", industria, descricao);
    fclose(file);
    printf("Atualização registrada com sucesso!\n");
}

int main() {
    int opcao;
    while (1) {
        printf("\n=== MENU ===\n");
        printf("1. Registrar usuário\n");
        printf("2. Login\n");
        printf("3. Registrar atualização\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpa buffer

        switch (opcao) {
            case 1:
                registrarUsuario();
                break;
            case 2:
                if (verificarLogin()) {
                    printf("Acesso permitido!\n");
                }
                break;
            case 3:
                registrarAtualizacao();
                break;
            case 4:
                printf("Saindo...\n");
                return 0;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }
    return 0;
}
