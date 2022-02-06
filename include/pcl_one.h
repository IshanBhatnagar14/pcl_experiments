#ifndef __PCL_ONE_H__
#define __PCL_ONE_H__

/*
 * File: pcl_one.h
 * Project: include
 * File Created: Wednesday, 2nd February 2022 5:15:18 am
 * Author: <<Ishan B>> (<<ishan.b@octobotics.tech>>)
 * -----
 * Last Modified: Thursday, 3rd February 2022 12:54:44 pm
 * Modified By: <<Ishan B>> (<<ishan.b@octobotics.tech>>>)
 * -----
 * Copyright 2022 - 2022 Octobotics Tech Pvt Ltd, Octobotics-Tech
 */



#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <sensor_msgs/PointCloud2.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/filters/voxel_grid.h>



#include<ros/ros.h>
#include<ros/console.h>

class ProcessPointClouds {

public:

ProcessPointClouds(ros::NodeHandle *nodehandle);

ProcessPointClouds();
/**
 * @brief Default Constructor
 * 
 */

~ProcessPointClouds();

private:

ros::NodeHandle nh_;

ros::Publisher Pub_Point_Cloud_Data;

ros::Subscriber Sub_Point_Cloud_Data ;

void Subscribe_Point_Cloud(const sensor_msgs::PointCloud2ConstPtr &msg);
/**
 * @brief Callback for Point Cloud Data
 * 
 */

void DownSampling_Filter(const sensor_msgs::PointCloud2ConstPtr  &Point_Cloud);
/**
 * @brief Downsample the Incoming 
 * 
 */

// Variables



pcl::PCLPointCloud2 cloud_filtered ;


static pcl::PCLPointCloud2::Ptr cloud_blob ;


static pcl::PointCloud<pcl::PointXYZRGB>::Ptr _colour_point_cloud ;




// Filter

pcl::VoxelGrid<pcl::PCLPointCloud2> sor ;



};
#endif // __PCL_ONE_H__