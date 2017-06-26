#include "mainwindow.h"
#include "../build/ui_mainwindow.h"
#include <QFileDialog>
#include "Coord_Transformation.h"
#include <QMessageBox>


PointCloudT::Ptr clicked_points_3d (new PointCloudT);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle ("WorkObj Calibration");

     // Setup the cloud pointer
     cloud.reset (new PointCloudT);

     saveCloud =false;
     init_checker = true;

     // Set up the QVTK window
     viewer.reset (new pcl::visualization::PCLVisualizer ("viewer", false));

     ui->qvtkWidget->SetRenderWindow (viewer->getRenderWindow ());
     viewer->setupInteractor (ui->qvtkWidget->GetInteractor (), ui->qvtkWidget->GetRenderWindow ());
     ui->qvtkWidget->update ();
     viewer->resetCamera ();

     viewer->registerPointPickingCallback(&MainWindow::pointPickingOccured, *this);


     std::string Offset_RS_lists_init;
     std::ifstream myfile_init ("Sensor_Base_Frame.txt");
     if (myfile_init.is_open())
     {
       while ( std::getline (myfile_init,Offset_RS_lists_init) )
       {
          std::stringstream Offset_RS_init(Offset_RS_lists_init);
          float j_init;
          int k=0;

          while (Offset_RS_init >> j_init)
               {
               switch(k) {
                 case 0 :
                    ui->lineEdit_SB_x->setText(QString::number(j_init));
                 case 1 :
                  ui->lineEdit_SB_y->setText(QString::number(j_init));
                 case 2 :
                  ui->lineEdit_SB_z->setText(QString::number(j_init));
                }
                if (Offset_RS_init.peek() == ',')
                {
                    Offset_RS_init.ignore();
                    ++k;
                }
               }
       }
       myfile_init.close();
     }
     else QMessageBox::warning(this,tr("warning"),tr("Unable to open file Sensor_Base_Frame.txt"));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Load_PCD_clicked()
{


    QString filename_0 = QFileDialog::getOpenFileName(this, tr("Open File"), "/home/reza","All files (*.*);;pcd file (*.pcd)");

    QByteArray filename_1 = filename_0.toLatin1();
    const char *filename = filename_1.data();

    if (*filename)
    {

    viewer->removeAllPointClouds();

    pcl::io::loadPCDFile (filename, *cloud);

    // Set up the QVTK window

    ui->qvtkWidget->SetRenderWindow (viewer->getRenderWindow ());
    viewer->setupInteractor (ui->qvtkWidget->GetInteractor (), ui->qvtkWidget->GetRenderWindow ());
    ui->qvtkWidget->update ();


    viewer->addPointCloud (cloud, "cloud");
    viewer->resetCamera ();
    viewer->initCameraParameters ();
    viewer->setCameraPosition(0.05, 0.05, 0.15, 0, 0, 1, 0, -1, 0);
    //viewer->setSize (440,450);
    viewer->addCoordinateSystem(0.3);
    ui->qvtkWidget->update ();
    viewer->setSize (ui->qvtkWidget->width()-5,ui->qvtkWidget->height()-5);

    //viewer->registerPointPickingCallback(&MainWindow::pointPickingOccured, *this);

    }

}

void MainWindow::addCustomAction(double number1,double number2,double number3)
{
      ui->listWidget->addItem("Point " + QString::number(ui->listWidget->count()+1) +" :  " +
                              QString::number(number1) +",  "+ QString::number(number2) + ",  " + QString::number(number3) );

      PointT *current_point (new PointT);
      current_point->x = number1;
      current_point->y = number2;
      current_point->z = number3;

      clicked_points_3d->points.push_back(*current_point);


}


void MainWindow::on_Clear_List_clicked()
{
    ui->listWidget->clear();
    ui->WorkObj_Frame->clear();
    clicked_points_3d->clear();

    viewer->removeAllShapes();

    viewer->removeCoordinateSystem();
    //viewer->setCameraPosition(0, 0, 0, 0, 0, 1, 0, -1, 0);

}

