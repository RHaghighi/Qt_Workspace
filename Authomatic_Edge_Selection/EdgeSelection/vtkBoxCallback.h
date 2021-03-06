#include <vtkSmartPointer.h>
// For the rendering pipeline setup:
#include <vtkConeSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkInteractorStyleTrackballCamera.h>
// For vtkBoxWidget2:
#include <vtkBoxWidget2.h>
#include <vtkBoxRepresentation.h>
#include <vtkCommand.h>
#include <vtkTransform.h>


class vtkBoxCallback : public vtkCommand
{
public:
  static vtkBoxCallback *New()
  {
    return new vtkBoxCallback;
  }
 
  vtkSmartPointer<vtkActor> m_actor;
 
  void SetActor( vtkSmartPointer<vtkActor> actor )
  {
    m_actor = actor;
  }
 
  virtual void Execute( vtkObject *caller, unsigned long, void* )
  {
    vtkSmartPointer<vtkBoxWidget2> boxWidget =
      vtkBoxWidget2::SafeDownCast(caller);
 
    vtkSmartPointer<vtkTransform> t =
      vtkSmartPointer<vtkTransform>::New();
 
    vtkBoxRepresentation::SafeDownCast( boxWidget->GetRepresentation() )->GetTransform( t );
    //this->m_actor->SetUserTransform( t );


    double* position = t->GetPosition();
    std::cout << "Position:  "  << position[0] << "  " << position[1] << "  " << position[2]  << std::endl;

    double* rotation = t->GetOrientation();
    std::cout << "Rotation:  " << rotation[0] << "  " << rotation[1] << "  " << rotation[2]  << std::endl;

    double* scale = t->GetScale();
    std::cout << "Scale:  " <<  scale[0] << "  " << scale[1] << "  " << scale[2]  << std::endl;


  }
 
  vtkBoxCallback(){}
};
