FROM ubuntu:22.04

LABEL author="ArhNex"

ENV TZ="Europe/Moscow"
RUN date

RUN apt-get -y update 

# for disable interactive mod apt-get
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends tzdata

RUN apt-get -y update 

# install some develop tools
RUN apt-get install -y g++ make nano check clang-format gcovr git valgrind htop lcov libgtest-dev

#install zsh and oh-my-zsh
RUN apt-get install -y neofetch zsh curl

RUN curl -L https://raw.github.com/robbyrussell/oh-my-zsh/master/tools/install.sh | sh
RUN echo clear >> ~/.zshrc
RUN echo neofetch >> ~/.zshrc
RUN echo "alias sh='bash'" >> ~/.zshrc

RUN apt-get -y upgrade 
RUN mkdir /project

WORKDIR /project