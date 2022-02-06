#ifndef __PCL_TWO_H__
#define __PCL_TWO_H__

/*
 * File: pcl_two.h
 * Project: include
 * File Created: Sunday, 6th February 2022 11:39:08 am
 * Author: <<Ishan B>> (<<ishan.b@octobotics.tech>>)
 * -----
 * Last Modified: Sunday, 6th February 2022 11:39:29 am
 * Modified By: <<Ishan B>> (<<ishan.b@octobotics.tech>>>)
 * -----
 * Copyright 2022 - 2022 Octobotics Tech Pvt Ltd, Octobotics-Tech
 */


#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <sensor_msgs/PointCloud2.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/filters/passthrough.h>



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

void PassThrough_Filter(const sensor_msgs::PointCloud2ConstPtr  &Point_Cloud);
/**
 * @brief Downsample the Incoming 
 * 
 */

// Variables



pcl::PCLPointCloud2 cloud_filtered ;


// Filter



};



#endif // __PCL_TWO_H__