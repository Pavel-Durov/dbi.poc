FROM mcr.microsoft.com/devcontainers/base:0.203-ubuntu-22.04

WORKDIR /app

# Install DynamoRIO
RUN wget -q https://github.com/DynamoRIO/dynamorio/releases/download/cronbuild-9.93.19503/DynamoRIO-Linux-9.93.19503.tar.gz -O ./dynamorio.tar.gz
RUN tar -xzf ./dynamorio.tar.gz
ENV DRIO_HOME="/app/DynamoRIO-Linux-9.93.19503"

RUN sudo apt update
RUN sudo apt install shellcheck
RUN sudo apt install build-essential
RUN wget https://github.com/Kitware/CMake/releases/download/v3.22.1/cmake-3.22.1-linux-x86_64.sh \
    -q -O /tmp/cmake-install.sh \
    && chmod u+x /tmp/cmake-install.sh \
    && mkdir /opt/cmake-3.22.1 \
    && /tmp/cmake-install.sh --skip-license --prefix=/opt/cmake-3.22.1 \
    && rm /tmp/cmake-install.sh \
    && ln -s /opt/cmake-3.22.1/bin/* /usr/local/bin

COPY ../ .

# cmake
RUN rm -fr /app/build/ && cmake -DCMAKE_BUILD_TYPE=Debug -DDynamoRIO_DIR=/app/DynamoRIO-Linux-9.93.19503/cmake  -S  . -B ./build
# build
RUN cd ./build && make VERBOSE=1
