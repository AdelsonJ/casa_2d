#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

// Largura e altura da janela
GLfloat windowWidth;
GLfloat windowHeight;

GLfloat cor_background_1 = 35.0/255.0;
GLfloat cor_background_2 = 38.0/255.0;
GLfloat cor_background_3 = 48.0/255.0;

GLfloat cor_piso_1 = 28.0/255.0;
GLfloat cor_piso_2 = 49.0/255.0;
GLfloat cor_piso_3 = 18.0/255.0; 

GLfloat cor_parede1_1 = 100.0/255.0; 
GLfloat cor_parede1_2 = 97.0/255.0; 
GLfloat cor_parede1_3 = 90.0/255.0; 
GLfloat cor_parede2_1 = 95.0/255.0; 
GLfloat cor_parede2_2 = 93.0/255.0; 
GLfloat cor_parede2_3 = 87.0/255.0; 

GLfloat cor_telhado_1 = 25.0/255.0; 
GLfloat cor_telhado_2 = 23.0/255.0;
GLfloat cor_telhado_3 = 22.0/255.0;

GLfloat cor_chamine1_1 = 52.0/255.0; 
GLfloat cor_chamine1_2 = 44.0/255.0; 
GLfloat cor_chamine1_3 = 35.0/255.0; 
GLfloat cor_chamine2_1 = 37.0/255.0; 
GLfloat cor_chamine2_2 = 31.0/255.0; 
GLfloat cor_chamine2_3 = 24.0/255.0;

GLfloat cor_porta1_1 = 27.0/255.0; 
GLfloat cor_porta1_2 = 21.0/255.0; 
GLfloat cor_porta1_3 = 14.0/255.0; 
GLfloat cor_porta2_1 = 86.0/255.0; 
GLfloat cor_porta2_2 = 72.0/255.0; 
GLfloat cor_porta2_3 = 26.0/255.0; 

GLfloat cor_janela1_1 = 10.0/255.0; 
GLfloat cor_janela1_2 = 10.0/255.0; 
GLfloat cor_janela1_3 = 1/255.0;
GLfloat cor_janela2_1 = 246.0/255.0; 
GLfloat cor_janela2_2 = 164.0/255.0; 
GLfloat cor_janela2_3 = 61/255.0; 

GLfloat cor_fumaca_1 = 102.0/255.0; 
GLfloat cor_fumaca_2 = 102.0/255.0; 
GLfloat cor_fumaca_3 = 102.0/255.0; 

GLfloat detalhe = 0.2; 

GLfloat madeira_1 = 29.0/255.0; 
GLfloat madeira_2 = 16.0/255.0; 
GLfloat madeira_3 = 7.0/255.0; 

GLfloat folha_1 = 16.0/255.0; 
GLfloat folha_2 = 52.0/255.0; 
GLfloat folha_3 = 7.0/255.0; 

GLfloat raio = 1; 

int x_fumaca_1 = 0;
int x_fumaca_2 = 50;
int y_fumaca_1 = 0;
int y_fumaca_2 = 20;
int alternancia = 0;
int trovao = 0;
int cai = 0;
int fala = 0;
int cai_aux = 0;

void tempo_normal(int);
void tempo_trovao(int);
void texto(float, float, void *, const char*);

//Desenha um quadrado de lado 1 centrado na origem
void desenhaQuadrado() {
    glBegin(GL_QUADS);
        glVertex2f(-0.5, -0.5);
        glVertex2f(0.5, -0.5);
        glVertex2f(0.5, 0.5);
        glVertex2f(-0.5, 0.5);
    glEnd();
}

//Desenha um triângulo equilátero de lado 1 centrado na origem
void desenhaTriangulo() {
    glBegin(GL_TRIANGLES);
        glVertex2d(0.0, 0.5);
        glVertex2d(-0.5, -0.5);
        glVertex2d(0.5, -0.5);
    glEnd();
}

//Desenha um círculo de raio centrado na origem
void desenhaCirculo() {
    glBegin(GL_POLYGON);
        for (int i = 0; i < 30; i++) {
            glVertex2f(cos(i), sin(i));
        }
    glEnd();
}

