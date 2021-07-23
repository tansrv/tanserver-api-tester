#! /bin/bash

apt-get update                                      && \
apt-get -y install build-essential cmake libssl-dev && \

cd ../build/ && cmake .. && make

if [ $? -ne 0 ]; then
  echo -e "\ntanserver: install failed\n"
fi
