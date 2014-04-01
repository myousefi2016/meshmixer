#ifndef MODEL_HH
#define MODEL_HH

#include <iostream>
#include <fstream>
#include <QString>
#include <QVector>
#include <QPainter>
#include <QGraphicsItem>
#include "Scene.hh"
#include "MyMesh.hh"
#include <QVector3D>
#include <eigen3/Eigen/Dense>
#include <nanoflann.hpp>

//#include <flann/io/hdf5.h>

using namespace Qt;
using namespace OpenMesh;
using namespace Eigen;

template <typename M>
class QtModelT : public QGraphicsItem
{
public:
    typedef M MyMesh;
    typedef std::vector<std::vector< std::pair< size_t, double > > > MapTable;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    int number;
    void calcNormals();

public:
    M mesh;
    QtModelT(M& m);
    ~QtModelT();
    void render();
    void select(int faceNumber);
    void updateColour();
    void updateRotation(QVector3D& rotationVec);
    void updateHorizontal(float x);
    void updateVertical(float x);
    void applyTransformations();
    M* getMesh(){ return &mesh; }
    PointMatrix buildMatrix();
    PointMatrix buildSampledMatrix();
    PointMatrix buildNormalMatrix();
    int getNoVerticies();
    void updateTransformations(Matrix<double, 3, 3>& R, double x, double y, double z);
    void nearestNeighbours(double radius, MapTable* resultTable);
    void scale(float alpha);


private:
    QVector3D modelRotation;
    QColor modelColor;
    GLfloat vertical;
    GLfloat horizontal;
    GLfloat depth;
    const float deg2Rad;



};

#if defined(OM_INCLUDE_TEMPLATES) && !defined(MODEL_CC)
#  define SCENE_TEMPLATES
#  include "QtModelT.cc"
#endif

#endif