//Faz o cisalhamento de um objeto em relação ao eixo X
//Basta utilizar como uma das funções do OpenGL como glTranslatef, glRotatef, glScalef
void skewX(GLfloat angle) {
    GLfloat m[16] = {
        1, 0, 0, 0,
        tan(angle), 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0 ,1
    };
    glMultMatrixf(m);
}

//Faz o cisalhamento de um objeto em relação ao eixo Y
//Basta utilizar como uma das funções do OpenGL como glTranslatef, glRotatef, glScalef
void skewY(GLfloat angle) {
    GLfloat m[16] = {
        1, tan(angle), 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
    };
    glMultMatrixf(m);
}

// Função callback chamada para fazer o desenho
void Desenha(void)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Limpa a janela de visualização com a cor de fundo especificada
    glClear(GL_COLOR_BUFFER_BIT);

    // Aqui entra todo o seu código da casa 2D.
    //Vocês só pode usar as funções de desenho:
        // desenhaQuadrado, desenhaTriangulo, desenhaCirculo
    // as transformações geométricas:
        // glTranslatef, glRotatef, glScalef, skewX, skewY
    // e as funções de cor:
        // glColor3f
    // Não desenhe nenhuma primitiva utilizando glBegin/glEnd diretamente aqui.

        

        /* FUNDO */
        glColor3f(cor_background_1, cor_background_2, cor_background_3);
        glTranslatef(0, 175, 0);
        glPushMatrix();
        glScalef(1000, 237.5, 1);
        desenhaQuadrado();
        glPopMatrix();

        glColor3f(cor_piso_1, cor_piso_2, cor_piso_3);
        glTranslatef(0, -150, 0);
        glPushMatrix();
        glScalef(1000, 75, 1);
        desenhaQuadrado();
        glPopMatrix();
        
        
        /* PAREDES */
        glColor3f(cor_parede1_1, cor_parede1_2, cor_parede1_3);
        glTranslatef(75, 75, 0);
        glPushMatrix();
        glScalef(75, 75, 1);
        desenhaQuadrado();
        glPopMatrix();
        
        glColor3f(cor_parede2_1, cor_parede2_2, cor_parede2_3);
        glTranslatef(112.5, 0, 0);
        glPushMatrix();
        glScalef(150, 75, 1);
        desenhaQuadrado();
        glPopMatrix();


        /* TELHADO */
        glColor3f(cor_telhado_1, cor_telhado_2, cor_telhado_3);
        glTranslatef(-112.5, 56, 0);
        glPushMatrix();
        glScalef(95, 37.5, 1);
        desenhaTriangulo();
        glPopMatrix();
        
        glColor3f(cor_parede1_1, cor_parede1_2, cor_parede1_3);
        glTranslatef(0, -5, 0);
        glPushMatrix();
        glScalef(75, 27.5, 1);
        desenhaTriangulo();
        glPopMatrix();

        glColor3f(cor_telhado_1, cor_telhado_2, cor_telhado_3);
        glTranslatef(100, 5, 0);
        skewX(-50*3.1415/180.0f);
        glPushMatrix();
        glScalef(156, 37.5, 1);
        desenhaQuadrado();
        glPopMatrix();


        /* FUMACA */      
        glColor3f(cor_fumaca_1,cor_fumaca_2,cor_fumaca_3);
        glTranslatef(42.5 + x_fumaca_1 , 44 + y_fumaca_1 , 0);           
        skewX(-310*3.1415/180.0f);  
        glPushMatrix();
        glScalef(7, 7, 1);
        desenhaCirculo();
        glPopMatrix(); 

        glColor3f(cor_fumaca_1,cor_fumaca_2,cor_fumaca_3);
        glTranslatef(5, 2, 0);  
        glPushMatrix();
        glScalef(7, 7, 1);
        desenhaCirculo();
        glPopMatrix(); 

        glColor3f(cor_fumaca_1,cor_fumaca_2,cor_fumaca_3);
        glTranslatef(0, -7, 0);  
        glPushMatrix();
        glScalef(7, 7, 1);
        desenhaCirculo();
        glPopMatrix(); 

        glColor3f(cor_fumaca_1,cor_fumaca_2,cor_fumaca_3);
        glTranslatef(5, 2, 0);  
        glPushMatrix();
        glScalef(7, 7, 1);
        desenhaCirculo();
        glPopMatrix(); glColor3f(cor_fumaca_1,cor_fumaca_2,cor_fumaca_3);
        glTranslatef(0, 7, 0);  
        glPushMatrix();
        glScalef(7, 7, 1);
        desenhaCirculo();
        glPopMatrix(); 

        glColor3f(cor_fumaca_1,cor_fumaca_2,cor_fumaca_3);
        glTranslatef(5, -2, 0);  
        glPushMatrix();
        glScalef(7, 7, 1);
        desenhaCirculo();
        glPopMatrix(); 

        glColor3f(cor_fumaca_1,cor_fumaca_2,cor_fumaca_3);
        glTranslatef(0, -5, 0);  
        glPushMatrix();
        glScalef(7, 7, 1);
        desenhaCirculo();
        glPopMatrix(); 

        glPopMatrix(); 

        /* FUMACA 2*/
        glPushMatrix();
        glColor3f(cor_fumaca_1,cor_fumaca_2,cor_fumaca_3);
        glTranslatef(x_fumaca_2, y_fumaca_2, 0);  
        glPushMatrix();
        glScalef(7, 7, 1);
        desenhaCirculo();
        glPopMatrix(); 

        glColor3f(cor_fumaca_1,cor_fumaca_2,cor_fumaca_3);
        glTranslatef(5, 2, 0);  
        glPushMatrix();
        glScalef(7, 7, 1);
        desenhaCirculo();
        glPopMatrix(); 

        glColor3f(cor_fumaca_1,cor_fumaca_2,cor_fumaca_3);
        glTranslatef(0, -7, 0);  
        glPushMatrix();
        glScalef(7, 7, 1);
        desenhaCirculo();
        glPopMatrix(); 

        glColor3f(cor_fumaca_1,cor_fumaca_2,cor_fumaca_3);
        glTranslatef(5, 2, 0);  
        glPushMatrix();
        glScalef(7, 7, 1);
        desenhaCirculo();
        glPopMatrix(); glColor3f(cor_fumaca_1,cor_fumaca_2,cor_fumaca_3);
        glTranslatef(0, 7, 0);  
        glPushMatrix();
        glScalef(7, 7, 1);
        desenhaCirculo();
        glPopMatrix(); 

        glColor3f(cor_fumaca_1,cor_fumaca_2,cor_fumaca_3);
        glTranslatef(5, -2, 0);  
        glPushMatrix();
        glScalef(7, 7, 1);
        desenhaCirculo();
        glPopMatrix(); 

        glColor3f(cor_fumaca_1,cor_fumaca_2,cor_fumaca_3);
        glTranslatef(0, -5, 0);  
        glPushMatrix();
        glScalef(7, 7, 1);
        desenhaCirculo();
        glPopMatrix(); 

        glPopMatrix();


        /* CHAMINE */
        glPushMatrix();
        glColor3f(cor_chamine1_1, cor_chamine1_2, cor_chamine1_3);
        glTranslatef(-6, -16 , 0); 
        glPushMatrix();
        glScalef(13.33, 14.67, 1);
        desenhaQuadrado();
        glPopMatrix();

        glColor3f(cor_chamine2_1,cor_chamine2_2,cor_chamine2_3);
        glTranslatef(0, 5.625, 0);    
        glPushMatrix();
        glScalef(20, 5.625, 1);
        desenhaQuadrado();
        glPopMatrix();


        /* JANELAS */
        /*PRIMEIRA*/
        glColor3f(detalhe,detalhe,detalhe);
        glTranslatef(-18, -87.625, 0);  
        glPushMatrix();
        glScalef(37.5, 23.125, 1);
        desenhaQuadrado();
        glPopMatrix(); 

        glColor3f(cor_janela2_1,cor_janela2_2,cor_janela2_3);
        glTranslatef(8.75, 5, 0);  
        glPushMatrix();
        glScalef(16, 9, 1);
        desenhaQuadrado();
        glPopMatrix(); 

        glColor3f(cor_janela2_1,cor_janela2_2,cor_janela2_3);
        glTranslatef(-17.5, 0, 0);  
        glPushMatrix();
        glScalef(16, 9, 1);
        desenhaQuadrado();
        glPopMatrix();

        glColor3f(cor_janela2_1,cor_janela2_2,cor_janela2_3);
        glTranslatef(0, -10.5, 0);  
        glPushMatrix();
        glScalef(16, 9, 1);
        desenhaQuadrado();
        glPopMatrix();
        
        glColor3f(cor_janela2_1,cor_janela2_2,cor_janela2_3);
        glTranslatef(17.5, 0, 0);  
        glPushMatrix();
        glScalef(16, 9, 1);
        desenhaQuadrado();
        glPopMatrix(); 

        /*SEGUNDA*/
        glColor3f(detalhe,detalhe,detalhe);
        glTranslatef(55, 5.5, 0);  
        glPushMatrix();
        glScalef(37.5, 23.125, 1);
        desenhaQuadrado();
        glPopMatrix(); 

        glColor3f(cor_janela1_1,cor_janela1_2,cor_janela1_3);
        glTranslatef(8.75, 5, 0);  
        glPushMatrix();
        glScalef(16, 9, 1);
        desenhaQuadrado();
        glPopMatrix(); 

        glColor3f(cor_janela1_1,cor_janela1_2,cor_janela1_3);
        glTranslatef(-17.5, 0, 0);  
        glPushMatrix();
        glScalef(16, 9, 1);
        desenhaQuadrado();
        glPopMatrix();

        glColor3f(cor_janela1_1,cor_janela1_2,cor_janela1_3);
        glTranslatef(0, -10.5, 0);  
        glPushMatrix();
        glScalef(16, 9, 1);
        desenhaQuadrado();
        glPopMatrix();
        
        glColor3f(cor_janela1_1,cor_janela1_2,cor_janela1_3);
        glTranslatef(17.5, 0, 0);  
        glPushMatrix();
        glScalef(16, 9, 1);
        desenhaQuadrado();
        glPopMatrix(); 

        /* REDONDA */
        glColor3f(detalhe,detalhe,detalhe);
        glTranslatef(-153.5, 52.5, 0);  
        glPushMatrix();
        glScalef(7.5, 7.5, 1);
        desenhaCirculo();
        glPopMatrix();

        glColor3f(cor_janela1_1,cor_janela1_2,cor_janela1_3);
        glTranslatef(0, 0, 0);  
        glPushMatrix();
        glScalef(6, 6, 1);
        desenhaCirculo();
        glPopMatrix();   


        /* PORTA */      
        glColor3f(cor_porta1_1,cor_porta1_2,cor_porta1_3);
        glTranslatef(0, -60, 0);  
        glPushMatrix();
        glScalef(23, 50, 1);
        desenhaQuadrado();
        glPopMatrix(); 

        glColor3f(cor_porta2_1,cor_porta2_2,cor_porta2_3);
        glTranslatef(8.5, 0, 0);  
        glPushMatrix();
        glScalef(2, 2, 1);
        desenhaQuadrado();
        glPopMatrix();

        /* ARVORE */      
        glColor3f(madeira_1, madeira_2, madeira_3);
        glTranslatef(250, -12.5, 0);  
        glPushMatrix();
        glScalef(7.5, 25, 1);
        desenhaQuadrado();
        glPopMatrix(); 

        if(cai == 0){
            
            skewX(cai_aux*3.1415/180.0f);  
            glColor3f(madeira_1, madeira_2, madeira_3);
            glTranslatef(0, 35, 0);  
            glPushMatrix();
            glScalef(7.5, 45, 1);
            desenhaQuadrado();
            glPopMatrix();     

            /* COPA */
            glColor3f(folha_1, folha_2, folha_3);
            glTranslatef(-20, 25, 0); 
            glPushMatrix();
            glScalef(20, 20, 1);
            desenhaCirculo();
            glPopMatrix(); 
            
            glColor3f(folha_1, folha_2, folha_3);
            glTranslatef(-10, 17.5, 0); 
            glPushMatrix();
            glScalef(20, 20, 1);
            desenhaCirculo();
            glPopMatrix(); 

            glColor3f(folha_1, folha_2, folha_3);
            glTranslatef(10, 5, 0); 
            glPushMatrix();
            glScalef(20, 20, 1);
            desenhaCirculo();
            glPopMatrix(); 
            
            glColor3f(folha_1, folha_2, folha_3);
            glTranslatef(10, -25, 0); 
            glPushMatrix();
            glScalef(20, 20, 1);
            desenhaCirculo();
            glPopMatrix(); 

            glColor3f(folha_1, folha_2, folha_3);
            glTranslatef(10, 0, 0); 
            glPushMatrix();
            glScalef(20, 20, 1);
            desenhaCirculo();
            glPopMatrix(); 

            glColor3f(folha_1, folha_2, folha_3);
            glTranslatef(15, 5, 0); 
            glPushMatrix();
            glScalef(20, 20, 1);
            desenhaCirculo();
            glPopMatrix(); 

            glColor3f(folha_1, folha_2, folha_3);
            glTranslatef(5, 10, 0); 
            glPushMatrix();
            glScalef(20, 20, 1);
            desenhaCirculo();
            glPopMatrix(); 

            glColor3f(folha_1, folha_2, folha_3);
            glTranslatef(-10, 5, 0); 
            glPushMatrix();
            glScalef(20, 20, 1);
            desenhaCirculo();
            glPopMatrix();

            glColor3f(folha_1, folha_2, folha_3);
            glTranslatef(-5, 10, 0); 
            glPushMatrix();
            glScalef(20, 20, 1);
            desenhaCirculo();
            glPopMatrix();

            skewX(-cai_aux*3.1415/180.0f);  
            glPopMatrix();
        }
        
        
        glPushMatrix();
        glColor3f(raio, raio, raio);
        glTranslatef(0, 200, 0);  
        glPushMatrix();
        glScalef(1, 1, 1);
        desenhaQuadrado();
        glPopMatrix();

        if(trovao == 1){
            /* RAIO */ 
            glColor3f(raio, raio, raio);
            glTranslatef(87.5, -160, 0);
            skewX(-30*3.1415/180.0f);  
            glPushMatrix();
            glScalef(5, 90, 1);
            desenhaQuadrado();
            glPopMatrix();

            glColor3f(raio, raio, raio);
            glTranslatef(-12, -43, 0);
            skewX(30*3.1415/180.0f);  
            glPushMatrix();
            glScalef(22, 4, 1);
            desenhaQuadrado();
            glPopMatrix();

            glColor3f(raio, raio, raio);
            glTranslatef(20.5, -55.5, 0);
            skewX(-30*3.1415/180.0f);  
            glPushMatrix();
            glScalef(5, 115, 1);
            desenhaQuadrado();
            glPopMatrix();
        }

        if(fala == 1){ 
            glColor3f(raio, raio, raio);
            glTranslatef(20, -285, 0); 
            glPushMatrix();
            glScalef(25, 10, 1);
            desenhaCirculo();
            glPopMatrix();

            glColor3f(raio, raio, raio);
            glTranslatef(-15, 0, 0); 
            skewX(30*3.1415/180.0f); 
            glPushMatrix();
            glScalef(15, 15, 1);
            desenhaTriangulo();
            glPopMatrix();
            
            skewX(-30*3.1415/180.0f); 
            glColor3f(0, 0, 0);
            texto(-2, -1.5, GLUT_BITMAP_HELVETICA_12, "MADEIRAAAA");
        }


    /* Executa os comandos OpenGL*/
    glutSwapBuffers();
}

