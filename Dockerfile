# FROM mcr.microsoft.com/devcontainers/base:0.203-ubuntu-22.04
FROM --platform=linux/amd64 ubuntu:20.04

WORKDIR /app

RUN apt update
RUN apt install wget build-essential -y
RUN wget https://github.com/Kitware/CMake/releases/download/v3.22.1/cmake-3.22.1-linux-x86_64.sh \
    -q -O /tmp/cmake-install.sh \
    && chmod u+x /tmp/cmake-install.sh \
    && mkdir /opt/cmake-3.22.1 \
    && /tmp/cmake-install.sh --skip-license --prefix=/opt/cmake-3.22.1 \
    && rm /tmp/cmake-install.sh \
    && ln -s /opt/cmake-3.22.1/bin/* /usr/local/bin

COPY . .

# Install DynamoRIO
RUN cd /app && bash /app/scripts/shell/drio-setup
# cmake
RUN rm -fr build && \
    cmake -DCMAKE_BUILD_TYPE=Debug \
    -DDynamoRIO_DIR=/app/DynamoRIO-Linux-9.93.19503/cmake  \
    -S  . -B ./build

# build
RUN cd ./build && make VERBOSE=1
