#ifndef SCENE_HH
#define SCENE_HH

#include <OpenMesh/Core/IO/MeshIO.hh>

#include <SceneT.hh>
#include <OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh>
#include <OpenMesh/Tools/Utils/getopt.h>
#include "MyMesh.hh"

using namespace Qt;
using namespace OpenMesh;


class Scene : public SceneT<MyMesh>
{
  Q_OBJECT
public:
    /// default constructor
    Scene() : SceneT<MyMesh>()
    {
      connect(m_modelButton, SIGNAL(clicked()), this, SLOT(selectMesh()));
      connect(removeModelButton, SIGNAL(clicked()), this, SLOT(removeMesh()));

    }
public slots:
    void selectMesh()
    {
      QString selfilter = tr("Meshes (*.stl *.obj)");
      loadMesh(QFileDialog::getOpenFileName(0, tr("Choose mesh"), QString(), tr("All files (*.*);;Meshes (*.stl *.obj)" ), &selfilter));
    }
  
  void removeMesh(){
    models.erase(models.begin());
  }



};
#endif