void mudaTrovao(){
    cor_background_1 = 71.0/255.0;
    cor_background_2 = 76.0/255.0;
    cor_background_3 = 96.0/255.0;

    cor_piso_1 = 57.0/255.0;
    cor_piso_2 = 99.0/255.0;
    cor_piso_3 = 36.0/255.0;

    cor_parede1_1 = 204.0/255.0; 
    cor_parede1_2 = 199.0/255.0; 
    cor_parede1_3 = 187.0/255.0; 
    cor_parede2_1 = 191.0/255.0; 
    cor_parede2_2 = 186.0/255.0; 
    cor_parede2_3 = 174.0/255.0; 

    cor_telhado_1 = 51.0/255.0; 
    cor_telhado_2 = 47.0/255.0;
    cor_telhado_3 = 44.0/255.0;

    cor_chamine1_1 = 104.0/255.0; 
    cor_chamine1_2 = 88.0/255.0; 
    cor_chamine1_3 = 71.0/255.0; 
    cor_chamine2_1 = 75.0/255.0;
    cor_chamine2_2 = 62.0/255.0;
    cor_chamine2_3 = 49.0/255.0; 

    cor_porta1_1 = 54.0/255.0; 
    cor_porta1_2 = 43.0/255.0; 
    cor_porta1_3 = 29.0/255.0;
    cor_porta2_1 = 104.0/255.0; 
    cor_porta2_2 = 87.0/255.0; 
    cor_porta2_3 = 33.0/255.0;

    cor_janela1_1 = 10.0/255.0; 
    cor_janela1_2 = 10.0/255.0; 
    cor_janela1_3 = 1/255.0;
    cor_janela2_1 = 246.0/255.0; 
    cor_janela2_2 = 164.0/255.0; 
    cor_janela2_3 = 61/255.0; 

    cor_fumaca_1 = 204.0/255.0; 
    cor_fumaca_2 = 204.0/255.0; 
    cor_fumaca_3 = 204.0/255.0; 
    
    detalhe = 0.2; 

    madeira_1 = 58.0/255.0; 
    madeira_2 = 33.0/255.0; 
    madeira_3 = 14.0/255.0; 

    folha_1 = 33.0/255.0; 
    folha_2 = 104.0/255.0; 
    folha_3 = 15.0/255.0; 
}

