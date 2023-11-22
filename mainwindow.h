#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QGraphicsEllipseItem>
#include <iostream>
#include "administradora.h"
#include "neurona.h"
#include <cmath>
#include <algorithm>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct Conexion {
    int nodo;
    float distancia;
};

struct ListaAdyacencia {
    int id;
    std::vector<Conexion> conexiones;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:

    void wheelEvent(QWheelEvent*);

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void llenarTabla();

    void buscarPorNeurona();

    void dibujarNeurona();

    void ordenarID();

    void ordenarVOLT();

    void puntosCercanos();

    void realizarDFS(int);

    void DFSUtil(int, QMap<int, bool>&, QString&, QList<int>&);

    bool sonAdyacentes(int, int);

    void realizarDFSDesdeNodoInicial();

    void mostrarTextoEnNodo(int);

private:
    Ui::MainWindow *ui;
    Neurona n;
    administradora administrarNeuronas;
    QGraphicsScene *scene;
    std::vector<ListaAdyacencia> listaAdyacencia;


};
#endif // MAINWINDOW_H
