#pragma once

#include <string>
#include <memory>
#include "config.pb.h" // 对应的proto文件的路径

namespace process {
class Process {
 public:
  typedef std::shared_ptr<Process> Ptr;
  typedef std::shared_ptr<Process const> ConstPtr;

  void LoadConfig(const std::string &config_file);
  void Init();

 private:
  alan::test::Config config_;
  std::string name_;
};
}  // namespace process