void mudaNormal(){
    cor_background_1 = 35.0/255.0;
    cor_background_2 = 38.0/255.0;
    cor_background_3 = 48.0/255.0;

    cor_piso_1 = 28.0/255.0;
    cor_piso_2 = 49.0/255.0;
    cor_piso_3 = 18.0/255.0;

    cor_parede1_1 = 100.0/255.0; 
    cor_parede1_2 = 97.0/255.0; 
    cor_parede1_3 = 90.0/255.0; 
    cor_parede2_1 = 95.0/255.0; 
    cor_parede2_2 = 93.0/255.0; 
    cor_parede2_3 = 87.0/255.0; 

    cor_telhado_1 = 25.0/255.0; 
    cor_telhado_2 = 23.0/255.0;
    cor_telhado_3 = 22.0/255.0;

    cor_chamine1_1 = 52.0/255.0; 
    cor_chamine1_2 = 44.0/255.0; 
    cor_chamine1_3 = 35.0/255.0; 
    cor_chamine2_1 = 37.0/255.0; 
    cor_chamine2_2 = 31.0/255.0; 
    cor_chamine2_3 = 24.0/255.0;

    cor_porta1_1 = 27.0/255.0; 
    cor_porta1_2 = 21.0/255.0; 
    cor_porta1_3 = 14.0/255.0; 
    cor_porta2_1 = 86.0/255.0; 
    cor_porta2_2 = 72.0/255.0; 
    cor_porta2_3 = 26.0/255.0; 

    cor_janela1_1 = 10.0/255.0; 
    cor_janela1_2 = 10.0/255.0; 
    cor_janela1_3 = 1/255.0;
    cor_janela2_1 = 246.0/255.0; 
    cor_janela2_2 = 164.0/255.0; 
    cor_janela2_3 = 61/255.0; 

    cor_fumaca_1 = 102.0/255.0; 
    cor_fumaca_2 = 102.0/255.0; 
    cor_fumaca_3 = 102.0/255.0; 

    detalhe = 0.2; 

    madeira_1 = 29.0/255.0; 
    madeira_2 = 16.0/255.0; 
    madeira_3 = 7.0/255.0; 

    folha_1 = 16.0/255.0; 
    folha_2 = 52.0/255.0; 
    folha_3 = 7.0/255.0; 

}

