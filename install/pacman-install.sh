#! /bin/bash

pacman -Sy                                            && \
pacman -S gcc make cmake openssl --noconfirm --needed && \

cd ../build/ && cmake .. && make

if [ $? -ne 0 ]; then
  echo -e "\ntanserver: install failed\n"
fi
