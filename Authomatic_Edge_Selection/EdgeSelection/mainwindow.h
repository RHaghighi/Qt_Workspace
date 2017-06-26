#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// Qt
#include <QMainWindow>

#include <iostream>

// Point Cloud Library
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/io/pcd_io.h>
#include <pcl/visualization/point_picking_event.h>
#include <pcl/console/time.h>

// Visualization Toolkit (VTK)
#include <vtkRenderWindow.h>

#include <pcl/common/geometry.h>
#include <pcl/common/distances.h>

#include <pcl/io/openni_grabber.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/filters/fast_bilateral_omp.h>
#include <pcl/common/transforms.h>
#include <pcl/filters/median_filter.h>

#include "organized_edge_detection.h"
#include "organized_edge_detection.hpp"

#include <pcl/filters/voxel_grid.h>
#include <pcl/filters/passthrough.h>

#include <pcl/sample_consensus/ransac.h>
#include <pcl/sample_consensus/method_types.h>
#include <pcl/sample_consensus/model_types.h>
#include <pcl/segmentation/sac_segmentation.h>
#include <pcl/ModelCoefficients.h>
#include <pcl/filters/extract_indices.h>

#include"Edge_Detection.h"

#include <pcl/filters/extract_indices.h>
#include <pcl/visualization/area_picking_event.h>




typedef pcl::PointXYZRGBA PointT;
typedef pcl::PointCloud<PointT> PointCloudT;

using namespace pcl;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void addCustomAction(double number1,double number2,double number3);

    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;
    PointCloudT::Ptr cloud;

    pcl::OpenNIGrabber* openniGrabber;

    //boost::shared_ptr<pcl::visualization::CloudViewer> viewer_CV;
    //pcl::visualization::CloudViewer *viewer_CV;
    //boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer_CV;

    pcl::PointCloud<PointT> cloud_;

    boost::mutex cloud_mutex;

    void cloud_cb_ (const pcl::PointCloud<pcl::PointXYZRGBA>::ConstPtr& cloud02);

    boost::shared_ptr<pcl::visualization::PCLVisualizer> initCloudViewer (pcl::PointCloud<pcl::PointXYZRGBA>::ConstPtr cloud00);

    void grabberCallback(const pcl::PointCloud<pcl::PointXYZRGBA>::ConstPtr& cloud0);

    void AreaPickingEventOccurred(const pcl::visualization::AreaPickingEvent &event, void* viewer_void);


    bool saveCloud;

    openni_wrapper::OpenNIDriver& driver = openni_wrapper::OpenNIDriver::getInstance ();

    pcl::PointCloud<pcl::PointXYZRGBA>::Ptr high_curvature_edges;

    pcl::PointCloud<pcl::PointXYZRGBA>::Ptr high_curvature_edges_filtered_PT;

    double offset_R_K;

    std::vector<float> Sensor_vect;
    std::vector<float> Robot_vect;
    std::vector<float> Offset_RS_vect;
    std::vector<float> Gantry_vect;

    bool init_checker;

    bool Edge_detec_param;

    pcl::PointCloud<pcl::PointXYZRGBA>::Ptr cloud_filtered;



protected:




private slots:
  void on_Load_PCD_clicked();

  void on_Clear_List_clicked();

  void on_Compute_clicked();

  void on_Start_Live_Stream_clicked();

  int on_Stop_Live_Stream_clicked();

  void on_actionOpen_triggered();

  void pointPickingOccured (const pcl::visualization::PointPickingEvent &eventp, void* args);

  void keyboardEventOccurred(const pcl::visualization::KeyboardEvent& event, void* nothing);

  //void areaPickingOccured (const pcl::visualization::AreaPickingEvent &eventp, void* args);

  void on_pushButton_Quaternion2Euler_clicked();

  void on_pushButton_Euler2Quaternion_clicked();

  void on_Update_SB_clicked();

  void on_Edge_Detect_clicked();

  void on_Filter_x_pos_valueChanged(double arg1);

  void on_Filter_x_neg_valueChanged(double arg1);


  void on_Filter_y_pos_valueChanged(double arg1);

  void on_Filter_y_neg_valueChanged(double arg1);

  void on_Filter_z_pos_valueChanged(double arg1);

  void on_Filter_z_neg_valueChanged(double arg1);

  void on_Filter_Edge_clicked();

private:
  Ui::MainWindow *ui;

};





#endif // MAINWINDOW_H