void MainWindow::on_Compute_clicked()
{
    viewer->removeCoordinateSystem();
    viewer->addCoordinateSystem(0.3);
    ui->WorkObj_Frame->clear();


    // Median Filter
    pcl::MedianFilter<pcl::PointXYZRGBA> mf;
    mf.setInputCloud (cloud);
    mf.setWindowSize (7);
    mf.filter (*cloud);

    // Bilateral Filter
    pcl::FastBilateralFilterOMP<pcl::PointXYZRGBA> fbf;
    fbf.setInputCloud (cloud);
    fbf.setSigmaS (6.0f);
    fbf.setSigmaR (0.01f);
    fbf.filter (*cloud);

    pcl::PointCloud<pcl::Normal>::Ptr normal (new pcl::PointCloud<pcl::Normal>);
    pcl::IntegralImageNormalEstimation<PointXYZRGBA, pcl::Normal> ne;
    ne.setNormalEstimationMethod (ne.COVARIANCE_MATRIX);
    ne.setNormalSmoothingSize (10.0f);
    ne.setBorderPolicy (ne.BORDER_POLICY_MIRROR);
    ne.setInputCloud (cloud);
    ne.compute (*normal);


    float th_dd = 0.02f;
    int   max_search = 50;

    pcl::OrganizedEdgeFromRGBNormals<PointXYZRGBA, Normal, Label> oed;
    oed.setInputNormals (normal);
    oed.setInputCloud (cloud);
    oed.setDepthDisconThreshold (th_dd);
    oed.setMaxSearchNeighbors (max_search);
    oed.setEdgeType (oed.EDGELABEL_NAN_BOUNDARY | oed.EDGELABEL_OCCLUDING | oed.EDGELABEL_OCCLUDED | oed.EDGELABEL_HIGH_CURVATURE | oed.EDGELABEL_RGB_CANNY);
    PointCloud<Label> labels;
    std::vector<PointIndices> label_indices;
    oed.compute (labels, label_indices);


    pcl::PointCloud<pcl::PointXYZRGBA>::Ptr occluding_edges (new pcl::PointCloud<pcl::PointXYZRGBA>),
      occluded_edges (new pcl::PointCloud<pcl::PointXYZRGBA>),
      nan_boundary_edges (new pcl::PointCloud<pcl::PointXYZRGBA>),
      high_curvature_edges (new pcl::PointCloud<pcl::PointXYZRGBA>),
      rgb_edges (new pcl::PointCloud<pcl::PointXYZRGBA>);

    pcl::copyPointCloud (*cloud, label_indices[0].indices, *nan_boundary_edges);
    pcl::copyPointCloud (*cloud, label_indices[1].indices, *occluding_edges);
    pcl::copyPointCloud (*cloud, label_indices[2].indices, *occluded_edges);
    pcl::copyPointCloud (*cloud, label_indices[3].indices, *high_curvature_edges);
    pcl::copyPointCloud (*cloud, label_indices[4].indices, *rgb_edges);

    std::vector<int> indices_NaN;
    pcl::removeNaNFromPointCloud(*high_curvature_edges, *high_curvature_edges, indices_NaN);


    // VoxelGrid of edge
    pcl::PointCloud<pcl::PointXYZRGBA>::Ptr high_curvature_edges_filtered (new pcl::PointCloud<pcl::PointXYZRGBA>);
    pcl::VoxelGrid<pcl::PointXYZRGBA> sor;
    sor.setInputCloud (high_curvature_edges);
    sor.setLeafSize (0.002f, 0.002f, 0.002f);
    sor.filter (*high_curvature_edges_filtered);

    high_curvature_edges.swap (high_curvature_edges_filtered);


      // PassThrough Filter
      pcl::PassThrough<pcl::PointXYZRGBA> pass;
          pcl::PointCloud<pcl::PointXYZRGBA>::Ptr PassThrough_Cloud (new pcl::PointCloud<pcl::PointXYZRGBA>);

      pass.setInputCloud (high_curvature_edges);
      pass.setFilterFieldName ("x");
      pass.setFilterLimits (-0.05, 0.25);
      pass.filter (*high_curvature_edges);
      pass.setInputCloud (high_curvature_edges);
      pass.setFilterFieldName ("y");
      pass.setFilterLimits (-0.035, 0.35);
      pass.filter (*high_curvature_edges);

      double min_dist=4;
          for (int i=0; i<high_curvature_edges->size();++i)
          {  if (high_curvature_edges->points[i].z<min_dist)
                 min_dist=high_curvature_edges->points[i].z;
           }

      pass.setInputCloud (high_curvature_edges);
      pass.setFilterFieldName ("z");
      pass.setFilterLimits (min_dist-0.05, min_dist+0.015);
      pass.filter (*high_curvature_edges);


      // Line Segmentation
      double x01, y01, z01, l01, m01, n01;
      double x02, y02, z02, l02, m02, n02;

      pcl::PointCloud<pcl::PointXYZRGBA>::Ptr Line1_Data (new pcl::PointCloud<pcl::PointXYZRGBA>);
      pcl::PointCloud<pcl::PointXYZRGBA>::Ptr Line2_Data (new pcl::PointCloud<pcl::PointXYZRGBA>);

      pcl::PointIndices::Ptr inliers (new pcl::PointIndices);
      pcl::SACSegmentation<pcl::PointXYZRGBA> seg;
      seg.setOptimizeCoefficients(true);
      seg.setModelType(pcl::SACMODEL_LINE);
      seg.setMethodType(pcl::SAC_RANSAC);
      seg.setDistanceThreshold(0.01);

      int nr_points = (int) high_curvature_edges->points.size ();
      pcl::PointCloud<pcl::PointXYZRGBA>::Ptr segment_p(new pcl::PointCloud<pcl::PointXYZRGBA>);
      pcl::PointCloud<pcl::PointXYZRGBA>::Ptr segment_p1(new pcl::PointCloud<pcl::PointXYZRGBA>);
      pcl::PointCloud<pcl::PointXYZRGBA>::Ptr segment_f(new pcl::PointCloud<pcl::PointXYZRGBA>);

      double k=0;

      while (high_curvature_edges->points.size () > 0.2 * nr_points)
      {
          pcl::ModelCoefficients::Ptr line_coeff (new pcl::ModelCoefficients);
      seg.setInputCloud(high_curvature_edges);
      seg.segment(*inliers, *line_coeff);

      if (inliers->indices.size () == 0  or inliers->indices.size () < 30)
      {
      break;
      }

      pcl::ExtractIndices<pcl::PointXYZRGBA> extract;
      extract.setInputCloud (high_curvature_edges);
      extract.setIndices (inliers);
      extract.setNegative (false);

      extract.filter (*segment_p1);

      *segment_p+=*segment_p1;

      extract.setNegative (true);
      extract.filter (*segment_f);
      high_curvature_edges.swap (segment_f);

      if (k==0)
          {
          x01 = line_coeff->values[0];
          y01 = line_coeff->values[1];
          z01 = line_coeff->values[2];
          l01 = line_coeff->values[3];
          m01 = line_coeff->values[4];
          n01 = line_coeff->values[5];

          *Line1_Data=*segment_p1;

          }
      else if (k==1)
          {
          x02 = line_coeff->values[0];
          y02 = line_coeff->values[1];
          z02 = line_coeff->values[2];
          l02 = line_coeff->values[3];
          m02 = line_coeff->values[4];
          n02 = line_coeff->values[5];

          *Line2_Data=*segment_p1;
          }

          line_coeff->values[3]=-line_coeff->values[3];
          line_coeff->values[4]=-line_coeff->values[4];
          line_coeff->values[5]=-line_coeff->values[5];

          ++k;
      }

          high_curvature_edges.swap (segment_p);


          // Find Intersection of Two Lines

         double t01 = (-l01*(pow(m02,2) + pow(n02,2))*(x01 - x02) - (m02*n01 - m01*n02)*(n02*(-y01 + y02) + m02*(z01 - z02)) + pow(l02,2)*(m01*(-y01 + y02) + n01*(-z01 + z02)) + l02*(m01*m02*(x01 - x02) + n01*n02*(x01 - x02) + l01*(m02*y01 - m02*y02 + n02*z01 - n02*z02))) / (pow(l02,2)*(pow(m01,2) + pow(n01,2)) + pow(m02*n01 - m01*n02, 2) - 2*l01*l02*(m01*m02 + n01*n02) + pow(l01,2) * (pow(m02,2) + pow(n02,2)));

         double t02 = -((l01*l02 + m01*m02 + n01*n02)*(l01*(x01 - x02) + m01*(y01 - y02) + n01*(z01 - z02)) - (pow(l01,2) + pow(m01,2) + pow(n01,2))*(l02*(x01 - x02) + m02*(y01 - y02) + n02*(z01 - z02))) / (-pow(l01*l02 + m01*m02 + n01*n02, 2) + (pow(l01,2) + pow(m01,2) + pow(n01,2))*(pow(l02,2) + pow(m02,2) + pow(n02,2)));

         double p_x = x01 + l01 * t01;
         double p_y = y01 + m01 * t01;
         double p_z = z01 + n01 * t01;
         double q_x = x02 + l02 * t02;
         double q_y = y02 + m02 * t02;
         double q_z = z02 + n02 * t02;

         double dist = sqrt(pow(p_x - q_x, 2) + pow(p_y - q_y, 2) + pow(p_z - q_z,2));

         std::cout << "distant: " << dist << std::endl;

         std::cout << "p_x : " << p_x  << p_y <<q_x  << std::endl;

         pcl::PointCloud<pcl::PointXYZ>::Ptr Cloud_Intersect (new pcl::PointCloud<pcl::PointXYZ>);
         Cloud_Intersect->width=2;
         Cloud_Intersect->height   = 1;
         Cloud_Intersect->points.resize (Cloud_Intersect->width * Cloud_Intersect->height);

         Cloud_Intersect->at(0).x = p_x;
         Cloud_Intersect->at(0).y = p_y;
         Cloud_Intersect->at(0).z = p_z;

         Cloud_Intersect->at(1).x = q_x;
         Cloud_Intersect->at(1).y = q_y;
         Cloud_Intersect->at(1).z = q_z;


         // Line 1 direction checking
         int index_Line;
         double max_val;
         double max_dist=0.01;

          for (int i=0; i<Line1_Data->size();++i)
          {
          max_val = pow(Line1_Data->at(i).x-Cloud_Intersect->at(0).x,2)+pow(Line1_Data->at(i).y-Cloud_Intersect->at(0).y,2)+pow(Line1_Data->at(i).z-Cloud_Intersect->at(0).z,2);
          if (max_val>max_dist)
               {
                 max_dist=max_val;
                 index_Line = i;
               }
          }

         Eigen::Vector3f vector_line1;
         vector_line1[0] = Line1_Data->at(index_Line).x - Cloud_Intersect->at(0).x;
         vector_line1[1] = Line1_Data->at(index_Line).y - Cloud_Intersect->at(0).y;
         vector_line1[2] = Line1_Data->at(index_Line).z - Cloud_Intersect->at(0).z;

         Eigen::Vector3f vector_line2;
         vector_line2[0] = l01;
         vector_line2[1] = m01;
         vector_line2[2] = n01;

         if (vector_line1.dot(vector_line2)<0)
         {
            l01=-l01;
            m01=-m01;
            n01=-n01;
         }

         pcl::PointCloud<pcl::PointXYZ>::Ptr Line_Direction (new pcl::PointCloud<pcl::PointXYZ>);
         Line_Direction->width=3;
         Line_Direction->height = 1;
         Line_Direction->points.resize (Line_Direction->width * Line_Direction->height);

         Line_Direction->at(0).x = Cloud_Intersect->at(0).x+l01/4;
         Line_Direction->at(0).y = Cloud_Intersect->at(0).y+m01/4;
         Line_Direction->at(0).z = Cloud_Intersect->at(0).z+n01/4;

         // Line 2 direction checking
         max_dist=0.01;
         for (int i=0; i<Line2_Data->size();++i)
          { max_val = pow(Line2_Data->at(i).x-Cloud_Intersect->at(1).x,2)+pow(Line2_Data->at(i).y-Cloud_Intersect->at(1).y,2)+pow(Line2_Data->at(i).z-Cloud_Intersect->at(1).z,2);
          if (max_val>max_dist)
               {
                 max_dist=max_val;
                 index_Line = i;
               }
          }

         vector_line1[0] = Line2_Data->at(index_Line).x - Cloud_Intersect->at(1).x;
         vector_line1[1] = Line2_Data->at(index_Line).y - Cloud_Intersect->at(1).y;
         vector_line1[2] = Line2_Data->at(index_Line).z - Cloud_Intersect->at(1).z;

         vector_line2[0] = l02;
         vector_line2[1] = m02;
         vector_line2[2] = n02;

         if (vector_line1.dot(vector_line2)<0)
         {
            l02=-l02;
            m02=-m02;
            n02=-n02;
         }

         Line_Direction->at(1).x = Cloud_Intersect->at(1).x+l02/4;
         Line_Direction->at(1).y = Cloud_Intersect->at(1).y+m02/4;
         Line_Direction->at(1).z = Cloud_Intersect->at(1).z+n02/4;

         vector_line1[0] = l01;
         vector_line1[1] = m01;
         vector_line1[2] = n01;

         vector_line2[0] = l02;
         vector_line2[1] = m02;
         vector_line2[2] = n02;

         Eigen::Vector3f vector_line3 = vector_line1.cross(vector_line2);

         Line_Direction->at(2).x = Cloud_Intersect->at(1).x+vector_line3[0]/4;
         Line_Direction->at(2).y = Cloud_Intersect->at(1).y+vector_line3[1]/4;
         Line_Direction->at(2).z = Cloud_Intersect->at(1).z+vector_line3[2]/4;
std::cout << "stage 7" <<std::endl;
         if (vector_line3[2]>0)
            {
             Line_Direction->at(0).x = Cloud_Intersect->at(1).x+l02/4;
             Line_Direction->at(0).y = Cloud_Intersect->at(1).y+m02/4;
             Line_Direction->at(0).z = Cloud_Intersect->at(1).z+n02/4;

             Line_Direction->at(1).x = Cloud_Intersect->at(0).x+l01/4;
             Line_Direction->at(1).y = Cloud_Intersect->at(0).y+m01/4;
             Line_Direction->at(1).z = Cloud_Intersect->at(0).z+n01/4;

             Line_Direction->at(2).x = Cloud_Intersect->at(1).x-vector_line3[0]/4;
             Line_Direction->at(2).y = Cloud_Intersect->at(1).y-vector_line3[1]/4;
             Line_Direction->at(2).z = Cloud_Intersect->at(1).z-vector_line3[2]/4;
            }


     // Find Transformation
      Eigen::Vector3f a0 = Eigen::Vector3f::Zero();
      Eigen::Vector3f a1 = Eigen::Vector3f::Zero();
      Eigen::Vector3f a2 = Eigen::Vector3f::Zero();


      a0 << Line_Direction->at(0).x-Cloud_Intersect->at(0).x, Line_Direction->at(0).y-Cloud_Intersect->at(0).y,Line_Direction->at(0).z-Cloud_Intersect->at(0).z;
      a1 << Line_Direction->at(1).x-Cloud_Intersect->at(0).x, Line_Direction->at(1).y-Cloud_Intersect->at(0).y,Line_Direction->at(1).z-Cloud_Intersect->at(0).z;
      a2 << Line_Direction->at(2).x-Cloud_Intersect->at(0).x, Line_Direction->at(2).y-Cloud_Intersect->at(0).y,Line_Direction->at(2).z-Cloud_Intersect->at(0).z;

      a0.normalize();
      a1.normalize();
      a2.normalize();

      Eigen::Matrix3f Matrix0 = Eigen::Matrix3f::Zero();

      Matrix0 << a0,
            a1,
            a2;
      Matrix0.transpose();

      Eigen::Matrix3f Matrix1 = Eigen::Matrix3f::Zero();

      Matrix1 << 1, 0, 0,
            0, 1, 0,
            0, 0, 1;

     Matrix0.inverse();

     Eigen::Affine3f transform0 = Eigen::Affine3f::Identity();

     Eigen::Vector3f trans0 = Eigen::Vector3f::Zero();

     trans0 << (Cloud_Intersect->at(0).x+Cloud_Intersect->at(1).x)/2, (Cloud_Intersect->at(0).y+Cloud_Intersect->at(1).y)/2, (Cloud_Intersect->at(0).z+Cloud_Intersect->at(1).z)/2;

     transform0.linear() = Matrix0;
     transform0.translation() = trans0;

     float yaw, pitch, roll;
     pcl::getEulerAngles (transform0, roll, pitch, yaw);

     viewer->addCoordinateSystem(0.3,  transform0);



/*

    // //////////////////

    Eigen::Vector3f a0 = Eigen::Vector3f::Zero();
    Eigen::Vector3f a1 = Eigen::Vector3f::Zero();
    Eigen::Vector3f a2 = Eigen::Vector3f::Zero();


    clicked_points_3d->at(0).x = (clicked_points_3d->at(0).x + clicked_points_3d->at(1).x)/2;
    clicked_points_3d->at(0).y = (clicked_points_3d->at(0).y + clicked_points_3d->at(1).y)/2;
    clicked_points_3d->at(0).z = (clicked_points_3d->at(0).z + clicked_points_3d->at(1).z)/2;

    clicked_points_3d->at(1).x = (clicked_points_3d->at(2).x + clicked_points_3d->at(3).x)/2;
    clicked_points_3d->at(1).y = (clicked_points_3d->at(2).y + clicked_points_3d->at(3).y)/2;
    clicked_points_3d->at(1).z = (clicked_points_3d->at(2).z + clicked_points_3d->at(3).z)/2;

    clicked_points_3d->at(2).x = (clicked_points_3d->at(4).x + clicked_points_3d->at(5).x)/2;
    clicked_points_3d->at(2).y = (clicked_points_3d->at(4).y + clicked_points_3d->at(5).y)/2;
    clicked_points_3d->at(2).z = (clicked_points_3d->at(4).z + clicked_points_3d->at(5).z)/2;

    double New_z = (clicked_points_3d->at(0).z + clicked_points_3d->at(1).z + clicked_points_3d->at(2).z)/3;

    clicked_points_3d->at(0).z = New_z;
    clicked_points_3d->at(1).z = New_z;
    clicked_points_3d->at(2).z = New_z;

    float t, t_num, t_den;

    t_num = (clicked_points_3d->at(1).x-clicked_points_3d->at(0).x)*(clicked_points_3d->at(2).x-clicked_points_3d->at(0).x)+
            (clicked_points_3d->at(1).y-clicked_points_3d->at(0).y)*(clicked_points_3d->at(2).y-clicked_points_3d->at(0).y)+
            (clicked_points_3d->at(1).z-clicked_points_3d->at(0).z)*(clicked_points_3d->at(2).z-clicked_points_3d->at(0).z);

    t_den = (clicked_points_3d->at(1).x-clicked_points_3d->at(0).x)*(clicked_points_3d->at(1).x-clicked_points_3d->at(0).x)+
            (clicked_points_3d->at(1).y-clicked_points_3d->at(0).y)*(clicked_points_3d->at(1).y-clicked_points_3d->at(0).y)+
            (clicked_points_3d->at(1).z-clicked_points_3d->at(0).z)*(clicked_points_3d->at(1).z-clicked_points_3d->at(0).z);

    t = t_num / t_den;

    float point_x, point_y, point_z;

    point_x = clicked_points_3d->at(0).x + t * (clicked_points_3d->at(1).x-clicked_points_3d->at(0).x);
    point_y = clicked_points_3d->at(0).y + t * (clicked_points_3d->at(1).y-clicked_points_3d->at(0).y);
    point_z = clicked_points_3d->at(0).z + t * (clicked_points_3d->at(1).z-clicked_points_3d->at(0).z);

    a0 << clicked_points_3d->at(1).x-point_x, clicked_points_3d->at(1).y-point_y,
            clicked_points_3d->at(1).z-point_z;

    a1 << clicked_points_3d->at(2).x-point_x, clicked_points_3d->at(2).y-point_y,
            clicked_points_3d->at(2).z-point_z;

    a0 = 1000* a0;
    a1 = 1000* a1;

    a0.normalize();
    a1.normalize();

    a2=a0.cross(a1);
    a2.normalize();

    Eigen::Matrix3f m0 = Eigen::Matrix3f::Zero();

    m0 << a0,
          a1,
          a2;
    m0.transpose();


    Eigen::Matrix3f m1 = Eigen::Matrix3f::Zero();

    m1 << 1, 0, 0,
          0, 1, 0,
          0, 0, 1;

   m0.inverse();

   Eigen::Affine3f transform0 = Eigen::Affine3f::Identity();

   Eigen::Vector3f trans0 = Eigen::Vector3f::Zero();

   //trans0 << clicked_points_3d->at(0).x, clicked_points_3d->at(0).y, clicked_points_3d->at(0).z;
   trans0 << point_x, point_y, point_z;

   transform0.linear() = m0;
   transform0.translation() = trans0;


   float yaw, pitch, roll;
   pcl::getEulerAngles (transform0, roll, pitch, yaw);

   roll *= (180/3.14159265359);
   pitch *= (180/3.14159265359);
   yaw *= (180/3.14159265359);

   Eigen::Vector3f rotate0 = Eigen::Vector3f::Zero();
   rotate0(0)=roll;
   rotate0(1)=pitch;
   rotate0(2)=yaw;


   viewer->addCoordinateSystem(0.3,  transform0);

*/

   // //////////////////

   Eigen::Vector3f a0_WB = Eigen::Vector3f::Zero();
   Eigen::Vector3f a1_WB = Eigen::Vector3f::Zero();
   Eigen::Vector3f a2_WB = Eigen::Vector3f::Zero();

   a0_WB << 0, 1, 0;
   a1_WB << 1, 0, 0;
   a2_WB << 0, 0, -1;

   Eigen::Matrix3f m0_WB = Eigen::Matrix3f::Zero();

   m0_WB << a0_WB,
         a1_WB,
         a2_WB;
   m0_WB.transpose();

   m0_WB.inverse();

   Eigen::Affine3f transform0_WB = Eigen::Affine3f::Identity();

   Eigen::Vector3f trans0_WB = Eigen::Vector3f::Zero();

   transform0_WB.linear() = m0_WB;
   transform0_WB.translation() = trans0_WB;

   float yaw_WB, pitch_WB, roll_WB;
   pcl::getEulerAngles (transform0_WB, roll_WB, pitch_WB, yaw_WB);

   roll_WB *= (180/3.14159265359);
   pitch_WB *= (180/3.14159265359);
   yaw_WB *= (180/3.14159265359);

   // ////////////


   Eigen::Affine3f transform0_WWo = Eigen::Affine3f::Identity();

   transform0_WWo = transform0_WB * transform0;

   float yaw_WWo, pitch_WWo, roll_WWo;
   pcl::getEulerAngles (transform0_WWo, roll_WWo, pitch_WWo, yaw_WWo);

   roll_WWo *= (180/3.14159265359);
   pitch_WWo *= (180/3.14159265359);
   yaw_WWo *= (180/3.14159265359);


   //  /////////////

   std::string Offset_RS_lists;
   std::ifstream myfile ("Sensor_Base_Frame.txt");
   if (myfile.is_open())
   {
     while ( std::getline (myfile,Offset_RS_lists) )
     {
        std::stringstream Offset_RS(Offset_RS_lists);
        float j;

        Offset_RS_vect.clear();

        while (Offset_RS >> j)
             {
              Offset_RS_vect.push_back(j);

              if (Offset_RS.peek() == ',')
                  Offset_RS.ignore();
             }
     }
     myfile.close();
   }

   else QMessageBox::warning(this,tr("warning"),tr("Unable to open file Sensor_Base_Frame.txt"));


   //Offset_RS_vect.assign(3,0);
   //Offset_RS_vect.at(0)=103.45;
   //Offset_RS_vect.at(1)=-352.95;
   //Offset_RS_vect.at(2)=894.91;


//    Gantry Position

   QString Gantry_x = ui->Gantry_x->text();
   float Gantry_xf = Gantry_x.toFloat();

   QString Gantry_y = ui->Gantry_y->text();
   float Gantry_yf = Gantry_y.toFloat();

   QString Gantry_z = ui->Gantry_z->text();
   float Gantry_zf = Gantry_z.toFloat();

   Gantry_vect.assign(3,0);
   Gantry_vect.at(0)=Gantry_xf;
   Gantry_vect.at(1)=Gantry_yf;
   Gantry_vect.at(2)=Gantry_zf;

   //Gantry_vect.at(0)=3600.1;
   //Gantry_vect.at(1)=92.3;
   //Gantry_vect.at(2)=649.2;


//


   Eigen::Vector3f rotate1 = Eigen::Vector3f::Zero();
   rotate1(0)=roll_WWo;
   rotate1(1)=pitch_WWo;
   rotate1(2)=yaw_WWo;

   if (Gantry_vect.size()>0)
   ui->WorkObj_Frame->setText(QString::number(1000*trans0(1)+Offset_RS_vect.at(1)+Gantry_vect.at(0)) + ",  " +
                             QString::number(1000*trans0(0)+Offset_RS_vect.at(0)-Gantry_vect.at(1)) + ",  " +
                             QString::number(-1000*trans0(2)-Offset_RS_vect.at(2)-Gantry_vect.at(2)) + ",  " +
                             QString::number(rotate1(0)) + ",  " +QString::number(rotate1(1)) + ",  " +
                             QString::number(rotate1(2)) + "  " );


}



