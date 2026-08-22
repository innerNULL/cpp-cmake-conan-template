# file: build_in_container.sh
# date: 2026-08-22


# Install micromamba
curl -L micro.mamba.pm/install.sh | bash -s -- -y
source ~/.bashrc

# Initialize conda environment
micromamba env create -f environment.yaml -p ./_venv --yes
micromamba activate /workspace/_venv

# Install conan dependiencies
conan profile detect
# TODO: Add more compiling options around `-DDUMMY_COMPILE_OPTION=...` based on need
conan install . -pr=./conan_profile --output-folder=build --build=missing -s build_type=Release

# Build
# TODO: Add more compiling options around `-DDUMMY_COMPILE_OPTION=...` based on need
cmake \
  -DDUMMY_COMPILE_OPTION=ON \
  --preset conan-release

cmake --build --preset conan-release

