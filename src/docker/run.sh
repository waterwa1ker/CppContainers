#! /bin/bash
echo Ubuntu_tester from ArhNex


docker stop tester
docker rmi ubuntu_tester:arhnex
docker build -t ubuntu_tester:arhnex ./docker
docker run -it --name tester --rm -v .:/project ubuntu_tester:arhnex /bin/zsh