void MainWindow::on_Start_Live_Stream_clicked()
{


    if (driver.getNumberDevices() == 0)
        QMessageBox::warning(this,tr("warning"),tr("No devices connected."));

    else{

    viewer->removeAllPointClouds();
    //viewer.reset (new pcl::visualization::PCLVisualizer ("viewer", false));
    viewer->setCameraPosition(0.05, 0.05, 0.15, 0, 0, 1, 0, -1, 0);
    viewer->addCoordinateSystem(0.3);

    ui->qvtkWidget->SetRenderWindow (viewer->getRenderWindow ());
    viewer->setupInteractor (ui->qvtkWidget->GetInteractor (), ui->qvtkWidget->GetRenderWindow ());
    ui->qvtkWidget->update ();

    openniGrabber = new pcl::OpenNIGrabber("");

    boost::function<void(const pcl::PointCloud<pcl::PointXYZRGBA>::ConstPtr&)> f = boost::bind (&MainWindow::grabberCallback,this, _1);

    // Make and initialize a cloud viewer
    pcl::PointCloud<pcl::PointXYZRGBA>::Ptr init_cloud_ptr (new pcl::PointCloud<PointT>);

    if (init_checker)
        viewer = MainWindow::initCloudViewer (init_cloud_ptr);

    boost::signals2::connection c = openniGrabber->registerCallback (f);
    viewer->registerKeyboardCallback(&MainWindow::keyboardEventOccurred, *this);

    ui->qvtkWidget->update ();

    openniGrabber->start();

    viewer->addPointCloud(cloud_.makeShared (),"cloud");

    ui->qvtkWidget->update ();

   //openniGrabber->stop();

    }
}


