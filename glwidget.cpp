#include "glwidget.h"
#include <GL/glut.h>


GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)
{
    this->R = 1;
    this->wired = false;
    this->ang = 0.5;
    this->x=0;
    this->y=0;
    this->z=0;
    this->ang30=3.1415/6.0;
    this->ang45=3.1415/4.0;
    this->ang60=3.1415/3.0;


    connect( &timer, SIGNAL(timeout()), this, SLOT(updateGL()) );
    timer.start(16);
}

void GLWidget::initializeGL()
{
    glClearColor(0.2, 0.2, 0.2, 1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    float LightAmbient[3] = {0.6,0.6,0.9};
    float LightDiffuse[3] = {0.6,0.6,0.9};
    float LightPosition[3] = {0.0,5,0.0};
    glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);
    glLightfv(GL_LIGHT1, GL_POSITION, LightPosition);
}

void GLWidget::paintGL()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //gluLookAt(5,0,5,0,0.5,0,0,1,0);
    //gluLookAt(5,5,5,0,0,0,0,1,0); //Questao 5
    //gluLookAt(2,0,2,0,0,0,0,1,0); //questao 6
    //gluLookAt(1,1,1,0,0,0,0,1,0); //questao 7

    //gluLookAt(5,5,20,0,0,0,0,1,0); //Questao 8 2)
    //gluLookAt(2,0,8,0,0,0,0,1,0); //questao 8 4)

    //ang += 0.5;

    //glRotatef(ang,0,5,0);
    glScalef(1, 1, 4); //Questão 8
    //glTranslatef(x,y,z);

    glColor3f(0,1,0);
    //wired=!wired;
    if(wired)
        glutWireCube(R);
    else
        glutSolidCube(R);

}

/*### Questão 1*/
void projecaoCavaleira1(){
    float cavalieraMatriz [4][4] = {{1,0,0,0},{0,1,0,0},{-cos(3.1415/4.0),-sin(3.1415/4.0),0,0},{0,0,0,1}};
    glOrtho(-5, 5, -5, 5, -5, 5);
    glMultMatrixf(*cavalieraMatriz);

}

/*### Questão 2, 3 e 4*/
void projecaoObliqua(float alpha, float l){

    float cavalieraMatriz [4][4] = {{1,0,0,0},{0,1,0,0},{-cos(alpha/180*3.1415)*l,-sin(alpha/180*3.1415)*l,0,0},{0,0,0,1}};
    glOrtho(-5, 5, -5, 5, -5, 5);
    glMultMatrixf(*cavalieraMatriz);
}

/*### Questão 5*/
//habilitar o gluLookAt
void projecaoOrtograficaIsometrica5(){

    glOrtho(-5,5, -5, 5, -5,15);
}

/*### Questão 6*/
//habilitar o gluLookAt
void projecaoPespectiva6(){

    //gluPerspective(45,1,0.5,3);
    gluPerspective(45,1,0.5,4);

}

/*### Questão 7*/
//habilitar o gluLookAt
void projecaoPerpectivaComparar7(){

   gluPerspective(60,1,0.5,20);
}

/*### Questão 8*/
//habilitar o gluLookAt
void transformacaoPara8(double alpha, double l){

    //1)Visão Frontal
     glOrtho(-5, 5, -5, 5, 0, 15);

    //2) Visão Isométrica
    //glOrtho(-5,5, -5, 5, -5,40);

    //3) Projeção Cavaleira com alfa = 30°
//    float Matriz [4][4] = {{1,0,0,0},{0,1,0,0},{-cos(alpha/180*3.1415)*l,-sin(alpha/180*3.1415)*l,0,0},{0,0,0,1}};
//    glOrtho(-5, 5, -5, 5, -5, 20);
//    glMultMatrixf(*Matriz);

    //4) Projeção pespectiva com dois ponto de fuga
    //gluPerspective(45,1,1,16);



}


void GLWidget::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //CAVALIER
    /*### Questão 1*/
    //projecaoCavaleira1();

    /*### Questão 2, 3 e 4*/
    //projecaoObliqua(60, 0.5);

    /*### Questão 5 - habilitar o LookAt 5*/
    //projecaoOrtograficaIsometrica5();

    /*### Questão 6 - habilitar o LookAt 6*/
    //projecaoPespectiva6();

    /*### Questão 7 - habilitar o LookAt 7*/
    //projecaoPerpectivaComparar7();

    /*### Questão 8 - habilitar o LookAt 8*/
    transformacaoPara8(30, 1);


    glClearColor(0.0f,0.0f,0.0f,0.0f);
    glClear( GL_COLOR_BUFFER_BIT  );

    glClear(GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    updateGL();
}
