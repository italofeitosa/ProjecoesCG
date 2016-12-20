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
    //gluLookAt(5,5,5,0,0,0,0,1,0); //projecaoOrtograficaIsometrica5();

    //ang += 0.5;

    //glRotatef(ang,0,1,0);
    glScalef(1, 1, 4); //Questão 8
    glTranslatef(x,y,z);

    glColor3f(1,0,0);
    //wired=!wired;
    if(wired)
        glutWireCube(R);
    else
        glutSolidCube(R);

}

/*### Questão 1*/
void projecaoCavaleira1(){
    float cavalieraMatriz [4][4] = {{1,0,0,0},{0,1,0,0},{-cos(3.1415/4.0),-sin(3.1415/4.0),0,0},{0,0,0,1}};
    glMultMatrixf(*cavalieraMatriz);

}

/*### Questão 2*/
void projecaoCavaleiraObliqua2(){
    float cavalieraMatriz [4][4] = {{1,0,0,0},{0,1,0,0},{-cos(3.1415/4.0),-sin(3.1415/4.0),0,0},{0,0,0,1}};
    glOrtho(-5,5, -5, 5, -5,5);
    glMultMatrixf(*cavalieraMatriz);

}

/*### Questão 3*/
//Angulos 30, 45 e 60 (CAVALEIRA)
void projecaoCavaleira3(double angulo){
    float cavalieraMatriz [4][4] = {{1,0,0,0},{0,1,0,0},{-cos(angulo),-sin(angulo),0,0},{0,0,0,1}};
    //glOrtho(-5,5, -5, 5, -5,5);
    glMultMatrixf(*cavalieraMatriz);

}

/*### Questão 4*/
//Angulos 30, 45 e 60 (CABINET)
void projecaoCabinet4(double angulo){
    float cabinetMatriz [4][4] = {{1.0,0.0,0.0,0.0},{0.0,1.0,0.0,0.0},{-cos(angulo)/2.0,-sin(angulo)/2,0.0,0.0},{0.0,0.0,0.0,1.0}};
    //glOrtho(-5,5, -5, 5, -5,15);
    glMultMatrixf(*cabinetMatriz);
}

/*### Questão 5*/
//habilitar o gluLookAt
void projecaoOrtograficaIsometrica5(double angulo){
    float cabinetMatriz [4][4] = {{1.0,0.0,0.0,0.0},{0.0,1.0,0.0,0.0},{-cos(angulo)/2.0,-sin(angulo)/2,0.0,0.0},{0.0,0.0,0.0,1.0}};
    glMultMatrixf(*cabinetMatriz);
    glOrtho(-5,5, -5, 5, -5,15);
}

/*### Questão 6*/
void projecaoPespectiva6(double angulo, int h, int w){
    float cabinetMatriz [4][4] = {{1.0,0.0,0.0,0.0},{0.0,1.0,0.0,0.0},{-cos(angulo)/2.0,-sin(angulo)/2,0.0,0.0},{0.0,0.0,0.0,1.0}};
    glMultMatrixf(*cabinetMatriz);
    gluPerspective(90,h/w,5,15);
}

/*### Questão 7*/
void projecaoPerpectivaComparar7(double angulo, int h, int w){
    float cabinetMatriz [4][4] = {{1.0,0.0,0.0,0.0},{0.0,1.0,0.0,0.0},{-cos(angulo)/2.0,-sin(angulo)/2,0.0,0.0},{0.0,0.0,0.0,1.0}};
    glMultMatrixf(*cabinetMatriz);
    gluPerspective(90,h/w, 5,-15);
}

/*### Questão 8*/
void transformacaoPara8(double angulo){
    float cavalieraMatriz [4][4] = {{1,0,0,0},{0,1,0,0},{-cos(angulo),-sin(angulo),0,0},{0,0,0,1}};
   // float cabinetMatriz [4][4] = {{1.0,0.0,0.0,0.0},{0.0,1.0,0.0,0.0},{-cos(angulo)/2.0,-sin(angulo)/2,0.0,0.0},{0.0,0.0,0.0,1.0}};
    glMultMatrixf(*cavalieraMatriz);
    glOrtho(-5,5, -5, 5, -5, 15);
}

void GLWidget::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //CAVALIER
    /*### Questão 1*/
    //projecaoCavaleira1();

    /*### Questão 2*/
    //projecaoCavaleiraObliqua2();

    /*### Questão 3*/
    //projecaoCavaleira3(ang45);

    //CABINET
    /*### Questão 4*/
    //projecaoCabinet4(ang45);

    /*### Questão 5*/
    //projecaoOrtograficaIsometrica5(ang60);

    /*### Questão 6*/
    //projecaoPespectiva6(ang60,h,w);

    /*### Questão 7*/
    //projecaoPerpectivaComparar7(ang60,h,w);

    /*### Questão 8*/
    //transformacaoPara8(ang45);


    glClearColor(0.0f,0.0f,0.0f,0.0f);
    glClear( GL_COLOR_BUFFER_BIT  );

    glClear(GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    updateGL();
}