void
MainWindow::grabberCallback(const pcl::PointCloud<pcl::PointXYZRGBA>::ConstPtr& cloud1)
{
    timeval curTime;
    gettimeofday(&curTime, NULL);
    int milli = curTime.tv_usec / 1000;

    char buffer [80];
    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", localtime(&curTime.tv_sec));

    char currentTime[84] = "";
    sprintf(currentTime, "%s:%d", buffer, milli);
    std::string filename0(currentTime);

    std::stringstream stream;
    stream << filename0 << ".pcd";
    std::string filename = stream.str();

      cloud_ = *cloud1;

         viewer->updatePointCloud(cloud_.makeShared ());

         boost::this_thread::sleep (boost::posix_time::microseconds (500000));


     if (saveCloud)
     {
         timeval curTime;
         gettimeofday(&curTime, NULL);
         int milli = curTime.tv_usec / 1000;

         char buffer [80];
         strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", localtime(&curTime.tv_sec));

         char currentTime[84] = "";
         sprintf(currentTime, "%s:%d", buffer, milli);
         std::string filename0(currentTime);

         std::stringstream stream;
         stream << filename0 << ".pcd";
         std::string filename = stream.str();

         pcl::io::savePCDFile(filename, *cloud1, true);

         saveCloud = false;
     }

}

