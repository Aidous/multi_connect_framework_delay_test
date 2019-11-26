export SCRIPTS_PATH=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)
export CYBER_PATH=${SCRIPTS_PATH}/cyber/deps/cyber/cyber
binary_path="${CYBER_PATH}/lib"
qt_path=/opt/Qt5.5.1/5.5/gcc_64
exe_path="${SCRIPTS_PATH}/../../build/connect_delay_test"
cyber_exe_path="${SCRIPTS_PATH}/../../build/connect_delay_test/cyber"

export LD_LIBRARY_PATH=${qt_path}/lib:${binary_path}:$LD_LIBRARY_PATH
export QT_QPA_PLATFORM_PLUGIN_PATH=${qt_path}/plugins:${qt_path}/bin:$PATH
export PYTHONPATH=${PYTHON_LD_PATH}:$PYTHONPATH
export PATH=${exe_path}:${cyber_exe_path}:$PATH

export CYBER_DOMAIN_ID=80
export CYBER_IP=127.0.0.1
export CYBER_RUN_MODE=reality  # reality or simulation


export GLOG_log_dir=${SCRIPTS_PATH}/cyber/data/log  # add for glog dir. # /apollo/data/log
export GLOG_alsologtostderr=1   # if print all meesage to terminal else 0.
export GLOG_colorlogtostderr=1
export GLOG_minloglevel=0

export cyber_trans_perf=0
export cyber_sched_perf=0

# for DEBUG log
#export GLOG_minloglevel=-1
#export GLOG_v=4