void tempo_fumaca(int value) {
    if(y_fumaca_1 < 25){
        y_fumaca_1 += 1;
        x_fumaca_1 += 1;
    }
    
    if(y_fumaca_2 < 20){
        y_fumaca_2 += 1;
        x_fumaca_2 += 1;
    }

    if(x_fumaca_1 < 175)
        x_fumaca_1 += 1;
    else{
        x_fumaca_1 = 0;
        y_fumaca_1 = 0;
    }


    if(x_fumaca_2 < 175)
        x_fumaca_2 += 1;
    else{
        x_fumaca_2 = 0;
        y_fumaca_2 = 0;
    }

    glutPostRedisplay(); 
    glutTimerFunc(200, tempo_fumaca, 0); 
}

void tempo_arvore(int value) {
    if(cai_aux == 5)
        fala = 1;

    if(cai_aux < 90)
        cai_aux += 1;
    else 
        fala = 0;

    glutPostRedisplay(); 
    glutTimerFunc(120, tempo_arvore, 0);  // Redesenha a cada ~16 milissegundos (aproximadamente 60 FPS)
}

void tempo_trovao(int value) {
    mudaTrovao(); 
    alternancia++;
    glutPostRedisplay();
    
    if(alternancia == 1)
        trovao = 1;

    if (alternancia < 3) 
        glutTimerFunc(200, tempo_normal, 0);
    else {
        trovao = 0;     
        mudaNormal(); 
        glutPostRedisplay();
        tempo_arvore(0); 
        glutPostRedisplay();
        glutTimerFunc(5000, tempo_arvore, 0);
    }
}