boost::shared_ptr<pcl::visualization::PCLVisualizer> MainWindow::initCloudViewer (pcl::PointCloud<pcl::PointXYZRGBA>::ConstPtr cloud00)
{
  viewer->addPointCloud<pcl::PointXYZRGBA> (cloud00,"oo");
  //viewer->initCameraParameters ();
  viewer->setCameraPosition(0.05, 0.05, 0.15, 0, 0, 1, 0, -1, 0);
  viewer->addCoordinateSystem(0.3);

  return (viewer);
  init_checker = false;
}



void
MainWindow::keyboardEventOccurred(const pcl::visualization::KeyboardEvent& event, void* nothing)
{
    if (event.getKeySym() == "space" && event.keyDown())
        saveCloud = true;

}

void MainWindow::on_Stop_Live_Stream_clicked()
{
    if (driver.getNumberDevices() == 0)
        QMessageBox::warning(this,tr("warning"),tr("No devices connected."));
    else{

    if (openniGrabber->isRunning ())
        openniGrabber->stop();

    }
}

void MainWindow::on_actionOpen_triggered()
{

}




void
MainWindow::pointPickingOccured (const pcl::visualization::PointPickingEvent &eventp, void* args)
{

  PointT *current_point (new PointT);
  eventp.getPoint(current_point->x, current_point->y, current_point->z);

  addCustomAction(current_point->x,current_point->y,current_point->z);


  std::string str;
  timeval curTime;
  gettimeofday(&curTime, NULL);
  int milli = curTime.tv_usec / 1000;

  char buffer [80];
  strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", localtime(&curTime.tv_sec));

  char currentTime[84] = "";
  sprintf(currentTime, "%s:%d", buffer, milli);
  str=currentTime;

  viewer->addSphere (*current_point, 0.001, 255, 0, 0, str);

  delete current_point;

}



