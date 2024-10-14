# Casa Simples com Raio e Queda de Árvore 🌳⚡

Este projeto implementa uma cena simples em C utilizando OpenGL (mais especificamente a biblioteca GLUT), onde uma casa e uma árvore são renderizadas. O destaque da aplicação é a simulação de um raio que ilumina a tela e faz com que a árvore caia ao apertar a tecla `T`.

## 🎮 Funcionalidades

- Renderização de uma casa e uma árvore em uma cena 2D.
- Pressione `T` para ativar um raio que ilumina a tela.
- A árvore cai quando o raio é ativado.

## 🛠️ Tecnologias Utilizadas

- **Linguagem**: C
- **Biblioteca gráfica**: OpenGL (GLUT)

## 🚀 Como Executar o Projeto

1. Certifique-se de ter o OpenGL e GLUT instalados no seu sistema.

2. Clone este repositório:
   ```bash
   git clone https://github.com/AdelsonJ/seu-repositorio.git
   
3. Compile o projeto utilizando o Makefile. Simplesmente execute:
   ```bash
   make

4. Execute o programa:
   ```bash
   ./casa

## 📦 Dependências
- **OpenGL:** Para renderizar gráficos.
- **GLUT:** Biblioteca que facilita o uso do OpenGL.

## No Linux:
Para instalar as dependências no Linux, utilize:
   ```bash
      sudo apt-get install freeglut3-dev
   ```

## No Windows:
Você pode baixar os arquivos de cabeçalho e bibliotecas do GLUT no site oficial e configurá-los manualmente.

## 💡 Como Funciona
- **Cena Inicial:** Uma casa com uma árvore ao lado.
- **Tecla T:** Ao apertar T, um raio aparece, iluminando brevemente a tela. Após o raio, a árvore cai, simulando o impacto do raio.

## ✨ Melhorias Futuras
Adicionar efeito sonoro para o raio.
Inserir novas interações com a cena, como chuva.

## 🧑‍💻 Autor
Projeto desenvolvido por AdelsonJ.
