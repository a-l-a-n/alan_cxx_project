#include <fstream>
#include <sstream>
#include <google/protobuf/util/json_util.h>
#include <glog/logging.h>
#include "process.h"

namespace process {
  void Process::LoadConfig(const std::string &config_file) {
    std::ifstream fin(config_file.c_str());
    if (!fin) {
      LOG(FATAL) << "Fail to read config file" << config_file;
    }
    std::stringstream buffer;
    buffer << fin.rdbuf();
    google::protobuf::util::JsonParseOptions options;
    options.ignore_unknown_fields = false;  // proto 和 json 的域必须对应
    auto status = google::protobuf::util::JsonStringToMessage(buffer.str(),
                                                        &config_, options);
    if (!status.ok()) {
      LOG(FATAL) << "Fail to parse json file [" << config_file << "]: ["
                 << status.error_message() << "]";
    }
  }

  void Process::Init() {
    name_ = config_.name();
    LOG(WARNING) << config_.name();
  }
}  // namespace process