/*  Tab 2:  Calibration */

void MainWindow::on_pushButton_Quaternion2Euler_clicked()
{
    QString SQuat_q0 = ui->lineEdit_q0->text();
    float Quat_q0 = SQuat_q0.toFloat();

    QString SQuat_q1 = ui->lineEdit_q1->text();
    float Quat_q1 = SQuat_q1.toFloat();

    QString SQuat_q2 = ui->lineEdit_q2->text();
    float Quat_q2 = SQuat_q2.toFloat();

    QString SQuat_q3 = ui->lineEdit_q3->text();
    float Quat_q3 = SQuat_q3.toFloat();

    Quat_q0 /= std::sqrt(Quat_q0*Quat_q0+Quat_q1*Quat_q1+Quat_q2*Quat_q2+Quat_q3*Quat_q3);
    Quat_q1 /= std::sqrt(Quat_q0*Quat_q0+Quat_q1*Quat_q1+Quat_q2*Quat_q2+Quat_q3*Quat_q3);
    Quat_q2 /= std::sqrt(Quat_q0*Quat_q0+Quat_q1*Quat_q1+Quat_q2*Quat_q2+Quat_q3*Quat_q3);
    Quat_q3 /= std::sqrt(Quat_q0*Quat_q0+Quat_q1*Quat_q1+Quat_q2*Quat_q2+Quat_q3*Quat_q3);

    Eigen::Matrix3f mat3 = Eigen::Quaternionf(Quat_q0, Quat_q1, Quat_q2, Quat_q3).toRotationMatrix();
    Eigen::Matrix4f mat4 = Eigen::Matrix4f::Identity(); mat4.block(0,0,3,3) = mat3;

    Eigen::Affine3f Transform = Eigen::Affine3f::Identity();
    Transform.matrix()=mat4;

    float yaw, pitch, roll;
    pcl::getEulerAngles (Transform, roll, pitch, yaw);

    roll *= (180/3.14159265359);
    pitch *= (180/3.14159265359);
    yaw *= (180/3.14159265359);

    ui->lineEdit_roll->setText(QString::number(roll));
    ui->lineEdit_pitch->setText(QString::number(pitch));
    ui->lineEdit_yaw->setText(QString::number(yaw));

}

