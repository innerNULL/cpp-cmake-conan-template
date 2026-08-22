# -*- coding: utf-8 -*-
# file: containerized_build.sh
# date: 2025-08-22


set -x

source $1


function init {
  rm -rf ${WORKSPACE}
  mkdir -p ${WORKSPACE}
  cp conanfile.txt ${WORKSPACE}
  cp CMakeLists.txt ${WORKSPACE}
  cp CMakeUserPresets.json ${WORKSPACE}
  cp -r ./src ${WORKSPACE}
  cp -r ./bindings ${WORKSPACE}
  cp -r ./test ${WORKSPACE}
  #cp -r ./cmake ${WORKSPACE}
  cp ${CONDA_YAML_PATH} ${WORKSPACE}
  cp ${BUILD_IN_CONTAINER_SCRIPT_PATH} ${WORKSPACE}
  cp ${CONAN_PROFILE_PATH} ${WORKSPACE}/conan_profile
}


# TODO: Add more custom compiling options around `-e DUMMY_COMPILE_OPTION=...` based on need
function main {
  init
  local build_script=$(basename ${BUILD_IN_CONTAINER_SCRIPT_PATH})
  podman run -it --rm \
    -v ${WORKSPACE}:/workspace \
    -w /workspace \
    -e DUMMY_COMPILE_OPTION=${DUMMY_COMPILE_OPTION} \
    ${IMAGE} /bin/bash -c "cd /workspace && bash ./${build_script}"
}


main
