#include <ros/ros.h>
#include <sensor_msgs/PointCloud.h>
#include <sensor_msgs/PointCloud2.h>
#include <sensor_msgs/point_cloud_conversion.h>
#include "convert_pcl/ConvertPCL.h" 

using convert_pcl::ConvertPCL;

bool Cloud2ToCloudCallback(ConvertPCL::Request& request, ConvertPCL::Response& response)
{
  sensor_msgs::convertPointCloud2ToPointCloud(request.pointcloud2, response.pointcloud);

  return true;
}

int main(int argc, char** argv) {
  ros::init(argc, argv, "convert_pcl_server");
  ros::NodeHandle n;
  ros::ServiceServer service = n.advertiseService("convert_pcl_service", Cloud2ToCloudCallback);
  ros::spin();
  return 0;
}