#include <pcl_one.h>



pcl::PCLPointCloud2::Ptr ProcessPointClouds::cloud_blob(new pcl::PCLPointCloud2)  ;

pcl::PointCloud<pcl::PointXYZRGB>::Ptr ProcessPointClouds::_colour_point_cloud(new pcl::PointCloud<pcl::PointXYZRGB>) ;

// static pcl::visualization::CloudViewer ProcessPointClouds::viewer ;


ProcessPointClouds::ProcessPointClouds(ros::NodeHandle *nodehandle):nh_(*nodehandle){}


ProcessPointClouds::ProcessPointClouds(){
    ROS_INFO("Constructor Initialized");

    Sub_Point_Cloud_Data = nh_.subscribe("/os_cloud_node/points",100,&ProcessPointClouds::Subscribe_Point_Cloud,this);
}


ProcessPointClouds::~ProcessPointClouds(){

    Sub_Point_Cloud_Data.shutdown();
}

void ProcessPointClouds::Subscribe_Point_Cloud(const sensor_msgs::PointCloud2 &msg){

    sensor_msgs::PointCloud2 output ;

    output = msg;

    pcl::fromROSMsg(output,*_colour_point_cloud);

    // viewer.showCloud(_colour_point_cloud);

    
}

int main (int argc, char** argv)
{
    ros::init(argc,argv,"pcl_one");

    ros::NodeHandle nh;

    ROS_INFO("Starting Node");

    ProcessPointClouds ProcessPointClouds(&nh);

    ros::Rate loop_rate(100);
    while (ros::ok())
    {
        /* code for loop body */
    
        ros::spinOnce();
        loop_rate.sleep();
    }
}