void tempo_normal(int value) {
    trovao = 0;
    mudaNormal(); 
    glutPostRedisplay();

    if (alternancia < 4) 
        glutTimerFunc(100, tempo_trovao, 0); 
    else {
        tempo_arvore(0); 
        glutPostRedisplay();
        glutTimerFunc(2000, tempo_arvore, 0);
    }
}

void texto(float x, float y, void *font, const char* string) {
    glRasterPos2f(x, y);

    while (*string) {
        glutBitmapCharacter(font, *string);
        string++;
    }
}

void meuTeclado(unsigned char key, int x, int y){
    switch(key){
        case 27:
            exit(0);
            break; 
        case 't':
            alternancia = 0; 
            tempo_trovao(0);
            break;
    }
}

// Inicializa parâmetros de rendering
void Inicializa (void)
{
    // Define a cor de fundo da janela de visualização como preta
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

// Função callback chamada quando o tamanho da janela é alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
    // Evita a divisao por zero
    if(h == 0) h = 1;

    // Especifica as dimensões da Viewport
    glViewport(0, 0, w, h);

    // Inicializa o sistema de coordenadas
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Estabelece a janela de seleção (left, right, bottom, top)
    // Se a largura da janela, em pixels, for menor que a altura, a largura da viewport é fixada em 250 e a altura é escalada para o necessário
    if (w <= h)  {
        windowHeight = 250.0f*h/w;
                windowWidth = 250.0f;
    }
    else  {
    // Se a altura da janela, em pixels, for menor que a largura, a altura da viewport é fixada em 250 e a largura é escalada para o necessário
                windowWidth = 250.0f*w/h;
                windowHeight = 250.0f;
    }

    // As dimensões da janela vão de (0.0, 0.0) até (windowWidth, windowHeight), essas são as coordenadas da tela
    gluOrtho2D(0.0f, windowWidth, 0.0f, windowHeight);
}

// Programa Principal
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(900,600);
    glutInitWindowPosition(10,10);
    glutCreateWindow("Minha Casa");
    glutDisplayFunc(Desenha);
    glutReshapeFunc(AlteraTamanhoJanela);
    glutKeyboardFunc(meuTeclado);
    glutTimerFunc(0, tempo_fumaca, 0); 
    Inicializa();
    glutMainLoop();
    return 0;
}