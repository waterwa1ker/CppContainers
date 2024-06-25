#! /bin/bash
echo Ubuntu_tester from ArhNex

is_ubuntu_tester=`docker images | grep ubuntu_tester | awk '{print $1}'`
if [ $is_ubuntu_tester == ubuntu_tester ]
    then
        docker run -it --name tester --rm -v .:/project ubuntu_tester:arhnex /bin/zsh
else
    docker stop tester
    docker rmi ubuntu_tester:arhnex
    docker build -t ubuntu_tester:arhnex .
    docker run -it --name tester --rm -v .:/project ubuntu_tester:arhnex /bin/zsh
fi