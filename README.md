# Gerenciador de Usuários com Cifra de César

Este projeto é um programa simples em C que permite cadastrar usuários, armazenando suas senhas de forma criptografada utilizando a **Cifra de César**. O programa usa manipulação de arquivos para salvar os dados de forma persistente.

## Funcionalidades

- **Cadastro de usuários** com nome e senha
- **Criptografia da senha** usando a Cifra de César
- **Armazenamento de dados** em um arquivo de texto

## Como funciona?

1. O usuário insere um nome e uma senha.
2. A senha é criptografada utilizando a Cifra de César.
3. Os dados são armazenados em um arquivo (`usuarios.txt`).

## Como executar?

### **Requisitos**

- Compilador C (como GCC)

### **Compilar o programa**

```bash
gcc -o gerenciador gerenciador.c
```

### **Executar o programa**

```bash
./gerenciador
```

## Estrutura do Código

### **Principais Funções**

- `criptografarSenha(char *senha, int chave)` → Aplica a Cifra de César à senha.
- `descriptografarSenha(char *senha, int chave)` → Reverte a Cifra de César.
- `cadastrarUsuario()` → Coleta os dados do usuário e salva no arquivo.

## Exemplo de Uso

**Entrada:**

```
Nome: Gustavo
Senha: minhaSenha123
```

**Armazenado no arquivo:**

```
Gustavo xpkjcVhpwcj456
```

(Onde "minhaSenha123" foi cifrada com deslocamento de 3 caracteres)

## Melhorias Futuras

- Implementar autenticação de login
- Adicionar opção para alterar ou excluir usuários
- Melhorar a criptografia utilizando hashing (ex: SHA-256)

## Autor

Desenvolvido por \*\*Gustavo, Gleciane, Beatriz, Bruno e Fernando \*\*

