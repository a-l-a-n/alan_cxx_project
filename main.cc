#include <gflags/gflags.h>
#include <glog/logging.h>
#include "process.h"

DEFINE_string(config_path, "", "path of json config file");

int main (int argc, char** argv) {
  google::InitGoogleLogging(argv[0]);
  FLAGS_logtostderr = true;
  FLAGS_colorlogtostderr = true;

  gflags::SetUsageMessage("\nUsageMessage: ./bin/test --config_path config.json");
  google::ParseCommandLineFlags(&argc, &argv, true);

  if (FLAGS_config_path.empty()) {
    gflags::ShowUsageWithFlagsRestrict(argv[0], "main");
    return -1;
  }

  process::Process processor;
  processor.LoadConfig(FLAGS_config_path);
  processor.Init();

  google::ShutdownGoogleLogging();
  return 0;
}
