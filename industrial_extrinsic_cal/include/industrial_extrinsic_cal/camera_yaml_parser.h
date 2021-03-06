#ifndef CAMERA_YAML_PARSER_H
#define CAMERA_YAML_PARSER_H

#include <boost/shared_ptr.hpp>
#include <yaml-cpp/yaml.h>
#include <iostream>
#include <industrial_extrinsic_cal/basic_types.h>
#include <industrial_extrinsic_cal/camera_definition.h>
#include <industrial_extrinsic_cal/transform_interface.hpp>
#include <industrial_extrinsic_cal/trigger.h>


namespace industrial_extrinsic_cal {

  using std::string;
  using std::ifstream;
  using std::vector;
  using boost::shared_ptr;
  using YAML::Node;

  // prototypes
  /** @brief parses a single camera, either moving or static 
   *   @param node, the yaml node 
   *   @return a shared pointer to camera parsed
   **/
  shared_ptr<Camera> parseSingleCamera(const Node &node);
  /** @brief parses a transform interface
   *   @param node, the yaml node 
   *   @param frame, the frame that the transform interface refers to
   *   @return a shared pointer to transform interface parsed
   **/
  shared_ptr<TransformInterface> parseTransformInterface(const Node &node, string &name, string &frame);
  /** @brief parses a trigger
   *   @param node, the yaml node 
   *   @param name name of trigger
   *   @return shared pointer to the trigger parsed
   **/
  shared_ptr<Trigger> parseTrigger(const Node &node, string &name);
  /** @brief parses a Pose6d
   *   @param node, the yaml node 
   *   @return Pose6d parsed
   **/
  Pose6d parsePose(const Node &node);
  /** @brief parse all the cameras, the main function of this module
   *   @param camera_input_file the stream from which to parse a vector of cameras
   *   @param returned vector of shared pointers to cameras
   **/
  void parseCameras(ifstream &cameras_input_file,vector<shared_ptr<Camera> >& cameras);
}// end industrial_extrinsic_cal namespace

#endif
