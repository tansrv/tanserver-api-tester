#! /bin/bash

yum -y install libarchive gcc gcc-c++ kernel-devel make cmake3 openssl-devel && \

cd ../build/ && cmake .. && make

if [ $? -ne 0 ]; then
  echo -e "\ntanserver: install failed\n"
fi
