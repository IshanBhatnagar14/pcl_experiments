#include <pcl_one.h>



pcl::PCLPointCloud2::Ptr ProcessPointClouds::cloud_blob(new pcl::PCLPointCloud2)  ;

pcl::PointCloud<pcl::PointXYZRGB>::Ptr ProcessPointClouds::_colour_point_cloud(new pcl::PointCloud<pcl::PointXYZRGB>) ;

// static pcl::visualization::CloudViewer ProcessPointClouds::viewer ;


ProcessPointClouds::ProcessPointClouds(ros::NodeHandle *nodehandle):nh_(*nodehandle){

    ROS_INFO("Nodehandle Initialized");


    Pub_Point_Cloud_Data = nh_.advertise<sensor_msgs::PointCloud2>("/reduced_points",1);

    Sub_Point_Cloud_Data = nh_.subscribe("/os_cloud_node/points",10,&ProcessPointClouds::Subscribe_Point_Cloud,this);

   


}


ProcessPointClouds::ProcessPointClouds( ){
    ROS_INFO(" Default Constructor Initialized");

}


ProcessPointClouds::~ProcessPointClouds(){

    Sub_Point_Cloud_Data.shutdown();
}

void ProcessPointClouds::Subscribe_Point_Cloud(const sensor_msgs::PointCloud2ConstPtr& msg){

    ROS_INFO("Subscriber Callback Called");

    sensor_msgs::PointCloud2 output;

    DownSampling_Filter(msg);

}

void ProcessPointClouds::DownSampling_Filter(const sensor_msgs::PointCloud2ConstPtr &Point_Cloud){

    ROS_INFO("Downsampling Filter Called");

    /*
      Container for original & filtered data
      The PCL library can only handle the PCL type, so you need to transfer the released ROS information to a PCL.
      First define the processed PCL variable first
      Define a new address of a PCL * Cloud
      Then define a constant pointer with this pointer to handle it to prevent the original pointer to modify the CloudPtr
      Do not directly define a constant pointer directly, because if a constant pointer is defined, you cannot save ROS's information into a PCL.
      Define an output PCL variable cloud_filtered

  */
    
    sensor_msgs::PointCloud2 output ;

    pcl::PCLPointCloud2 *cloud = new pcl::PCLPointCloud2;

    pcl::PCLPointCloud2ConstPtr cloudPtr(cloud);

  

    pcl_conversions::toPCL(*Point_Cloud,*cloud);
    
    sor.setInputCloud(cloudPtr);
    sor.setLeafSize(0.05f,0.05f,0.05f);
    sor.filter(cloud_filtered);

    pcl_conversions::fromPCL(cloud_filtered,output);

    Pub_Point_Cloud_Data.publish(output);
}

int main (int argc, char** argv)
{
    ros::init(argc,argv,"pcl_one");

    ros::NodeHandle nh;

    ROS_INFO("Starting Node V 1.0");

    ProcessPointClouds ProcessPointClouds(&nh);

    

    ros::Rate loop_rate(100);
    
   
        /* code for loop body */
    
    ros::spin();

    loop_rate.sleep();
    
}