void MainWindow::on_pushButton_Euler2Quaternion_clicked()
{
    QString Sroll = ui->lineEdit_roll->text();
    float roll = Sroll.toFloat();

    QString Spitch = ui->lineEdit_pitch->text();
    float pitch = Spitch.toFloat();

    QString Syaw = ui->lineEdit_yaw->text();
    float yaw = Syaw.toFloat();

    roll *= (3.14159265359/180);
    pitch *= (3.14159265359/180);
    yaw *= (3.14159265359/180);

    Eigen::Affine3f transformation;
    transformation = pcl::getTransformation(0,0,0,roll,pitch,yaw);

    Eigen::Matrix4f mat4 = transformation.matrix();
    Eigen::Matrix3f mat3 = mat4.block(0,0,3,3);

    Eigen::Quaternionf q2(mat3);

    ui->lineEdit_q0->setText(QString::number(q2.w()));
    ui->lineEdit_q1->setText(QString::number(q2.x()));
    ui->lineEdit_q2->setText(QString::number(q2.y()));
    ui->lineEdit_q3->setText(QString::number(q2.z()));

}

void MainWindow::on_Update_SB_clicked()
{

    if (clicked_points_3d->size()<1)
        QMessageBox::warning(this,tr("warning"),tr("Please select at least 1 points"));
    else
    {
    QString list = ui->listWidget->item(0)->text();

    std::string lists = list.toUtf8().constData();

    std::stringstream ss;

    for (int i=10;i<lists.size();++i)
        ss << lists[i];

    float i;
    Sensor_vect.clear();

    while (ss >> i)
        {
         Sensor_vect.push_back(i);

         if (ss.peek() == ',')
            ss.ignore();
        }
    }

    QString RobotPos_x_str = ui->lineEdit_RobotPos_x->text();
    float RobotPos_x = RobotPos_x_str.toFloat();

    QString RobotPos_y_str = ui->lineEdit_RobotPos_y->text();
    float RobotPos_y = RobotPos_y_str.toFloat();

    QString RobotPos_z_str = ui->lineEdit_RobotPos_z->text();
    float RobotPos_z = RobotPos_z_str.toFloat();

    ui->lineEdit_SB_x->setText(QString::number(RobotPos_x-1000*Sensor_vect.at(0)));
    ui->lineEdit_SB_y->setText(QString::number(RobotPos_y-1000*Sensor_vect.at(1)));
    ui->lineEdit_SB_z->setText(QString::number(RobotPos_z-1000*Sensor_vect.at(2)));


    QString SB_x = ui->lineEdit_SB_x->text();
    std::string SB_x_str = SB_x.toUtf8().constData();

    QString SB_y = ui->lineEdit_SB_y->text();
    std::string SB_y_str = SB_y.toUtf8().constData();

    QString SB_z = ui->lineEdit_SB_z->text();
    std::string SB_z_str = SB_z.toUtf8().constData();

    std::stringstream SB_xyz;

    SB_xyz << SB_x_str << ", " << SB_y_str << ", " << SB_z_str << "\n";

    std::ofstream myfile_write;

    myfile_write.open ("Sensor_Base_Frame.txt");
    myfile_write << SB_xyz.str();
    myfile_write.close();

    //103.45, -352.95, 894.91
}
